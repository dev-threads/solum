#include "solumqt.h"
#include <memory>
#include <iostream>
#include <solum.h>

static std::unique_ptr<Solum> _solum;
static std::vector<char> _image;
static std::vector<char> _prescanImage;
static std::vector<char> _spectrum;
static std::vector<char> _rfData;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName(QStringLiteral("Clarius"));
    QCoreApplication::setOrganizationDomain(QStringLiteral("clarius.com"));
    QCoreApplication::setApplicationName(QStringLiteral("Solum Demo"));

    const int width  = 640; // width of the rendered image
    const int height = 480; // height of the rendered image

    _solum = std::make_unique<Solum>();

    if (solumInit(argc, argv, QStandardPaths::writableLocation(QStandardPaths::AppDataLocation).toStdString().c_str(),
        // connection callback
        [](CusConnection res, int port, const char* msg)
        {
            QApplication::postEvent(_solum.get(), new event::Connection(res, port, QString::fromLatin1(msg)));
        },
        // cert callback
        [](int daysValid)
        {
            QApplication::postEvent(_solum.get(), new event::Cert(daysValid));
        },
        // power down callback
        [](CusPowerDown res, int tm)
        {
            QApplication::postEvent(_solum.get(), new event::PowerDown(res, tm));
        },
        // new image callback
        [](const void* img, const CusProcessedImageInfo* nfo, int npos, const CusPosInfo* pos)
        {
            int sz = nfo->imageSize;
            // we need to perform a deep copy of the image data since we have to post the event (yes this happens a lot with this api)
            if (_image.size() < static_cast<size_t>(sz))
                _image.resize(sz);
            memcpy(_image.data(), img, sz);
            QQuaternion imu;
            if (npos && pos)
                imu = QQuaternion(static_cast<float>(pos[0].qw), static_cast<float>(pos[0].qx), static_cast<float>(pos[0].qy), static_cast<float>(pos[0].qz));

            QApplication::postEvent(_solum.get(), new event::Image(IMAGE_EVENT, _image.data(), nfo->width, nfo->height, nfo->bitsPerPixel, sz, imu));
        },
        // new raw data callback
        [](const void* data, const CusRawImageInfo* nfo, int, const CusPosInfo*)
        {
            // we need to perform a deep copy of the image data since we have to post the event (yes this happens a lot with this api)
            int sz = nfo->lines * nfo->samples * (nfo->bitsPerSample / 8);
            if (nfo->rf)
            {
                if (_rfData.size() < static_cast<size_t>(sz))
                    _rfData.resize(sz);
                memcpy(_rfData.data(), data, sz);
                QApplication::postEvent(_solum.get(), new event::RfImage(_rfData.data(), nfo->lines, nfo->samples, nfo->bitsPerSample, sz,
                                                                            nfo->lateralSize, nfo->axialSize));
            }
            else
            {
                // image may be a jpeg, adjust the size
                if (nfo->jpeg)
                    sz = nfo->jpeg;
                if (_prescanImage.size() < static_cast<size_t>(sz))
                    _prescanImage.resize(sz);
                memcpy(_prescanImage.data(), data, sz);
                QApplication::postEvent(_solum.get(), new event::Image(PRESCAN_EVENT, _prescanImage.data(), nfo->lines, nfo->samples,
                                                                          nfo->bitsPerSample, sz, QQuaternion()));
            }
        },
        // new spectrum callback
        [](const void* img, const CusSpectralImageInfo* nfo)
        {
            size_t sz = nfo->lines * nfo->samples * (nfo->bitsPerSample / 8);
            // we need to perform a deep copy of the spectrum data since we have to post the event (yes this happens a lot with this api)
            if (_spectrum.size() < sz)
                _spectrum.resize(sz);
            memcpy(_spectrum.data(), img, sz);
            QApplication::postEvent(_solum.get(), new event::SpectrumImage(_spectrum.data(), nfo->lines, nfo->samples, nfo->bitsPerSample));
        },
        // imaging state change callback
        [](CusImagingState state, int imaging)
        {
            // post event here, as the gui (statusbar) will be updated directly, and it needs to come from the application thread
            QApplication::postEvent(_solum.get(), new event::Imaging(state, imaging ? true : false));
        },
        // button press callback
        [](CusButton btn, int clicks)
        {
            // post event here, as the gui (statusbar) will be updated directly, and it needs to come from the application thread
            QApplication::postEvent(_solum.get(), new event::Button(btn, clicks));
        },
        // error message callback
        [](const char* err)
        {
            // post event here, as the gui (statusbar) will be updated directly, and it needs to come from the application thread
            QApplication::postEvent(_solum.get(), new event::Error(err));
        },
        width, height) != 0)
    {
        qDebug() << "error initializing listener";
        return -1;
    }

    _solum->show();
    const int result = a.exec();
    solumDestroy();
    _solum.reset();
    return result;
}

/*=========================================================================

  Program:   OpenIGTLLink Library -- Dummy tdata data
  Module:    $RCSfile: $
  Language:  C
  Date:      $Date: $
  Version:   $Revision: $

  Copyright (c) Insight Software Consortium. All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#ifndef __IGTL_TEST_DATA_TDATA_H
#define __IGTL_TEST_DATA_TDATA_H

unsigned char test_tdata_message[] = {
  /*------- OpenIGTLink message header --------*/
  0x00, 0x01,                                     /* Version number */
  0x54, 0x44, 0x41, 0x54, 0x41, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,                         /* TDATA */
  0x44, 0x65, 0x76, 0x69, 0x63, 0x65, 0x4e, 0x61,
  0x6d, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,                         /* Device name */
  0x00, 0x00, 0x00, 0x00, 0x49, 0x96, 0x02, 0xd4, /* Time stamp */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd2, /* Body size */
  0x5c, 0x7c, 0xeb, 0xfd, 0x27, 0x67, 0x68, 0x77, /* CRC */

  /*---------- TDATA message body ------------*/
  /* Tracker data 0 */
  0x54, 0x72, 0x61, 0x63, 0x6b, 0x65, 0x72, 0x30,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,                         /* Name */
  0x02,                                           /* Instrument type */
  0x00,
  0xBF, 0x74, 0x73, 0xCD, 0x3E, 0x49, 0x59, 0xE6, /* tx, ty */
  0xBE, 0x63, 0xDD, 0x98, 0xBE, 0x49, 0x59, 0xE6, /* tz, sx */
  0x3E, 0x12, 0x49, 0x1B, 0x3F, 0x78, 0x52, 0xD6, /* sy, sz */
  0x3E, 0x63, 0xDD, 0x98, 0x3F, 0x78, 0x52, 0xD6, /* nx, ny */
  0xBD, 0xC8, 0x30, 0xAE, 0x42, 0x38, 0x36, 0x60, /* nz, px */
  0x41, 0x9B, 0xC4, 0x67, 0x42, 0x38, 0x36, 0x60, /* py, pz */

  /* Tracker data 1 */
  0x54, 0x72, 0x61, 0x63, 0x6b, 0x65, 0x72, 0x31,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,                         /* Name */
  0x02,                                           /* Instrument type */
  0x00,
  0xBF, 0x74, 0x73, 0xCD, 0x3E, 0x49, 0x59, 0xE6, /* tx, ty */
  0xBE, 0x63, 0xDD, 0x98, 0xBE, 0x49, 0x59, 0xE6, /* tz, sx */
  0x3E, 0x12, 0x49, 0x1B, 0x3F, 0x78, 0x52, 0xD6, /* sy, sz */
  0x3E, 0x63, 0xDD, 0x98, 0x3F, 0x78, 0x52, 0xD6, /* nx, ny */
  0xBD, 0xC8, 0x30, 0xAE, 0x42, 0x38, 0x36, 0x60, /* nz, px */
  0x41, 0x9B, 0xC4, 0x67, 0x42, 0x38, 0x36, 0x60, /* py, pz */

  /* Tracker data 1 */
  0x54, 0x72, 0x61, 0x63, 0x6b, 0x65, 0x72, 0x32,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,                         /* Name */
  0x02,                                           /* Instrument type */
  0x00,
  0xBF, 0x74, 0x73, 0xCD, 0x3E, 0x49, 0x59, 0xE6, /* tx, ty */
  0xBE, 0x63, 0xDD, 0x98, 0xBE, 0x49, 0x59, 0xE6, /* tz, sx */
  0x3E, 0x12, 0x49, 0x1B, 0x3F, 0x78, 0x52, 0xD6, /* sy, sz */
  0x3E, 0x63, 0xDD, 0x98, 0x3F, 0x78, 0x52, 0xD6, /* nx, ny */
  0xBD, 0xC8, 0x30, 0xAE, 0x42, 0x38, 0x36, 0x60, /* nz, px */
  0x41, 0x9B, 0xC4, 0x67, 0x42, 0x38, 0x36, 0x60, /* py, pz */

};

#endif /* IGTL_TEST_DATA_TDATA_H */




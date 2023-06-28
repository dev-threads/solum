/*=========================================================================

  Program:   OpenIGTLLink Library -- Dummy status data
  Module:    $RCSfile: $
  Language:  C
  Date:      $Date: $
  Version:   $Revision: $

  Copyright (c) Insight Software Consortium. All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#ifndef __IGTL_TEST_DATA_SENSOR_H
#define __IGTL_TEST_DATA_SENSOR_H

unsigned char test_sensor_message[] = {
  0x00, 0x01,                                     /* Version number */
  0x53, 0x45, 0x4e, 0x53, 0x4f, 0x52, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,                         /* SENSOR */ 
  0x44, 0x65, 0x76, 0x69, 0x63, 0x65, 0x4e, 0x61,
  0x6d, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00,                         /* Device name */
  0x00, 0x00, 0x00, 0x00, 0x49, 0x96, 0x02, 0xd4, /* Time stamp */
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3a, /* Body size */
  0x63, 0x7b, 0x80, 0x08, 0x66, 0x20, 0x20, 0xe7, /* CRC */

  0x06,                                           /* larray */
  0x00,                                           /* status */
  0x00, 0x44, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, /* unit */

  0x40, 0xfe, 0x24, 0x0c, 0x7a, 0xe1, 0x47, 0xae, /* value: sensor #0 */
  0x40, 0xc8, 0x1c, 0xd6, 0xc8, 0xb4, 0x39, 0x58, /* value: sensor #1 */
  0x40, 0x93, 0x4a, 0x45, 0x6d, 0x5c, 0xfa, 0xad, /* value: sensor #2 */
  0x40, 0x5e, 0xdd, 0x3b, 0xe2, 0x2e, 0x5d, 0xe1, /* value: sensor #3 */
  0x40, 0x28, 0xb0, 0xfc, 0xb4, 0xf1, 0xe4, 0xb4, /* value: sensor #4 */
  0x3f, 0xf3, 0xc0, 0xca, 0x2a, 0x5b, 0x1d, 0x5d, /* value: sensor #4 */
};

#endif /* IGTL_TEST_DATA_SENSOR_H */





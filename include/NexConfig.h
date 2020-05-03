/**
 * @file NexConfig.h
 *
 * Options for user can be found here. 
 *
 * @author  Wu Pengfei (email:<pengfei.wu@itead.cc>)
 * @date    2015/8/13
 * @author Jyrki Berg 2/17/2019 (https://github.com/jyberg)
 * 
 * @copyright 
 * Copyright (C) 2014-2015 ITEAD Intelligent Systems Co., Ltd. \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 * 
 * @copyright 2019 Jyrki Berg
 *
 */

#pragma once

/**
 * @addtogroup Configuration 
 * @{ 
 */

/** 
 * Define DEBUG_SERIAL_ENABLE to enable debug serial. 
 * Comment it to disable debug serial. 
 */
//#define DEBUG_SERIAL_ENABLE

/**
 * Define dbSerial for the output of debug messages. 
 * it is resonsibility of main program to initialize debug serial port (begin(...)
 */
//#define dbSerial Serial

// Enable Next TFT file upload functionality
//#define NEX_ENABLE_TFT_UPLOAD

// Enable SoftwareSerial support by definign NEX_ENABLE_SW_SERIAL
// NodeMcu / Esp8266 use Softwareserial if usb port is used for debuging
// NodeMcu board pin numbers not match with Esp8266 pin numbers use NodeMcu Pin number definitions (pins_arduino.h)
#define NEX_ENABLE_SW_SERIAL


#ifdef DEBUG_SERIAL_ENABLE
#define dbSerialPrint(a)    dbSerial.print(a)
#define dbSerialPrintln(a)  dbSerial.println(a)
#define dbSerialBegin(a)    dbSerial.begin(a)
#else
#define dbSerialPrint(a)   do{}while(0)
#define dbSerialPrintln(a) do{}while(0)
#define dbSerialBegin(a)   do{}while(0)
#endif

/**
 * @}
 */

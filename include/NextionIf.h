/**
 * @file NextionIf.h
 *
 * Nextion interface implementation interface
 *
 * @author Jyrki Berg 11/23/2019 (https://github.com/jyberg)
 * 
 * @copyright 2019 Jyrki Berg
 *
 */

#pragma once
#include "NexHardwareInterface.h"
class Nextion;


/**
 * @addtogroup CoreAPI 
 * @{ 
 */

/**
 * Nextion Interface class implementation for Nextion objects
 *
 * Provides call wrapper to nextion interface
 */
class NextionIf:public NextionInterface
{
public:

    NextionIf(const Nextion *nextion);
    ~NextionIf();

/* Receive unsigned number
*
* @param number - received value
* @param timeout - set timeout time.
*
* @retval true - success.
* @retval false - failed. 
*/
bool recvRetNumber(uint32_t *number, size_t timeout = 100) const final;

/* Receive signed number
*
* @param number - received value
* @param timeout - set timeout time.
*
* @retval true - success.
* @retval false - failed. 
*/
bool recvRetNumber(int32_t *number, size_t timeout = 100) const final;

/* Receive string
*
* @param string - received value
* @param timeout - set timeout time.
*
* @retval true - success.
* @retval false - failed. 
*/
virtual bool recvRetString(String &str, size_t timeout = 100) const final;

/* Receive string
*
* @param buffer - received value buffer
* @param le - value buffer size
* @param timeout - set timeout time.
*
* @retval true - success.
* @retval false - failed. 
*/
bool recvRetString(char *buffer, uint16_t &len, size_t timeout = 100) const final;

/* Send Command to device
*
* parameter command string
*/
void sendCommand(const char* cmd) const final;

/* Send Raw data to device
*
* parameter raw data buffer
*/
#ifdef ESP8266
void sendRawData(const std::vector<uint8_t> &data) const final;
#endif

/* Send Raw data to device
*
* @param buf - raw data buffer poiter
* @param len - raw data buffer pointer
*/
void sendRawData(const uint8_t *buf, uint16_t len) const final;


/* Send Raw byte to device
*
* parameter raw byte
*/
void sendRawByte(const uint8_t byte) const final;

/* Receive command
*
* @param command - command to be received / checked
* @param timeout - set timeout time.
*
* @retval true - success.
* @retval false - failed. 
*/
bool recvCommand(const uint8_t command, size_t timeout) const final;

/*
 * Command is executed successfully. 
 *
 * @param timeout - set timeout time.
 *
 * @retval true - success.
 * @retval false - failed. 
 *
 */
bool recvRetCommandFinished(size_t timeout = 200) const final;

/*
 * Transpared data mode setup successfully 
 *
 * @param timeout - set timeout time.
 *
 * @retval true - success.
 * @retval false - failed. 
 *
 */
bool RecvTransparendDataModeReady(size_t timeout = 400) const final;

/*
 * Transpared data mode finished 
 *
 * @param timeout - set timeout time.
 *
 * @retval true - success.
 * @retval false - failed. 
 *
 */
bool RecvTransparendDataModeFinished(size_t timeout = 200) const final;

/**
 * current baud value
 * 
 * 
 * @return current baud value
 */
uint32_t GetCurrentBaud() const final;


private: // data
    const Nextion *m_nextion; // nextion interface instance
};

/**
 * @} 
 */

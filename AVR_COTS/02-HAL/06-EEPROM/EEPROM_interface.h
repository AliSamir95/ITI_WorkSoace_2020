/*
 * EEPROM__interface.h
 *
 *  
 *      Author: ALI
 */

#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

#define  OK   0
#define  NOK  1

u8 EEPROM_u8WriteDataByte(u16 ByteAddress,u8 ByteData);
u8 EEPROM_u8ReadDataByte(u16 ByteAddress,u8 * pu8ReturnData);


#endif 

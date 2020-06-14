#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "I2C_interface.h"
#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_config.h"

u8 EEPROM_u8WriteDataByte(u16 ByteAddress,u8 ByteData)
{
	u8 Return_status=OK;
	/*Start condition*/
	I2C_enuSendStartCondition();
	/*Send Slave Adress*/
	I2C_enuSendSlaveAddWithWrite ((EEPROM_FIXED_ADDRESS | (EEPROM_A2_VALUE << 2)) | ((ByteAddress >> 8)&3));
	/*Send Byte Address*/
	I2C_voidMasterSendDataByte((u8)ByteAddress);
	/*Send DATA*/
	I2C_voidMasterSendDataByte(ByteData);
	/*Stop Condition*/
	I2C_voidSendStopCondition();
	return Return_status;
}
u8 EEPROM_u8ReadDataByte(u16 ByteAddress,u8 * pu8ReturnData)
{
	u8 Return_status=OK;
	/*Start condition*/
	I2C_enuSendStartCondition();
	/*Send Slave Adress*/
	I2C_enuSendSlaveAddWithWrite ((EEPROM_FIXED_ADDRESS | (EEPROM_A2_VALUE << 2)) | ((ByteAddress >> 8)&3));
	/*Send Byte Address*/
	I2C_voidMasterSendDataByte((u8)ByteAddress);
	/*Repeated start condition */
	I2C_enuSendReStartCondition();
	/*Send slave address with read*/
	I2C_enuSendSlaveAddWithRead(EEPROM_FIXED_ADDRESS | (EEPROM_A2_VALUE << 2)) | ((ByteAddress >> 8)&3));
	/*Read Data */
	I2C_enuMasterReadDataByte(pu8ReturnData);
	/*Stop Condition*/
	I2C_voidSendStopCondition();
	return Return_status;	
}





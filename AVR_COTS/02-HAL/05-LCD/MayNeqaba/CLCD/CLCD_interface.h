 /************************************************************************\
 * Author : May Alaa                                                     * 
 * Version : 1                                                           *
 * Date 14/1/2020                                                        *
 \************************************************************************/

/*****************************************************
* Description: This API shall initialize LCD
*  Input Parameter: void
*  Return: void 
*****************************************************/
void CLCD_voidInitialize(void);

/*****************************************************
* Description: This API shall Display Data on LCD
*  Input Parameter: 
*		- u8 Copy_u8Data: Data to be displayed
*  Return: void 
******************************************************/
void CLCD_voidWriteData(u8 Copy_u8Data);

/*****************************************************
* Description: This API shall execute commands
*  Input Parameter: 
*		- u8 Copy_u8Cmd: Command to be executed
*  Return: void 
******************************************************/
void CLCD_voidWriteCmd(u8 Copy_u8Cmd);


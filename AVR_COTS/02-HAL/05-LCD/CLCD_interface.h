
/********************************/
/* Author : Ali Samir           */ 
/*Version : V01                 */
/*Date    : 14 Jan 2020         */
/********************************/
 

#define CLCD_LINE_1      1     
#define CLCD_LINE_2      4   
 
 /*Description : This API shall initialize LCD */ 
void CLCD_voidInitalize (void);
/*Description : This API shall display data on LCD */ 
void CLCD_voidWriteData (u8 Copy_u8Data);
/*Description : This API shall display data on LCD */ 
void CLCD_voidWriteCmd (u8 Copy_u8Cmd);

/*Goto location function*/
void CLCD_voidGotoLocation(u8 Copy_LineNb,u8 Copy_Position);

/*Write String */

void CLCD_voidWriteString( char * Copy_Pu8String ) ;

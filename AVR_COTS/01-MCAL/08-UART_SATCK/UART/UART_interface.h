/*******************************************************/
/* Author : ALI SAMIR                                  */ 
/* DATEE  : 9 march 2020                               */ 
/* Version: V01                                        */ 
/*******************************************************/

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H



void UART_voidInitialize(void);

u8 UART_u8TransmitDataSynch(u8 Copy_u8Data)

void UART_voidTransmitDataASynch(u8 Copy_u8Data,void(*Copy_ptr)(void));

u8 UART_u8ReceiveSynch(u8 * Copy_ptrData)

void UART_u8ReceiveSynch(void(*Copy_ptr)(void));

#endif

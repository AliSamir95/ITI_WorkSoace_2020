/*******************************************************/
/* Author : ALI SAMIR                                  */ 
/* DATEE  : 9 march 2020                               */ 
/* Version: V01                                        */ 
/*******************************************************/

#ifndef UART_CONFIG_H
#define UART_CONFIG_H


/* options: UART_PARITY_DISABLED
 *          UART_PARITY_EVEN
 *          UART_PARITY_ODD
*/

#define UART_u8_PARITY   UART_PARITY_DISABLED


/* options: UART_BAUDRATE_4800
 *          UART_BAUDRATE_9600
 *          UART_BAUDRATE_115200
*/

#define  UART_BAUDRATE   UART_BAUDRATE_9600

/* options: UART_STOP_1_BIT
 *          UART_STOP_2_BIT
*/

#define  UART_u8_STOP_BITS   UART_STOP_1_BIT
/* options: UART_u8_SYS_FREQ_8M
 *          UART_u8_SYS_FREQ_12M
 *          UART_u8_SYS_FREQ_16M
*/

#define  UART_u8_SYS_FREQ  UART_u8_SYS_FREQ_8M

/* Time out mechanism*/

#define  UART_u8_TIME_OUT_TH  10000 

#endif

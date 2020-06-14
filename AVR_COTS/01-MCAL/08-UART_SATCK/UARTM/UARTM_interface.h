/*******************************************************/
/* Author : ALI SAMIR                                  */ 
/* DATEE  : 11 march 2020                              */ 
/* Version: V01                                        */ 
/*******************************************************/

#ifndef UARTM_INTERFACE_H
#define UARTM_INTERFACE_H
            
            
#define            UARTM_SEND_SYNC       0
#define            UARTM_SEND_ASYNC      1
#define            UARTM_REC_SYNC        2
#define            UARTM_REC_ASYNC       3

typedef struct
{
  u8 JobType;
  u8 * DataBuffer;
  u8 Length;
  void (*CallBack)(void);
}UARTM_JobRequest;


u8 URTM_u8performJobRequest(UARTM_JobRequest Copy_JobInfo);

#endif

/*******************************************************/
/* Author : ALI SAMIR                                  */ 
/* DATEE  : 11 march 2020                              */ 
/* Version: V01                                        */ 
/*******************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"UART_interface.h"
#include"UARTM_interface.h"
#include"UARTM_config.h"
#include"UARTM_private.h"


  
UARTM_JobRequest  UARTM_QUEUE[UARTM_u8_MAX_QUEUE_SIZE];
u8                UARTM_QCurrent=0;
u8                UARTM_QNext=0;
u8                UARTM_QAvailable=UARTM_u8_MAX_QUEUE_SIZE; 
 
 u8 URTM_u8performJobRequest(UARTM_JobRequest Copy_JobInfo)
{
 
  u8 Local_u8status=OK;
 /*add the job to the queue "Enqueu"*/
  /*add job to the next location */
  if(UARTM_QAvailable>0)
  {
  UARTM_QAvailable--;
  UARTM_QUEUE[UARTM_QCurrent]=Copy_JobInfo;
  /*Increment the next*/
 
  if(UARTM_QNext==(UARTM_u8_MAX_QUEUE_SIZE-1))
  {
    UARTM_QNext=0;
  }
  else
  {
   UARTM_QNext++; 
  }
    voidExecute();
  }
  else 
  {
  Local_u8status=NOK;
  }
}


static void voidExecute(void)
{
 
u8 localaCounter;

 if(UARTM_QAvailable==UARTM_u8_MAX_QUEUE_SIZE)
  {
    
  } 
 /*Queue include jobs*/ 
  else 
  {
      if(UARTM_QAvailable==UARTM_u8_MAX_QUEUE_SIZE-1)
      {
        /*start Job */
        switch(UARTM_QUEUE[UARTM_QCurrent].JobType)
        {
          case UARTM_SEND_SYNC:
          
          for(localaCounter=0,localaCounter<UARTM_QUEUE[UARTM_QCurrent].Length;localaCounter++)
          {
            UART_u8TransmitDataSynch(UARTM_QUEUE[UARTM_QCurrent].DataBuffer[localaCounter]);
          }
          UARTM_QAvailable++;
          if(UARTM_QCurrent==(UARTM_u8_MAX_QUEUE_SIZE-1))
            {
              UARTM_QCurrent=0;
            }
            else
            {
            UARTM_QCurrent++; 
            }
              voidExecute();
            }
          break;
          case UARTM_SEND_ASYNC:
          break;

          case UARTM_REC_SYNC:
          break;

          case UARTM_REC_ASYNC:
          break;

        }
      }
      else
      {
        
      }
  }
}
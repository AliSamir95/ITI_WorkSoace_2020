/*************************************************/
/*Author :Ali Samir                              */ 
/*DATE :30 March 2020                            */ 
/*Version :V01                                   */ 
/*************************************************/
#ifnde  _DMA_REGISTER_H
#define _DMA_REGISTER_H

typedef struct 
{
  u32 CCR;
  u32 CNDTR;
  u32 CPAR;
  u32 CMAR;
  u32 Reserved;
}DMA_Channel;

typedef struct 
{
  u32               ISR;
  u32              IFCR;
  DMA_Channel  Array[7];
}DMA_Type;


#define  myDMA   ((volatile DMA_Type *)0x4002 0000) 


#endif
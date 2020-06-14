/*************************************************/
/*Author :Ali Samir                              */ 
/*DATE :30 March 2020                            */ 
/*Version :V01                                   */ 

#ifnde  _DMA_INTERFACE_H
#define _DMA_INTERFACE_H

/*DMA Channel 1 initialization */ 
void DMA_Init(void);


/*DMA Channel 1 Start*/

void DMA_voidStart(u32  Copy_SourceAddress,u32  Copy_DestinationAddress,u16 Copy_BlockKength);

#endif
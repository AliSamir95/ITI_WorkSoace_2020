/*
 * DMA_Cfg.h
 *
 *  Created on: Apr 15, 2020
 *      Author: MOSTAFA
 */

#ifndef DMA_CFG_H_
#define DMA_CFG_H_

#define DMA1_GET_INT_GL1                       0
#define DMA1_GET_INT_TC1                       1
#define DMA1_GET_INT_HT1                       2
#define DMA1_GET_INT_TE1                       3
#define DMA1_GET_INT_GL2                       4
#define DMA1_GET_INT_TC2                       5
#define DMA1_GET_INT_HT2                       6
#define DMA1_GET_INT_TE2                       7
#define DMA1_GET_INT_GL3                       8
#define DMA1_GET_INT_TC3                       9
#define DMA1_GET_INT_HT3                       10
#define DMA1_GET_INT_TE3                       11
#define DMA1_GET_INT_GL4                       12
#define DMA1_GET_INT_TC4                       13
#define DMA1_GET_INT_HT4                       14
#define DMA1_GET_INT_TE4                       15
#define DMA1_GET_INT_GL5                       16
#define DMA1_GET_INT_TC5                       17
#define DMA1_GET_INT_HT5                       18
#define DMA1_GET_INT_TE5                       19
#define DMA1_GET_INT_GL6                       20
#define DMA1_GET_INT_TC6                       21
#define DMA1_GET_INT_HT6                       22
#define DMA1_GET_INT_TE6                       23
#define DMA1_GET_INT_GL7                       24
#define DMA1_GET_INT_TC7                       25
#define DMA1_GET_INT_HT7                       26
#define DMA1_GET_INT_TE7                       27

#define MEMORY2MEMORY			 0x00004000
#define MEMORY2PERIPHERAL		 0x00000000

#define PRIORITY_LOW			 0x00000000
#define PRIORITY_MEDIUM			 0x00001000
#define PRIORITY_HIGH			 0x00002000
#define PRIORITY_VERYHIGH		 0x00003000

#define MEMORY_SIZE_1_BYTE 		 0x00000000
#define MEMORY_SIZE_2_BYTE		 0x00000400
#define MEMORY_SIZE_4_BYTE		 0x00000800

#define PERIPHERAL_SIZE_1_BYTE 	 0x00000000
#define PERIPHERAL_SIZE_2_BYTE	 0x00000100
#define PERIPHERAL_SIZE_4_BYTE	 0x00000200

#define MEMORY_INCREMENT_ON		 0x00000080
#define MEMORY_INCREMENT_OFF	 0x00000000

#define PERIPHERAL_INCREMENT_ON  0x00000040
#define PERIPHERAL_INCREMENT_OFF 0x00000000

#define CIRCULER_INT_ON			 0x00000020
#define CIRCULER_INT_OFF		 0x00000000

#define DIR_PERI_TO_MEMORY		 0x00000000
#define DIR_MEMORY_TO_PERI	 	 0x00000010

#define TRANSFER_ERROR_INT_ON  	 0x00000008
#define TRANSFER_ERROR_INT_OFF	 0x00000000

#define HALF_TRANSFER_INT_ON	 0x00000004
#define HALF_TRANSFER_INT_OFF	 0x00000000

#define TRANSFER_COMP_INT_ON	 0x00000002
#define TRANSFER_COMP_INT_OFF	 0x00000000



#define MAX_NUMBER_OF_CHANNELS	2

typedef struct
{
	uint_32t Mem2Mem;
	uint_32t PL;
	uint_32t MSIZE;
	uint_32t PSIZE;
	uint_32t MINC;
	uint_32t PINC;
	uint_32t CIRC;
	uint_32t DIR;
	uint_32t TEIE;
	uint_32t HTIE;
	uint_32t TCIE;
	uint_8t	 ChannelNumber;
}DMA_Config;





#endif /* DMA_CFG_H_ */

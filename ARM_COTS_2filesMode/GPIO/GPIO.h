typedef enum 
{
  PortA,
  PortB,
  PortC,
  PortD,
  PortE,
  PortF,
  PortG
}PORT_t;

typedef struct 
{
  uint32_t CRL;
  uint32_t CRH;
  uint32_t IDR;
  uint32_t ODR;
  uint32_t BSRR;
  uint32_t BRR;
  uint32_t LCKR;
}REG_t


#define PIN_0 	0x0001
#define PIN_1   0x0002
#define PIN_2	  0x0004
#define PIN_3 	0x0008
#define PIN_4	  0x0010
#define PIN_5 	0x0020
#define PIN_6 	0x0040
#define PIN_7   0x0080
#define PIN_8	  0x0100
#define PIN_9	  0x0200
#define PIN_10	0x0400
#define PIN_11	0x0800
#define PIN_12	0x1000
#define PIN_13	0x2000
#define PIN_14	0x4000
#define PIN_15	0x8000
#define PIN_ALL 0xFFFF

typedef enum 
{
  Input_Analog=0x00,
  Input_Floating=0x04,
  Input_PullUp=0x08,
  Input_PullDown=0x18,
  Output_GP_PP=0x10,
  Output_GP_OD=0x14,
  Output_AF_PP=0x28,
  Output_AF_OD=0x0c
  
}MODE_t;


typedef enum 
{
  Speed_10MHZ,
  Speed_2MHZ,
  Speed_50MHZ
}SPEED_t;


typedef struct 
{
  uint16_t  Pin ;
  PORT_t  Port;
  MODE_t Mode;
  SPEED_t Speed;
}GPIO_t;

typedef enum 
{
  OK,
  NOT_OK
}Error_Status_t;

#define OK  0
#define NOK 1

Error_Status_t GPIO_ErrorInit (GPIO_t * Copy_Init);
Error_Status_t GPIO_ErrorWrite(PORT_t Copy_port,uint16_t  Copy_Pin,uint16_t  Copy_Value);
Error_Status_t GPIO_ErrorRead (PORT_t Copy_port,uint16_t  Copy_Pin,uint16_t  Copy_Value);














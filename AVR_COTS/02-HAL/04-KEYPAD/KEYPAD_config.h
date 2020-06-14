/*Keypad ROWS PINS Configuration */
#define KEYPAD_R1_PORT   'D'
#define KEYPAD_R1_PIN      4

#define KEYPAD_R2_PORT    'D'
#define KEYPAD_R2_PIN       5

#define KEYPAD_R3_PORT    'D'
#define KEYPAD_R3_PIN       6

#define KEYPAD_R4_PORT    'D'
#define KEYPAD_R4_PIN       7

/*Keypad ROWS PINS Configuration */                                        
#define KEYPAD_c1_PORT     'D'
#define KEYPAD_c1_PIN        0

#define KEYPAD_c2_PORT     'D'
#define KEYPAD_c2_PIN        1
                                        
#define KEYPAD_c3_PORT     'D'
#define KEYPAD_c3_PIN        2
                                        
#define KEYPAD_c4_PORT     'D'
#define KEYPAD_c4_PIN        3


#define KEYPAD_ROWSMAXNUM   4 
#define KEYPAD_COLMAXNUM      4 

#define  KEYPAD_COLS_PORTS  (KEYPAD_c1_PORT,KEYPAD_c2_PORT,KEYPAD_c3_PORT,KEYPAD_c4_PORT)
#define  KEYPAD_COLS_PINS     (KEYPAD_c1_PIN,KEYPAD_c2_PIN,KEYPAD_c3_PIN,KEYPAD_c4_PIN)

#define KEYPAD_ROWS_PORTS  (KEYPAD_R1_PORT,KEYPAD_R2_PORT,KEYPAD_R3_PORT,KEYPAD_R4_PORT)
#define KEYPAD_ROWS_PINS     (KEYPAD_R1_PIN,KEYPAD_R2_PIN,KEYPAD_R3_PIN,KEYPAD_R4_PIN)

#define KEYPAD_KEYS  {(1,2,3,4),(5,6,7,8),(9,10,11,12),(13,14,15,16)}

#define KEYPAD_NOKEYPRESSED 0xff 

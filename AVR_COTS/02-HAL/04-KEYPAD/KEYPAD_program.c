#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_interface.h"
#include"KEYPAD_config.h"
#include"KEYPAD_interface.h"
#include"KEYPAD_private.h"

u8 KEYPAD_GetPressedKey(void)
{
  u8 pressedkey=KEYPAD_NOKEYPRESSED;
  u8 row;
  u8 col;
 static  u8 rowsPorts[KEYPAD_ROWSMAXNUM]=KEYPAD_ROWS_PORTS;
 static  u8 rowsPins [KEYPAD_ROWSMAXNUM]=KEYPAD_ROWS_PINS ;
 static  u8 colsPorts[KEYPAD_COLMAXNUM]=KEYPAD_COLS_PORTS;
 static  u8 colspins [KEYPAD_COLMAXNUM]=KEYPAD_COLS_PINS;
 static u8 KEYPAD_KEYSArray[KEYPAD_ROWSMAXNUM][KEYPAD_COLMAXNUM]=KEYPAD_KEYS;
 
 for (row =0 ; row<KEYPAD_ROWSMAXNUM ;row++)
  {
    /**put on each row 0**/
  SetPinValue(rowsPorts[row],rowsPins[row],0);
  /**Check on each col**/ 
    for (col =0 ; col<KEYPAD_COLMAXNUM ;col++)
  {
       while (!GetPinValue (colsPorts[col],colspins[col]))
       {
         pressedkey=KEYPAD_KEYSArray[row][col];
       }
      }
        SetPinValue(rowsPorts[row],rowsPins[row],1);
  }
  return pressedkey;
}

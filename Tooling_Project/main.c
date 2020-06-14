#include "MathGeek/MathGeek.h"
#include "FastPrinter/FastPrinter.h"
#include "ScanningEye/ScanningEye.h"
#include "AngrySpeaker/AngrySpeaker.h"
#include "TheOldWise/TheOldWise.h"
 
int main()
{
    int result=0;
    int input1=0;
    int input2=0;
    bool ValidatorSays=false;
    
    while(ValidatorSays == false)
    {
        ScanningEye_Scan(&input1);
        ValidatorSays = TheOldWise_Validate(input1);
        if (ValidatorSays==false)
        {
          AngrySpeaker_Say("Wrong",5);
        }
    }
	/* producing warnings 
		/* to test gcc warnings */
    ValidatorSays=false;
    while(ValidatorSays == false)
    {
        ScanningEye_Scan(&input2);
        ValidatorSays = TheOldWise_Validate(input2);
        if (ValidatorSays==false)
        {
          AngrySpeaker_Say("Wrong",5);
        }
    }
    result = MathGeek_Add(input1,input2);
    FastPrinter_Print(result);
    return 0;
}

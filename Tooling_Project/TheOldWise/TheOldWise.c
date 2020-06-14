#include "TheOldWise.h"
#include <stdio.h>
#include <stdlib.h>

bool TheOldWise_Validate(int input)
{
  bool returnVal;
  if(input<0 || input>99)
    returnVal=false;
  else
    returnVal=true;
  return returnVal;
}
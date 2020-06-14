#include "AngrySpeaker.h"
#include <stdio.h>
#include <stdlib.h>

void AngrySpeaker_Say(char* string,int length)
{
  int i;
  char* newString=(char*)calloc(length,sizeof(char));
  for(i=0;i<length;i++)
  {
    if(string[i]>='a' && string[i]<='z')
    {
      newString[i]=string[i]-'a'+'A';
    }
    else
    {
      newString[i]=string[i];
    }
  }
  printf("%s\n",newString);
}
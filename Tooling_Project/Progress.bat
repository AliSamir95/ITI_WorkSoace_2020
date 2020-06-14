@ECHO OFF

 if not exist progress.txt (ECHO 0 > progress.txt)

 set /p value=<progress.txt

 set /A "value=value+1"
  
 echo %value%  > progress.txt
  
 exit
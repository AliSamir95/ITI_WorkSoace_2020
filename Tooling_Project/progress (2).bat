@ECHO OFF


rem if the file doesn't exist make it and put a value of zero in it
if not exist progress.txt (echo 0 > progress.txt)


rem to read the value form another source you need to put /p
SET /p value=<progress.txt


rem to make an arthemitic operation: incerement the value by 1 
set /A "value=value+1"

rem put the value of the file afer being incremented
echo %value% > progress.txt

exit
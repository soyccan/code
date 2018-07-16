@echo off
g++ checkcycle.cpp -std=c++14 -o checkcycle
:loop
echo | set /p = "." rem print a dot
python rand.py > in.txt
checkcycle < in.txt
if errorlevel 1 goto loop

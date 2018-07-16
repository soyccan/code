@echo off
g++ c.cpp -std=c++14 -o c
g++ d.cpp -std=c++14 -o d
:loop
echo | set /p = "." rem print a dot
python rand.py > in.txt
c.exe < in.txt > c.txt
d.exe < in.txt > d.txt
fc c.txt d.txt > nul
if errorlevel 1 goto loop

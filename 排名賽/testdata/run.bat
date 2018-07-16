@echo off
del *.out
g++ ..\c.cpp -std=c++14 -o ..\c
for %%f in ("*.in") do (
	..\c < %%f > %%~nf.out
)
rem 31.out = 49289092
rem n <= 1e6
rem m <= 1e6

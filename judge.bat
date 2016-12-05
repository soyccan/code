@echo off
FOR /L %%i IN (1,1,510) DO (
	if exist "254\res\testdata\%%i.in" (
		echo %%i:
		a.exe < "254\res\testdata\%%i.in"
		type "254\res\testdata\%%i.out"
		echo.
	)
)

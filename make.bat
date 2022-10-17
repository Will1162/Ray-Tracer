@echo off

set showDebugCmd=1

cd build
del RayTracer-x64.exe

cls

echo Building...

if %showDebugCmd%==0 (
	g++ -std=c++17 -O2 ^
	../src/main.cpp ^
	-o RayTracer-x64.exe ^
	-mwindows
)

if %showDebugCmd%==1 (
	g++ -std=c++17 -O2 ^
	../src/main.cpp ^
	-o RayTracer-x64.exe ^
	-g -Wall
)

echo Done
echo.

if exist RayTracer-x64.exe (
	RayTracer-x64.exe
)

cd ../
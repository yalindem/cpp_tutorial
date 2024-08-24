@echo off
rm build
set "BUILD_TYPE=Debug"
if "%1"=="" (
    echo No build type specified, defaulting to Debug.
) else (
    set "BUILD_TYPE=%1"
)


mkdir build
cd build

cmake -DCMAKE_BUILD_TYPE=%BUILD_TYPE% ..
cmake --build . --config %BUILD_TYPE%

set "EXECUTABLE_PATH=%BUILD_TYPE%\main.exe"

if exist %EXECUTABLE_PATH% (
    echo Running the executable...
    echo -----------------------------------------
    
    %EXECUTABLE_PATH%
    pause  # This line ensures the window stays open
) else (
    echo Error: Executable not found!
)


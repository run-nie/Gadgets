@echo off
setlocal

:: 设置程序名
set EXE_NAME=main
set CPP_FILE=main.cpp
set ICO_FILE=icon.ico
set RC_FILE=myicon.rc
set RES_OBJ=myicon.o

:: 编译资源文件
if exist %RC_FILE% (
    echo 正在编译图标资源...
) else (
    echo IDI_ICON1 ICON "%ICO_FILE%" > %RC_FILE%
)

windres %RC_FILE% -o %RES_OBJ%
if errorlevel 1 (
    echo 资源编译失败！
    goto end
)

:: 编译 C++ 源代码并链接资源
echo 正在编译程序...
g++ -std=c++17 -Wall -O2 %CPP_FILE% %RES_OBJ% -o %EXE_NAME%.exe
if errorlevel 1 (
    echo 编译失败！
    goto end
)

echo 编译成功！运行程序...
echo ----------------------------------
%EXE_NAME%.exe

:end
pause

#!/bin/bash
echo "Building Project"
cmake --build build
if [ $? -ne 0 ]; then
    echo "Build Error"
    exit 1
fi
echo "Build OK.Starting System"
start build/Server.exe
sleep 1
start build/Client.exe
start build/Client.exe
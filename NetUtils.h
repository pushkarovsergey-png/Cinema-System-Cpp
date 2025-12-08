#pragma once
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")
class NetUtils{
    public:
    static void initialize(){
        WSADATA wsaData;
        
        int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
        if (result != 0){
            std::cerr << "WSAStartup failed: " << result << "\n";
            exit(1);
        }
    }
    static void cleanup() {
        WSACleanup();
    }
};

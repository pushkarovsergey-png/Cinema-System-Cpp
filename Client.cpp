#include "NetUtils.h"
#include <string>
#include <iostream>
#include <winsock2.h>

int main(){
    NetUtils::initialize();
    SOCKET clientSocket;
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in clientAddr;
    clientAddr.sin_port = htons(8080);
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    int connectResult = connect(clientSocket, (sockaddr*)&clientAddr, sizeof(clientAddr));
    if(connectResult != 0){
        std::cout << "Connection failed" << std::endl;
    }
    else{
        std::cout << "Connected" << std::endl;
    }
    char buffer[1024];
    while(true){
        std::cout << "\nEnter SHOW or BOOK and id or EXIT" << std::endl;
        std::string command;
        std::getline(std::cin, command);
        send(clientSocket, command.c_str(), command.length(), 0);
        if(command == "EXIT"){
            std::cout << "Finishing work..." << std::endl;
            break;
        }
        int bytes = recv(clientSocket, buffer, 1024, 0);
        if(bytes > 0){
            buffer[bytes] = '\0';
            std::cout << buffer;
        }
    }
    closesocket(clientSocket);
    NetUtils::cleanup();
    return 0;
}
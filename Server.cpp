#include "NetUtils.h"
#include "Cinema.h"
#include <thread>
#include <iostream>
#include <string>
#include <winsock2.h>

void clientHandler(SOCKET clientSocket, Cinema& cinema){
    char buffer[1024];
    while(true){
        int bytes = recv(clientSocket, buffer, 1024, 0);
        if (bytes <= 0){
            std::cout << "The client has disconnected (error or disconnection)." << std::endl;
            break;
        }
        buffer[bytes] = '\0';
        std::string answer = "";
        std::string command = buffer;
        if(command == "SHOW"){
            answer = cinema.getHallStatus();
        }
        else if(command.starts_with("BOOK")){
            try{
                command.erase(0, 4);
                int id = std::stoi(command);
                bool success = cinema.bookSeat(id);
                if(success){
                    answer += "You BootSeat: " + command;                
                }
                else{
                    answer += "Is this seat occupied";
                }
            }
                catch(...){
                    answer = "Error: Invalid format. Use 'BOOK <number>' (e.g., BOOK 5)";
                }                
        }
        else{
            answer = "Wrong command";
        }
        send(clientSocket, answer.c_str(), answer.length(), 0);
    }
    closesocket(clientSocket);
}

int main(){
    NetUtils::initialize();
    SOCKET serverSocket;
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 1);
    std::cout << "Server started. Waiting for conection..." << std::endl;
    Cinema cinema;
    std::cout << "Server started..." << std::endl;
    while(true){
        SOCKET terminalSocket = accept(serverSocket, nullptr, nullptr);
        if(terminalSocket == INVALID_SOCKET){
            int errorCode = WSAGetLastError();
            std::cerr << "Accept failed. Error code: " << errorCode << std::endl;
            continue; 
        }
        std::thread t(clientHandler, terminalSocket, std::ref(cinema));
        t.detach();
    }
    closesocket(serverSocket);
    NetUtils::cleanup();
    return 0;
    
}
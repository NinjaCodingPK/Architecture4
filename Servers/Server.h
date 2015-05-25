/* 
 * File:   Server.h
 * Author: lunelink
 *
 * Created on 10 мая 2015 г., 21:37
 */

//#ifndef SERVER_H
//#define	SERVER_H
#pragma once
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include <cstring>
#include <sstream>
#include "Morse.h"
#include "connection.h"
#include "Client.h"


class Server {
public:
    Server(){};
    Server(const Server& orig){};
    virtual ~Server(){};
  
    void run();
    int Send(int soc,std::string str,int flag = 0);
    int Recv(int soc,int flag=0);
    
    void Processing();
//private:
    
    
    
protected:
    std::string buffer;  //
    Morse morse;
      int sock;    // сокет 
    int listener; //очередь запросов
    struct sockaddr_in addr; // структура с адресом
    int CountConnect;
    int concl;
    unsigned int *client;
    
    
};

//#endif	/* SERVER_H */


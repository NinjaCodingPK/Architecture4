/* 
 * File:   Client.h
 * Author: lunelink
 *
 * Created on 11 мая 2015 г., 0:54
 */

#ifndef CLIENT_H
#define	CLIENT_H
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <fstream>
#include <sstream>
#include "Data.h"
#include <random>

class Client
{
public:
    Client(int SizeSend);
    int Send(int soc,std::string str,int flag = 0);
    int Recv(int soc,int flag=0);
    //Client(const Client& orig);
    //virtual ~Client();
    void run();
private:
    std::string message;    
    Data data;
    std::string symb;
    //std::string buffer;
};

#endif	/* CLIENT_H */


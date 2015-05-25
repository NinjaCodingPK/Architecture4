/* 
 * File:   connection.h
 * Author: lunelink
 *
 * Created on 17 мая 2015 г., 13:13
 */

#ifndef CONNECTION_H
#define	CONNECTION_H

#include "Morse.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#include <cstring>
#include <sstream>

#include "Client.h"
#include "Data.h"

#include <fstream>
#include <ostream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

class connection {
public:
    connection(unsigned int clientsc);
    connection(unsigned int clientsc,bool run);
    connection(const connection& orig);
    virtual ~connection();
    void run();
    
    
    int SSend(unsigned soc,std::string str,int flag = 0);
    int SRecv(unsigned soc,int flag = 0);
    

    
private:
    bool stop;
    std::string buffer;
    int clffile;
    Morse morse;
    
    

};

#endif	/* CONNECTION_H */


/* 
 * File:   Server_Pthread.h
 * Author: lunelink
 *
 * Created on 20 мая 2015 г., 22:08
 */

#ifndef SERVER_PTHREAD_H
#define	SERVER_PTHREAD_H

#include "Server.h"
#include "connection.h"
#include <pthread.h>


class Server_Pthread :public Server 
{
public:
    void Processing();
    void thread_c(unsigned int cl);
   /* Server_Pthread();
    Server_Pthread(const Server_Pthread& orig);
    virtual ~Server_Pthread();*/
private:

};

#endif	/* SERVER_PTHREAD_H */


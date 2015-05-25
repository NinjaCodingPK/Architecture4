/* 
 * File:   Server_Pthread.cpp
 * Author: lunelink
 * 
 * Created on 20 мая 2015 г., 22:08
 */

#include "Server_Pthread.h"

void Server_Pthread::Processing() 
{
    while(1)
    {
        // сервер готов обслужить запрос
        client[concl] = accept(listener,NULL,NULL);
        
        if(client[concl] < 0)
        {
            perror("accept");
            exit(3);
        }

        //pthread_t thread;
        //pthread_create(&thread , NULL , , "test");
            std::cout<<"Connect "<<concl+1<<" Client"<<std::endl;
            new connection(client[concl]);
            concl--;
        
        concl++;
            
        close(sock);   
    }
}
void *Thre(void * threadid)
{
    connection con(reinterpret_cast<unsigned long>(const_cast<void*>( threadid)));
    con.run();
}


void Server_Pthread::thread_c(unsigned int cl)
{ 
    pthread_t thread;
    int id = cl;
    pthread_create(&thread , NULL , &Thre , &cl);
}



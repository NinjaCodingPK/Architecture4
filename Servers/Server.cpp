/* 
 * File:   Server.cpp
 * Author: lunelink
 * 
 * Created on 10 мая 2015 г., 21:37
 */

#include "Server.h"
//#include "connection.h"

void Server::run()
{
    this->CountConnect = 10;
    this->concl = 0;
    this->client = new unsigned int[CountConnect];
    /*int sock;    // сокет 
    int listener; //очередь запросов
    struct sockaddr_in addr; // структура с адресом
    int CountConnect = 10;
    static int concl=0;*/
 
    listener = socket(AF_INET, SOCK_STREAM, 0);
    // (интеренет доменб,поток для надежной передачи данных, не используем)
    if(listener < 0)
    {
        perror("socket");
        exit(1);
    }
    
    // заполнение структуры
    addr.sin_family = AF_INET;
    addr.sin_port = htons(3425);
    addr.sin_addr.s_addr = INADDR_ANY;//htonl(INADDR_ANY);

    // связывание сокета с адресом
    if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind");
        exit(2);
    }
 
    listen(listener,CountConnect); //создание очереди запросов на соединение
  
    std::cout<<"Running"<<std::endl;
    
    Processing();
}

void Server::Processing()
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
        pid_t pid = fork();
        
        if (pid == 0)
        {
            
            std::cout<<"Connect "<<concl+1<<" Client"<<std::endl;
            new connection(client[concl],true);
            concl--;
        }
        
        concl++;
            
        close(sock);   
    }
}


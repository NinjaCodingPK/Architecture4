/* 
 * File:   Client.cpp
 * Author: lunelink
 * 
 * Created on 11 мая 2015 г., 0:54
 */

#include "Client.h"

Client::Client(int SizeSend) 
{
    for (int i = 97; i < 122; i++)
        symb += char(i);
    symb +=' ';
    
    for (int i = 0; i < SizeSend; i++)
        //message += symb[rand()%symb.size()-1];
        message += symb[rand()%(symb.size()-1)];
}

/*Client::Client(const Client& orig) {
}

Client::~Client() {
}*/
void Client::run()
{
    
    //char buf[1024];
    
    
    int sock;
    struct sockaddr_in addr;
 
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("socket");
        exit(1);
    }
 
    addr.sin_family = AF_INET;
    addr.sin_port = htons(3425); // или любой другой порт...
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);//gethostname("178.159.231.195",sizeof("178.159.231.195"));//inet_addr("127.0.0.1");//inet_addr("178.159.231.195");
    //inet_aton("195.161.42.222",&addr.sin_addr);//

    if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("connect");
        exit(2);
    }
    //std::cout<<std::endl;
    //std::cin.ignore();
   // while (true)
    //{
       //// std::cout<<"Enter your String"<<std::endl;
        //char ch;
        
        //std::getline ( std::cin, message);
        //getc(stdin);
        //system("pause");
        //std::cin.get();
        //message = "stop";
        std::cout<<message<<std::endl;
        Send(sock, message);
        //if (message == "/stop")
        //    return;
        //send(sock, message, sizeof(message), 0);
        //recv(sock, buf, 1023, 0);
        Recv(sock);
    
        std::cout<<data.Get_date()<<std::endl;
        data.clear();
        message = "/stop";
        Send(sock, message);
       // Recv(sock);
        //buffer.erase(0,buffer.size());
   // }
    close(sock);
 
}

int Client::Send(int soc,std::string str,int flag)
{
    
    std::ostringstream oss;
    oss << str.size()+1;
    std::string  strforsend;
    strforsend += oss.str();
    strforsend += ';';
    strforsend += str;
   
    int  n = send(soc,strforsend.c_str(),strforsend.size()+1,flag);
    return n; 
}
/*int Server::Send(int soc,std::string str,int flag)
{
    
    std::ostringstream oss;
    oss << str.size()+1;
    std::string  strforsend;
    strforsend += oss.str();
    strforsend += ';';
    strforsend += str;
   
    int  n = send(soc,strforsend.c_str(),strforsend.size()+1,flag);
    return n; 
}*/


int Client::Recv(int soc,int flag)
{
    char ch;
    std::string str;
    while (true)
    {
        recv(soc,&ch,1,flag);
        if (ch == ';')
            break;
        str+=ch;
    }
    
    int siz = atoi( str.c_str());
    
    char *buff2 = new char [siz];
    
    recv(soc,buff2,siz,flag);
    str.clear();
    str.append(buff2);
    
    data.Set_date(str);
    
    
    /*std::ifstream rifs("ifs.txt");
    
    boost::archive::text_iarchive ia(rifs);
    
    ia >> data;*/
    
   /* std::fstream ifs("filename.txt");
    ifs<<buffer;
    ifs.close;
        boost::archive::text_iarchive ia(ifs);
        // read class state from archive
        ia >> *this;*/
    
    return 0;//buffer.size();
}
        



 


/* 
 * File:   connection.cpp
 * Author: lunelink
 * 
 * Created on 17 мая 20105 г., 13:13
 */

#include "connection.h"

connection::connection(unsigned int clientsc) 
{
    clffile = clientsc;
    stop = false;
}
connection::connection(unsigned int clientsc, bool run) 
{
    clffile = clientsc;
    stop = false;
    this->run();
}

void connection::run()
{
    while (true)
    {
        SRecv(clffile);
        if (stop == true) return;
        if (buffer.size() !=0)
            SSend(clffile,morse.Code(buffer));
    }
}

connection::connection(const connection& orig) {
}

connection::~connection() {
}

 

int connection::SSend(unsigned int soc,std::string str,int flag)
{

    Data d;
    d.Set_date(str);
    
    std::ostringstream oss;
    oss <<clffile;
    
    std::string filename ("f");
    filename.append(oss.str());
    filename.append(".txt");
    
    std::ofstream fser(filename);
    {
        boost::archive::text_oarchive oa(fser);
        oa << d;
        fser.close();
    }
    
           
    std::ostringstream oss1;
    //oss1.clear();
    oss1 << str.size()+1;
    std::string  strforsend;
    strforsend += oss1.str();
    strforsend += ';';
    strforsend += str;
   
    int  n = send(soc,strforsend.c_str(),strforsend.size()+1,flag);
    fser.close();
    return n; 
}

int connection::SRecv(unsigned int soc,int flag)
{
    buffer.clear();
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
    if (siz == 1) return 0;
    
    char *buff2 = new char [siz];
    
    recv(soc,buff2,siz,flag);
    buffer.append(buff2);
    
    if (buffer == "/stop")
    {
        this->stop = true;
        return 0;
    }
    
    return buffer.size();
}
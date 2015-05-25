/* 
 * File:   main.cpp
 * Author: lunelink
 *
 * Created on 10 мая 2015 г., 11:28
 */

#include <cstdlib>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <sstream>
#include "Server.h"
#include "Client.h"
#include "Server_Pthread.h"
#include "AServer.h"

#include <boost/thread.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
using namespace boost::asio;
using namespace boost::posix_time;
using boost::system::error_code;


ip::tcp::acceptor acceptor(service, ip::tcp::endpoint(ip::tcp::v4(), 8001));

void handle_accept(talk_to_client::ptr client, const boost::system::error_code & err) 
{
    client->start();
    talk_to_client::ptr new_client = talk_to_client::new_();
    acceptor.async_accept(new_client->sock(), boost::bind(handle_accept,new_client,_1));
}

void Serv()
{
    talk_to_client::ptr client = talk_to_client::new_();
    acceptor.async_accept(client->sock(), boost::bind(handle_accept,client,_1));
    service.run();
}

int main(int argc, char** argv) 
{  
    if (argv[1][0] == '0')
    {
        Server ser;
        ser.run();
    }
    else
      if (argv[1][0] == '1')
      {
        Server_Pthread ser;
        ser.run();
      }
      else
        Serv();
    return 0;
}


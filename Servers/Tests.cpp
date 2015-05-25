//#define BOOST_TEST_DYN_LINK
//#define BOOST_TEST_MAIN
//#define BOOST_TEST_MODULE wat
//#include <boost/test/included/unit_test.hpp>
//#include "Morse.h"
//#include "Client.h"
//#include "Server.h"
// 
//BOOST_AUTO_TEST_CASE(MorseTest)
//{
//    Morse *morse = new Morse();
//    std::string temp = "a";
//    BOOST_CHECK(morse->Code(temp) == ".-");
//}

//BOOST_AUTO_TEST_CASE(ClientSendTest)
//{
//    Server ser;
//    ser.run();
//    Client *tempClient = new Client(2);
//    int temp_sock = socket(AF_INET, SOCK_STREAM, 0);
//    BOOST_CHECK(tempClient->Send(temp_sock, "aa") == 2);
//}

//BOOST_AUTO_TEST_CASE(ClientRecvTest)
//{
//    int temp_sock = socket(AF_INET, SOCK_STREAM, 0);
//    Client *tempClient = new Client(2);
//    BOOST_CHECK(tempClient->Recv(temp_sock) == 0);   
//}
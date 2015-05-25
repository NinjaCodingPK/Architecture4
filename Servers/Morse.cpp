/* 
 * File:   Morse.cpp
 * Author: lunelink
 * 
 * Created on 11 мая 2015 г., 15:38
 */

#include "Morse.h"

Morse::Morse() {
}

Morse::Morse(const Morse& orig) {
}

Morse::~Morse() {
}

/*char* Morse::Code(char *str char &ch)
{
    /*std::string str = new std::string(str);
    str = Code(str);
    
    char * retstr = new char [str.size()+1];
    retstr [0]=0;
    strcat(retstr,str.c_str());
    return retstr;
}*/

std::string Morse::Code(std::string str)
{
 
std::map <char, std::string> morze = {
    	{ 'a', ".-"},
    	{ 'b', "-..."},
    	{ 'w', ".--"},
    	{ 'g', "--."},
    	{ 'd', "-.."},
    	{ 'e', "."},
    	{ 'v', "...-"},
    	{ 'z', "--.."},
    	{ 'i', ".."},
    	{ 'j', ".---"},
    	{ 'k', "-.-"},
    	{ 'l', ".-.."},
    	{ 'm', "--"},
    	{ 'n', "-."},
    	{ 'o', "---"},
    	{ 'p', ".--."},
    	{ 'r', ".-."},
    	{ 's', "..."},
    	{ 't', "-"},
    	{ 'u', "..-"},
    	{ 'f', "..-."},
    	{ 'h', "...."},
    	{ 'c', "-.-."},
    	{ 'q', "--.-"},
    	{ 'y', "-.--"},
    	{ 'x', "-..-"},
    	{ '1', ".----"},
    	{ '2', "..---"},
    	{ '3', "...--"},
    	{ '4', "....-"},
    	{ '5', "....."},
    	{ '6', "-...."},
    	{ '7', "--..."},
    	{ '8', "---.."},
    	{ '9', "----."},
    	{ '0', "-----"},
        { ' ', "-...-"}};
    	/*{ '.', "......"},
    	{ ',', ".-.-.-"},
    	{ ':', "---..."},
    	{ ';', "-.-.-."},
    	{ '(', "-.--.-"},
    	{ ')', "-.--.-"},
    	{ '"', ".-..-."},
    	{ '-', "-....-"},
    	{ '/', "-..-."},
    	{ '?', "..--.."},
    	{ '!', "--..--"},    	
    	{ '@', ".--.-."}};*/

        std::string StrForRet;
    
        for (int i = 0; i < str.size(); i++)
        {
            StrForRet.append(morze[str[i]]);
            StrForRet.append(" ");
        }
        StrForRet.erase(StrForRet.size()-1);
        return StrForRet;
}

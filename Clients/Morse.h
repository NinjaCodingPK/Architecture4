/* 
 * File:   Morse.h
 * Author: lunelink
 *
 * Created on 11 мая 2015 г., 15:38
 */

#ifndef MORSE_H
#define	MORSE_H
#include <vector>
#include <map>
#include <iostream>
#include <cstring>
#include <string>

class Morse {
public:
    Morse();
    Morse(const Morse& orig);
    virtual ~Morse();
    std::string Code(std::string str);
    char*       Code(char *str);
private:

};

#endif	/* MORSE_H */


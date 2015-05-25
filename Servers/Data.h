/* 
 * File:   Data.h
 * Author: lunelink
 *
 * Created on 20 мая 2015 г., 16:45
 */

#ifndef DATA_H
#define	DATA_H

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
    
class Data {
public:
    Data();
    Data(const Data& orig);
    virtual ~Data();
    
    std::string Get_date()
    {
        return this->date;
    }
    void Set_date(std::string str)
    {
        date = str;
    }
    void clear()
    {
        this->date.clear();
    }
    
private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & date;
    }
    
    std::string date;

};

#endif	/* DATA_H */


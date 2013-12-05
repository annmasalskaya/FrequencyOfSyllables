#ifndef ASSOTIATIVEARRAY_H
#define ASSOTIATIVEARRAY_H
#include <map>
#include <string>
#include <vector>
#include <exception>
#include "smartPtr.h"

class MapIsEmpty: public std::exception
{
    const char *what() const throw()
    {
        return "You want to print nonexistent map ";
    }
};

class MapContainer
{
public:

    MapContainer();
   // ~MapContainer();
    void addElement(std::string,int);
    bool find(std::string);
    void print();
    void oftenSeldomOccur();
    ;

private:
    std::map <std::string,int>  *syllables;
};

#endif

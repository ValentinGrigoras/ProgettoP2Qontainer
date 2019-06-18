#ifndef NOFILEEXCEPTION_H
#define NOFILEEXCEPTION_H
#include<iostream>

class OpenFileException
{
    std::string what;
public:
    OpenFileException(std::string );


    std::string getWhat() const;
    void printError()const;
};

#endif // NOFILEEXCEPTION_H

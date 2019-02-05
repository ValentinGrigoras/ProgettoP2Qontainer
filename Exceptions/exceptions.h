#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include<iostream>

using namespace std;
class Exceptions
{
private:

    string type_error;


public:
    Exceptions(string t = "Errore sconosciuto");
    void printError() const;
};





#endif // EXCEPTIONS_H

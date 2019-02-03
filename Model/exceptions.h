#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include<string>
using std::string;

class Exceptions
{
private:

    string type_error;


public:
    Exceptions(string = "Errore sconosciuto");
    void printError() const;
};

class PastTheEnd : public Exceptions{
public:
    PastTheEnd():Exceptions("Errore sul Past The End"){};

};

class InvalidIterator : public Exceptions{
public:
    InvalidIterator(): Exceptions("Iteratore non valido"){};
};

#endif // EXCEPTIONS_H

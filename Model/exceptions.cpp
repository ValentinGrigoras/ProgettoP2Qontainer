#include "exceptions.h"
#include<iostream>
using std::iostream;

Exceptions::Exceptions(string t)
{

}

void Exceptions::printError() const
{
     std::cout << type_error << std::endl;
}

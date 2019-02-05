#include "exceptions.h"


Exceptions::Exceptions(string t):type_error(t){}

void Exceptions::printError() const
{
     cout << type_error << std::endl;
}


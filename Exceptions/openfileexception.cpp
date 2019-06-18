#include "OpenFileException.h"

std::string OpenFileException::getWhat() const
{
    return what;
}

void OpenFileException::printError() const
{
    std::cout<<"errore e': "<<getWhat();
}

OpenFileException::OpenFileException(std::string w):
    what(w){}

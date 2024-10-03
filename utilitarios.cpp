#include "utilitarios.hpp"

string toLowerCase(string palavra)
{
    string palavraLower;
    for(char letra: palavra){
        palavraLower += tolower(letra);
    }
    return palavraLower;
}

string toUpperCase(string palavra)
{
    string palavraUpper;
    for(char letra: palavra){
        palavraUpper += toupper(letra);
    }
    return palavraUpper;
}

#ifndef Classe_HEADER
#define Classe_HEADER

#include <ostream>
#include <string>
#include <list>

#pragma once
using namespace std;

namespace Classes
{
    class Cesar
    {
    public:
        Cesar();
        string crypter(string messageParametre);
        string decrypter(string messageParametre);

    private:
        string messageDecrypte, messageEncrypte, alphabet;
        int cle;
    };

    class cryptageXOR
    {
    public:
	    char XOR(char caractere, char cle);
    };
}

#pragma once
namespace programme
{
    class prosit
    {
    public :
        void run();
    private :
        Classes::Cesar* _Cesar;
        Classes::cryptageXOR* _cryptageXOR;
    };
}

#endif 

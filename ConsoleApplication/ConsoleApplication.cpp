#include <iostream>
#include <fstream>
#include "Interface.h"


int main()
{
    const char* wstep = "Baza Pojazdow\nPolecenia:\ndodaj\nusun\ndrukuj\nwyczysc\nzapisz\nwczytaj\nzamknij\n";
    cout << wstep;
    Interface i;
    while (i.get_stan())
    {
        cout << "Polecenie:" << '\n';
        i.polecenie();
    }

    return 0;
};
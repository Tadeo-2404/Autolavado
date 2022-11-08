#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
using namespace std;
#include <string>
#include "time.h"

string generarID()
{
    srand(time(NULL));
    const int size = 36;
    int length = 1 + rand() % 10;
    char characters[size] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z', '0', '1', 
                          '2', '3', '4', '5', '6', '7', '8', 
                          '9'};
    string result = "";
    for (int i = 0; i < length; i++)
        result = result + characters[rand() % size];

    return result;
};
 
bool ClienteExiste(string ID)
{
    bool flag = false;
    cout << ID;
    return flag;
}

bool AutoExiste(string ID)
{
    bool flag = false;
    cout << ID;
    return flag;
}

bool ServicioExiste(string ID)
{
    bool flag = false;
    cout << ID;
    return flag;
}

bool TicketExiste(string ID)
{
    bool flag = false;
    cout << ID;
    return flag;
}

bool FacturaExiste(string ID)
{
    bool flag = false;
    cout << ID;
    return flag;
}

bool PromocionExiste(string ID)
{
    bool flag = false;
    cout << ID;
    return flag;
}

bool EmpleadoExiste(string ID)
{
    bool flag = false;
    cout << ID;
    return flag;
}

#endif
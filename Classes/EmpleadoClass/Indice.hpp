#ifndef INDICE_HPP
#define INDICE_HPP
#include <string>
using namespace std;

class Indice
{
private:
    long int pos;
    string ID;
public:
    Indice();
    Indice(long int pos, string ID);
    ~Indice();
    long int getPos();
    string getID();
    void setPos(long int pos);
    void setID(string id);
};

#endif
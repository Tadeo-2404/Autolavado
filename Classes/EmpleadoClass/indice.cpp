#include <iostream>
#include "Indice.hpp"
using namespace std;

Indice::Indice() 
{

}

Indice::Indice(long int pos, string ID) 
{
    this->pos = pos;
    this->ID = ID;
}

Indice::~Indice()
{
    
}

long int Indice::getPos()
{
    return this->pos;
}

string Indice::getID() 
{
    return this->ID;
}

void Indice::setPos(long int pos)
{
    this->pos = pos;
}

void Indice::setID(string id) 
{
    this->ID = id;
}

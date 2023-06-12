#ifndef CARANGAJAT_H
#define CARANGAJAT_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "CarClient.h"
class CarAngajat : public CarClient
{
private:
    string Cod;

public:
    CarAngajat(const string& plate, const string& entry, const string& code,bool angajat) : CarClient(plate,angajat), Cod(code) {}


    bool authenticate(const string& authFile, const string& numarInmatriculare, const string& Cod);

    string getCod() const;

};

#endif // CARANGAJAT_H

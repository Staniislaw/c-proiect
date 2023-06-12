#ifndef PARCARE_H
#define PARCARE_H
#include <iostream>
using namespace std;
#include <ctime>
#include <fstream>
#include <vector>
#include <algorithm>
#include "CarClient.h"
#include "CarAngajat.h"
#include "BiletParcare.h"
class Parcare
{
private:
    int ParkingSpace;
    double tarif;
    vector<CarClient*> clienti;
    vector<CarAngajat*> angajati;
    bool stergeInformatiiDinFisier(const std::string& inmatriculare);
public:
    Parcare(int ParkingSpace, double tarif) :ParkingSpace(ParkingSpace), tarif(tarif) {}
    void AddCarClient(CarClient* client);
    void AddCarAngajat(CarAngajat* angajat);
    void RemoveCar(const std::string& plate);
    bool verificaPlataLaIesire(double sumaIntrodusa, double plata, double& rest, CarClient& car);
};

#endif // PARCARE_H

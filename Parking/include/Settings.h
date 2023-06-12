#ifndef SETTINGS_H
#define SETTINGS_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Settings {
public:
    static int ParkingSpace;
    static const double pret_pe_ora;
    static void UpdateParkingSpace(int numarMasini)
    {
        ParkingSpace -= numarMasini;
    }

};
#endif // SETTINGS_H

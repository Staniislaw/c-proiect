#ifndef CARCLIENT_H
#define CARCLIENT_H
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;
class CarClient
{
private:
    std::string getCurrentTimeFormatted(const std::string& format);
protected:
    string numarInmatriculare;
    string oraIntrarii;
    bool isAngajat;
    double ultimaPlata=0;
public:
    CarClient(const string& ID,bool angajat);
    string getNrDeInmatriculare() const;
    string getOraIntrare() const;
    void setOraIntrare(const string& ora);
    bool getIsAngajat() const;
    void setUltimaPlata(double plata);
    double getUltimaPlata();
};

#endif // CARCLIENT_H

#ifndef BILETPARCARE_H
#define BILETPARCARE_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class BiletParcare
{
private:
    string codUnic;
    string oraIntrarii;


public:
    BiletParcare();
    BiletParcare(const string& cod,const  string& ora):codUnic(cod),oraIntrarii(ora) {}
    string getCodUnic() const;
    string getOraIntrare() const;
    void setCodUnic(const string& cod);
    void setOraIntrare(const string& ora);
    void salvareFisier(const string& filename,const char& isAngajat) const;
    void GenerateParkingTicket() const;

};

#endif // BILETPARCARE_H

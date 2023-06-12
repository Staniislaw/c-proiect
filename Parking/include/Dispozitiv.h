#ifndef DISPOZITIV_H
#define DISPOZITIV_H
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <stdexcept>
#include <algorithm>

using namespace std;
#include "Settings.h"

class Dispozitiv
{
private:
    double calculateDuration(const std::string& entryTime) const;
    double calcul_plata(double durata_sedere) const;
public:
    std::string readFromFile(const std::string& id);
    std::string readTimeFromFile(const std::string& id);
    double calculatePayment(const std::string& id);

};


#endif // DISPOZITIV_H

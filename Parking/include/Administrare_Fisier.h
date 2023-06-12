#ifndef ADMINISTRARE_FISIER_H
#define ADMINISTRARE_FISIER_H
#include "CarAngajat.h"
#include "CarClient.h"

class Administrare_Fisier
{
public:
    CarClient* readFromFile(const std::string& numarInmatriculare);

    void afisareMasiniDinFisier(const std::string& numeFisier);
    int numarMasiniInFisier(const std::string& numeFisier);
};

#endif // ADMINISTRARE_FISIER_H

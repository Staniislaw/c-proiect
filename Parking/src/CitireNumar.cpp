#include "CitireNumar.h"
string CitireNumar::convertesteLaMajuscule(const string& numarInmatriculare)
    {
        string numarMajuscule = numarInmatriculare;
        for (auto& c : numarMajuscule)
        {
            c = std::toupper(c);
        }
        return numarMajuscule;
    }
string CitireNumar::citesteNumarInmatriculare()
    {
        string numarInmatriculare;
        cout << "Introduceti numarul de inmatriculare: ";
        cin >> numarInmatriculare;
        string nrInmatriculareMajuscule = convertesteLaMajuscule(numarInmatriculare);
        return nrInmatriculareMajuscule;
    }

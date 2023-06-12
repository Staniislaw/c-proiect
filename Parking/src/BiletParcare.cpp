#include "BiletParcare.h"

 string BiletParcare::getCodUnic() const
    {
        return codUnic;
    }
    string BiletParcare::getOraIntrare() const
    {
        return oraIntrarii;
    }
    void BiletParcare::setCodUnic(const string& cod)
    {
        codUnic = cod;
    }
    void BiletParcare::setOraIntrare(const string& ora)
    {
        oraIntrarii = ora;
    }
    void BiletParcare::salvareFisier(const string& filename,const char& isAngajat) const
    {
        ofstream file(filename, std::ios_base::app);
        if (file.is_open())
        {
            file<< codUnic <<" "<<oraIntrarii<<" "<<isAngajat<<"\n";
            file.close();
            cout << "Biletul a fost adaugat in fisierul " << filename << endl;
        }
        else
        {
            cout << "Nu s-a putut deschide fisierul pentru adaugare!" << endl;
        }
    }
    void BiletParcare::GenerateParkingTicket() const
    {
        cout<<endl;
        cout << "Bilet de parcare\n";
        cout << "Numarul de Inmatriculare: " << getCodUnic() << endl;
        cout << "Ora emiterii: " << getOraIntrare() << endl;
        cout<<endl;
    }

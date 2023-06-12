#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;
#include "BiletParcare.h"
#include "Dispozitiv.h"
#include "Settings.h"
#include "CarClient.h"
#include "CarAngajat.h"
#include "Parcare.h"
#include "Administrare_Fisier.h"
#include "CitireNumar.h"
const double Settings::pret_pe_ora=5.0;
int Settings::ParkingSpace=100;
std::string toupperString(const std::string& str)
{
    std::string result;
    for (char c : str)
    {
        result += std::toupper(c);
    }
    return result;
}

int main()
{
    CitireNumar numarInmatriculare;
    Administrare_Fisier admin;
    int numarMasini = admin.numarMasiniInFisier("bilet.txt");
    Settings::UpdateParkingSpace(numarMasini);
    Parcare parcare(Settings::ParkingSpace, Settings::pret_pe_ora);
    string ID,nrInmatriculare;
    string cod;
    while (true)
    {
        int choice;
        std::cout << "\n----- Meniu -----\n";
        std::cout << "1. Citire detalii masina\n";
        std::cout << "2. Adaugare masina in parcare\n";
        std::cout << "3. Stergere masina din parcare\n";
        std::cout << "4. Afisare masini din parcare\n";
        std::cout << "5. Iesire\n";
        std::cout << "Introduceti optiunea: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            nrInmatriculare = numarInmatriculare.citesteNumarInmatriculare();
            cout << "Numarul de inmatriculare introdus: " << nrInmatriculare << std::endl;
            break;
        }
        case 2:

            std::cout << "Esti angajat? (y/n): ";
            char str;
            std::cin >> str;
            if (str == 'y' || str == 'Y')
            {
                cout << "Introduceti Codul unic:";
                cin >> cod;

                bool codCorect = false;
                CarAngajat angajat(nrInmatriculare, "", cod, true);

                for (int contor = 1; contor <= 3; contor++)
                {
                    if (angajat.authenticate("angajat.txt", nrInmatriculare, cod))
                    {
                        codCorect = true;
                        break;
                    }
                    else
                    {
                        cout << "Codul introdus este gresit. Mai aveti " << 3 - contor << " incercari." << endl;
                        cout << "Introduceti codul din nou:";
                        cin >> cod;
                    }
                }

                if (codCorect)
                {
                    parcare.AddCarAngajat(&angajat);
                }
                else
                {
                    CarClient client(nrInmatriculare, false);
                    parcare.AddCarClient(&client);
                }
            }
            else if (str == 'n' || str == 'N')
            {
                CarClient client(nrInmatriculare,false);
                parcare.AddCarClient(&client);
            }
            else
            {
                cout << " Masina nu a fost adaugat în parcare.\n";
            }
            break;
        case 3:
        {
            ID = numarInmatriculare.citesteNumarInmatriculare();
            cout << "Numarul de inmatriculare introdus: " << ID << std::endl;
            Dispozitiv dispozitiv;
            CarClient* carToRemove = admin.readFromFile(ID);
            if(carToRemove==nullptr)
            {
                cout<<"Numarul de inmatriculare nu sa gasit";
                continue;
            }
            cout<<"Suma catre achitare este de: "<<dispozitiv.calculatePayment(toupperString(ID));
            if(dispozitiv.calculatePayment(toupperString(ID))==0)
            {
                parcare.RemoveCar(ID);
                cout<<endl<<"Masina extrasa cu succes"<<endl;
            }
            else
            {
                double plata = dispozitiv.calculatePayment(toupperString(ID));
                double plataAcutala = plata - carToRemove->getUltimaPlata();
                cout << endl << "Plata pentru achitare este: " << plataAcutala << " LEI." << endl;
                double sumaIntrodusa = 0.0;
                double rest = plataAcutala;
                while (sumaIntrodusa < plataAcutala)
                {
                    cout << "\nIntroduceti bancnotele: ";
                    double bancnote;
                    cin >> bancnote;

                    sumaIntrodusa += bancnote;
                    rest = plataAcutala - sumaIntrodusa;
                    if (sumaIntrodusa >= plataAcutala)
                    {
                        cout << "Plata este suficienta. Rest de returnat: " << fabs(rest) << " lei.\n";
                        //utilizam fabs pentru a calcula valoarea absolută
                        parcare.RemoveCar(ID);
                        break;
                    }
                    else
                    {
                        cout << "Plata insuficienta. Mai trebuie sa introduceti: " << fabs(rest) << " lei.\n";
                    }
                }
            }
            break;
        }
        case 4:
            admin.afisareMasiniDinFisier("bilet.txt");
            break;
        case 5:

            return 0;
        default:
            std::cout << "Optiune invalida. Va rugam sa introduceti o optiune valida.\n";
            break;
        }
    }
    return 0;
}

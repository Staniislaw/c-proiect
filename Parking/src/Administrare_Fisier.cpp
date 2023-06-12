#include "Administrare_Fisier.h"
  CarClient* Administrare_Fisier::readFromFile(const std::string& numarInmatriculare)
    {
        std::ifstream file("bilet.txt");
        std::string line;
        std::string filePlate;
        std::string oraEmiterii;
        std::string isAngajat;

        while (std::getline(file, line))
        {
            std::istringstream iss(line);
            iss >> filePlate >> oraEmiterii >> isAngajat;

            if (filePlate == numarInmatriculare)
            {
                file.close();
                char lastChar = isAngajat.back();  // Obține ultima literă din stringul isAngajat

                if (lastChar == 'Y')
                {
                    return new CarAngajat(filePlate, "", "", true);
                }
                else
                {
                    return new CarClient(filePlate, false);
                }
            }
        }
        file.close();

        return nullptr;
    }

    void Administrare_Fisier::afisareMasiniDinFisier(const std::string& numeFisier)
    {
        std::ifstream fisier(numeFisier);
        if (!fisier.is_open())
        {
            std::cout << "Nu s-a putut deschide fisierul " << numeFisier << std::endl;
            return;
        }

        std::string line;
        int numarMasiniAfisate = 0;
        while (std::getline(fisier, line) && numarMasiniAfisate < 15)
        {
            std::istringstream iss(line);
            std::string numarInmatriculare;
            std::string oraIntrarii;
            std::string isAngajat;

            if (iss >> numarInmatriculare >> oraIntrarii >> isAngajat)
            {
                std::cout << "Numar inmatriculare: " << numarInmatriculare << std::endl;
                std::cout << "Ora intrarii: " << oraIntrarii << std::endl;
                std::cout << "Is angajat: " << isAngajat << std::endl;
                std::cout << std::endl;

                numarMasiniAfisate++;
            }
        }

        fisier.close();
    }
    int Administrare_Fisier::numarMasiniInFisier(const std::string& numeFisier)
    {
        std::ifstream fisier(numeFisier);
        if (!fisier.is_open())
        {
            std::cout << "Nu s-a putut deschide fisierul " << numeFisier << std::endl;
            return 0;
        }

        std::string line;
        int numarMasini = 0;
        while (std::getline(fisier, line))
        {
            numarMasini++;
        }

        fisier.close();
        return numarMasini;
    }

#include "Parcare.h"

bool Parcare::stergeInformatiiDinFisier(const std::string& inmatriculare)
{
    std::ifstream inputFile("bilet.txt");
    std::ofstream tempFile("temp.txt");

    if (!inputFile || !tempFile)
    {
        std::cerr << "Eroare la deschiderea fisierelor." << std::endl;
        return false;
    }

    std::string line;
    bool gasit = false;

    while (std::getline(inputFile, line))
    {
        // Verificați dacă linia începe cu numărul de înmatriculare
        if (line.substr(0, inmatriculare.length()) != inmatriculare)
        {
            tempFile << line << std::endl;
        }
        else
        {
            gasit = true;
        }
    }

    inputFile.close();
    tempFile.close();

    if (gasit)
    {
        std::remove("bilet.txt");               // Ștergeți fișierul original
        std::rename("temp.txt", "bilet.txt");   // Redenumiți fișierul temporar
        std::cout <<endl<< "Linia a fost stearsa cu succes." << std::endl;
        return true;
    }
    else
    {
        std::cout << "Numarul de inmatriculare nu a fost gasit in fisier." << std::endl;
        std::remove("temp.txt"); // Ștergeți fișierul temporar dacă nu s-a găsit linia
        return false;
    }
}
void Parcare::AddCarClient(CarClient* client)
{
    if (client != nullptr)
    {
        if (ParkingSpace > 0)
        {
            cout<<"Parking Space"<<ParkingSpace;
            time_t currentTime = std::time(nullptr);
            tm localTime;
            localtime_s(&localTime, &currentTime);
            char buffer[9]; // Buffer pentru a stoca ora în formatul "HH:MM:SS"
            strftime(buffer, sizeof(buffer), "%H:%M", &localTime);
            std::string oraCurenta = buffer;
            // Actualizați ora de intrare a mașinii
            CarClient carWithTime(client->getNrDeInmatriculare(),client->getIsAngajat());
            carWithTime.setOraIntrare(oraCurenta); // Actualizați ora de intrare a mașinii noi cu ora curentă
            // Cars.push_back(carWithTime);

            clienti.push_back(client);
            cout << "Masina adaugata cu succes!" << endl;

            ParkingSpace--;
            // Generați automat biletul de parcare
            BiletParcare bilet(client->getNrDeInmatriculare(), client->getOraIntrare());
            bilet.GenerateParkingTicket();
            bilet.salvareFisier("bilet.txt",'N');
        }
        else
        {
            std::cout << "Nu exista locuri de parcare disponibile!\n";
            return ;
        }

    }
    else
    {
        cout << "Nu s-a putut adauga masina!" << endl;
    }
}
void Parcare::AddCarAngajat(CarAngajat* angajat)
{
    if (angajat != nullptr)
    {
        if (ParkingSpace > 0)
        {
            cout<<"Parking Space"<<ParkingSpace;
            time_t currentTime = std::time(nullptr);
            tm localTime;
            localtime_s(&localTime, &currentTime);
            char buffer[9]; // Buffer pentru a stoca ora în formatul "HH:MM:SS"
            strftime(buffer, sizeof(buffer), "%H:%M", &localTime);
            std::string oraCurenta = buffer;
            // Actualizați ora de intrare a mașinii
            CarAngajat carWithTime(angajat->getNrDeInmatriculare(), angajat->getOraIntrare(), angajat->getCod(),angajat->getIsAngajat());
            carWithTime.setOraIntrare(oraCurenta); // Actualizați ora de intrare a mașinii noi cu ora curentă
            // Cars.push_back(carWithTime);

            angajati.push_back(angajat);
            cout << "Masina adaugata cu succes!" << endl;

            ParkingSpace--;
            // Generați automat biletul de parcare
            BiletParcare bilet(angajat->getNrDeInmatriculare(), angajat->getOraIntrare());
            bilet.GenerateParkingTicket();
            bilet.salvareFisier("bilet.txt",'Y');
        }
        else
        {
            std::cout << "Nu exista locuri de parcare disponibile!\n";
            return;
        }

    }
    else
    {
        cout << "Nu s-a putut adauga masina!" << endl;
    }
}
void Parcare::RemoveCar(const std::string& plate)
{
    bool removedFromFisier = stergeInformatiiDinFisier(plate);
    if (removedFromFisier)
    {

        auto clientIt = std::find_if(clienti.begin(), clienti.end(), [plate](CarClient* client)
        {
            return client->getNrDeInmatriculare() == plate;
        });
        if (clientIt != clienti.end())
        {
            clienti.erase(clientIt);
            cout << "Masina cu numarul de inmatriculare " << plate << " a fost stearsa din vectorul clienti cu succes!" << endl;
        }

        // Verificăm și în vectorul angajati
        auto angajatIt = std::find_if(angajati.begin(), angajati.end(), [plate](CarAngajat* angajat)
        {
            return angajat->getNrDeInmatriculare() == plate;
        });
        if (angajatIt != angajati.end())
        {
            angajati.erase(angajatIt);
        }
        cout << "Masina cu numarul de inmatriculare " << plate << " a fost stearsa din fisier cu succes!" << endl;
    }
    else
    {
        cout << "Masina cu numarul de inmatriculare " << plate << " nu a fost gasita in fisier!" << endl;
    }
}
bool Parcare::verificaPlataLaIesire(double sumaIntrodusa, double plata, double& rest, CarClient& car)
{
    double sumaIntrodusaActuala = car.getUltimaPlata() + sumaIntrodusa;

    if (sumaIntrodusaActuala >= plata)
    {
        rest = sumaIntrodusaActuala - plata;
        return true; // Plata este suficientă, șoferul poate ieși
    }
    else
    {
        rest = plata - sumaIntrodusaActuala;
        return false;
    }
}

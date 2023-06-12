#include "Dispozitiv.h"

double Dispozitiv::calculateDuration(const std::string& entryTime) const
{
    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::tm localTime;
    localtime_s(&localTime, &currentTime);
    int currentHour = localTime.tm_hour;
    int currentMinute = localTime.tm_min;
    std::string ora_str = entryTime.substr(0, 2);
    std::string minut_str = entryTime.substr(3, 2);
    int entryHour = std::stoi(ora_str);
    int entryMinute = std::stoi(minut_str);


    int durationHours = currentHour - entryHour;
    int durationMinutes = currentMinute - entryMinute;
    if (durationMinutes < 0)
    {
        durationHours--;
        durationMinutes += 60;
    }
    double duration = durationHours + (durationMinutes / 60.0);
    return duration;
}
double Dispozitiv::calcul_plata(double durata_sedere) const
{
    double tarif_suplimentar = Settings::pret_pe_ora / 60; // tariful suplimentar per minut
    if (durata_sedere <= 2.0)
    {
        return 0;
    }
    else
    {
        double durata_suplimentara = durata_sedere - 2.0; // calculăm durata suplimentară (în ore)
        // Calculăm plata pentru tariful suplimentar
        double plata_totala = (durata_suplimentara * 60) * tarif_suplimentar;
        return plata_totala;
    }
}
std::string Dispozitiv::readFromFile(const std::string& id)
{
    std::ifstream fisier("bilet.txt");
    std::string line;
    std::string numarInmatriculare;
    std::string oraEmiterii;
    std::string isAngajat;

    while (std::getline(fisier, line))
    {
        std::istringstream iss(line);
        iss >> numarInmatriculare >> oraEmiterii >> isAngajat;

        if (numarInmatriculare == id)
        {
            fisier.close();
            return isAngajat;
        }
    }
    fisier.close();
    return ""; //in caz ca nu gasim id returnam empty
}
std::string Dispozitiv::readTimeFromFile(const std::string& id)
{
    std::ifstream fisier("bilet.txt");
    std::string line;
    std::string numarInmatriculare;
    std::string oraEmiterii;

    while (std::getline(fisier, line))
    {
        std::istringstream iss(line);
        iss >> numarInmatriculare >> oraEmiterii;

        if (numarInmatriculare == id)
        {
            fisier.close();
            return oraEmiterii;
        }
    }

    fisier.close();
    return ""; //in caz ca nu gasim id returnam empty
}
double Dispozitiv::calculatePayment(const std::string& id)
{
    std::string isAngajat = readFromFile(id);

    if (isAngajat == "Y" || isAngajat == "y")
    {
        return 0;
    }
    else
    {
        std::string oraEmiterii = readTimeFromFile(id);
        double parkingDuration = calculateDuration(oraEmiterii);
        double payment = calcul_plata(parkingDuration);
        return payment;
    }
}

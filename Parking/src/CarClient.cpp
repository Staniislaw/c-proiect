#include "CarClient.h"
std::string CarClient::getCurrentTimeFormatted(const std::string& format)
    {
        time_t rawTime;
        struct tm* timeInfo;
        char buffer[80];

        time(&rawTime);
        timeInfo = localtime(&rawTime);
        strftime(buffer, sizeof(buffer), format.c_str(), timeInfo);

        return std::string(buffer);
    }
CarClient::CarClient(const string& ID,bool angajat) : numarInmatriculare(ID),isAngajat(angajat)
    {
        oraIntrarii = getCurrentTimeFormatted("%H:%M");
    }
    string CarClient::getNrDeInmatriculare() const
    {
        return numarInmatriculare;
    }
    string CarClient::getOraIntrare() const
    {
        return oraIntrarii;
    }
    void CarClient::setOraIntrare(const string& ora)
    {
        oraIntrarii = ora; // Actualizați membrul oraIntrare cu valoarea primită
    }
    bool CarClient::getIsAngajat() const
    {
        return isAngajat;
    }
    void CarClient::setUltimaPlata(double plata)
    {
        ultimaPlata = plata;
    }
    double CarClient::getUltimaPlata()
    {
        return ultimaPlata;
    }

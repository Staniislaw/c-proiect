#include "CarAngajat.h"

bool CarAngajat::authenticate(const string& authFile, const string& numarInmatriculare, const string& Cod)
    {
        ifstream file(authFile);
        string line;
        bool authenticated = false;
        if (file.is_open())
        {
            while (getline(file, line))
            {
                size_t pos = line.find(" ");
                string filePlate = line.substr(0, pos);
                string fileAuthCode = line.substr(pos + 1);

                if (filePlate == numarInmatriculare && fileAuthCode == Cod)
                {
                    authenticated = true;
                    break;
                }
            }
            file.close();
        }
        else
        {
            cout << "Nu s-a putut deschide fisierul de autentificare!" << endl;
        }

        return authenticated;
    }

    string CarAngajat::getCod() const
    {
        return Cod;
    }

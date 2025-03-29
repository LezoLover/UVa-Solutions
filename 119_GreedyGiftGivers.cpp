#include <iostream>
#include <string>
#include <sstream>

struct PERSON
{
    std::string name;
    int balance = 0;
};

int main() {
    int n, i = 0;
    std::string names, lectura;

    std::cin >> n;
    std::cin.ignore();

    if (n > 10)
        return 1;

    std::getline(std::cin, names);

    std::stringstream ss(names);
    PERSON people[n];

    while (std::getline(ss, lectura, ' ')) {
        if (lectura.length() > 12)
            return 1;

        people[i].name = lectura;
        i++;
    }

    std::string querys[n];

    for (i = 0; i < n; i++)
        std::getline(std::cin, querys[i]);

    for (i = 0; i < n; i++) {
        std::stringstream ss(querys[i]);

        ss >> lectura;
        std::string name = lectura;

        ss >> lectura;
        int dineroGastado = std::stoi(lectura);

        if (dineroGastado < 0 || dineroGastado >= 2000)
            return 1;

        for (int j = 0; j < n; j++) {
            if (people[j].name == name) {
                people[j].balance -= dineroGastado;
                j = n;
            }
        }

        ss >> lectura;
        int count = std::stoi(lectura);
        int dineroGanado = 0;

        if (count != 0)
            dineroGanado = dineroGastado / count;

        if (count > 0 && dineroGanado > 0) {
            while (std::getline(ss, lectura, ' '))
            {
                for (int j = 0; j < n; j++) {
                    if (people[j].name == lectura) {
                        people[j].balance += dineroGanado;
                    }
                }
            }
        }
    }

    for (i = 0; i < n; i++)
        std::cout << people[i].name << " " << people[i].balance << std::endl;

    return 0;
}
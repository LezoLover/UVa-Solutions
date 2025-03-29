#include <iostream>
#include <string>
#include <sstream>

int zeroOne(std::string txt, std::string query) {
    int indexes[2];
    int zeros = 0, ones = 0, temp, i = 0;

    std::string lectura;
    std::stringstream ss(query);

    while (std::getline(ss, lectura, ' ')) {
        indexes[i] = std::stoi(lectura);
        i++;
    }

    if (indexes[0] > indexes[1]) {
        temp = indexes[0];
        indexes[0] = indexes[1];
        indexes[1] = temp;
    }

    for (i = indexes[0]; i <= indexes[1]; i++) {
        if (txt[i] == '0')
            zeros++;
        else
            ones++;
    }

    if (zeros == ones)
        return 1;
    else if (zeros == 0 && ones != 0)
        return 1;
    else if (zeros != 0 && ones == 0)
        return 1;

    return 0;
}

int main() {
    std::string txt;
    int n;

    std::getline(std::cin, txt);

    if (txt.length() > 1000000)
        return 1;

    std::cin >> n;
    std::cin.ignore();

    if (n < 0)
        return 1;

    std::string querys[n];
    int resultados[n];

    for (int i = 0; i < n; i++)
        std::getline(std::cin, querys[i]);

    for (int i = 0; i < n; i++)
        resultados[i] = zeroOne(txt, querys[i]);

    for (int i = 0; i < n; i++) {
        if (resultados[i] == 0)
            std::cout << "No" << std::endl;
        else
            std::cout << "Yes" << std::endl;
    }

    return 0;
}
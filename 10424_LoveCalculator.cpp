#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

int sumar(int);
int value(char);

int main() {
    int sum1 = 0, sum2 = 0;

    std::string name1, name2;

    std::getline(std::cin, name1);
    std::getline(std::cin, name2);

    if (name1.length() > 25 || name2.length() > 25)
        return 1;

    for (std::size_t i = 0; i < name1.length(); i++)
        sum1 += value(name1[i]);

    for (std::size_t i = 0; i < name2.length(); i++)
        sum2 += value(name2[i]);

    int value1 = sumar(sum1);
    int value2 = sumar(sum2);

    float result = 100.00;

    if (value1 > value2) 
        result = 1.0 * (static_cast<float>(value2)/value1) * 100;
    else if (value1 < value2) 
        result = 1.0 * (static_cast<float>(value1)/value2) * 100;

    std::cout << std::fixed << std::setprecision(2) << result << " %" << std::endl;

    return 0;
}

int sumar(int num) {
    int sum = 0, charNum;

    if (num < 10)
        return num;
    else {
        std::string numC = std::to_string(num);

        for (std::size_t i = 0; i < numC.length(); i++)
        {
            charNum = numC[i] - '0';
            sum += charNum;
        }

        return sumar(sum);
    }
}

int value(char letter) {
    if (letter == 'A' || letter == 'a')
        return 1;
    else if (letter == 'B' || letter == 'b')
        return 2;
    else if (letter == 'C' || letter == 'c')
        return 3;
    else if (letter == 'D' || letter == 'd')
        return 4;
    else if (letter == 'E' || letter == 'e')
        return 5;
    else if (letter == 'F' || letter == 'f')
        return 6;
    else if (letter == 'G' || letter == 'g')
        return 7;
    else if (letter == 'H' || letter == 'h')
        return 8;
    else if (letter == 'I' || letter == 'i')
        return 9;
    else if (letter == 'J' || letter == 'j')
        return 10;
    else if (letter == 'K' || letter == 'k')
        return 11;
    else if (letter == 'L' || letter == 'l')
        return 12;
    else if (letter == 'M' || letter == 'm')
        return 13;
    else if (letter == 'N' || letter == 'n')
        return 14;
    else if (letter == 'O' || letter == 'o')
        return 15;
    else if (letter == 'P' || letter == 'p')
        return 16;
    else if (letter == 'Q' || letter == 'q')
        return 17;
    else if (letter == 'R' || letter == 'r')
        return 18;
    else if (letter == 'S' || letter == 's')
        return 19;
    else if (letter == 'T' || letter == 't')
        return 20;
    else if (letter == 'U' || letter == 'u')
        return 21;
    else if (letter == 'V' || letter == 'v')
        return 22;
    else if (letter == 'W' || letter == 'w')
        return 23;
    else if (letter == 'X' || letter == 'x')
        return 24;
    else if (letter == 'Y' || letter == 'y')
        return 25;
    else if (letter == 'Z' || letter == 'z')
        return 26;

    return 0;
}

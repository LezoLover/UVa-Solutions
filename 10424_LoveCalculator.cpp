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
    if (letter >= 'A' && letter <= 'Z')
        return int(letter) - 64;
    else if (letter >= 'a' && letter <= 'z')
        return int(letter) - 96;

    return 0;
}

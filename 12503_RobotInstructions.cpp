#include <iostream>
#include <string>

int move(std::string instructions[], int i)
{
    if (instructions[i] == "RIGHT")
        return 1;
    else if (instructions[i] == "LEFT")
        return -1;
    else {
        int index;

        if (instructions[i].length() == 9) 
            index = std::stoi(std::string(1, instructions[i][8])) - 1;
        else
            index = std::stoi(instructions[i].substr(8)) - 1;

        return move(instructions, index);
    }
}

int main()
{
    int T, n, pos;

    std::cin >> T;

    if (T > 100)
        return 1;

    for (int j = 0; j < T; j++)
    {
        pos = 0;

        std::cin >> n;
        std::cin.ignore();

        if (n < 1 || n > 100)
            return 1;

        std::string instructions[n];

        for (int i = 0; i < n; i++) {
            std::getline(std::cin, instructions[i]);
        }

        for (int i = 0; i < n; i++)
            pos += move(instructions, i);

        std::cout << pos << std::endl;
    }

    return 0;
}
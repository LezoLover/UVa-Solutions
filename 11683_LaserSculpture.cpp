#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>

struct CASE
{
    int A, C;
    std::queue<int> x;

    int result;
};

int countTimes (CASE currentCase)
{
    int A = currentCase.A;
    int C = currentCase.C;
    std::queue<int> x = currentCase.x;

    int X[C];
    for (int i = 0; i < C; i++)
    {
        X[i] = x.front();
        x.pop();
    }

    int block[A][C] = {};

    for (int j = 0; j < C; j++)
        if (A != X[j])
            for (int i = 0; i < A - X[j]; i++)
                block[i][j] = 1;

    int groups = 0;
    
    for (int i = 0; i < A; i++)
    {
        bool counting = false;
        for (int j = 0; j < C; j++)
        {
            if (block[i][j] == 1 && !counting)
            {
                groups++;
                counting = true;
            }
            else if (block[i][j] == 0)
                counting = false;
        }
    }

    return groups;
}

int main()
{
    std::string read;
    std::vector<CASE> cases;

    while (std::getline(std::cin, read) && (read != "0 0" && read != "0"))
    {
        int A, C;
        std::queue<int> x;

        std::stringstream ss(read);
        ss >> A >> C;

        std::getline(std::cin, read);
        std::stringstream ss2(read);
        for (int i = 0; i < C; i++)
        {
            int value;
            ss2 >> value;
            x.push(value);
        }

        CASE currentCase;
        currentCase.A = A;
        currentCase.C = C;
        currentCase.x = x;

        cases.push_back(currentCase);
    }

    for (CASE currentCase : cases)
        std::cout << countTimes(currentCase) << std::endl;

    return 0;
}

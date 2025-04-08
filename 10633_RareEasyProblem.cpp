#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

struct CASE
{
    unsigned long long input;
    std::vector<unsigned long long> results;
};

bool isK(unsigned long long R, int k)
{
    return k == std::floor((R + k) / 10);
}

std::vector<unsigned long long> solutions(unsigned long long R)
{
    unsigned long long a = std::ceil((R - 10) / 9);
    unsigned long long b = std::floor(R / 9);

    std::vector<unsigned long long> sols;
    std::vector<unsigned long long> list;

    for (unsigned long long i = 0; i < b - a + 1; i++)
        if (isK(R, a + i))
            list.push_back(a + i);

    for (std::size_t i = 0; i < list.size(); i++)
        sols.push_back(R + list[i]);

    return sols;
}

int main()
{
    int n = 0;
    unsigned long long val;
    std::string txt = "", input;

    while (true)
    {
        std::cin >> val;

        if (val == 0)
            break;

        if (!txt.empty())
            txt += " ";

        txt += std::to_string(val);

        n++;
    }

    CASE cases[n];

    std::stringstream ss(txt);

    int i = 0;
    while (ss >> val)
    {
        cases[i].input = val;
        i++;
    }

    for (i = 0; i < n; i++)
        cases[i].results = solutions(cases[i].input);

    for (i = 0; i < n; i++)
    {
        for (int n : cases[i].results)
            std::cout << n << " ";

        std::cout << std::endl;
    }

    return 0;
}

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

struct CASE
{
    int N;
    std::vector<std::string> solutions;
};

bool verifyDigits(std::string str)
{
    if (str.length() != 10)
        return false;

    std::sort(str.begin(), str.end());

    for (int i = 0; i < 10; ++i)
        if (str[i] != '0' + i)
            return false;

    return true;
}

std::vector<std::string> findSols(int N)
{
    std::vector<std::string> solutions;

    int end = (98765 / N < 45876) ? 98765 / N : 45876;
    for (int denom = 1234; denom <= end; denom++)
    {
        int numer = denom * N;
        
        std::string s_numer = (numer < 10000 ? "0" : "") + std::to_string(numer);
        std::string s_denom = (denom < 10000 ? "0" : "") + std::to_string(denom);

        std::string combined = s_numer + s_denom;

        if (verifyDigits(combined))
            solutions.push_back(s_numer + " / " + s_denom + " = " + std::to_string(N));
    }

    if (solutions.size() == 0)
        solutions.push_back("There are no solutions for " + std::to_string(N) + ".");

    return solutions;
}

int main()
{
    int val, n = 0;
    std::string txt = "";

    while (true)
    {
        std::cin >> val;

        if ((val > 0 && val < 2) || val > 79)
            return 1;

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
        cases[i].N = val;
        i++;
    }

    for (i = 0; i < n; i++)
        cases[i].solutions = findSols(cases[i].N);

    for (int i = 0; i < n; i++)
    {
        for (const std::string &str : cases[i].solutions)
            std::cout << str << std::endl;
        
        if (i != n - 1)
            std::cout << std::endl;
    }

    return 0;
}

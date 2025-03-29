#include <iostream>
#include <string>
#include <sstream>

struct CASE
{
    int H, U, D, F;
    
    bool success = false;
    int day = 0;
};


int main()
{
    int n = 0, i = 0;
    int val;
    std::string txt = "", temp;

    while (true) {
        std::getline(std::cin, temp);

        std::stringstream ss(temp);
        ss >> val;

        if (val == 0)
            break;

        if (!txt.empty())
            txt += " ";

        txt += temp;

        n++;
    }

    CASE cases[n];

    std::stringstream ss(txt);

    while (ss >> val) {
        cases[i].H = val;

        ss >> val;
        cases[i].U = val;

        ss >> val;
        cases[i].D = val;

        ss >> val;
        cases[i].F = val;

        i++;
    }

    //std::cout << n << std::endl;

    return 0;
}

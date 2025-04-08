#include <iostream>
#include <string>
#include <sstream>

struct CASE
{
    float H, U, D, F;
};

std::string calcSol(CASE inputCase) {
    int day = 0;
    float position = 0.0;

    float wellHeight = 1.0 * inputCase.H;
    float climbDist = 1.0 * inputCase.U;
    float dropNight = 1.0 * inputCase.D;
    float fatigueDistance = ((1.0 * inputCase.F) * climbDist) / 100;

    while (true) {
        if (position < 0)
            return ("failure on day " + std::to_string(day));
        
        day++;
        position += climbDist;

        if (position >   wellHeight)
            return ("success on day " + std::to_string(day));

        climbDist -= fatigueDistance;

        if (climbDist < 0.0)
            climbDist = 0.0;

        position -= dropNight;
    }

    return "";
}

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
    std::string results[n];

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

    for (i = 0; i < n; i++) 
        results[i] = calcSol(cases[i]);

    for (i = 0; i < n; i++)
        std::cout << results[i] << std::endl;

    return 0;
}

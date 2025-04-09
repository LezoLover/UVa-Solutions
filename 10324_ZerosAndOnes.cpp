#include <iostream>
#include <string>
#include <sstream>
#include <vector>

struct RESULTS {
    std::vector<std::string> results;
};

bool zeroOne(std::string txt, std::string query) {
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

    return (zeros == ones) || (zeros == 0) || (ones == 0);
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

    std::vector<std::string> querys(n);
    RESULTS results_struct;

    for (int i = 0; i < n; i++)
        std::getline(std::cin, querys[i]);

    for (int i = 0; i < n; i++)
        results_struct.results.push_back(zeroOne(txt, querys[i]) ? "Yes" : "No");

    for (const auto &res : results_struct.results)
        std::cout << res << std::endl;

    return 0;
}

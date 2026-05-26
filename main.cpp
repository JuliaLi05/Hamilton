#include <iostream>
#include <vector>
#include <string>
#include "hamilton.h"

int main() {
    while (true) {
    std::vector<std::vector<int>> graf;
    int wybor;
    std::cout << "Wybierz sposob wprowadzenia grafu:" << std::endl;
    std::cout << "1. Wprowadz recznie" << std::endl;
    std::cout << "2. Wczytaj z pliku" << std::endl;
    std::cout << "3. Wyjscie" << std::endl;
    std::cout << "Wybor: ";
    std::cin >> wybor;
    if (wybor == 1) {
        graf = wczytajRecznie();
    }
    else if (wybor == 2) {
        std::string nazwaPliku;
        std::cout << "Podaj nazwe pliku: ";
        std::cin >> nazwaPliku;
        graf = wczytajZPliku(nazwaPliku);
    }
    else if (wybor == 3) {
        std::cout << "Zamykanie programu...";
        break;
    }
    else {
        std::cout << "Nieprawidlowy wybor." << std::endl;
        continue;
    }
    hamiltonCycle(graf);
    }
    return 0;
}

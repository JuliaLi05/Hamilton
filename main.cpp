#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>
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
    auto start = std::chrono::high_resolution_clock::now();
    hamiltonCycle(graf);
    auto stop = std::chrono::high_resolution_clock::now();
    auto czasMs = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    std::chrono::duration<double> czasSekundy = stop - start;
    std::chrono::duration<double, std::ratio<60>> czasMinuty = stop - start;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "\nCzas znajdowania cyklu Hamiltona:" << std::endl;
    std::cout << "Milisekundy: " << czasMs.count() << " ms" << std::endl;
    std::cout << "Sekundy: " << czasSekundy.count() << " s" << std::endl;
    std::cout << "Minuty: " << czasMinuty.count() << " min" << std::endl;
    }
    return 0;
}
   

// AISD2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

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
// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln

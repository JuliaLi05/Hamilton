#include "hamilton.h"
#include <iostream>
#include <fstream>
#include <limits>

void hamiltonCycleUtil(const std::vector<std::vector<int>>& graph,
    std::vector<int>& path,
    std::vector<bool>& visited,
    int pos,
    std::vector<std::vector<int>>& cycles) {
    const int n = static_cast<int>(graph.size());
    if (pos == n) {
        if (graph[path[pos - 1]][path[0]] == 1) {
            std::vector<int> cycle = path;
            cycle.push_back(path[0]);
            cycles.push_back(cycle);
        }
        return;
    }
    for (int v = 1; v < n; ++v) {
        if (graph[path[pos - 1]][v] == 1 && !visited[v]) {
            path[pos] = v;
            visited[v] = true;
            hamiltonCycleUtil(graph, path, visited, pos + 1, cycles);
            visited[v] = false;
            path[pos] = -1;
        }
    }
}

void hamiltonCycle(const std::vector<std::vector<int>>& graph) {
    const int n = static_cast<int>(graph.size());
    if (n == 0) {
        std::cout << "Graf jest pusty." << std::endl;
        return;
    }
    std::vector<int> path(n, -1);
    std::vector<bool> visited(n, false);
    std::vector<std::vector<int>> cycles;
    path[0] = 0;
    visited[0] = true;
    hamiltonCycleUtil(graph, path, visited, 1, cycles);
    if (cycles.empty()) {
        std::cout << "Brak cyklu Hamiltona w grafie." << std::endl;
    }
   else {
     std::ofstream wynik("hamilton.txt");
     if (!wynik.is_open()) {
         std::cout << "Nie mozna utworzyc pliku hamilton.txt"
             << std::endl;
     }
     for (size_t i = 0; i < cycles.size(); ++i) {
         std::cout << "Cykl " << i + 1 << ": ";
         wynik << "Cykl " << i + 1 << ": ";
         for (int vertex : cycles[i]) {
             std::cout << vertex << " ";
             wynik << vertex << " ";
         }
         std::cout << std::endl;
         wynik << std::endl;
     }
     wynik.close();
     std::cout << "Wyniki zapisano do pliku hamilton.txt"
         << std::endl;
 }
    
}
std::vector<std::vector<int>> wczytajRecznie() {
    int n;
    std::cout << "Podaj liczbe wierzcholkow: ";
    while (!(std::cin >> n) || n <= 0) {
        std::cout << "Blad: podaj dodatnia liczbe calkowita: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::vector<std::vector<int>> graph(n, std::vector<int>(n));
    while (true) {
        bool poprawnaMacierz = true;
        std::cout << "Podaj macierz sasiedztwa " << n << "x" << n << ":" << std::endl;
        for (int i = 0; i < n && poprawnaMacierz; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!(std::cin >> graph[i][j]) ||
                    (graph[i][j] != 0 && graph[i][j] != 1)) {

                    poprawnaMacierz = false;
                    break;
                }
            }
        }
        if (poprawnaMacierz) {
            return graph;
        }
        std::cout << "\nBlad: niepoprawnie wprowadzona macierz sasiedztwa." << std::endl;
        std::cout << "Wprowadz tylko liczby 0 lub 1 oddzielone spacjami." << std::endl;
        std::cout << "Przyklad:" << std::endl;
        std::cout << "0 1 1 0\n"
            << "0 0 1 1\n"
            << "0 1 0 1\n"
            << "1 0 0 0\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::vector<std::vector<int>> wczytajZPliku(const std::string& nazwaPliku) {
    std::string nazwaPlikuLokalna = nazwaPliku;
    while (true) {
        std::ifstream plik(nazwaPlikuLokalna);
        if (!plik.is_open()) {
            std::cout << "Nie mozna otworzyc pliku."
                << std::endl;
            std::cout << "Podaj nazwe pliku ponownie: ";
            std::cin >> nazwaPlikuLokalna;
            continue;
        }
       int n;
if (!(plik >> n) || n <= 0) {
    std::cout << "\nBlad: niepoprawny format pliku." << std::endl;
    std::cout << "Pierwsza liczba w pliku musi byc dodatnia liczba wierzcholkow." << std::endl;
    std::cout << "Podaj nazwe pliku ponownie: ";
    std::cin >> nazwaPlikuLokalna;
    continue;
}

std::vector<std::vector<int>> graph(n, std::vector<int>(n));
bool poprawnyPlik = true;
for (int i = 0; i < n && poprawnyPlik; ++i) {
    for (int j = 0; j < n; ++j) {
        if (!(plik >> graph[i][j]) ||
            (graph[i][j] != 0 && graph[i][j] != 1)) {
            poprawnyPlik = false;
            break;
        }
    }
}

if (!poprawnyPlik) {
    std::cout << "\nBlad: niepoprawna macierz sasiedztwa w pliku." << std::endl;
    std::cout << "Plik powinien zawierac tylko liczby 0 lub 1 oddzielone spacjami." << std::endl;
    std::cout << "Przyklad poprawnego formatu:" << std::endl;
    std::cout << "4\n"
        << "0 1 1 0\n"
        << "0 0 1 1\n"
        << "0 1 0 1\n"
        << "1 0 0 0\n";
    std::cout << "Podaj nazwe pliku ponownie: ";
    std::cin >> nazwaPlikuLokalna;
    continue;
}
return graph;
    }
}

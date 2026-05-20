#include "hamilton.h"
#include <iostream>
#include <fstream>

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
        std::cout << "Znalezione cykle Hamiltona:" << std::endl;
        for (size_t i = 0; i < cycles.size(); ++i) {
            std::cout << "Cykl " << i + 1 << ": ";
            for (int vertex : cycles[i]) {
                std::cout << vertex << " ";
            }
            std::cout << std::endl;
        }
    }
}

std::vector<std::vector<int>> wczytajRecznie() {
    int n;
    std::cout << "Podaj liczbe wierzcholkow: ";
    std::cin >> n;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n));
    std::cout << "Podaj macierz sasiedztwa " << n << "x" << n << ":" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> graph[i][j];
        }
    }
    return graph;
}

std::vector<std::vector<int>> wczytajZPliku(const std::string& nazwaPliku) {
    std::ifstream plik(nazwaPliku);
    if (!plik) {
        std::cout << "Nie mozna otworzyc pliku." << std::endl;
        return {};
    }
    int n;
    plik >> n;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            plik >> graph[i][j];
        }
    }
    return graph;
}
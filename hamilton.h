#ifndef HAMILTON_H
#define HAMILTON_H

#include <vector>
#include <string>

std::vector<std::vector<int>> wczytajRecznie();
std::vector<std::vector<int>> wczytajZPliku(const std::string& nazwaPliku);
void hamiltonCycle(const std::vector<std::vector<int>>& graph);

#endif

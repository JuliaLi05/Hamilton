# Hamilton
## Opis Projektu
Aplikacja umożliwia znajdowanie **cykli Hamiltona** (każdy wierzchołek znajdowany tylko raz) w grafie, zarówno w przypadku danych **wprowadzanych przez użytkownika**, jak i **wczytanych z pliku**. Kod został napisany zgodnie ze standardem **C++11**. Program wyświetla wszystkie znalezione cykle Hamiltona w postaci kolejności odwiedzanych wierzchołków (jeżeli istnieją). W przeciwnym wypadku wyświetla **komunikat o braku takich cykli**.
## Sposób Wprowadzania Danych Wejściowych
Program umożliwia wprowadzanie danych na dwa sposoby:

- **ręcznie przez użytkownika**,
- **poprzez wczytanie danych z pliku**.

---
### Ręczne wprowadzanie danych
W przypadku wprowadzania danych ręcznie należy najpierw podać liczbę wierzchołków grafu, a następnie macierz sąsiedztwa
**Przykład:**

```txt
Podaj liczbe wierzcholkow: 4
Podaj macierz sasiedztwa 4x4:
0 1 1 0
0 0 1 1
0 1 0 1
1 0 0 0
```

**Wartości w macierzy oznaczają:**

- `1` — istnieje krawędź między wierzchołkami  
- `0` — brak krawędzi  

### Wczytywanie z pliku
W przypadku wczytywania z pliku należy podać nazwę pliku, np.:
graf.txt
Plik powinien mieć następujący format:
```txt
4
0 1 1 0
0 0 1 1
0 1 0 1
1 0 0 0
```
Pierwsza liczba oznacza liczbę wierzchołków grafu. Kolejne wiersze zawierają macierz sąsiedztwa grafu.
Dla powyższego przykładu graf ma 4 wierzchołki: '0, 1, 2, 3'.
## Wymagania i Kompilacja
Projekt zawiera plik `Makefile` automatyzujący proces budowania.
### Wymagania:
* Kompilator **g++**`
* System zgodny ze standardem POSIX (Linux/Unix/macOS) lub Windows.
### Instrukcja kompilacji:
Aby skompilować projekt, w katalogu głównym uruchom komendę:

```bash
make

```

Spowoduje to utworzenie pliku wykonywalnego `cykl_hamiltona`.

Aby wyczyścić pliki obiektowe i plik wykonywalny:

```bash
make clean

```

## Uruchomienie i Obsługa
Uruchomienie w terminalu:

```bash
./cykl_hamiltona

```



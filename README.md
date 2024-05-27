# Warships - Gra w Statki

## Spis Treści
1. [Opis Gry](#opis-gry)
2. [Zasady Gry](#zasady-gry)
3. [Instrukcja Instalacji](#instrukcja-instalacji)
4. [Uruchomienie Gry](#uruchomienie-gry)
5. [Sterowanie](#sterowanie)
6. [Autor](#autor)
7. [Licencja](#licencja)

## Opis Gry

"Warships" to klasyczna gra w statki, w której dwóch graczy próbuje zatopić nawzajem swoje floty. Każdy gracz posiada planszę o wymiarach 10x10 pól, na której umieszcza swoje statki. Celem gry jest odgadnięcie, na których polach przeciwnik umieścił swoje statki i zatopienie ich przed przeciwnikiem.

## Zasady Gry

1. **Ustawienie statków**:
    - Każdy gracz ma do dyspozycji flotę składającą się z następujących statków:
        - 1x Lotniskowiec (5 pól)
        - 2x Pancernik (4 pola)
        - 3x Krążownik (3 pola)
        - 2x Niszczyciel (2 pola)
    - Statki mogą być umieszczane poziomo lub pionowo, ale nie mogą się stykać ani krzyżować.

2. **Rozgrywka**:
    - Gracze na zmianę wykonują ruchy, zgadując współrzędne na planszy przeciwnika (np. A5, C3).
    - Jeśli trafienie jest celne, gracz oznacza to na swojej planszy trafień.
    - Gra kończy się, gdy wszystkie statki jednego z graczy zostaną zatopione.

## Instrukcja Instalacji

Aby zainstalować grę "Warships", wykonaj poniższe kroki:

1. **Pobierz repozytorium**:
    ```bash
    git clone https://github.com/adriansudak/gra-w-statki.git
    ```
2. **Przejdź do katalogu z grą**:
    ```bash
    cd gra-w-statki
    ```
3. **Skompiluj projekt**:
    ```bash
    g++ -o gra-w-statki gra-w-statki.cpp Game.cpp Player.cpp Ships.cpp ShipsInConsole.cpp Engine.cpp
    ```

## Uruchomienie Gry

Aby uruchomić grę, użyj poniższej komendy w terminalu:

```bash
./gra-w-statki
```

## Sterowanie

- **Ustawienie statków**: Wprowadź współrzędne początkowe i końcowe statku.
- **Atak**: Wprowadź współrzędne pola, które chcesz zaatakować (np. B7).

## Autor

- **Adrian Sudak** - Autor projektu, wykonał całą pracę

## Licencja

Ten projekt jest licencjonowany na warunkach licencji MIT.

---

## Opis Techniczny

### Struktura Katalogów

```
gra-w-statki/
│
├── gra-w-statki/           # Katalog z projektem
│       # Pliki nagłówkowe
│   ├── Player.h
│   ├── Ships.h
│   ├── ShipsInConsole.h
│   ├── Game.h
│   └── Engine.h
│       # Pliki źródłowe
│   ├── gra-w-statki.cpp
│   ├── Player.cpp
│   ├── Ships.h
│   ├── ShipsInConsole.cpp
│   ├── Game.cpp
│   └── Engine.cpp
└── README.md               # Plik README
```

### Technologie

- **C++** - Główny język programowania
- **Konsola** - Interfejs użytkownika

### Przykładowy Kod

#### gra-w-statki.cpp
```cpp
#include "ShipsInConsole.h"

using namespace std;

int main() {
    ShipsInConsole ships;
    ships.play();

    return 0;
}
```

## Uwagi

Ten projekt jest częścią zaliczenia na przedmioty Programowanie Obiektowe na Studiach.

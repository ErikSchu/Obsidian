#dap1 
### Quiz Arrays
``` c++
int main() {
	int array[4] = {1, 2, 3, 4};
	
	for (int i = 1; i < 4, ++i) {
		printf("%i,", array[i - 1] + array[i]);
	}
	printf("\n");
}
``` 
`Ausgabe: 3, 5, 7,`

## Mehrdimensionale Arrays
- `int a[x]` erzeugt Array von x **int-Variablen**
- `int a[x][y]` erzeugt Array von x **int-Arrays** der Größe y

#### BEISPIEL
``` c++
#include <cstdio>

int main() {
	int array[3][2] = {{1, 2}, {3, 4}, {5, 6}};
	
	for (int i = 0; i < 3; ++i) {
		printf("(%i,%i),", array[i][0], array[i][1]);
	}
	printf ("\n");
}
```
⤷ Ausgabe: `(1,2),(3,4),(5,6)`

---
## Tic-Tac-Toe

>[!note] **Algorithmus** (Annahne: gegner beginnt mit Kreisen):
>1. warte auf gegnerischen Zug
>2. falls Gegner 3 Kreise in einer Zeile/Spalte/Diagonale → verloren; *Ende*
>3. falls kein Feld mehr frei ist: unentschieden; *Ende*
>4. falls ich ein Kreuz setzen kann, sodass ich 3 Kreuze in einer Zeile/Spalte/Diagonale habe
	>- setze dieses Kreuz → gewonnen; *Ende*
>5. falls es eine Zeile/Spalte/Diagonale gibt, in der der Gegner 2 Kreise hat:
	>- setze Kreuz auf freies Feld in dieser Zeile/Spalte/Diagonale
>6. sonst: setze Kreuz auf beliebiges freies Feld
>7. falls kein Feld mehr frei ist: unentschieden; *Ende*
>8. gehe zurück zu (1)


### Modellierung

- Spielfeld `char board[9]`
	- initial mit *'1', '2', ... , '9'* belegt (freie Felder)
	- Gegner (Mensch) $\leadsto$ *'0'*, Computer $\leadsto$ *'X'*
	![[Pasted image 20251127131212.png]]


- Hauptfunktion: Endloswiederholung
	- setzt die Zugfolge um (Zug Mensch, Zug Computer, Mensch, ... )
	- **Ende** wird an verschiedenen Punkten überprüft

- weitere Funktionen
	- `void drawBoard()`  druckt das aktuelle Spielfeld
	- `char checkWinner()`  überprüft auf Gewinnkonfiguration und gibt *'X'* / *'O'* / *'D'* / *Null* zurück (*'D'* = unentschieden; *Null* = nichts davon)
	- `int findMove()`  findet das Feld, auf das der Computer das nächste *'X'* setzt

### Code TTT
``` c++
#include <cstdio>
#include <cstdlib>
#include <ctime>

char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char const human = 'O';
char const cpu = 'X';

constexpr int number_wins = 8;
int win_lines[number_wins][3] = {
    {0, 1, 2},                        // Zeile 1
    {3, 4, 5},                        // Zeile 2
    {6, 7, 8},                        // Zeile 3
    {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // Spalten
    {0, 4, 8}, {2, 4, 6}              // Diagonalen
};

void drawBoard() {
  printf("\n");

  printf(" %c | %c | %c\n", board[0], board[1], board[2]);
  printf("---+---+---\n");
  printf(" %c | %c | %c\n", board[3], board[4], board[5]);
  printf("---+---+---\n");
  printf(" %c | %c | %c\n", board[6], board[7], board[8]);
}

char checkWinner() {
  // checke, ob Gewinner:
  for (int i = 0; i < number_wins; ++i) {
    char a = board[win_lines[i][0]];
    char b = board[win_lines[i][1]];
    char c = board[win_lines[i][2]];

    // test, ob a=b=c, wenn ja, dann gib entsprechenden zurück:
    if (a == b && b == c) return a;
  }

  // checke, ob unentschieden:
  for (int i = 0; i < 9; ++i) {
    if (board[i] != cpu && board[i] != human)
      return 0;  // es gibt ein freies Feld
  }
  return 'D';  // es gibt kein freies Feld
}

int findMove() {
  // kann ich einen Kreis setzen, sodass ich gewinne?
  for (int i = 0; i < number_wins; ++i) {
    char a = board[win_lines[i][0]];
    char b = board[win_lines[i][1]];
    char c = board[win_lines[i][2]];

    if (a == cpu && b == cpu && c != human) return win_lines[i][2];
    if (a == cpu && c == cpu && b != human) return win_lines[i][1];
    if (b == cpu && c == cpu && a != human) return win_lines[i][0];
  }

  // kann ich verhindern, dass Gegner gewinnt?
  for (int i = 0; i < number_wins; ++i) {
    char a = board[win_lines[i][0]];
    char b = board[win_lines[i][1]];
    char c = board[win_lines[i][2]];

    if (a == human && b == human && c != cpu) return win_lines[i][2];
    if (a == human && c == human && b != cpu) return win_lines[i][1];
    if (b == human && c == human && a != cpu) return win_lines[i][0];
  }

  // ansonsten: wähle ein zufälliges FREIES Feld:
  int anzahl_freie_felder = 0;  // wie viele Felder sind frei
  int freie_felder[9];          // welche Felder sind frei?
  for (int i = 0; i < 9; ++i) {
    if (board[i] != human && board[i] != cpu) {
      // freies Feld!
      freie_felder[anzahl_freie_felder] = i;
      ++anzahl_freie_felder;
    }
  }
  int move = rand() % anzahl_freie_felder;
  return freie_felder[move];
}

int main() {
  srand(time(0));  // setze Zufallsgenerator auf von Systemzeit abhängigen Wert

  while (true) {
    drawBoard();

    // warte auf gegnerischen Zug:
    int move;
    printf("Gib ein Zug ein (1-9): ");
    scanf("%i", &move);
    board[move - 1] = human;  // setze Kreis

    if (checkWinner() == human) {
      drawBoard();
      printf("Mensch hat gewonnen.\n");
      return 0;
    }
    if (checkWinner() == 'D') {
      drawBoard();
      printf("Unentschieden.\n");
      return 0;
    }

    // Computer zieht:
    move = findMove();
    board[move] = cpu;

    if (checkWinner() == cpu) {
      drawBoard();
      printf("Computer hat gewonnen.\n");
      return 0;
    }
    if (checkWinner() == 'D') {
      drawBoard();
      printf("Unentschieden.\n");
      return 0;
    }
  }
}
```

---

## Parameterübergabe || const

>[!TIP] **Parameterübregabe von Arrays an Funktionen**
>- Anders als bei anderen parametern wird *keine* Kopie des gesamten Arrays übergeben
>	- durch Verwenden von [] in der Parameterliste signalisiert
>	- beim FUnktionsaufruf wird eine **Kopie der Anfangsadressen** von `array` übergeben
>		- exakt wie bei *Referenzparametern*
>
``` c++
 void print_all(int a[], int length) {
	 fpr (int i = 0; i < length; ++i) {
		 printf("&i,", a[i]);
	 }
	 printf("\n");
	 ++a[0]; // for testing
 }
 
 int main() {
	 int array[3] = {1,2,3};
	 print_all(array,3); // prints 1,2,3
	 print_all(array,3); // prints 2,2,3 (1st Value!)
 }
```

>[!TIP] ***const:* Verhindert die Modufikation von Parametern**
>- in den meisten Fällen ist es ungünstig , dass Funktionen ihnen als Parameter übergenene Arrys verändern können $\leadsto$ Verhindern durch *const*:
>`void print_all(int const array[], int length);`
>- Schlüsselwort *const* allgemein:
>	- Compiler erlaubt **nur eine Zuweisung** an die Variable
>	- bei *const*-Funktionsparameterm: (automatische) Zuweisung bei Funktionsaufruf
>	- bei *const*-Variablen: nur direkt bei der Deklaration
>	- *const* bezieht sich ummer auf das, das direkt **davor** steht (wird später wichtig


> [!abstract] Definition
> Eine Funktion $f: B^n \rightarrow B^m$ heißt **boolesche Funktion**.
> * $B^n$ ist die Menge aller n-stelligen Tupel (Eingänge).
> * $B^m$ ist die Menge aller m-stelligen Tupel (Ausgänge).
>
> **Wichtiger Spezialfall:** $f: B^n \rightarrow B^1$ (eine Funktion mit $n$ Eingängen und 1 Ausgang).

### Kombinatorik: Anzahl boolescher Funktionen

- $|B^n| = 2^n$ **Zeilen**
- $|B^m| = 2^m$ **Funktionswerten pro Zeilen**  
	⤷ $2^{m^{2^n}} = 2^{m * 2^n}$ boolesche Funktionen für $f: B^n \rightarrow B^m$

> [!EXAMPLE] Beispiel $n=2$
> * Anzahl Zeilen: $2^2 = 4$ (00, 01, 10, 11)
> * Anzahl Funktionen: $2^{2^2} = 2^4 = 16$
> * Diese 16 Funktionen ($f_0$ bis $f_{15}$) sind alle möglichen 2-stelligen booleschen Funktionen.

### Wichtige Grundfunktionen (n=2)

| $x = 0$ | $x = 1$ | Funktion | Name           |                 |
| ------- | ------- | -------- | -------------- | --------------- |
| $f_0$   | 0       | 0        | Konstante 0    | **Kontraktion** |
| $f_1$   | 0       | 1        | $x$            | **Identität**   |
| $f_2$   | 1       | 0        | $\overline{x}$ | **Negation**    |
| $f_3$   | 1       | 1        | Konstante 1    | **Tautologie**  |

|   $x_1$    | $x_2$ |   $f_1$ (UND)   |  $f_6$ (XOR)   |  $f_7$ (ODER)   |    $f_8$ (NOR)    |  $f_{14}$ (NAND)   |
| :--------: | :---: | :-------------: | :------------: | :-------------: | :---------------: | :----------------: |
|     0      |   0   |        0        |       0        |        0        |         1         |         1          |
|     0      |   1   |        0        |       1        |        1        |         0         |         1          |
|     1      |   0   |        0        |       1        |        1        |         0         |         1          |
|     1      |   1   |        1        |       0        |        1        |         0         |         0          |
|  **Name**  |       | **Konjunktion** | **Antivalenz** | **Disjunktion** |  **NICHT-ODER**   |   **NICHT-UND**    |
| **Symbol** |       |     $\land$     |    $\oplus$    |     $\lor$      | $\overline{\lor}$ | $\overline{\land}$ |

> [!WARNING] Vorsicht bei der Notation (De Morgan)
> $\overline{x_1 \land x_2}$ (NAND) ist **nicht** das Gleiche wie $\overline{x_1} \land \overline{x_2}$ !
>
> | $x_1$ | $x_2$ | $\overline{x_1 x_2}$ (NAND) | $\overline{x_1} \land \overline{x_2}$ (NOR) |
> | :---: | :---: | :---: | :---: |
> | 0 | 0 | 1 | 1 |
> | 0 | 1 | 1 | 0 |
> | 1 | 0 | 1 | 0 |
> | 1 | 1 | 0 | 0 |
>
> Korrekt ist: $\overline{x_1 \land x_2} = \overline{x_1} \lor \overline{x_2}$

---

## 2. [[Boolsche_Formeln]]


---

## 3. [[Normalformen]]

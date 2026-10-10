#dap1

- Eine **Handlungsvorschrift** um ein(e Klasse von) Problem(en) zu lösen (**Klasse** von Problemen ≠ nur eine **Instanz** (d.h. ein konkretes Problem))

- Immer unter Berücksichtigung des zur verfügung stehenden **Baukastens**:
	- Für das Sortieren von Matrikelnummern, wäre "sortiere die Matrikelnummern" kein geeigneter Algorithmus, da der Baukasten in diesem fall beispielsweise C-Instruktionen wären.
	- Wird hingegen bei einem anderen Poblem das sortieren als Teillösung benötigt, kann die Anweisung "sortiere die Matrikelnummern" verwendet werden, vorausgesetzt es handelt sich um ein bekanntes (generisch) lösbares Problem (In diesem Fall wäre der Baukasten die C++-Standardbibliothek (→ z.B. allg. generische Funktion `std::sort`))

- Grundsätzlich **unabhängig** von einem konkreten Computer (die logische Idee ist somit universell) → z.B. egal ob AMD-/Intel-CPU
	- Allerdings muss die Gundfunktionalität des Computers (=Baukasten) Berücksichtigt werden (die einzelnen Schritte müssen auf die primitiven Operationen zurückführbar sein)

### Beispiel: Wie kann ein Computer Tic-Tac-Toe spielen?
- Algorithmus (Annahme: Gegner beginnt mit Kreisen):
    1. warte auf gegnerischen Zug
    2. falls Gegner 3 Kreise in einer Zeile/Spalte/Diagonale  verloren; **Ende**
    3. falls kein Feld mehr frei ist: unentschieden; **Ende**
    4. falls ich ein Kreuz setzen kann, sodass ich 3 Kreuze in einer Zeile/Spalte/Diagonale habe
	    - setze dieses Kreuz  gewonnen; **Ende**
    5. falls es eine Zeile/Spalte/Diagonale gibt, in der der Gegner 2 Kreise hat:
	    - setze Kreuz auf freies Feld in dieser Zeile/Spalte
    6. sonst: setze Kreuz auf beliebiges freies Feld
    7. falls kein Feld mehr frei ist: unentschieden; **Ende**
    8. gehe zurück zu (1)

### Handlungsvorschrift für ein konkretes Problem
- häufiges beispiel: Kochrezepte
- oder bewegen in einem Labyrinth: https://blockly.games
- oder Anleitung Papierfliegerfalten

### Stand 15.10.2025:
Die Frage “Was ist ein Algorithmus?” (und verwandte) ist sehr philosophisch.
In DAP1 wird versucht, diese Frage auf intuitive Weise zu lösen: durch das Entwickeln von Algorithmen für bestimmte Probleme unter Zuhilfenahme eines immer komplexer werdenden Baukastens.
→ Daher keine endgültige Klärung dieses Begriffs.
⤷ In **DAP1** geht es also vielmehr um tiefes, intuitives Verständnis, welches das Praktische Fundament für formal & mathematisch exakte Definitionen bildet.

### Algorithmen ausserhalb der Informatik
- **Technik-, ingenieur-, Naturwissenschaften, Mathematik:** *iterative* Verfahren, Anleitungen zum Messen, mathematische Verfahren ...
- **Sprachwissenschaften**: z.B. i.F.v. Transformationsgrammatiken oder generativen Grammatiken
- **Kunst**: serielle Kunst, Aleatorik, fraktale Kunst
- **Sozialwissenschaften:** z.B. im Zusammenhang mit d'Hodentschen (und anderen)  Verfahren zur Ermittlung der Sitzverteilung in Parlamenten
- **Rechtswissenschaften:** z.B. Formuierung bon Gesetzen: "Wenn ... gemäß § ... dann ... außer ... "
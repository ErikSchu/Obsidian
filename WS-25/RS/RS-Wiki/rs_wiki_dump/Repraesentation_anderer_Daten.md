
Neben Zahlen müssen auch Programme, Bilder, Audio, Objekte etc. repräsentiert werden.

## Das zentrale Problem

Was repräsentiert ein Byte (oder Wort) im Speicher?

Ein Bitmuster wie `01000001` könnte sein:
* Die Zahl `65` (Dezimal)
* Das Zeichen `'A'` (ASCII)
* Ein Teil eines Maschinenbefehls
* Ein Farbwert

**Lösung:** [[#Typisierung]]

## 1. Programme
* Ein Programm besteht aus Maschinenbefehlen (z.B. `ADD`, `LOAD`, `STORE`).
* Jeder Befehl wird als Bitmuster fester Länge (z.B. 32 Bit) codiert.
* Dieses Muster enthält den **Befehl** selbst (Opcode) und die **Operanden** (Daten oder Adressen).

## 2. Typisierung
* Da ein Bitmuster mehrdeutig ist, muss das Programm "wissen", wie es interpretiert werden soll.
* Der **Compiler** sorgt zur Übersetzungszeit für die richtige Interpretation.
* Wenn eine Variable als `int` deklariert ist, wird das Bitmuster an ihrer Adresse als [[Repräsentation ganzer Zahlen|Zweierkomplement]] behandelt.
* Wenn sie als `float` deklariert ist, wird sie als [[Repraesentation_rationaler_Zahlen_(Gleitkomma)|IEEE-754]]-Zahl behandelt.

## 3. Repräsentation von Datenfolgen
Speicher ist oft in **Worten** organisiert (z.B. 4 Bytes / 32 Bit).

* **Heterogene Daten (z.B. C-Structs):**
    * Verschiedene Datentypen werden hintereinander in den Speicher geschrieben.
    * **Alignment:** Manchmal werden leere Bytes ("Padding") eingefügt, damit jeder Datentyp an einer Wortgrenze beginnt (schnellerer Zugriff).

* **Homogene Daten (Arrays):**
    * Folgen des *gleichen* Datentyps.
    * **Problem:** Wie erkennt man das Ende der Folge?
        * **Lösung 1:** Feste, vorab vereinbarte Anzahl (z.B. in C: `int a[10]`).
        * **Lösung 2:** Die Länge am Anfang der Folge speichern (z.B. Java-Arrays).
        * **Lösung 3:** Ein spezielles Endezeichen verwenden (z.B. `\0` bei C-Strings).
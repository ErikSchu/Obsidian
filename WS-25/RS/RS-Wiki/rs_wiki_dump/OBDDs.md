

OBDDs sind eine spezielle Datenstruktur (ein Graph), um [[Boolsche_Funktionen]] $f: B^n \rightarrow B^1$ effizient zu repräsentieren.

## 1. Ziele und Motivation

Im Gegensatz zu [[Boolesche_Funktionen|Normalformen]] (DNF/KNF) haben OBDDs andere Optimierungsziele:

* **Schnelle Auswertung:** Den Funktionswert $f(x_1, \dots, x_n)$ für eine gegebene Belegung schnell finden.
* **Gleichheitstest:** Schnell testen, ob zwei Funktionen $f$ und $g$ identisch sind.
* **Manipulation:** Funktionen schnell ändern (z.B. eine Variable auf 1 oder 0 setzen).
* **Kompaktheit:** Funktionen möglichst klein repräsentieren.

---

## 2. Aufbau und Regeln

Ein OBDD ist ein gerichteter, azyklischer Graph. Sein Aufbau folgt festen Regeln:

1.  **Variablenordnung ($\pi$):** Es wird eine feste Reihenfolge der Variablen festgelegt (z.B. $\pi = (x_1, x_2, x_3)$). Diese Ordnung muss im gesamten Graphen eingehalten werden.
2.  **Knoten:**
    * **Variablen-Knoten:** Sind mit einer Variable (z.B. $x_1$) markiert.
    * **Konstanten-Knoten (Senken):** Markiert mit **0** (falsch) oder **1** (wahr).
3.  **Kanten:**
    * **0-Kante** (gestrichelt/low): Entspricht der Zuweisung $x_i = 0$.
    * **1-Kante** (durchgezogen/high): Entspricht der Zuweisung $x_i = 1$.
4.  **Strukturregeln:**
    * Es gibt genau einen Startknoten (Wurzel).
    * Jeder Variablen-Knoten hat genau eine 0-Kante und eine 1-Kante.
    * Konstanten-Knoten haben keine ausgehenden Kanten.
    * Die Variablenordnung $\pi$ muss auf jedem Pfad von der Wurzel zu einer Senke eingehalten werden (Variablen dürfen übersprungen, aber nicht vertauscht werden).

---

## 3. Auswertung eines OBDD

Um den Funktionswert für eine Belegung (z.B. $f(1, 0, 1)$) zu finden, folgt man einem Pfad von der Wurzel zur Senke:

1.  Starte am Wurzelknoten (z.B. $x_1$).
2.  Ist die Belegung für $x_1 = 1$? Folge der 1-Kante. (Sonst 0-Kante).
3.  Komme zum nächsten Knoten (z.B. $x_2$).
4.  Ist die Belegung für $x_2 = 0$? Folge der 0-Kante.
5.  Wiederhole dies, bis ein Konstanten-Knoten (0 oder 1) erreicht ist. Dieser Wert ist der Funktionswert.

> [!EXAMPLE] Auswertung $f(1, 0, 1)$
> * Start bei $x_1$: $x_1 = 1 \rightarrow$ Folge 1-Kante.
> * Knoten $x_2$: $x_2 = 0 \rightarrow$ Folge 0-Kante.
> * Knoten $x_3$: $x_3 = 1 \rightarrow$ Folge 1-Kante.
> * Ergebnis: **Senke 1**.
> * Somit ist $f(1, 0, 1) = 1$.

---

## 4. Reduzierung zum minimalen OBDD (piOBDD)

Ein aus einer Wertetabelle erstelltes OBDD (ein "Binärbaum") ist oft riesig. Es wird durch **Reduktionsregeln** vereinfacht.

> [!TIP] Reduktionsregeln
> 1.  **Verschmelzungsregel (Gleichartige Knoten):** Zwei Knoten, die die *gleiche Variable* markieren und auf die *gleichen Nachfolger* zeigen (gleiche 0-Kante UND gleiche 1-Kante), werden verschmolzen. Man beginnt "von unten" bei den Senken.
> 2.  **Eliminationsregel (Redundante Knoten):** Ein Knoten, dessen 0-Kante und 1-Kante zum *exakt gleichen Nachfolger* führen, ist redundant (die Variable hat keinen Einfluss). Er wird entfernt und die eingehenden Kanten werden direkt zum Nachfolger umgeleitet.

> [!abstract] Satz: Reduziertes $\pi$OBDD
> Die erschöpfende Anwendung dieser Regeln führt zum **reduzierten $\pi$OBDD**.
>
> **Eigenschaften:**
> * Das ROBDD ist für eine feste Variablenordnung $\pi$ **eindeutig**.
> * Es hat die **minimale Größe**.
>
> Diese Eindeutigkeit (Kanonizität) ist der Hauptvorteil: Um $f=g$ zu testen, reduziert man beide OBDDs (mit gleicher $\pi$). Sind die Graphen identisch, sind die Funktionen gleich.

---

## 5. OBDD zurück in eine Funktion umwandeln

Man kann aus einem piOBDD wieder eine (oft vereinfachte) DNF ableiten.

1.  Berücksichtige nur Pfade, die zur **Konstanten-Senke "1"** führen.
2.  Jeder dieser Pfade wird zu einem Minterm (Produktterm).
3.  **Regeln für Literale im Pfad:**
    * Folgt man der **1-Kante** eines Knotens $x_i$, kommt $x_i$ in den Term.
    * Folgt man der **0-Kante** eines Knotens $x_i$, kommt $\overline{x_i}$ in den Term.
4.  Alle so gefundenen Terme (Pfade) werden mit **ODER ($\lor$)** verknüpft.

> [!EXAMPLE] Beispiel $f_{bsp}$
> Die DNF aus der Wertetabelle war:
> $f_{bsp} = \overline{x_1}\overline{x_2}\overline{x_3} \lor x_1\overline{x_2}\overline{x_3} \lor x_1\overline{x_2}x_3 \lor x_1x_2\overline{x_3} \lor x_1x_2x_3$
>
> Das reduzierte OBDD hat nur zwei Pfade zur 1:
> 1.  Pfad 1: $x_1$ (0-Kante) $\rightarrow$ $x_2$ (0-Kante) $\rightarrow$ $x_3$ (0-Kante) $\rightarrow$ 1
>     * Term 1: $\overline{x_1} \land \overline{x_2} \land \overline{x_3}$
> 2.  Pfad 2: $x_1$ (1-Kante) $\rightarrow$ 1
>     * Term 2: $x_1$
>
> **Ergebnis (Funktion aus ROBDD):**
> $f_{bsp} = (\overline{x_1} \land \overline{x_2} \land \overline{x_3}) \lor x_1$
>
> Dies ist eine extrem vereinfachte Darstellung der Originalfunktion!
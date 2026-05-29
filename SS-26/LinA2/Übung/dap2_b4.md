#dap2 **11.05.2026**
## Aufgabe 1: $O$-Kalkül für Experten

> [!info] Vorüberlegung
> Bei diesen Aufgaben reicht ein einziges Gegenbeispiel (mit positiven, monoton wachsenden Funktionen), um eine Aussage zu widerlegen.

### (a) $2^{O(f(n))} = O(2^{f(n)})$
> [!failure] Aussage ist **Falsch**
> Wenn eine konstante Funktion im Exponenten steht, wächst der Ausdruck wesentlich schneller. 

**Beweis durch Gegenbeispiel:**
Wähle $f(n) = n$.
Die Funktion $g(n) = 2n$ ist in $O(f(n))$, da $2n \le 2 \cdot n$.
Setzen wir dies in die linke Seite ein: 

$$
2^{2n} = (2^2)^n = 4^n
$$

Nun prüfen wir die rechte Seite: Ist $4^n \in O(2^{f(n)}) = O(2^n)$?
Dafür müsste gelten: $\exists c > 0, n_0 : 4^n \le c \cdot 2^n$ für alle $n \ge n_0$.
Teilen wir durch $2^n$, steht da: $2^n \le c$. Da $2^n$ aber ins Unendliche wächst, gibt es keine solche Konstante $c$. Somit ist $4^n \notin O(2^n)$.

### (b) $2^{o(g(n))} = o(2^{g(n)})$
> [!failure] Aussage ist **Falsch**

**Beweis durch Gegenbeispiel:**
Erinnerung: $h(n) \in o(g(n)) \iff \lim_{n \to \infty} \frac{h(n)}{g(n)} = 0$.
Wähle $g(n) = 1$.
Wähle $h(n) = \frac{1}{n}$. Es gilt $h(n) \in o(g(n))$, da $\lim_{n \to \infty} \frac{1/n}{1} = 0$.
Linke Seite: $2^{h(n)} = 2^{1/n}$. Für $n \to \infty$ geht $2^{1/n} \to 2^0 = 1$.
Rechte Seite: $o(2^{g(n)}) = o(2^1) = o(2)$. Eine Funktion $k(n)$ ist in $o(2)$, wenn $\lim_{n \to \infty} \frac{k(n)}{2} = 0$, was bedeutet, dass $k(n) \to 0$ gehen muss.
Da unsere linke Seite aber gegen $1$ konvergiert und nicht gegen $0$, liegt sie nicht in $o(2)$.

### (c) $e^{\Theta(n \log n)} = O(n!)$
> [!failure] Aussage ist **Falsch**

**Beweis durch Gegenbeispiel:**
Wähle für den Exponenten die Funktion $f(n) = 2n \log n$. Offensichtlich gilt $f(n) \in \Theta(n \log n)$.
Setzen wir das in die linke Seite ein:

$$
e^{2n \log n} = (e^{\log n})^{2n} = n^{2n}
$$

Nun prüfen wir, ob $n^{2n} \in O(n!)$ gilt.
Wir wissen, dass $n! \le n^n$.
Wenn wir das Verhältnis bilden: 

$$
\frac{n^{2n}}{n!} \ge \frac{n^{2n}}{n^n} = n^n
$$

Da $n^n \to \infty$ für $n \to \infty$, wächst $n^{2n}$ asymptotisch strikt schneller als $n!$. Es ist also nicht in $O(n!)$.

### (d) $\log(\Theta(\log(\Theta(e^n)))) = \Theta(\log n)$
> [!success] Aussage ist **Wahr**

**Beweis:**
Wir lösen den Ausdruck von innen nach außen auf.
1. $\Theta(e^n)$: Eine Funktion hierin wird nach oben und unten durch $c_1 e^n$ und $c_2 e^n$ beschränkt.
2. $\log(\Theta(e^n))$: Wenden wir den Logarithmus an, erhalten wir $\log(c \cdot e^n) = \log(c) + n \cdot \log(e)$. Da $\log(c)$ eine Konstante ist, dominiert das $n$. Also ist $\log(\Theta(e^n)) = \Theta(n)$.
3. Nun bleibt noch der äußere Teil: $\log(\Theta(n))$.
4. Der Logarithmus einer Funktion, die linear wächst, ist $\log(c \cdot n) = \log(c) + \log(n)$. Hier dominiert $\log(n)$.
5. Das Ergebnis ist somit $\Theta(\log n)$.

### (e) $f(n) = \Theta(g(n)), \Phi \text{ ist monoton steigend} \implies \Phi(f(n)) = \Theta(\Phi(g(n)))$
> [!failure] Aussage ist **Falsch**

**Beweis durch Gegenbeispiel:**
Wähle $f(n) = 2n$ und $g(n) = n$. Es gilt $2n \in \Theta(n)$.
Wähle als monoton steigende Funktion $\Phi(x) = 2^x$.
Linke Seite: $\Phi(f(n)) = 2^{2n} = 4^n$.
Rechte Seite: $\Theta(\Phi(g(n))) = \Theta(2^n)$.
Wie in Aufgabe (a) bereits gezeigt, gilt $4^n \notin \Theta(2^n)$.

### (f) $f(n) = 2^{g(n)}, g(n) = n + \delta(n)$, dann gilt $f(n) = \Theta(2^n) \iff \delta(n) = O(1)$
> [!success] Aussage ist **Wahr**

**Beweis:**
Setzen wir $g(n)$ in $f(n)$ ein: 

$$
f(n) = 2^{n + \delta(n)} = 2^n \cdot 2^{\delta(n)}
$$

Damit $f(n) = \Theta(2^n)$ gilt, muss der Faktor $2^{\delta(n)}$ durch positive Konstanten nach unten und oben beschränkt sein.
Es muss also Konstanten $c_1, c_2 > 0$ geben, sodass für hinreichend große $n$ gilt:

$$
c_1 \le 2^{\delta(n)} \le c_2
$$

Wenden wir den Logarithmus (Basis $2$) an:

$$
\log_2(c_1) \le \delta(n) \le \log_2(c_2)
$$

Das bedeutet, dass $\delta(n)$ durch Konstanten nach oben und unten beschränkt ist. Genau das ist die Definition von $\delta(n) = O(1)$.

---

## Aufgabe 2: Problem der 100 Gefangenen 
>[!fail] nicht Klausurrelevant

> [!abstract] Die optimale Strategie (Pointer-Chasing)
> Die Gefangenen nutzen die Tatsache, dass die Schubladen eine zufällige Permutation der Zahlen $1$ bis $100$ darstellen. Jede Permutation zerfällt in disjunkte Zyklen.

**Die Strategie:**
1. Gefangener $i$ öffnet zuerst die Schublade mit seiner eigenen Nummer $i$.
2. Er liest die Nummer $j$, die in dieser Schublade liegt.
3. Als Nächstes öffnet er die Schublade mit der Nummer $j$.
4. Diesen Prozess wiederholt er, bis er entweder seine eigene Nummer $i$ findet (Erfolg) oder $50$ Schubladen geöffnet hat (Misserfolg).

**Warum funktioniert das?**
Der Gefangene folgt dem Zyklus der Permutation, in dem sich seine Nummer befindet. Er findet seine Nummer *genau dann*, wenn die Länge dieses Zyklus maximal $50$ ist.
Da alle Gefangenen dieselbe Permutation vorfinden, gewinnen **alle** Gefangenen genau dann, wenn die Permutation **keinen Zyklus der Länge $> 50$** enthält.

**Berechnung der Erfolgswahrscheinlichkeit:**
Wir berechnen die Gegenwahrscheinlichkeit: Wie groß ist die Wahrscheinlichkeit, dass es einen Zyklus gibt, der länger als $50$ ist?
Sei $k > 50$. Da es insgesamt nur $100$ Schubladen gibt, kann es in einer Permutation **höchstens einen** Zyklus der Länge $k$ geben (denn $2 \cdot 51 > 100$).
Die Wahrscheinlichkeit, dass ein bestimmter Zyklus der Länge $k$ existiert, ist genau $\frac{1}{k}$.
Da die Ereignisse (für verschiedene $k > 50$) disjunkt sind, können wir die Wahrscheinlichkeiten einfach addieren:

$$
P(\text{Zyklus } > 50) = \sum_{k=51}^{100} \frac{1}{k}
$$

Diese Summe lässt sich mit den harmonischen Zahlen $H_n = \sum_{i=1}^n \frac{1}{i}$ ausdrücken:

$$
P(\text{Zyklus } > 50) = H_{100} - H_{50}
$$

Setzen wir die gegebenen Näherungswerte ein ($H_{100} \approx 5,19$ und $H_{50} \approx 4,50$):

$$
P(\text{Zyklus } > 50) \approx 5,19 - 4,50 = 0,69
$$

Die Erfolgswahrscheinlichkeit (es gibt keinen solchen Zyklus) ist das Gegenereignis:

$$
P(\text{Erfolg}) = 1 - 0,69 = 0,31
$$

**Antwort:** Die genaue Erfolgswahrscheinlichkeit liegt bei ca. **$31\%$**.

---

## Aufgabe 3: Bau von `pickRandom`

> [!info] Konzept: Rejection Sampling (Verwerfungsmethode)
> Da wir nur faire Münzwürfe (`pickRandomBit`) haben, generieren wir Binärzahlen. Wenn die generierte Zahl außerhalb unseres gewünschten Bereichs liegt, verwerfen wir sie und versuchen es erneut.

### (a) `pickRandom2`
Wir brauchen eine Zahl zwischen $0$ und $2$ (also $3$ Möglichkeiten). Wir werfen die Münze $2$-mal, was uns $4$ Möglichkeiten gibt ($00, 01, 10, 11$).

```text
Algorithmus pickRandom2()
    wiederhole
        bit1 = pickRandomBit()
        bit2 = pickRandomBit()
        
        // Berechne den Wert (0, 1, 2 oder 3)
        val = bit1 * 2 + bit2 
        
    bis val <= 2
    
    return val
```

### (b) pickRandom(n)

Wir verallgemeinern das Prinzip. Wir suchen die Anzahl an Bits $k$, sodass $2^k > n$.

```
Algorithmus pickRandom(n)
    // Finde die benötigte Anzahl an Bits k
    k = 0
    solange (2^k <= n) tue
        k = k + 1
        
    wiederhole
        val = 0
        // Generiere k Bits und baue die Zahl zusammen
        für i = 1 bis k tue
            val = val * 2 + pickRandomBit()
            
    bis val <= n
    
    return val
```

### (c) pickRandom(a, b)

Wir verschieben einfach das Intervall auf $0$ bis $b-a$.

```
Algorithmus pickRandom(a, b)
    // Generiere eine Zahl zwischen 0 und (b-a)
    offset = pickRandom(b - a)
    
    // Verschiebe sie um a
    return a + offset
```

### Zusatz 1: Erwartete Laufzeit von pickRandom(n)

Sei $k$ die Anzahl der generierten Bits ($k = \lceil \log_2(n+1) \rceil$).  
In jedem Schleifendurchlauf generieren wir eine Zahl zwischen $0$ und $2^k - 1$.  
Die Wahrscheinlichkeit $p$, dass die Zahl gültig ist (also $\le n$), beträgt:

$$p = \frac{n+1}{2^k}$$

Da $2^{k-1} \le n < 2^k$, gilt immer $p > \frac{1}{2}$.  
Die Anzahl der Schleifendurchläufe folgt einer geometrischen Verteilung. Der Erwartungswert für die Anzahl der Versuche ist $1/p$. Da $p > 0{,}5$, ist der Erwartungswert strikt kleiner als $2$.  
Pro Versuch ziehen wir $k$ Bits. Die erwartete Laufzeit ist also:

$$O\!\left(k \cdot \frac{1}{p}\right) = O(k) = O(\log n)$$

### Zusatz 2: Ist $O(1)$ möglich?

**Nein.** Um eine Zahl gleichverteilt aus $n$ Möglichkeiten zu ziehen, benötigt man informationstheoretisch $\log_2(n)$ Bits an Entropie. Da `pickRandomBit` pro Aufruf genau $1$ Bit Entropie liefert (Laufzeit $O(1)$), müssen wir die Funktion zwingend $\Omega(\log n)$ mal aufrufen. Eine Laufzeit von $O(1)$ für beliebig große $n$ ist auf dieser rudimentären Maschine mathematisch unmöglich.

---

## Aufgabe 4: Der Turm von Hanoi

### Algorithmus

Das Problem lässt sich elegant rekursiv lösen. Um $n$ Scheiben von Säule $A$ nach $C$ zu bewegen, müssen wir zuerst die $n-1$ oberen Scheiben auf die Hilfssäule $B$ auslagern, dann die größte Scheibe nach $C$ legen und schließlich die $n-1$ Scheiben von $B$ nach $C$ bewegen.

```
// Aufruf für das Spiel: Hanoi(8, 'A', 'C', 'B')
Algorithmus Hanoi(n, quelle, ziel, hilfssaeule)
    wenn n == 1 dann
        drucke "Bewege Scheibe von " + quelle + " nach " + ziel
    sonst
        // 1. Bewege n-1 Scheiben von Quelle auf Hilfssäule
        Hanoi(n - 1, quelle, hilfssaeule, ziel)
        
        // 2. Bewege die größte Scheibe (n) ans Ziel
        drucke "Bewege Scheibe von " + quelle + " nach " + ziel
        
        // 3. Bewege die n-1 Scheiben von der Hilfssäule ans Ziel
        Hanoi(n - 1, hilfssaeule, ziel, quelle)
```

### Beweis der Laufzeit

Sei $T(n)$ die Anzahl der Bewegungen für $n$ Scheiben.  
Aus dem Pseudocode ergibt sich die Rekurrenzgleichung:

- $T(1) = 1$
- $T(n) = 2 \cdot T(n-1) + 1$

Wir lösen dies durch Einsetzen (oder Induktion):

$$T(n) = 2 \cdot (2 \cdot T(n-2) + 1) + 1 = 4 \cdot T(n-2) + 2 + 1$$

Allgemein formuliert:

$$T(n) = 2^k \cdot T(n-k) + \sum_{i=0}^{k-1} 2^i$$

Für $k = n-1$ erhalten wir:

$$T(n) = 2^{n-1} \cdot T(1) + \sum_{i=0}^{n-2} 2^i = 2^{n-1} + (2^{n-1} - 1) = 2^n - 1$$

Die Laufzeit ist somit exakt $2^n - 1$, also asymptotisch **$O(2^n)$**.

### Beweis der Korrektheit (durch vollständige Induktion)

**Behauptung:** Der Algorithmus Hanoi(n, quelle, ziel, hilfssaeule) verschiebt $n$ Scheiben regelkonform von quelle nach ziel.

**Induktionsanfang ($n=1$):**  
Es gibt nur eine Scheibe. Der Algorithmus verschiebt sie direkt von quelle nach ziel. Da es die einzige (und damit kleinste) Scheibe ist, wird keine Regel verletzt. Korrekt.

**Induktionsvoraussetzung (IV):**  
Der Algorithmus funktioniert korrekt für $n-1$ Scheiben.

**Induktionsschritt ($n-1 \to n$):**  
Wir betrachten den Aufruf für $n$ Scheiben.

1. Laut IV verschiebt der erste rekursive Aufruf Hanoi(n-1, ...) die oberen $n-1$ Scheiben regelkonform auf die Säule hilfssaeule. Die Scheibe $n$ (die größte) bleibt auf quelle und stört nicht, da alle anderen Scheiben kleiner sind und problemlos auf sie gelegt werden dürfen.
2. Nun liegt die Scheibe $n$ frei auf quelle und ziel ist leer (oder enthält noch größere Scheiben, falls wir uns in einer tieferen Rekursion befinden). Wir bewegen Scheibe $n$ nach ziel. Dies ist ein legaler Zug.
3. Laut IV verschiebt der zweite rekursive Aufruf Hanoi(n-1, ...) die $n-1$ Scheiben von hilfssaeule nach ziel. Da auf ziel nur die Scheibe $n$ liegt (welche die größte ist), ist jeder Zug auf ziel regelkonform.

Damit sind alle $n$ Scheiben regelkonform verschoben. $\blacksquare$
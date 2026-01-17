Freitag, 24.10.2025

Themen aus [[LinA_01 - Vektoren & Geraden]], [[LinA_02 - Mengen, Abbildungen, Kompositionen]], [[LinA_03 - Weiterführendes der Mengenlehre]]
## 1. Vektoren und Geraden

- **Vektor:** Eine geordnete Liste von reellen Zahlen, meist als Spalte geschrieben1. Die Reihenfolge ist entscheidend: $(\begin{smallmatrix} 2 \\ -1 \end{smallmatrix}) \ne (\begin{smallmatrix} -1 \\ 2 \end{smallmatrix}).$

- **$\mathbb{R}^n$:** Die Menge aller Vektoren mit _n_ reellen Einträgen.

- **Vektoraddition:** Einträge werden komponentenweise addiern. Geometrisch analog zum Bilden eines Parallelogramms.

- **Skalarmultiplikation:** Jeder Eintrag wird mit dem Skalar multipliziert. Geometrisch skaliert (streckt oder staucht) dies den Vektor.

- **Geradengleichung:** $L = \{ \vec{v} + t\vec{w} \mid t \in \mathbb{R} \}$.
    - $\vec{v}$ ist der **Stützvektor**, auch **Fußpunkt** genannt.
    - $\vec{w}$ ist der **Richtungsvektor**, der ungleich dem Nullvektor sein muss ($\vec{w} \neq \vec{0}$).

- **Kollinearität:** Zwei Vektoren $\vec{x}$ und $\vec{y}$ sind kollinear, wenn einer ein *skalares Vielfaches des anderen* ist, also $\vec{x} = c\vec{y}$ für einen Skalar $c \in \mathbb{R}$.


### **Typische Testat-Frage:**

> Gegeben sind die Vektoren $\vec{x} = (\begin{smallmatrix} 1 \\ 3 \end{smallmatrix})$ und $\vec{y} = (\begin{smallmatrix} 4 \\ 2 \end{smallmatrix})$.
> 
> a) Geben Sie die Gleichung für die Verbindungsgerade an, die durch $\vec{x}$ und $\vec{y}$ verläuft.
> b) Prüfen Sie, ob der Ursprung $\vec{0}$ auf dieser Geraden liegt.

#### Lösungsweg:
a) Wie in Satz 1.5 gezeigt, kannst du $\vec{x}$ als Stützvektor und $\vec{w} = \vec{y} - \vec{x}$ als Richtungsvektor verwenden. Also ist $\vec{w} = (\begin{smallmatrix} 4-1 \\ 2-3 \end{smallmatrix}) = (\begin{smallmatrix} 3 \\ -1 \end{smallmatrix})$. Die Gerade ist $L = \{ (\begin{smallmatrix} 1 \\ 3 \end{smallmatrix}) + t(\begin{smallmatrix} 3 \\ -1 \end{smallmatrix}) \mid t \in \mathbb{R} \}$.

b) Um zu prüfen, ob $\vec{0}$ auf der Geraden liegt, musst du schauen, ob es ein $t \in \mathbb{R}$ gibt, das die Gleichung $\vec{0} = \vec{x} + t\vec{w}$ löst.
$(\begin{smallmatrix} 0 \\ 0 \end{smallmatrix}) = (\begin{smallmatrix} 1 \\ 3 \end{smallmatrix}) + t(\begin{smallmatrix} 3 \\ -1 \end{smallmatrix})$.

Das ergibt zwei Gleichungen:
1. $0 = 1 + 3t \implies t = -1/3$
2. $0 = 3 - t \implies t = 3$
    Da man unterschiedliche Werte für t erhält, gibt es keine gemeinsame Lösung. Der Ursprung liegt nicht auf der Geraden.

---

## 2. Abbildungen, Bild & Urbild

- **Abbildung (Funktion):** Eine Regel $f: X \to Y$, die _jedem_ Element $x$ aus der Quellmenge X _genau ein_ Element $f(x)$ aus der Zielmenge Y zuordnet.

- **Bildmenge $f(A)$:** Für eine Teilmenge $A \subseteq X$ ist die Bildmenge $f(A)$ die Menge aller Ergebniswerte in Y. Formal: $f(A)=\{f(x) \mid x \in A\}$.

- **Urbildmenge $f^{-1}(B)$:** Für eine Teilmenge $B \subseteq Y$ ist die Urbildmenge $f^{-1}(B)$ die Menge aller Startelemente in X, deren Bild in B liegt16. Formal: $f^{-1}(B) = \{x \in X \mid f(x) \in B\}$.


### **Typische Testat-Frage:**

> Sei die Funktion $f: \mathbb{R} \to \mathbb{R}$, $f(x) = x^3$ gegeben.
> 
> a) Was ist die Bildmenge der Menge $A = \{-2, 0, 2\}$?
> b) Was ist die Urbildmenge der Menge $B = \{1, 8\}$?

### Lösungsweg:

a) $f(A) = \{f(-2), f(0), f(2)\} = \{(-2)^3, 0^3, 2^3\} = \{-8, 0, 8\}$.
b) Wir suchen alle $x \in \mathbb{R}$, sodass $f(x) \in \{1, 8\}$.
	Für $x^3 = 1$ ist die einzige reelle Lösung $x=1$.
	Für $x^3 = 8$ ist die einzige reelle Lösung $x=2$.
	Also ist $f^{-1}(\{1, 8\}) = \{1, 2\}$.

### Achtung

- **Urbild vs. Umkehrabbildung:** Der Urbildoperator $f^{-1}$ existiert **immer**, während die Umkehrfunktion $f^{-1}$ **nur für Bijektionen** existiert. Der Input für den Urbildoperator ist **immer eine Menge** (z.B. $f^{-1}(\{y\})$), nicht ein Element.


---

## 3. Injektiv, Surjektiv, Bijektiv

Eine Funktion $f: X \to Y$ ist...

- **Injektiv:** Wenn unterschiedliche Startwerte zu unterschiedlichen Zielwerten führen. Anders gesagt: Jedes Element in der Zielmenge Y hat **höchstens ein** Urbild.

- **Surjektiv:** Wenn jedes Element in der Zielmenge Y mindestens einmal getroffen wird. Anders gesagt: Jedes Element in Y hat **mindestens ein** Urbild. Das ist gleichbedeutend damit, dass die Bildmenge die gesamte Zielmenge ist: $f(X) = Y$.

- **Bijektiv:** Wenn sie sowohl injektiv als auch surjektiv ist. Jedes Element in Y hat **genau ein** Urbild.


### **Typische Testat-Frage:**

> Betrachten Sie die Projektion $\pi: \mathbb{R}^3 \to \mathbb{R}^2$ mit $\pi(x_1, x_2, x_3) = (x_1, x_2)$.
> 
> a) Ist $\pi$ injektiv? Begründen Sie Ihre Antwort.
> b) Ist $\pi$ surjektiv? Begründen Sie Ihre Antwort.

### **Dein Lösungsweg:**

a) Nein, $\pi$ ist nicht injektiv. Zur Begründung brauchst du ein Gegenbeispiel.

Sei $\vec{x} = (1, 2, 3)$ und $\vec{x}' = (1, 2, 9)$.
Dann ist $\vec{x} \neq \vec{x}'$, aber $\pi(\vec{x}) = (1, 2)$ und $\pi(\vec{x}') = (1, 2)$.
Also ist $\pi(\vec{x}) = \pi(\vec{x}')$, was die Definition der Injektivität verletzt.

b) Ja, $\pi$ ist surjektiv. Zur Begründung musst du zeigen, dass du für jeden beliebigen Zielvektor $\vec{y} = (y_1, y_2) \in \mathbb{R}^2$ einen Startvektor $\vec{x} \in \mathbb{R}^3$ finden kannst, sodass $\pi(\vec{x}) = \vec{y}$.

Wählen wir $\vec{x} = (y_1, y_2, 0)$. Dann ist $\pi(y_1, y_2, 0) = (y_1, y_2) = \vec{y}$. Da wir für jeden beliebigen Vektor $\vec{y}$ ein solches $\vec{x}$ finden können, ist die Funktion surjektiv.

---

## 4. Beweistechniken

- **Beweis vs. Gegenbeispiel:** Um eine "für alle"-Aussage zu beweisen, musst du mit allgemeinen Variablen argumentieren. Um sie zu widerlegen, brauchst du nur **ein einziges konkretes Gegenbeispiel**.

- **Äquivalenzbeweis ($A \iff B$):** Dieser erfordert immer zwei separate Beweise: die Richtung $A \implies B$ und die Richtung $B \implies A$.

- **Mengengleichheit ($M=N$):** Diese erfordert immer den Beweis von zwei Inklusionen: $M \subseteq N$ und $N \subseteq M$.

- **"Element-jagen":** Um $M \subseteq N$ zu beweisen, beginnst du immer mit "Sei $x \in M$..." und nutzt dann Definitionen, um zu zeigen, dass daraus "$x \in N$" folgt.

### **Typische Testat-Frage:**

> Beweisen oder widerlegen Sie: Für eine beliebige Funktion $f: X \to Y$ und beliebige Teilmengen $A, B \subseteq Y$ gilt: $f^{-1}(A \cup B) = f^{-1}(A) \cup f^{-1}(B)$.

### Lösungsweg:

1. **Versuche, ein Gegenbeispiel zu finden.** Nimm eine einfache, "gemeine" Funktion. Sei $X = \{1, 2\}$, $Y=\{a\}$, $f(1)=a, f(2)=a$. Sei $A=\{a\}, B=\emptyset$.
    
    - Linke Seite: $f^{-1}(A \cup B) = f^{-1}(\{a\} \cup \emptyset) = f^{-1}(\{a\}) = \{1, 2\}$.
    - Rechte Seite: $f^{-1}(A) \cup f^{-1}(B) = f^{-1}(\{a\}) \cup f^{-1}(\emptyset) = \{1, 2\} \cup \emptyset = \{1, 2\}$.
    - Es funktioniert. Die Aussage ist wahrscheinlich wahr. Jetzt musst du sie beweisen.

2. **Beweise $f^{-1}(A \cup B) \subseteq f^{-1}(A) \cup f^{-1}(B)$.**
    
    - Sei $x \in f^{-1}(A \cup B)$.
    - Per Definition des Urbilds bedeutet das $f(x) \in A \cup B$.
    - Per Definition der Vereinigung bedeutet das $f(x) \in A$ oder $f(x) \in B$.
    - **Fall 1:** Wenn $f(x) \in A$, dann ist per Definition des Urbilds $x \in f^{-1}(A)$.
    - **Fall 2:** Wenn $f(x) \in B$, dann ist per Definition des Urbilds $x \in f^{-1}(B)$.
    - In beiden Fällen gilt $x \in f^{-1}(A)$ oder $x \in f^{-1}(B)$, was $x \in f^{-1}(A) \cup f^{-1}(B)$ bedeutet.

3. **Beweise $f^{-1}(A) \cup f^{-1}(B) \subseteq f^{-1}(A \cup B)$.**
    
    - Sei $x \in f^{-1}(A) \cup f^{-1}(B)$.
    - Per Definition der Vereinigung ist $x \in f^{-1}(A)$ oder $x \in f^{-1}(B)$.
    - **Fall 1:** Wenn $x \in f^{-1}(A)$, dann ist per Definition des Urbilds $f(x) \in A$.
    - **Fall 2:** Wenn $x \in f^{-1}(B)$, dann ist per Definition des Urbilds $f(x) \in B$.
    - In beiden Fällen gilt $f(x) \in A$ oder $f(x) \in B$, was $f(x) \in A \cup B$ bedeutet.
    - Per Definition des Urbilds bedeutet das $x \in f^{-1}(A \cup B)$.

4. Da beide Inklusionen gelten, ist die Gleichheit bewiesen.
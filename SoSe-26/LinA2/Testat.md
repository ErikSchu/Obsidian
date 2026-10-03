#lina2
# Blatt 11
## Aufg. 52
$\det(T)\ne 0 \implies T \text{ invertierbar}$
Nahch Sylvesterschem Trägheitssatz $\text{Signatur}(A) = \text{Signatur}(T^tAT)$

## Aufg. 53
Signatur  von $A \implies$ doppelter gauß (wenn T irrelevant kann man auch nur A aufschreiben, dabei aber immer die zeilenoperationen auch auf die spalten anwenden)

___
## Rezept 1: Kongruenz zu Diagonalmatrizen ($T^t A T = D$)

Wird genutzt, um eine symmetrische Matrix ohne Eigenwertberechnung zu diagonalisieren (Symmetrischer Gauß).

### Algorithmus
1. **Setup:** Erstelle eine erweiterte Matrix $[A \mid I]$, wobei $A \in \text{Mat}_{n \times n}(K)$ symmetrisch ist und $I$ die Einheitsmatrix beschreibt.
2. **Symmetrie-Zwang:** Jede Zeilenoperation auf der linken Seite ($A$) muss sofort als **identische Spaltenoperation** auf der linken Seite wiederholt werden.
   * *Beispiel:* $Z_2 \leftarrow Z_2 + c \cdot Z_1 \implies \text{sofort danach } S_2 \leftarrow S_2 + c \cdot S_1$.
3. **Tracking von $T$:** Die Operationen auf der rechten Seite ($I$) werden **ausschließlich als Zeilenoperationen** ausgeführt. Spaltenoperationen rechts komplett ignorieren!
4. **Terminierung:** Wenn die linke Seite reine Diagonalgestalt $D$ besitzt, entspricht die rechte Seite der transponierten Transformationsmatrix $T^t$.
5. **Ergebnis:** Transponiere das Endergebnis der rechten Seite, um $T$ zu erhalten, sodass gilt:
   $$T^t A T = D$$

### Pivot-Problem (Null auf der Hauptdiagonale)
Falls $a_{ii} = 0$ an der aktuellen Eliminierungsposition steht:
* **Lösung:** Addiere eine andere Zeile $j$ und direkt danach die korrespondierende Spalte $j$.
* *Operation:* $Z_i \leftarrow Z_i + Z_j$ und $S_i \leftarrow S_i + S_j$. Der neue Eintrag an Position $(i,i)$ lautet $a_{ii} + a_{ij} + a_{ji} + a_{jj}$. Danach normal weitereliminieren.

---

## Rezept 2: Signatur & Definitheit (Sylvester)

Bestimmt die qualitativen Eigenschaften reeller symmetrischer oder komplexer hermitescher Matrizen. Die Sylvester-Signatur wird als Tupel $(p, m)$ angegeben.

### Weg A: Symmetrischer Gauß
Matrix wie in Rezept 1 auf Diagonalgestalt $D$ transformieren (Berechnung von $T$ ist für die reine Signatur nicht nötig).
* $p$: Anzahl der strikt positiven Einträge auf der Hauptdiagonale von $D$.
* $m$: Anzahl der strikt negativen Einträge auf der Hauptdiagonale von $D$.
* Es gilt: $\text{Rang}(A) = p + m$.

### Weg B: Eigenwert-Kriterium (Effizient für $2 \times 2$)
Berechnung über das charakteristische Polynom $\det(A - \lambda I) = 0$.

| Bedingung an Eigenwerte $\lambda_i$ | Signatur $(p,m)$ | Definitheit |
| :--- | :--- | :--- |
| Alle $\lambda_i > 0$ | $(n, 0)$ | positiv definit |
| Alle $\lambda_i \ge 0$ (mind. eine $0$) | $(p, 0)$ mit $p < n$ | positiv semidefinit |
| Alle $\lambda_i < 0$ | $(0, n)$ | negativ definit |
| Alle $\lambda_i \le 0$ (mind. eine $0$) | $(0, m)$ mit $m < n$ | negativ semidefinit |
| Mind. ein $\lambda > 0$ und ein $\lambda < 0$ | $p > 0$ und $m > 0$ | indefinit |

---

## Wichtige theoretische Fakten (Plaumann-Fallen)

* **Reelle symmetrische Matrizen ($A = A^t \in \text{Mat}_{n \times n}(\mathbb{R})$):**
  * Per Hauptachsentransformation (HAT) orthogonal diagonalisierbar: $U^t A U = D$ mit $U^t = U^{-1}$.
  * Hier gilt: **Kongruenz ist gleich Ähnlichkeit**.

* **Komplexe symmetrische Matrizen ($S = S^t \in \text{Mat}_{n \times n}(\mathbb{C})$):**
  * Per Kongruenz diagonalisierbar ($T^t S T = D$).
  * Im Allgemeinen **nicht** per Ähnlichkeit diagonalisierbar ($P^{-1} S P = D$). Die Aussage der HAT überträgt sich *nicht* auf den komplex-symmetrischen Fall (nur auf komplexe *hermitesche* Matrizen mit $H = H^*$).

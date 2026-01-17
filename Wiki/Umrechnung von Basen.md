#rs

Jede Zahl in einem **Stellenwertsystem** zur Basis $b$ kann umgerechnet werden. Die zwei grundlegenden Methoden sind die Summenmethode (in das Dezimalsystem) und der Divisionsalgorithmus (aus dem Dezimalsystem).

---

## 1. Beliebige Basis $b$ → Dezimal (b=10)

Diese Methode rechnet eine Zahl aus einem beliebigen System (Binär, Hexadezimal etc.) in das Dezimalsystem um.

### Summenmethode

1. **Stellen nummerieren:** rechts → links, beginnend bei 0.

2. **Stellenwerte berechnen:** für jede Stelle den Wert nach der Formel: $$Ziffer \cdot Basis^{Stelle}.$$
3. **Summieren:** Addiere alle berechneten Werte.


**Beispiel:**
$$(12AF)_{16} = 1 \cdot 16^3 + 2 \cdot 16^2 + 10 \cdot 16^1 + 15 \cdot 16^0 = 4783$$

---

## 2. Dezimal (b=10) → Beliebige Basis $b$

Hierfür wird der **Divisionsalgorithmus** verwendet, um eine Dezimalzahl in eine andere **Repräsentation** zu überführen.

### Divisionsalgorithmus

1. **Teilen:** Teile die Dezimalzahl durch die Zielbasis $b$.

2. **Rest notieren:** Notiere den **Rest** der Division.

3. **Wiederholen:** Nimm das ganzzahlige Ergebnis und wiederhole die Schritte 1 und 2, bis das Ergebnis 0 ist.

4. **Ablesen:** Lies die notierten Reste von **unten nach oben**.


**Beispiel: $(10)_{10}$ nach Binär (Basis 2)**

- $10 \div 2 = 5$ **Rest 0**

- $5 \div 2 = 2$ **Rest 1**

- $2 \div 2 = 1$ **Rest 0**

- $1 \div 2 = 0$ **Rest 1**
    

Von unten nach oben gelesen ergibt sich **1010**, also $(10)_{10} = (1010)_2$.

---

## 3. Sonderfall: Binärdarstellung ↔ Hexadezimaldarstellung

Die Umrechnung ist einfach, da $16 = 2^4$ ist. Eine Hex-Ziffer entspricht immer genau **vier Bits**.

### Anleitung

- **Hexadezimal → Binär:** Ersetze jede Hex-Ziffer durch ihren 4-Bit-Block.
    
    - **Beispiel:** $(3E)_{16} = (0011\ 1110)_2$

- **Binär → Hexadezimal:** Teile die Binärzahl von rechts in 4er-Blöcke auf. Ersetze jeden Block durch die passende Hex-Ziffer.
    
    - **Beispiel:** $(1101011)_2 \to (0110\ 1011)_2 = (6B)_{16}$
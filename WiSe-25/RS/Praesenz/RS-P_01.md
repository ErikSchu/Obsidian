#rs Donnerstag, 30.10.2025

![[RSUE_1.pdf]]

## 1.1 Umwandlung von Binär-, Dezimal- & Hexadezimaldarstellung (6P)
#### a.
$(10\ 1101)_2$ ist in die Repräsentation zur **Basis 10** umzuwandeln.
$$
1\cdot2^5+1\cdot2^3+1\cdot2^0 = 32+8+1 = 38
$$
**Antwort:** $(41)_{10}$

#### b.
$(F1)_{16}$ ist in die Repräsentation zur **Basis 10** umzuwandeln.
$$
15\cdot{16}^1+1\cdot16^0 = 240+1 = 241
$$
**Antwort:** $(241)_{10}$

#### c.
$(0110\ 1010\ 1110)_{16}$ ist in die Repräsentation zur **Basis 16** Umzuwandeln
$$
0110 \to 6;\ 1010 \to A;\ 1110 \to E
$$
**Antwort:** $(6AE)_{16}$

#### d. 
$(7DA)_{16}$ ist die Repräsentation zur **Basis 2**
**Antwort:** $(0111\ 1101\ 1010)_2$

---

## 1.2 Divisionsmethode (4P)
Konvertieren Sie mit der Divisionsmethode (vgl. Algorithmus 1) die Dezimalzahl in Binärdarstellung bzw. Hexadezimaldartellung. Schreiben Sie alle Schritte auf. 
#### a. 
$(207)_{10}$ ist in die Repräsentation zur Basis 2 umzuwandeln.
- $\frac{207}{2} = 103,\ R=1$
- $\frac{103}{2}=51, \ R=1$
- $\frac{51}{2} = 25, \ R = 1$
- $\frac{25}{2}=12, \ R=1$
- $\frac{12}{2} = 6, \ R=0$
- $\frac{6}{2} = 3, \ R = 0$
- $\frac{3}{2}=1, \ R=1$
- $\frac{1}{2}=0, \ R = 1$
**Antwort:** $(1100\ 1111)_{2}$

#### b.
$(3792)_{10}$ ist in die Reptäsentation zur Basis 16 umzuwandeln.
- $\frac{3792}{16}=237,\ R=0$
- $\frac{237}{16} = 14,\ R=13=D$
- $\frac{14}{16} = 0,\ R=14=F$
**Antwort:** $(FD0)_{16}$

---
## Umrechnungen
Wandeln Sie folgende 6-Bit Binärzahlen um. Die Zahlendarstellung ist jewails angegeben.

#### a.
Betragszahl: 10 0101
**Antwort:** $(-5)_{10}$
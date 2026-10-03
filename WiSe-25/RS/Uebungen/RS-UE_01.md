#rs ==Sonntag==, 02.11.2025

## 1.1 Umwandlung von Binär- Dezimal- und Hexadezimaldarstellung
### a.
$(10 1111)_2$ ist in die Repräsentation zur **Basis 10** umzuwandeln.
$$
2^5 + 2^3 + 2^2 + 2^1 + 2^0 = 32 + 8 + 4 + 2 + 1 = 47
$$
**Antwort:** $(10)_{10}$

### b.
$(FF)_{16}$ ist in die Repräsentation zur **Basis 10** umzuwandeln.
$$
15 \cdot 16^1 + 15 \cdot 16^0 = 240 + 15 = 255
$$
**Antwort:** $(255)_{10}$ 

### c.
$(1100 \ 0000 \ 1100)_2$ ist in die Repräsentation zur **Basis 16** umzuwandeln.
$$
\begin{align*}
& (1100)_{2} = (12)_{10} = (C)_{16} \\
& (0000)_{2} = (0)_{16} \\
& (1100)_{2} = (C)_{16}
\end{align*}
$$
**Antwort:** $(C0C)_{16}$

### d.
$(70E)_{16}$ ist in die Repräsentation zur **Basis 2** umzuwandeln.
$$
\begin{align}
& (7)_{16} = (0111)_{2} \\
& (0)_{16} = (0000)_{2} \\
& (E)_{16} = (14)_{10} = (1110)_{2}
\end{align}
$$
**Antwort:** $(0111 \ 0000 \ 1110)_{2}$

## 1.2 Divisionsmethode
### a.
$(211)_{10}$ ist in die Repräsentation zur **Basis 2** umzuwandeln. 
$$
\begin{align}
& \frac{211}{2} = 105, \ R=1 \\
& \frac{105}{2} = 52, \ R=1  \\
& \frac{52}{2} = 26, \ R=0 \\
& \frac{26}{2} = 13, \ R=0 \\
& \frac{13}{2} = 6, \ R=1 \\
& \frac{6}{2} = 3, \ R=0 \\
& \frac{3}{2} = 1, \ R=1 \\
& \frac{1}{2} = 0, \ R=1
\end{align}
$$
**Antwort:** $(1101 \ 0011)_{2}$

### b.
$(3161)_{10}$ ist in die Repräsentation zur **Basis 16** umzuwandeln.
$$
\begin{align}
& \frac{3161}{16} = 197, \ R=9 \\
& \frac{197}{16} = 12, \ R=5 \\
& \frac{12}{16} = 0, \ R=12=C \\
\end{align}
$$
**Antwort:** $(C59)_{16}$

## 1.3 Umrechnungen

**a)** Betragszahl: 10 0010 $(34)_{10}$
**b)** Festkomma-Betragszahl: 101,011 $(5.375)_{10}$
**c)** Vorzeichen-Betragszahl: 10 1001 $(-9)_{10}$
**d)** Vorzeichen-Betragszahl: 00 1010 $(10)_{10}$
**e)** Einerkomplement: 11 1000 $(-7)_{10}$
**f)** Einerkomplement: 00 0111 $(7)_{10}$
**g)** Zweierkomplement: 00 0100 $(4)_{10}$
**h)** Zweierkomplement: 11 0011 $(-13)_{10}$
**i)** Exzessdarstellung (Bias 8): 00 0101 $(-3)_{10}$
**j)** Exzessdarstellung (Bias 8): 10 0011 $(27)_{10}$

## 1.4 Zeichenkodierung

Entschlüsseln Sie die folgenden zwei "geheimen" Texte:
![[Pasted image 20251102221358.png]]
![[Pasted image 20251102221453.png]]

## 1.5 Ordnen von Zahlen

![[Pasted image 20251102221532.png]]
#dap1 

## Lempel-Ziv 77

>[!note] Wdh. LZ78
>In wieviele Paare zerlegt [[DAP1_29-Textkompession|LZ78]] den String $T = \text{aaaaaaaaaaaaaaa}$ (15 a's)? 
>⇒ *Antwort:* $z = 5$
>	⇒ Für $T = a^n$ *allgemein:*  $z \approx \sqrt{ n }$

>[!TIP] LZ77
>... gibt eine FOlge $l_{j}, d_{j}, c_{j}$ von $z$ Tripeln (Länge, Quelle, Buchstabe) aus, so dass $$T = \text{copy}(d_{1}, l_{1})c_{1} \ \cdot \ \text{copy}(d_{2},l_{2})c_{2} \ \cdots \ \text{copy}(d_{z}, l_{z})c_{z}$$

- **Annahme:** Es wurden bereits die ersten $i-1$ Buchstaben von $T$ dekodiert. Dann ist $$\text{copy}(d_{j}, l_{j}) = \begin{cases} T[i-d_{j}, i-d_{j}+l_{j}-1] &\text{falls } l_{j} > 0 \\ \text{" " (leerer String)} &\text{falls} l_j = 0 \end{cases}$$
>[!example] Beispiel
>$(0,0,a), \ (0,0,n), \ (3, 2, s)$
>$\implies T = \text{ananas}$

⇒ ***Wichtig:** Überlappungen sind erlaubt!*

##### Berechnung von $LZ 77$

- für alle $i$ von $1$ bis $n$:
	1. Finde längsten String $T[q, q+l-1]$ mit $q < i$, der ein Präfix von $T[i, n]$ ist
		*Informell: finde längsten String ab Pos. $i$, der vorher in $T$ vorkommt.*
	2. Gib $(l, i-q, T[i+l])$ aus
	3. Erhöhe $i$ um $l+1$

```cpp
dap1::MyString input("ananas");
int i = 0; // aktuelle Position
while (i < input.get_size()) {
int lpf_dist = 0; // Abstand vom besten Treffer
int lpf_len = 0; // Länge des besten Treffers
  for (int j = 0; j < i; j++) {
    int len = 0; // Länge des aktuellen Treffers
    while (i + len + 1 < input.get_size() &&
            input[i + len] == input[j + len]) {
      ++len;
    }
    if (len > lpf_len) { // neuer bester Treffer
      lpf_len = len;
      lpf_dist = i - j;
    }
  }
  printf("(%d, %d, %c)\n",
    lpf_len, lpf_dist, input[i + lpf_len]);
  i += lpf_len + 1;
}
```

$\implies$ **Asymptotische Laufzeit:** $\mathcal{O}(|T|^2)$ 

---
### Gleitendes Fenster

- Wir machen einen $\text{trade-off}:$ "Tausche **Kompressionsgüte** gegen **Zeit**"
- Wir betrachten nur noch höchstens $w$ Buchstaben vor und nach Position $i$
	- *gleitendes Fenster* der Größe $2w$
	⇒ **Asymptotische Laufzeit**, wenn $w$ konstant: $\mathcal{O}(|T|)$

___
### Einschub

>[!note] *Ternärer Operator*
>```cpp
>x = condition ? a : b;
>```
$$\iff$$
>```cpp
if (condition) x = a;
else x = b;
>```
>```

___

## Wie fu
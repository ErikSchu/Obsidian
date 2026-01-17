#dap1 Dienstag, 18.11.2025

## Lineare Suche in [[Arrays]]

> [!TIP] Lineare Suche
> - **Eingabe:** eine Liste von Matrikelnummern, gespeichert in `array[0, length-1]`, und eine Matrikelnnummer $x$
> - **Ausgabe:** die Position von $x$ in der Liste (oder -1, falls $x$ nicht vorkommt)

```c++
// lineare Suche: finde x in array[0, length-1]
int find(int const array[], int length, int x) {
	for (int i = 0; i < length; ++i) {
		if (array[i] == x) return i;
	}
	return -1;
}

int main () {
	int matr_nr[] = {34141, 45151, 53245, 52344};
	
	int pos = find(matr_nr, 4, 12335);
	printf("%i", pos);
}
```
⤷ *Worst-Case-Szenario:* Überprüfung findet `length`-mal statt

---

## Verbesserung: binäre Suche

>[!TIP]
>- **Eingabe:** eine *aufsteigend sortierte* Liste von Matrikelnummern, gespeicher in `array[0, length-1`, und eine Matrikelnummer $x$
>- **Ausgabe:** die Position von x in der Liste (oder -1, falls $x$ nicht vorkommt)
>---
>- **Notation `array[a,b]` **
>	- hiermit ist (in Kommentaren oder Pseudocode) gemeint, dass `array` ein Array der Länge $b-a+1$ ist(und von a bis b indiziert wird)
>	- oft nützlich, um von Teilarrays zu sprechen, z.B. bei der binären Suche
>	- kommt aus der diskreten Mathematik:
>		- `[a,b]` bezeichnet die Ganten Zahlen $\{ a, a+1, \dots, b-1, b \}$

```c++
// wie find(), aber mit binäerer Suche
int find_faster(int array[], int length, int x) {
	int left = 0;
	int right = length - 1;
	
	while () {
		int middle = (left + right) / 2;
		if(left == right && array[middle] != x) return -2;
		if (array[middle] == x) return middle;
		if (array[middle] > x) right = middle - 1;
		else left = middle + 1;
	}
	return -1;
}```

![[Pasted image 20251118131458.png]]

---

## Praxistest: Vergleich linearer und binärer Suche

- Mit dem Treminalkommando "`time`" können Programme auf ihre Laufzeit getestet werden
	- z.B. `time ./bin_search`
	- wichtig ist hier die angabe 'user'

>[!TIP] **Wichtiges beim empitischen Testen**
>- **ausreichend viele** Tests durchführen
>- Tests auf **ausreichend große Datenmengen** ausführen (z.B. Arrays der Große 100 MB)
>- sicherstellen, dass **alle möglichen Fälle** abgedeckt werden (z.B. erfolgreiche vs. erfolgose Suche)
>- **Hardware-Effekte** beachten, z.B. *Caching* vermeiden durch ausreichende Randomisierung der Tests

#### LINEARE Suche
- *BC:* $1$ Durchlauf
- *WC:* $n$ Durchläiufe

#### BINÄRE Suche
- *BC:* $1$ Durchlauf
- *WC:* $1 + \lceil \log n \rceil$ Durchläufe
#vorkurs
### Grundidee
- Eine Funktion löst ein Problem, indem sie sich selbst mit einer leicht vereinfachten Version des Problems aufruft.
- **Analogie:** Schlange am Kino, Matroschka-Puppen, ...
- Besteht immer aus zwei zwingend notwendigen Teilen:

	⤷ **1. Rekursionsanker:** Einfachser Fall, der ohne weiteren Aufruf gelöst werden kann und Kette der Funktionsaufrufe beendet ⇒ ansonsten [[StackOverflowError]]

	⤷ **2. Rekursionschritt:** Eine Regel, die das Problem in mimal kleinere Version seiner Selbst zerlegt, ruft die eigene Funktion solange auf, bis der Basisfall eintritt.
	Dannach wird der [[Call Stack]] wieder abgebaut und die teilprobleme zur Lösung des Gesamtproblems zusammengefügt.


### Abstr. Beispiel: Warteschlange → Wievielte Person?

1. **Problem:** Position unbekannt
2. **Rekursionsschritt:** Zerlegung Gesamtproblem in minimal kleineres ⇒ "Wievielte Person bist du?" ⇒ Problemdeligierung- & Zerlegung
3. **Basisfall:** Basisfall, der Aufrufskette beendet ⇒ Erste Person in der Schlange liefert Antwort "1"
4. **Lösung:** Rückgabe der Werte an vorherige Person ⇒ "Wenn du Pers. x bist, bin ich Pers. x + 1" ⇒ bis wieder bei Ursprungsperson angekommen

### ⮩ Anw'beispiel Potenzrechnung "power (x, y)" in [[Java]]:

- **Rekursionsanker:** Trivialster Fall, also y = 1, denn es gilt  x<sup>1</sup> = 1.0 für jedes x ∈ ℝ; power(x, 0) liefert somit immer das Ergebnis "1.0"
- **Rekursionsschritt (für y ≧ 0):** Minimal einfacheres Problem: x<sup>y</sup> = x ⋅ x <sup>y-1</sup>, also:
```java
power (x, y) = x * power (x, y - 1)
```
- **Rekursionsschritt (für x < 0):** $x^{-n}=\frac{1}{x^n}$

- poeweRek als [[API]] bzw. einzige public-Methode, um die Rekursion aufzurufen

⇨ **Quellcode**
```java
	//Rekursionsanker  
	public static double powerRek(int x, int y) {  
	    //Exponent == 0  
		    double erg = x;  
    if (y == 0) {  
        return 1.0;  
    }  
    return powerRekHlpr(x, y);  
}  
  
//Rekursionsschritt inkl. Vermeidung Eckfall y = Integer.MIN_VALUE
private static double powerRekHlpr(int x, long y) {  
    //positiver Exponent  
    if (y == 0) {  
        return x * powerRekHlpr(x, y-1);  
    }  
    //negativer Exponent  
    else {  
        return 1.0 / powerRekHlpr(x, -y);  
    }  
}
	 ```
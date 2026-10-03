Donnerstag, 13.11.2025
#dap1 

---

## Strings
-  sind arrays vom typ *(unsigned) char[]*
- sollten **nullmetiriert** sein (letztes char hat den Wert 0)
	- wird bei Strings in doppelten Anführungsstrichen "automatisch" hinzugefügt
	- Strings **müssen** natürlich **nicht** nullmetriert sein 
``` cpp
int main() {

//allokiere Array der Länge 7 (+1 für 0 am Ende)
char s[] = "Hello!";

// Strings können wir Arrays manipuliert werden
s[1] = 'e';

// prints "Hello!"
printf("%s\n", s); 
return 0;
}
```

## Gleichheit von Strings
``` c++
bool str_equal(char const str1[], char const str2[]) {
	for (int i = 0; str1[i] == str2[i]; ++i) {
		if (str1[i] == 0) return true; // dann auch str2[i]=0	
	}
	return false;
}
```

- die Ausführung dieser Funktion dauert **länger** als der Vergleich zweier Skalare, z.B. 2 int's
	- im worst-case werden zwei lange Strings bis zum Ende verglichen
		- z.B. `char s[] = "ein 1 MB langer String"; str_equal(s, s);`
	- dies ist **i.A nicht vermeidbar**, auch nicht in anderen Programmiersprachen (ist aber bei c(++) offensichtlicher)

---
## ToUpperCase (vgl. Praktikumsaufgabe 1.3) 

- **EIngabe:** String in
- **Ausgabe:** Eine Kopie von `in`, bei der alle Kleinbuchstaben in Großbuchstaben umgewandelt worden sind.

``` c++
// wandle übergebenen String in Großbuchstaben um und speichere Ergebnis in out
void to_upper_case(char const in[], char out[]) {
	for (int i = 0; ; ++i) {
		out[i] = in[i]; // kopiere Zeichen
		if (out[i] == 0) return;
		
		// ziehe Differenz der ASCII_Werte ab => Kleinbuchstaben
		// zu Großbuchstaben
		if (out[i] >= 'a' && out[i] <= 'z') out[i] -= 'a' - 'a'
	}
}
```

- Sollen Funktionen Arrays (oder Strings) als Rückgabewert liefern, nutzen wir wieder **Ausgabeparameter**
	- Platz muss "vom Aufrufenden" allokiert werden

---

## Dynamische Allokation von Strings

- wie bei Arrays auch **dynamische Allokation** mit dem `new`-Operator möglich
	- dann keine Zuweisungen mit String-Literalen möglich

```cpp
char* human_name = new char[100];
printf("Gib deinen Namen ein: ");
scanf(" &s", human_name);
```


> [!TIP] Ziel
Ändern wir unser Tix-Tac-Toe Spiel ab, dass es die Namen einliest und an den entsprechenden Stellen benutzt. Zusätzlich soll überprüft werden, dass die Spieler nicht den gleichen Namen haben.

⤷ ***Skript***

---
## Header-Dateien

- Die bisher entwickelten Funktionen für Strings sind evtl. in mehreren Kontexten nützlich

- Wollen wir diese auch in einem anderen Programm verwenden, können wir diese mit **\#include** "einbetten"

- allerdings würde **\#include** "`strings.cpp`" dazu führen, dass 2 main() Funktionen definiert wären $\leadsto$ das Programm könnte nicht kompiliert werden

- Dazu müssen Funktionen, die in eanderen Programmen verwendet werden solle, in sogenannten **Header-Dateien ohne main Funktion** gespeichert werden (Dateiendung "`.h`" oder "`.hpp`")
	- i.A. besser, als die Funktionen zu kopieren

---

## Funktionen auf (nulterminierten) Strings (s[], t[])

- Länge eines Strings:
```cpp
int str_len(char const s[]) { int i = 0; while (s[i] != 0) ++i; } 
```

- Stringvergleich: 
```cpp
// <0, fallst s<t; >0, falls s==t
int str_comp (char const s[], char const [t]) {
	int i;
	for (i = 0; s[i] == t[i]; ++i) {
		// a zu Ende => Strings gleich, Rückgabe 0
		of (s[i] == 0) return 0;
	}
	// positiv, falls s>t; sonst negativ
	return [s[i] - t[i]];
}
```
 
- etc.

- sind alle in der Bibliothek **cstring** implementiert (ohne die Unterstriche in den Namen)

- *merke:* `char`s sind letztendluch nur numerisch kodierte **ASCII-Zeichen**


### Äquivlente Formulierung

- **char** `string[]` entspricht **char**** bei Parameterübergabe
	- beide übergeben Adresse des Strings

- analog: **char const** `string[]` entspricht **char const**** string

- weitere Signatur der main-Funktion: **int** main(**int** number_of_args, **char**** args[])
	- nützlich bei der Übergabe von Parametern an das Programm `./compute.stat <filename> <t>`
	- number_of_args: Anzahl der Parameter
	- args: Array von Strings, jeder Eintrag 1 Parameter
	- der Programmname zählt in beiden Fällen mit

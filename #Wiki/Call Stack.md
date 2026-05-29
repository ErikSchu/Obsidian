#vorkurs
- **Was es ist:** Ein interner Speicherbereich, der von der [[JVM]] verwaltet wird, nicht vom Programmierer.

- Er wird von der [[JVM]] für **JEDEN** Methodenaufruf verwendet, um den Programmfluss zu steuern. Er ist nicht spezifisch für die [[Rekursion]].

- **Funktion:** Behält den Überblick über aktive Funktionsaufrufe. Wie ein Lesezeichen in einem Buch.

- **Prozess:**
	- **Push:** Bei jedem Funktionsaufruf wird ein neuer Frame (Kontext der Funktion) auf den Stapel gelegt.
    - **Pop:** Wenn eine Funktion mit `return` endet, wird ihr Frame vom Stapel entfernt und die Kontrolle an den darunterliegenden Frame zurückgegeben.

- **Relevanz für die [[Rekursion]]:** Der Call Stack ermöglicht es, dass jeder rekursive Aufruf seinen eigenen Satz von lokalen Variablen hat und weiß, wohin er sein Ergebnis zurückgeben muss.
- Die Rekursion ist nur ein **Spezialfall**, der den Call Stack sehr intensiv nutzt, weil sich eine Methode immer wieder selbst auf den Stapel legt.

- Der [[StackOverflowError]] ist die Folge davon, dass der für den Stack reservierte Speicherplatz durch zu viele (meist rekursive) Aufrufe aufgebraucht wird.
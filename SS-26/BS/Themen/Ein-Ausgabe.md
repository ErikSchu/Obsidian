---
kurs: Betriebssysteme
dozent: Prof. Peter Ulbrich
themengebiet:
datum: 15.07.2026
tags:
  - bs
  - io
---
## UNIX
#### Gerätespezifische Funktionen

- Spezielle Geräteeigenschaften erden über ***`ioctl`*** angesprochen:
  ![[Pasted image 20260715162349.png]]
- Schnittstelle generisch, Semantik gerätespezifisch:
  ![[Pasted image 20260715162433.png]]

#### Warten auf mehrere Geräte

- bisher: **Lese-/Schreibaufrufe blockieren**
	- Was tun beim Lesen von mehreren Quellen?

- ***Alternative 1:*** *nichtblockierende Ein-/Ausgabe*
	- `O_NDELAY` beim `open()`
	- **Polling-Betrieb:** Prozess muss immer wieder `read()` aufrufen
	⮩ Unbefriedigend, da *Verschwendung von CPU-Zeit* bis etwas vorliegt

- ***Alternative 2:** Blockieren an mehreren Dateideskriptoren*
	- **Systemaufruf**
	  `int select (int nfds, fd_set *readfds, fd_set *writefds, fd_set *errorfds, struct timeval *timeout);`
	- `ndfs` legt fest, bis zu welchem Dateideskriptor `select` wirken solll
		- fds sind Dateideskriptoren, auf die gewartet werden soll:
		  ⤷ `readfds` - bis ezwas zum Lesen vorhanden ist
		  ⤷ `writefds` - bis man selber schreiben kann
		  ⤷ `errorfds` - bis ein Fehler aufgetreten ist 
	- *Timeout* legt fest, wann der Aufruf spätestens deblockiert
	- Makros zum Erzeugen der Dateideskriptormengen
	- **Ergebnis:** In den Dateideskriptormengen sind nur noch die Dateideskriptoren vorhanden, die zur **De**blockade führten

___
## Pufferung bei E/A-Optionen

- ***Probleme** ohne Datenpuffer* im Betriebssystem:
	- Daten, die eintreffen, bevor `read` ausgeführt wurde (z.B. von der Tastatur), müssten verloren gehen.
	- Wenn ein Ausgabegerät beschäftigt ist, müsste `write` scheitern oder den Prozess blockieren, bis das Gerät wieder bereit ist.
	- Ein Prozess, der eine E/A-Operation durchführt, kann nicht ausgelagert werden. 
	  ![[Pasted image 20260715163944.png]]

#### E/A-Einzelpuffer

- ***Einlesen***
	- Daten können vom System entgegengenommen werden, auch wenn der Leserprozess noch nicht `read` aufgerufen hat.
	- Bei Blockgeräten kann der nächste Block vorausschauend gelesen werden, whrend der vorherige verarbeitet wird.
	- Prozess kann problemlos ausgelagert werden. DMA erfolgt im Puffer. 
	  ![[Pasted image 20260715164109.png]]
 
  - ***Schreiben***
	  - Daten werden kopiert. Aufrufer blockiert nicht. Datenpuffer im Benutzeradressraum kann sofort wiederverwendet werden.

>[!tip] Leistungsabschätzung
>Eine einfache Rechnung zeigt den Leistungsgewinn bei wiederholten blockweisen Lesen mit anschließender Verarbeitung:
>	$T$: Dauer der Leseoperation
>	$C$: Rechenzeit für die Verarbeitung
>	$M$: Dauer des Kopiervorgangs (Systempuffer → Benutzerprozess)
>	$G$: Gesamtdauer für Lesen und Verarbeiten eines Blocks
>- ohne Puffer $G_{0} = T + C$
>- mit Puffer: $G_{E} =\text{max}(T, C) + M$
>Mit $T \approx C$ und $M \approx 0$ wäre $G_{0} \approx 2 \cdot G_{E}$. Leider ist $M > 0$
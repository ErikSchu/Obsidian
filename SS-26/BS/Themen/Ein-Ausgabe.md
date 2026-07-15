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

#### E/A.Einzelpuffer

- ***Einlesen***
	- Daten können vom System entgegengenommen werden, auch wenn der Leserprozess noch nicht `read` aufgerufen hat.
	- Bei Blockgeräten kann der näch
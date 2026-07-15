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


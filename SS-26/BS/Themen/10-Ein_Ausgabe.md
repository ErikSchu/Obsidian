---
kurs: Betriebssysteme
dozent: Prof. Peter Ulbrich
themengebiet:
datum: 15.07.2026
tags:
  - bs
  - io
---
>[!note] #### Wiederholung: Betriebsmittel 
>- Aufgaben des Betriebssystems: 
>	- *Verwaltung der Betriebsmittel* des Rechners
>	- Schaffung von *Abstraktionen*, die Anwendungen einfachen & effizienten Umgang mit Betriebsmitteln erlauben
>___
>- **Bisher:**
>	- *Prozesse*
>	- *Arbeitsspeicher*
>___
>- **Jetzt:** *E/A-Greäte*
>	- Verwaltung von Peripheriegeräten
>	  ![[Pasted image 20260718110039.png]]

___
# Ein-/Ausgabe-Hardware
## Anbindung von E/A-Geräten
![[Pasted image 20260718110626.png]]
Ein-/Ausgabegeräte werden über **Controller** an den Systembus angebunden. Die Programmierung erfolgt über **E/A-Register** auf den Controllern. 

>[!example] Beispiele
>***PC-Tastatur***
>- **serielle zeichenweise** Kommunikation
>	- Tastatur ist “intelligent” (besitzt *eigenen Prozessor*)
>	  ![[Pasted image 20260718111039.png]]
>	- **Aufgaben der Software**
>		- Initialisierung des Controllers
>		- Abholen der Zeichen von der Tastatur
>		- Abbildung der `Make`- und `Brake`-Codes  auf ASCII 
>		- Senden von Kommandos
>___
>***CGA-Videocontroller***
>- Kommunikation über **Videosignal**
>	- Umwandlung des Sipeicherinhalts in ein Bild ($80$ x $25$ Z.)
>	  ![[Pasted image 20260718111636.png]]
>	- **Aufgaben der Software**
>		- Initialisierung des Controllers
>		- Bildschirmspeicher mit den gewünschten Zustandscodes füllen
>		- Steuerung der Position des Cursors
>		- Cursor an- und abschalten
>___
>***IDE-Plattencontroller***
>- Kommunikation über **AT-Befehle**
>	- *vlockweiser Wahlfreier Zugriff* auf Datenblöcke
>	  ![[Pasted image 20260718112032.png]]
>	- **Aufgaben der Software**
>		- AT-Befehle in Register schreiben
>		- Sektorpuffer füllen/leeren
>		- Auf die Unterbrechungen reagieren
>		- Fehlerbehandlung
>___
>***Ethernet-Controller***
>- **serielle paketbasierte Buskommunikation**
>	- Pakete haben eine Variable Größe und enthalten Adressen
>	  ![[Pasted image 20260718112705.png]]
>	- **Aufgaben der Software**
>		- Bereitstellen der Daten bzw. Puffer
>		- Initialisierung der Controllerregister
>		- auf die Unterbrechungen reagieren
>		- Fehlerbehandlung

## Geräteklassen

- ***zeichenorientierte Geräte***
	- Tastatur, Drucker, Modem, Maus, …
	- meist rein **sequentieller Zugriff**, selten wahlfreie Positionierung 

- ***blockorientierte Geräte***
	- Festplatte, Diskette, CD-ROM, DVD, Bandlaufwerke, …
	- meist **wahlfreier blockweiser Zugriff** *(random access)*

-  andere Geräte passen weniger gut in dieses Schema
	- *GPU* (insb. 3D-Beschleunigung)
	- *Netzwerkkarten* (Protokolle, Adressierung, Broadcast/Multicast, Nachrichtenfilterung, …)
	- *Zeitgeberbaustein* (einmalige oder periodische Unterbrechungen)

## Unterbrechungen

- signalisieren, das Software aktiv werden muss
- Ablauf einer Unterbrechung auf Hardwareebene ![[Pasted image 20260718113645.png]]
- Software kann **IRQ-Behandlung unterdrücken**. x86:
	- `sti` → erlauben
	- `cli` → unterdrücken

## Direct Memory Access *(DMA)*

- wird von komplexen Controllern benutzt, um Daten unabhängig von der CPU un den bzw. aus dem Hauptspeicher zu transferieren.
- Durchführung eines **DMA-Transfer**s:  ![[Pasted image 20260718114139.png]]

___

# Geräteprogrammierung
## Ein-/Ausgabeadressraum
- Zugriff auf *Controller*-Register und *Controller*-Speicher erfolgt je nach Systemarchitektur
  1. **separater E/A-Adressraum** (anzusprechen über spezielle Maschienen)
     ![[Pasted image 20260718114912.png]]
  2. **gemeinsamer Adressraum** (*Memory-Mapped I/0*)
     ![[Pasted image 20260718115044.png]]
  3. **hybride Architektur**
     ![[Pasted image 20260718115143.png]]

## Arbei

___
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

>[!note] Leistungsabschätzung
>Eine einfache Rechnung zeigt den Leistungsgewinn bei wiederholten blockweisen Lesen mit anschließender Verarbeitung:
>	$T$: Dauer der Leseoperation
>	$C$: Rechenzeit für die Verarbeitung
>	$M$: Dauer des Kopiervorgangs (Systempuffer → Benutzerprozess)
>	$G$: Gesamtdauer für Lesen und Verarbeiten eines Blocks
>- **ohne Puffer:** $G_{0} = T + C$
>- **mit Puffer:** $G_{E} =\text{max}(T, C) + M$
>  ___
>Mit $T \approx C$ und $M \approx 0$ wäre $G_{0} \approx 2 \cdot G_{E}$. Leider ist $M > 0$

#### E/A-Wechselpuffer

- ***Einlesen***
	- Während Daten vom E/A-Gerät in den einen Puffer transferiert werden, kann der andere Pufferinhalt in den Empfängeradressraum kopiert werden.
	  ![[Pasted image 20260715165244.png]]

- ***Schreiben***
	- Während Daten aus einem Puffer zum E/A-Gerät transferiert werden, kann der andere Puffer bereits mit neuen Daten aus dem Senderadressraum gefüllt werden.

>[!note] Leistungsabschätzung
>Mit einem Wechselpuffer kann eine Leseoperation parallel zur Kopieroperation und Verarbeitung erfolgen
>- **ohne Puffer:** $G_{0} = T + C$
>- **mit Puffer:** $G_{E} =\text{max}(T, C) + M$
>- **mit Wechselpuffer:** $G_{W} = \text{max}(T, C + M)$
>___
>Mit $C + M \le T$ könnte das Gerät zu $100\text{\%}$ ausgelastet werden.

#### E/A-Ringpuffer

- ***Einlesen***
	- Viele Daten können gepuffert werden, auch wenn der Leserprozess nicht schnell genut `read`-Aufrufe tätigt.
	  ![[Pasted image 20260715170013.png]]

- ***Schreiben:***
	- Ein Schreiberprozess kann mehrfach `write`-Aufrufe tätigen, ohne blockiert werden zu müssen. 

### Diskussion: E/A-Puffer

- **E/A-Puffer entkoppeln** die E/A-Operationen der Nutzerprozesse vom Gerätetreiber
	- *Kurzfristig* lässt sich eine erhöhte Ankunftsrate an E/A-Aufträge bewältigen.
	- *Langfristig* bleibt auch bei noch so vielen Puffern ein Blockieren von Prozessen (oder Verlust von Daten) nicht aus.

- Puffer haben ihren Preis:
	- Verwaltung der Pufferstruktur
	- Speicherplatz 
	- Zeit für das Kopieren

- In komplexen Systemen wird teilweise *mehrfach* gepuffert
	- z.B.: Schichten von Netzwerkprotokollen

___

## E/A-Scheduling

#### FIFO
- Referenzfolge (Folge von Spurnummern): $98, 183, 37, 122, 14, 124, 65, 67$
- Aktuelle Spur: $35$
  ![[Pasted image 20260718001633.png|672]]
	- $\sum\text{Spurwechsel} = 640$
	- Weite Bewegungen des Schwenkarms: **mittlere Bearbeitungsdauer lang**! 

#### SSTF *(Shortest Seek Time First)*
- Auftrag mit *kürzester* Positionierungszeit vorgezogen
- Dieselbe Referenzfolge (Annahme: Positionierungszeit proportional zum Spurabstand)
  ![[Pasted image 20260718002154.png]]
	- $\sum\text{Spurwechsel} = 236$
	- Ähnlich wie [[04-Ablaufplanung|SJF]] kann auch SSTF zu **Aushungerung** führen

#### Elevator
- Bewegung des Plattenarms in eine Richtung bis keine Aufträge mehr vorhanden sind
- Gleiche Referenzfolge (Annahme: bisherige Kopfbewegung Richrung $0$)
  ![[Pasted image 20260718002637.png]]
	- $\sum\text{Spurwechsel} = 208$
	- Neue Aufträge miterledigt ohne zusätzliche Positionierungszeit 
	- **keine Aushungerung**, *lange Wartezeiten* aber nicht ausgeschlossen 

### Diskussion

- Platten sind intelligente Geräte
	- Physikalische Eigenschaften werden verborgen (*Logische Blöcke*)
	- Platten weisen riesige Caches auf
	- *Solid State Disks* enthalten keine Mechanik mehr 
	→ E/A-Scheduling verliert langsam an Bedeutung
	→ Erfolg eiener Strategie schwerer vorherzusagen

- Trotzdem ist E/A-Scheduling **noch immer sehr wichtig**
	- CPUs werden immer schneller, Platten kaum
	- *Linux* implementiert z.Z. zwei verschiedene Varianten der *Fahrstuhlstrategie* (+ FIFO für “Platten” ohne Positionierungszeit)_
		- ***DEADLINE*** -  Bevorzugung von Leseanforderungen (kürzere Deadlines)
		- ***COMPLETELY FAIR*** -  Prozesse erhalten gleichen Anteil an E/A-Bandbreite

___

>[!list] ## Zusammenfassung
>- E/A-Hardware ist sehr unterschiedlich
>	- teilweise auch “hässlich” zu programmieren
>___
>- Die Kunst des Betriebssystembaus besteht darin, …
>	- trotzdem **einheitliche und einfache Schnittstellen** zu definieren
>	- **effizient** mit der Hardware umzugehen
>	- CPU und E/A-**Geräteauslastung zu maximieren**
>___
>- Gerätetreibervielfalt ist für den Erfolg des BS extrem wichtig. 
>	- Bei Systemen wie Linux und WIndows sind die Gerätetreiber das weitaus größte Subsystem.


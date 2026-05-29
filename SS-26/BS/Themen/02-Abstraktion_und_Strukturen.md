*15.04.2026*
https://sys-sideshow.cs.tu-dortmund.de/lehre/ss26/bs/decker/02-Abstraktionen-deck.html#/section

## Geschichte

- **Lochkarte** *1725 bis 1970er* als vielseitiger Speicher $\leadsto$ ==Bibliothek==
  
- Erste **Universalrechnre** in den 1940ern (ENIAC)
  
- **Serielle Verarbeitung** ab *1945* ⇒ in ==Maschienencode==, minimale Auslastung der CPU wegen langsamer E/A, erste ==Programmbibliotheken== (Binder, Lader, Debugger, Gerätetreiber, ... )
  
- **Stapelsysteme** ab *1955* zur reduktion manueller Eingriffe (*Monitor* bleibt dauerhaft im Speicher, während er ein Anweisungsprogramm ausführt) ![[Pasted image 20260415173522.png]]
	- **Timer** liefert *Interrupts*
	- **Traps** für Fehlerhafte PRogramme
		- *Schutzregister* (Fence Register) realisieren Primitiven ==Speicherschutz==
		- *Privilegierter Arbeitsmodus* der CPU (Deaktivierung des Schutzgatters // Ein-/Ausgabe
  
  - **I/O Bottleneck:** CPU schneller als IO
	  - *Off-line processing* entkoppekt Ein-/Ausgabe (Bandlaufwerke, Paralellisierung duch mehrer "Satellitenrechner")
	  - *Spooling* (Spulen, **Puffern**) mit Plattenlaufwerken (wahlfreier Zugriff) ⇒ **D**irect **M**emory **A**cces und **Unterbrechungen** → Parallelisierung vn Ein-/Ausgabe und Regeln für Prozessorzuteilung

- **Mehrprogrammrechner** ab *1965*: CPU bearbeitet mehrere Aufträge gleichzeitig

>[!TIP] Das Betriebssystem wird immer komplexer
>- Umgang mit nebenläufigen I/O-Aktivitäten
>- **Verwaltung des Arbeitsspeichers** für mehrere Programme
>- Interne verwaltung von *Programmen in Ausführung* (**Prozesse**)
>- **Prozessorzuteilung** (scheduling)
>- Mehrbenutzerbetrieb: **Sicherheit** und Abrechnung (accounting)

- **Dialogbetrieb** ab *1970*: Tastatur, Monitor, Maus als neue I/O-Geräte, ...


## UNIX-Systemstruktur
![[Pasted image 20260501143054.png]]

## Windows-Systemstruktur
![[Pasted image 20260501143134.png]]

___

# Systemabstraktionen
## Prozesse
*... sind Programme in Ausführung.*

>[!example] Prozesskontrollblock (PCB)
>- **Speicher:** Code-, Daten und Stapelsegment *(text, data, stack)*
>- **Prozessorregisterinhalte**
>	- Instruktionszeiger
>	- Stapelzeiger
>	- Vielzweckregister 
>	- ...
>- Prozesszustand
>- Benutzerkennung
>- Zugriffsrechte
>- Aktuell belegte Betriebsmittel
>	- Daten, I/O-Geräte, u.s.w.
>- ...

#### Prozessmodell
![[Pasted image 20260501143850.png]]


### CPU-Zuteilung (Scheduling)
- geordneter Ablauf konkurrierender Prozesse
- Grundsätzliche Fragestellungen
	- Welche Arten von Ereignissen führen zur *Veränderung*?
	- In welcher *Reihenfolge* sollen Prozesse Ablaufen?
- Ziele eines **Scheduling-Algorithmus**
	- benutzerorientiert, z.B. kurze Antwortzeiten
	- systemorientiert, z.B. optimale CPU-Auslastung
	⤷ es können nie alle Bedürfnisse erfüllt swerden

### Prozesssynchronisation 
Beispiel: unkoordinierter Zugriff
``` c
// Prozess A
...
print("Hallo Otto\n");
print("Ruf mich an.\n");
print("Tel.: 420815\n");
...

// Prozess B 
print("Karl-");
print("Ich mag dich.\n");

// Ausgabe
"Hallo Karl-Otto"
"Ruf mich an."
"Ich mag dich."
"Tel.: 420815"
```
- Ursache: *Kritische Abschnitte*
- Lösungsmöglichkeit: **gegenseitiger Ausschluss** *(Mutex-Abstraktion)*
  ```c
  ...
  lock(&printer_mutex);
  [...]
  unlock(&printer_mutex);
  ...
  ```
  ⤷ wenn sich ein Prozess zwischen (un)lock befindet, kann der andere lock nicht passieren bis der kritische Abschnitt wieder frei ist
	⤷ Problem: Verklemmungen (Deadlocks) → vgl. Rechts vor Links

#### Interprozesskommunikation
... ermöglicht Zusammenarbeit mehrerer Prozesse
- **local:** z.B. Drucker-Deamons, X-Server
- **remote:** z.B. Web-/Datenbank-/ftp-Server
  ⤷ *"Client/Server-Systeme"*

#### Abstraktion / Programmiermodelle
- **Gemeinsamer Speicher**
	- mehrere Prozesse gleichzeitig auf dem selben Speicherplatz
	- zusätzliche Synchronisierung notwendig
- **Nachrichtenaustausch**
	- emantik eines Faxes (verschickt wied Kopie der Nachricht)
	- synchron oder asynchron


___

# Speicherverwaltung

## Speicherhierarchie
![[Pasted image 20260501153602.png]]

- **Adressbildung**
	- *logische Adressen* auf physikalische Adressen
	- Gestattete *Relokation* von Code & Daten

- **Platzierungsstrategie**
	- *Kompaltifizierung* / *Fragmentierungsprobleme*

- **Ersatzungsstrategie**
	- sinnvolle Auslagerung des Speicherbereiches

## Hintergrundspeicher
![[Pasted image 20260501154046.png]]
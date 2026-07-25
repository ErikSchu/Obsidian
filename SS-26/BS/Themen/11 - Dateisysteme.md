#bs

>[!cite] Wiederhohlung: Betriebsmittel
>- BS hat folgende Aufgaben
>	- Vergaltung der Betriebsmittel
>	- Schaffung von Abstraktionen, die Anwendungen einen einfachen und effizienten Umgang mit Betriebsmitteln erlauben
>- Bisher
>	- **Prozesse**
>	- **Arbeitsspeicher**
>	- **E/A-Geräte** (insb. Blockorientiert)
>- Heute: **Dateisysteme**
>	- Organisation des Hintergrundspeichers
>___
>- ***Hintergrundspeicher***
>  ![[Pasted image 20260724100419.png]]

# Dateien

## Speicherung von Dateien

- benötigen oft **mehr als einen Block** auf der Festplatte
	- Welche Blöcke werden für die Speicherung einer Datei verwendet? ![[Pasted image 20260724100542.png]]

## Knotinuierliche Speicherung

- Datei wird in Blöcken mit aufsteigenden Blocknummer ngespeichert
	- Nummer des ersten Block und # Folgeblöcke muss gespeichert werden, *z.B.* Start: Block 4; Länge 3. ![[Pasted image 20260724100751.png]]

- ***Vorteile:***
	- Zugriff auf alle Blöcke mit **minimaler Positionierzeit** des Schwenkarms
	- Schneller direkter Zugriff auf **bestimmte** Dateiposition
	- Einsatz *z.B.* bei nicht modifizierbaren Dateisystemen wie auf CDs/DVDs

#### Probleme
- **Finden des freien Platzes** auf der Festplatte
	- Menge aufeinanderfolgender & freier Plattenblöcke
- **Fragmentierungsproblem**
	- Verschnitt: nicht nutzbare Plattenblöcke; analog zur Speicherverwaltung
- Größe bei neuen Dateien oft nicht im Voraus bekannt
- **Erweitern** ist problematisch
- **Umkopieren**, falls kein freier angrenzender Block mehr verfügbar

## Verkettete Speicherung

- Blöcke einer Datei sind **verkettet** ![[Pasted image 20260724101328.png]]
	- *z.B.* Commodore-Systeme
		- Blockgröße 256 Bytes
		- erste 2 Bytes bezeichnen Spur- & Sektornummer des nächsten Blocks
		- wenn Spurnummer == 0 → letzter Block
		- 254 Bytes Nutzdateien 
	→ Datei kann **vergrößert und verkleinert** werden
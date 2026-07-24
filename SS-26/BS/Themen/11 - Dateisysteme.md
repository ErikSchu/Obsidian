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

- Datei wird in Blöcken mit aufsteigenden Blocknummer ngespeichert
	- Nummer des ersten Block und # Folgeblöcke muss gespeichert werden, *z.B.* Start: Block 4; Länge 3. ![[Pasted image 20260724100751.png]]

- ***Vorteile:***
	- Zugriff auf alle Blöcke mit **minimaler Positionierzeit** des Schwenkarms
	- Schneller direkter Zugriff auf **b**

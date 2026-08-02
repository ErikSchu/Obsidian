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

#### Probleme
- **Speicher für Verzeigerung** geht von Nutzerdaten im Block ab
	- Ungünstig im Zusammenhang mit *Paging*:
	  Seite würde immer aus Teilen von *zwei Plattenblöcken* bestehen
- **Fehleranfälligkeit**
	- Datei ist nicht restaurierbar, falls einmal *Verzeigerung fehlerhaft*
- **Schlechter direkter Zugriff** auf bestimmte Dateiposition
- **Häufiges Positionieren** des Schreib-/Lesekopfs bei verstreuten Datenblöcken

### FAT *(File Allocation Table)*
- Verkettung wird in **seperaten Plattenblöcken** gespeichert
![[Pasted image 20260802125515.png]]
- ***Vorteile***
	- kompletter Inhalt des Datenblocks ist nutzbar
	- mehrfache Speicherung der FAT möglich → Einschränkung der Fehleranfälligkeit

#### Probleme
- **Zusätzliches Laden** mindestens eines Blocks
	- Caching der FAT zur Effizienzsteigerung nötig
- Laden unbenötigter Informationen
	- FAT enthält Verkettung für alle Dateien
- **Aufwändige Suche** nach dem zugehörigen Datenblock bei bekannter Position in der Datei
- **Häufiges Positionieren** des Schreib-, Lesekopfs bei verstreuten Datenblöcken 

>[!note] ### Diskussion: *Chunks*/*Extents*/*Clusters*
>- ***Variation:***
>	- Unterteilen einer Datei in kontinuierlich **gespeicherte Folgen von Blöcken** (*Chunk*, *Extend* oder *Cluster* genannt)
>	- Reduziert die Zahl der Positionierungsvorgänge
>	- Blocksuche wird linear in Abhängigkeit von der Chunk-Größe beschleunigt
>___
> - ***Probleme:***
> 	- zusätzliche Verwaltungsinformationen
> 	- Verschnitt
> 		- feste Größe: **innerhalb** einer Folge (interner)
> 		- variable Größe: **außerhalb** der Folgen (externer)
>___
> - Wird eingesetzt, bringt aber keinen fundamentalen Fortschritt


## Indiziertest Speichern

- ***Spezieller Plattenblock*** (Indexblock) enthält Blocknummern der Datenblöcke einer Datei:![[Pasted image 20260802131449.png]]
- **Problem:** Feste Anzahl von Blöclen im Indexblock
	- Verschnitt bei kleinen Dateien
	- erweiterung nötig für große Dateien 

### Unix-Inode
![[Pasted image 20260802131623.png]]

### Diskussion
- Einsatz von **mehreren Stufen** der Indizierung
	- Inode benötigt sowieso einen Block auf der Platten 
	  (Verschnitt unproblematisch bei kleinen Dateien)
	- durch mehrere Stufen der Indizierung auch größere Dateien adressierbar
- ***Nachteil:*** mehrere Blöcke müssen geladen werden (nur bei langen Dateien)


## Baumsequentielle Speicherung

- Wird bei Datenbanken zum effizienten Auffinden eines Datensatzes mit Hilfe eines Schlüssels eingesetzt
	- Schlüsselraum darf dünn besetzt sein
- Kann auch verwendet werden, im Datei-*Chunks* mit bestimmtem Datei-*Offset* aufzufinden
	- z.B. NTFS, ReiserFS, Btrfs, IBMs JFS2-Dateisystem (B$^+$-Baum)
	![[Pasted image 20260802132432.png]]

___

# Freispeicherverwaltung

![[Pasted image 20260802132659.png]]

Ähnlich wie Verwaltung von freiem Hauptspeicher 

- ***Bitvektoren*** zeigen für jeden Block Belegungen an
- oder ***verkettete Listen*** repräsentieren freie Blöcke
	- Verkettung kann in den freien Blöcken vorgenommen werden.
	- **Optimierung:** Aufeinanderfolgende Blöcke werden nicht einzeln aufgenommen, sondern am Stück verwaltet.
	- **Optimierung:** Ein freier Blocj enthält viele Blocknummern weiterer freier Blöcke, und evtl. die Blocknummer eines weitern Blocks mit den Nummern freier Blöcke.
- ***Baumsequentielle Speicherung*** freier Blockfolgen
	- erlaubt schnelle Suche nach freier Blockfolge bestimmter Größe
	- Anwendung z.B. im SGI XFS

___

# Verzeichnisse 

## Verzeichnis als Liste 

- Einträge gleicher Länge hintereinander in einer Liste, z.B. 
	- **FAT** *File systems* (**VFAT** nutzt mehrere Einträge für lange Dateinamen) ![[Pasted image 20260802133937.png]]
	- **UNIX** *System V.3* ![[Pasted image 20260802134122.png]]
- ***Probleme:*** 
	- Suche nach bestimmtem Eintrag muss linear erfolgen
	- Bei Sortierung der Liste: Schnelles Suchen, Aufwand beim Einfügen

### Einsatz von *Hash*-Funktionen

- Funktion bildet Dateinamen auf einen Index in die Katalogliste ab
	- schneller Zugriff auf den EIntrag möglich (kein lineares Suchen)
- Einfaches (aber schlechtes) Beispiel: $\Sigma \text{ mod } N$![[Pasted image 20260802161401.png]]
- ***Probleme:***
	- Kollisionen 
	  (mehrere Dateinamen werden auf denselben Eintrag abgebildet)
	- Anpassung der Listengröße, wenn Liste voll

### Variabel lange Listenelemente

- Beispiel: 4.2 BSD, System V Rel. 3, u.a. ![[Pasted image 20260802161554.png]]
- ***Probleme:***
	- Verwaltung von freien Einträgen in der Liste
	- Speicherverschnitt (Kompaktifizieren, etc.)


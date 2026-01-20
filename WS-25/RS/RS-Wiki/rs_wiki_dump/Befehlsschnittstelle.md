**Beispiel: RISC-V** (~ **R**educed **I**nstruction **S**et **C**omputer **V**) VOrgestellt im Jahr 2010 (mit 32 Bits)

#### Warum RISC-V?
- Weitgehend sauberer und klarer Befehlssatz
- Kein historischer Ballast
- Basis der richtungsweisenden Bücher von Hennessy/Patterson
- Simulation verfügbar
- RISC-V-Prozessoren werden realisiert (z.B. SiFive)

### Begriffe
- **RISC-V-Befehle** sind elementare Anweisungen an die RISC-V-Maschiene (z.B. SiFive)
- Ein **RISC-V-Maschienenprogramm** ist eine konkrete Folge von RISC-V-Befehlen
- Die **RISC-V-Maschienensprache** ist die Menge möglicher *RISC-V-Maschienenprogramme*
- Entsprechendes gilt für die Assemblerprogramm-Ebene
- Vielfach keine Unterscheidung zwischen beiden Ebenen

___
## Eigenschaften des Von-Neumann-Rechners

Wesentliche Merkmale der heute Üblichen Rechner, die auf dem Prinzip des **Von-Neumann-Rechner**s basieren:

1. Einteilung des Speichers in Zellen Gleicher Größe, die Über ***Adressen*** angesprochen werden können

2. Verwendung von speicherprogrammierbaren Programmen

3. Speicherung von Programmen und Daten in demselben Speicher

---

## [[RISC-V-Assembler-Befehle]]

___
## Darstellung von Befehlen im Rechner

Zergliederung eines Befehlswortes in **Befehlsfelder**; Jede benutzte Zergliederung heißt **Befehlsformat**;

*Beispiele*

|   Größe[Bit]   | Größe\[Bit\] |     7     |  5  |  5  |   3    |    5     | 7   |
| :------------: | :----------: | :-------: | :-: | :-: | :----: | :------: | --- |
|   Arithmetik   |   Format R   |  funct7   | rs2 | rs1 | funct3 |    rd    | op  |
| Immediate (lw) |   Format I   | imm(11:0) |     | rs1 | funct3 |    rd    | op  |
|     Store      |   Format S   | imm(11:5) | rs2 | rs1 | funct3 | imm(4:0) | op  |
⤷ function(funct): kodiert Befehlsvariante
⤷ Operationscode(op): kodiert Befehl

___

## Speicherung von Befehlen im Rechner

**Assemblerprogramm**
```Assembler
lw x2, 100(x0)
lw x3, 104(x0)
add x3, x2, x3
sw x3. 108(x0)
```

**Übersetzung** des Assemblerprogramm in ein *ladbares Maschienenprogramm* ist **Aufgabe des *Assemblers***.
`funct3`
`funct7`

Hauptspeicher (Speicher) 
![[Pasted image 20260106104255.png]]

___

## Zusammenfassung

- ***Schichtmodell***
	- Programme in hoherer Programmiersprache
	- Assemblerprogramme 
	- Maschienenprograme
	- RT-Verhalten/-Strukturen
	- Gatter

- ***Unterscheidung*** zwischen *Befehlen*, *Programmen*, *Sprachen*

- Exemplatische ***Betrachtung*** der *RISC-V-Assembler- & Maschienensprache*
	- `add`-, `lw`-, `sw`-Befehle; RT-Semantik
	- Speichermodell 
	- Darstellung von Befehlen
	- Prinzipien der Von-Neumann-Maschiene
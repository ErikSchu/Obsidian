#rs 

## Arithmetische und Transportbefehle

#### 1. Beispiel: Addition
**Allgemeines Format:**
` add a, b, c ` mit $a, b, c \in x_{0}, \dots, x_{31}$ (*32 Bit lange Register*)
` a ` ist hier das Zielregister

**Beispiel:**
` add x3, x2, x1 `

| **Register ("Reg")** | **Inhalt** |
| -------------------- | ---------- |
| x0                   | "0...0"    |
| x1                   | *5*        |
| x2                   | ***6***    |
| x3                   | **11**     |
| $\vdots$             |            |
| x31                  |            |
⤷ ` x0 ` ist ständig 0.

---

## Simulation des RISC-V-Befehlssatzes mit RARS

Simulator **RARS** (erfordert Java)
Warum **Simulation statt ausführung des Intel-Befehlssatzes**?
- Möglichkeit der Benutzung des RISC-V-Befehlssatzes
- Keine Gefährdung des laufenden Systems
- Bessere Interaktionsmöglichkeiten
- RARS läuft auf verschiedenen Plattformen 
⤷ INSTALLATION DRINGEND EMPFOHLEN

---

## Semantik: per Register-Transfer(-Verhaltens)-Notation

- **Argumente oder Zeile:** Register oder SPeicher, z.B. ` Reg[3]; PC; Reg[31] `

- **Zuweisung** mittels $:=$, z.B. ` PC := Reg[31] `

- **Konstante Bitvektoren**: Einschluss in ", z.B. ` "01010100011" `

- **Selektion von einzelnen Bits:** runde Klammern, z.B. ` PC(15:0) ` ⤷ VDHl "downto" statt ':', alte Schreibweise: '.' vor '('

- **Knotenaktion (Aneinanderreihung)** mit &, z.B. ` (x1 & x2); ` 

` PC := PC(31:28) & I(25:0) & "00" `


#### Semantik des Additionsbefehls
**Beispiel**
` add x3, x2, x1 # Reg[3] := Reg[2] + Reg[1] `
⤷ *#* leitet in der Assemblernotation einen *Kommentar* ein
⤷ Register Speichern (Teil des) aktuellen Zustands; **add**-Befehl veranlasst *Zustandstransformation*

---

## Addition fpr 2k-Zahlen oder für vorzeichenlose Zahlen? 

Muss der **add**-Befehl "linkestes" Bit als Vorzeichen bertachten?
	→ *Nein*, bei 2k-Zahlen und bei Betragszahlen kann jede Stelle des Ergebnisses gemäß der *Gleichungen für Volladdierer* bestimmt werden, unabhängig davon, ob die Bitfolgen als 2k-Zahlen oder als Betragszahlen zu interpretiren ist (siehe [[Repraesentation_ganzer_Zahlen]]).
	Es *reicht ein Additionsbefehl* zur Erzeugung der Ergebnis-Bitvektoren für beide Datentypen aus. Allerdings Unterschiede hinsichtlich der Behandlung von Bereichsüberschreitungen.


## Das Speichermodell der RISC-V-Architektur

**Registerspeicher ` Reg `** ![[Pasted image 20251215223322.png]]

**Hauptspeicher ` Speicher `** ![[Pasted image 20251215223428.png]]

\+  spez. Register (PC)

---

## load  word-Befehl

**allg. Form:** ` lw ziel,offset(reg) ` mit $\text{ziel, reg} \in x_{0}\dots x_{31}$, $\text{offset:}$ Konstante $\in -2^{11} \dots 2^{11}-1$, deren Wert beim Laden des Programms bekannt sein muss, bzw. deren Bezeichner.

*Beispiel:* ` lw x8, 12(x19) # Reg[8] := Speicher [12+Reg[19]] ` ![[Pasted image 20251215224247.png]]


## store  word-Befehl
**allg. Form:** `sw qual,offset(reg)` mit $\text{quel, reg} \in x_{0} \dots x_{31}$, $\text{offset}$: Konstante $\in -2^{11} \dots 2^{11}-1$, derem Wert beim Laden des Programms bekannt sein muss, bzw. deren Bezeichner. 

*Beispiel:* ` sw x8, 8(x19) # Speicher[8+Reg[19]] := Reg[8] `
![[Pasted image 20260106102958.png]]
![[Pasted image 20251215224847.png]]

---

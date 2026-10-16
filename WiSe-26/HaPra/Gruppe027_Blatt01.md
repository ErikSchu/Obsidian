## 1.3
###### (a)
- `ghdl -s` "syntax":
  Prüft den Code auf grammatikalische und strukturelle RIchrigkeit, ohne Objektdateien zu erzeugen oder die interne Bibliotheksdatenbank zu aktualisieren.
- `ghdl -a`  "analysis": 
  Analysiert den Code auf Syntaxfehler und kompiliert ihn. 
- `ghdl -e` "elaboration":
  Zwischen Analyse (a) und eigentlicher Simulation (r). Elaboriert angegebene Entities (hier 'test_file'). Dabei werden alle Komponenten zu einem Gesamtmodell zusammengesetzt.
- `ghdl -r` "run":
  Elaborierte Simulation wird ausgefühlt.
	⤷ `-- vcd = testbench.vcd` "value change dump": 
	  Standartformat für Wellenformen
- `gtkwave testbench.vcd` startet das Programm gtkwave und öffnet die Datei testbench.vcd, die davor erzeugt wurde. Dabei zeigt gtkwave nur an, was die vorherige Simulation aufgezeichnet hat. 
  ![[Pasted image 20261016141603.png]]
 ___

## 1.4
###### (a)
`not_gate` und `not_result` haben immer den gleichen Wert wie das Signal `c`.
###### (b)
`c` hat den gleichen Wert wie `u`.
###### (c)
Da dem Python-Skript, 
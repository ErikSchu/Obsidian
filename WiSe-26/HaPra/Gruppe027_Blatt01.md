# Gruppe 027 - Blatt 1
Fabio Viegas da Silva
Erik Schulze
enumerate
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

![[Pasted image 20261016150629.png]]
###### (b)
Das Signal `c` hat durchgängig gleichen Wert `u` ("undefiniert") und reagiert nicht auf das Signal `a`, das bei $10\text{ ns}$ von $0$ auf $1$ wechselt. Im ersten Durchlauf hingegen, war `c` die Inverse von `a`.
###### (c)
Da dem Python-Skript dieses Mal die Datei `notgate.vhdl` nicht übergeben wurde, existiert in der Simulation die Komponente `not_g` nicht, weswegen `c` den undefinierten Anfangswert beibehält.
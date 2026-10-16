## 1.3 (a)
- `ghdl -s` "syntax":
  Prüft den Code auf grammatikalische und strukturelle RIchrigkeit, ohne Objektdateien zu erzeugen oder die interne Bibliotheksdatenbank zu aktualisieren.
- `ghdl -a`  "analysis": 
  Analysiert den Code auf Syntaxfehler und kompiliert ihn. 
- `ghdl -e` "elaboration":
  Zwischen Analyse (a) und eigentlicher Simulation (r). Elaboriert angegebene Entities (hier 'test_f)
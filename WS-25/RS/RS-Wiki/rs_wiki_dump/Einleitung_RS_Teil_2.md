"Die Wissenschaft Informatik befasst sich mit der **Darstellung**, Speicherung, Übertragung und ***Verarbeitung*** von Informationen." ~Gesellschaft für Infirmatik

⤷ **Darstellung von informationen: z.B. Zahlendarstellung in RS, Teil 1**
⤷ ***Verarbeitung von Informationen: Inhalt von RS, Teil 2***

## Motivation
- Jede Programmausführung bedarf einer zu Ausführung fähigen Hardware → **Ausführungsplattformen / execution platforms**
- **Platform-based design** ist ein Ansatz für viele Anwendungen (Handys, Autos, ...)
- Plattformen sind *nichr immer ideal* (z.B. führen Anwengungen nicht in 0 Zeit mit 0 Energie aus)
⇒ Grundlegendes Verständnis für nicht-ideales Verhalten ist wichtig
	⇒ Wir beschäftigen uns mit ***Ausführungsplattformen***

![[Pasted image 20251215213546.png]]


# Thema RS Teil 2

- **Ziel:** Verständnis der Arbeitsweise von Rechnern einschl.
	- der Programmierung von Rechnern
	- des Prozessors
	- der Speicherorganisation
	- des Anschlusses von Peripherie
	- Anwendungen bei eingebetteten Systemen

- **Stil:**
	- Betonung des Skript
	- Integration mit praktischen Übungen 
	- Einsatz eines Simulators
	- Buch von Hennessy/Petterson: Computer Organization and Design: The Hardware/Software Interface RISC-V Edition, 2018
	- Weitere Bücher: siehe Literaturverzeichnis im Skript

## Abstraktionsebenen

| Ebene                                        | Beispiel                        | Ausführung         | Modul |
| -------------------------------------------- | ------------------------------- | ------------------ | ----- |
| Übliche Programmiersprache                   | `for`, `while`, `if`            | Compiler           | DAP   |
| ***Assemblerprogramm-Ebene***                | `bne x1,x2,loop`                | Compiler/Assembler | RS2   |
| Maschinenprogramm-Ebene/Befehlsschnittstelle | `01010...10₂`                   | Assembler          | RS2   |
| Reg-Transfer-Verhaltensebene                 | `Reg[2]:=Reg[3]`                | –                  | RS2   |
| Reg-Transfer-Strukturebene                   | Addierer, Multiplexer, Register | –                  | RS2   |
| Gatter-Ebene                                 | `f=a ∨ bc`                      |                    | RS1   |
| Transistorebene                              | –                               | –                  | ETKT  |

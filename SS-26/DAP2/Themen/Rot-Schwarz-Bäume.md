## Worum geht es?
- binäre Suchbäume sind nur dann effizient, wenn sie von geringer Höhe sind
- red black trees sind eine Variante, die sich selbst "trimmt"
- die Höhe bei $n$ Elementen ist dabei stets $O(\log n)$
- wir müssen dabei die Operationen `Insert` und `Delete` verändern

## Red black Regeln
- **RB1** - jeder Knoten ist entweder rot/schwarz gefärbt
- **RB2** - Wurzel ist schwarz 
- **RB3** - jeder 
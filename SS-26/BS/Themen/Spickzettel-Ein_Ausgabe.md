#bs

# E/A – Spickzettel

## Hardware
- E/A-Geräte hängen über **Controller** am Systembus; programmiert über **E/A-Register** des Controllers
- **Geräteklassen:**
  - **zeichenorientiert:** Tastatur, Drucker, Maus → meist sequentieller Zugriff
  - **blockorientiert:** Platte, CD/DVD, Band → wahlfreier blockweiser Zugriff (random access)
  - Sonderfälle: GPU, Netzwerk, **Zeitgeber** (einmalige/periodische Unterbrechungen)
- **Unterbrechungen (IRQ):** signalisieren, dass Software aktiv werden muss; x86: `sti` = erlauben, `cli` = unterdrücken
- **DMA:** Controller transferiert Daten **ohne CPU** zwischen Gerät und Hauptspeicher

## E/A-Adressraum
1. **separater E/A-Adressraum** (eigene Befehle)
2. **Memory-Mapped I/O** (gemeinsamer Adressraum)
3. **hybrid**

## Geräteprogrammierung – 3 Varianten
| | Prinzip | CPU-Last |
|---|---|---|
| **Polling** | aktives Warten auf `READY` | hoch (belegt CPU) |
| **Unterbrechung** | CPU wartet nicht, weckt Prozess | mittel |
| **DMA** | Controller macht Transfer selbst | gering |

## Unterbrechungen (Diskussion)
- **Kontextsicherung:** CPU sichert nur Minimum (Status, Rücksprungadr.); alle veränderten Register müssen von der Routine gesichert werden
- **Routine möglichst kurz** – sonst Verlust von Unterbrechungen (weitere IRQs werden i.d.R. unterdrückt)
- IRQs = **Quelle der Asynchronität** → Race Conditions im Kernel
- **Synchronisation:** IRQs hart sperren (`cli`/`sti`) vs. **mehrstufige Behandlung:** Prolog (asynchron) + Epilog (synchron) → UNIX: Top/Bottom Half, Linux: Tasklets, Windows: Deferred Procedures

## DMA (Diskussion)
- **DMA läuft am Cache vorbei** → Cache vorher zurückschreiben + invalidieren
- **DMA läuft am Speicherschutz (MMU) vorbei** → Anwender dürfen DMA-Controller nie direkt programmieren; Fehler extrem kritisch

## UNIX-Geräteabstraktion
- Geräte = **Spezialdateien** in `/dev`, angesprochen mit `read`/`write`
  - **Block-Devices** (Platten, Bänder) vs. **Character-Devices** (seriell, Drucker, Audio)
- **3-Tupel:** Gerätetyp + **Major Number** (Treiber) + **Minor Number** (Gerät im Treiber)
- Zugriffe: `open` → `read`/`write` (blockieren) / `lseek` (nur wahlfreier Zugriff) / `close`; Gerätespezifisches über **`ioctl`**

## Warten auf mehrere Geräte
- **Alt. 1:** nichtblockierend (`O_NDELAY` + Polling) → CPU-Verschwendung
- **Alt. 2:** **`select(nfds, readfds, writefds, errorfds, timeout)`** – blockiert bis min. 1 FD bereit; Ergebnis: nur noch die FDs, die deblockierten

## Pufferung
- ohne Puffer: Daten gehen verloren / Prozess blockiert / Prozess kann **nicht ausgelagert** werden
- Leistungsformeln ($T$: Lesezeit, $C$: Verarbeitung, $M$: Kopierzeit):
  - **ohne Puffer:** $G_0 = T + C$
  - **Einzelpuffer:** $G_E = \max(T, C) + M$
  - **Wechselpuffer:** $G_W = \max(T, C + M)$ → bei $C + M \le T$ Gerät zu 100 % ausgelastet
- **Ringpuffer:** viele Daten puffern, Schreiber blockiert nicht
- Puffer entkoppeln Prozess vom Treiber; Preis: Verwaltung, Speicher, Kopierzeit

## E/A-Scheduling (Plattenarm)
Referenzfolge: $98, 183, 37, 122, 14, 124, 65, 67$ (Start: Spur 35)
| Strategie | Prinzip | Spurwechsel | Risiko |
|---|---|---|---|
| **FIFO** | Reihenfolge der Aufträge | 640 | lange Wege |
| **SSTF** | kürzeste Positionierungszeit zuerst | 236 | **Aushungerung** (wie SJF) |
| **Elevator** | eine Richtung bis keine Aufträge, dann umkehren | 208 | keine Aushungerung, lange Wartezeiten möglich |

- Neue Aufträge werden beim Elevator ohne Zusatzbewegung miterledigt
- Platten sind intelligent (logische Blöcke, Caches, SSD ohne Mechanik) → Scheduling verliert an Bedeutung, bleibt aber wichtig
- Linux: **DEADLINE** (bevorzugt Lesen), **COMPLETELY FAIR** (gleicher Anteil E/A-Bandbreite)

## Merksätze
- Kunst des BS: einheitliche, einfache Schnittstellen + effizient mit HW umgehen + CPU- und Geräteauslastung maximieren
- Treiber = größtes Subsystem (Linux/Windows)

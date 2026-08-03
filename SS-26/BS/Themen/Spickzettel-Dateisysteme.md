#bs

# Dateisysteme – Spickzettel

## Datei-Speicherungsarten
| Art | Idee | Pro | Contra |
|---|---|---|---|
| **Kontinuierlich** | Blöcke mit aufsteigenden Nr. | min. Positionierzeit, schneller Direktzugriff (CDs) | Verschnitt, Erweitern/Umkopieren problematisch |
| **Verkettet** | Blöcke zeigen auf nächsten | vergrößer-/verkleinerbar | Zeiger kostet Nutzdaten, fehleranfällig, schlechter Direktzugriff |
| **FAT** | Verkettung in separater Tabelle | Datenblock voll nutzbar, FAT mehrfach speicherbar | +1 Block laden (Cache!), Suchaufwand, Kopfpositionieren |
| **Indiziert** | Indexblock listet Datenblöcke | guter Zugriff | fester Indexblock → Verschnitt bei kleinen, Stufen bei großen Dateien |
| **Baumsequent.** | B$^+$-Baum über Blöcke | schnelles Suchen per Schlüssel/Offset | NTFS, ReiserFS, Btrfs, JFS2 |

- **Chunks/Extents/Clusters:** kontinuierliche Blockfolgen → weniger Positionierungen, aber Verwaltung + Verschnitt (feste Gr. intern / variable Gr. extern)

## Unix-Inode
- mehrstufige Indizierung; Inode braucht ohnehin 1 Block → Verschnitt ok bei kleinen Dateien
- Nachteil: mehrere Block-Loads bei langen Dateien

## Freispeicherverwaltung
- **Bitvektor** (1 Bit/Block) oder **verkettete Liste** freier Blöcke (in freien Blöcken selbst; Optimierung: Blöcke am Stück / Block mit vielen Blocknummern)
- **Baumsequentielle** Suche freier Folgen (XFS)

## Verzeichnisse
- **Liste** (FAT, UNIX SysV): lineare Suche; sortiert → schnell, Einfügen teuer
- **Hash** (z.B. Σ mod N): schneller Zugriff, aber Kollisionen + Listengröße anpassen
- **variable Listeneinträge** (BSD, SysV R3): spart Platz, aber Freiliste + Verschnitt

## Dateisystem-Layouts
- **UNIX SysV:** Boot Block, Super Block (#Blöcke, #Inodes, Freilisten, Attribute)
- **BSD 4.2 FFS:** Super-Block-Kopie in jeder **Zylindergruppe**; Datei möglichst in einer Gruppe → kürzere Positionierungszeiten
- **ext2/3/4:** wie BSD FFS, aber Blockgruppen (unabhängig von Zylindern)

## Buffer Cache (UNIX)
- Plattenblöcke im RAM; Verwaltung wie bei Seitenverwaltung
- **Read ahead:** Folgeblöcke vorab laden
- **Lazy write:** Block wird nicht sofort geschrieben
- **Freiliste** per LRU, Wiederverwendung (Reclaim)
- Schreiben, wenn: keine freien Puffer, regelmäßig (fsflush/update), `sync()`, `O_SYNC`
- Adressierung: Hash über $(Gerätenummer, Blocknummer)$

## Fehlererholung
- Ausfälle → **inkonsistente Metadaten**; Reparatur mit `fsck`/`chkdsk` (langsam, Datenverlust möglich)

### Journaling
- **Protokolleintrag immer VOR der Änderung** schreiben
- Boot: vollständige Transaktionen → **Redo**, abgebrochene → **Undo**
- Vorteil: keine Inkonsistenz, schneller Start; Nachteil: ineffizient → meist nur **Metadata Journaling**
- Beispiele: NTFS, ext3/4, ReiserFS

## Merksätze
- BS-Abstraktion; von HW beeinflusst (Positionierzeit, Flash-Abnutzung, RAM-Disk ohne Cache)
- **Blockgröße:** zu klein → Verwaltung kostet; zu groß → Verschnitt

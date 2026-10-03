
Alles, was wir wissen, können wir aufschreiben. Daher ist die Repräsentation von Texten zentral.

> [!WARNING] Probleme eines naiven Ansatzes
> * **Problem 1:** Welche Zeichen sollen überhaupt codiert werden? (Nur Buchstaben? Satzzeichen? Umlaute? Emojis?)
>    
> * **Problem 2:** Wie kann man Daten mit anderen tauschen, wenn jeder sein eigenes System hat?
>
> **Lösung: Standardisierung**


---

## 1. ASCII (American Standard Code for Information Interchange)

* **7 Bit** Code $\rightarrow$ max. **128 Zeichen**.

* Legt eine Nummer für jedes Zeichen fest (z.B. "a" = 97, "A" = 65).

* Klein- und Großbuchstaben sind alphabetisch durchnummeriert.

* Oft als 8-Bit-Code erweitert, um Sonderzeichen (z.B. Umlaute) darzustellen.

- [ASCII-Tabelle](https://www.torsten-horn.de/techdocs/ascii.htm)

---

## 2. ISO 8859-1 (Latin-1)

* Eine **8 Bit** Erweiterung von ASCII (definiert die Plätze 128-255).

* Enthält viele Sonderzeichen für westeuropäische Sprachen (z.B. "ä", "ö", "ü").

* **Problem:** Enthält nicht alle gewünschten Zeichen (z.B. asiatische Schriftzeichen).

---

## 3. Unicode

* Der **aktuelle Standard** (z.B. von Java, Webseiten, modernen Betriebssystemen verwendet).

* Verwaltet vom Unicode-Konsortium.

* **Ziel:** Eine Obermenge *aller* weltweit geläufigen Zeichen zu sein.

* Vereinbart auch weitere Infos wie Schreibrichtung, Kombination von Zeichen etc.


> [!NOTE] Unicode vs. UTF (Unicode Transformation Format)
> * **Unicode** weist jedem Zeichen eine eindeutige Nummer zu (einen "Code Point").
> ---
> * **UTF** (Unicode Transformation Format) ist die *Codierung*, die festlegt, wie diese Nummer als Bitfolge gespeichert wird.
>     * **UTF-8:** Variable Länge (1-4 Bytes). ASCII-Zeichen brauchen nur 1 Byte und sind identisch zu ASCII. Das ist extrem effizient für Texte mit vielen lateinischen Buchstaben.
>     * **UTF-16:** Variable Länge (2 oder 4 Bytes). War lange der Standard (z.B. Java), da die meisten gängigen Zeichen in 16 Bit (2 Byte) passten.
>     * **UTF-32:** Feste Länge (4 Bytes). Jedes Zeichen braucht 32 Bit. Einfach, aber speicherintensiv.
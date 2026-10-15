---
datum: 15.10.2026
tags:
  - WRuMS
smry:
---
# Univariante Daten
## 2.1 Merkmale und Datentypen

- ***Einzelobjekte:*** Unterschungseinheiten, Merkmalsträger
![[Pasted image 20261015091053.png]]
- ***Statistische Gesamtheit:*** Kollektiv, Population

| Merkmal     | Merkmalsausprägungen                                   | Wertebereich                                |
| ----------- | ------------------------------------------------------ | ------------------------------------------- |
| Form        | Ellipse, Ellipse, Ellipse, Rechteck, Rechteck, Ellipse | {Ellipse, Rechteck}                         |
| Breite (cm) | 2, 1, 1, 2, 1, 3                                       | $(0,\infty) (\text{entspr. } ] 0, \infty[)$ |

### Skalentypen

- ***Qualitativ:*** (immer Diskret)
	- **Nominal:** gleich/verschieden, *z.B. Farbe, Form*
	- **Ordinal:** größer/kleiner, *z.B. Linienart*
  
- ***Quantitativ / metrisch***
	- **Intervall:** Differenzen gleich/verschieden, *z.B. (Breite, Höhe)*
	- **Verhältnis:** Verhältnisse gleich/vercshieden, *z.B. Breite, Höhe*
	  ⤷ braucht einen natürlichen Nullpunkt.

### Datentypen

- ***Diskret:*** endlich oder ==abzählbar unendlich== viele *z.B. Breite, Höhe (wenn grob gemessen)*
  ⤷ $\{x_{1}, \dots, x_{k}\}$

- ***Stetig:***  ==überabzählbar unendlich== viele *z.B. Breite, Höhe (wenn beliebig fein gemessen)*, immer **unendlich viele Möglichkeiten**, welche Ausprägung es haben kann (unendlich viele zwischen $x_{1}$ und $x_{2}$)
  ⤷ $(x_{1}, x_{2}) \space [x_{1}, x_{2}]$

### Niveaus

![[Pasted image 20261015093313.png]]
⤷ **Skalenniveau** von links nach rechts immer höher

- Unter Inkaufnahme von *Informationsverlust* können Merkmale ***in andere Skalenniveaus überführt*** und entsprechend analysiert werden
	- **stetig** $\to$ **diskret** (runden, *genaue Werte* gehen verloren)
	- **diskret quantitativ** $\to$ **ordinal** (*Abstände* gehen verloren)
	- **ordinal** $\to$ **nominal** (*Ordnung* geht verloren)

## 2.2 Tabellarische & grafische Darstellung univ. Daten

- ***Qualitative Daten***
	- $N$ ist die Stichprobengröße
	- $M_{N} = \{ e_{1}, \dots, e_{N} \}$ ist die Population bestehend aus Objekten $e_{1}, \dots, e_{N}$
	- $X$ ist ein nominales / ordinales Merkmal
	- $W_{X} = \{  x(j) \vert j = 1, \dots, J \} = \{ x(1) \}$

#etkt

>[!note] ##### Inhalt
>- SI-Präfixe
>- SI-Einheiten physikalischer Größen 
>- Generator- & Verbraucherzählpfeilsystem
>- Ohm'sche Gesetze
>- Ideale Spannungs- & Stromquelle
>- Grundbegriffe linearer Netze
>- Kirchhoff'sche Gesetze
>- Wiederstandsberechnungen

![[Elektrotechnik.pdf]]

___
# 1.1 Physikalische & mathematische Grundlagen

***Einheitspräfixe*** dienen der *Vermeidung vieler Vor-/Nachkommastellen*.

| ***SI-Präfix*** | **Name** | **Symbol** |
| --------------- | -------- | ---------- |
| $10^{-12}$      | *Piko*   | $p$        |
| $10^{-9}$       | *Nano*   | $n$        |
| $10^{-6}$       | *Mikro*  | $\mu$      |
| $10^{-3}$       | *Milli*  | $m$        |
| $10^3$          | *Kilo*   | $k$        |
| $10^6$          | *Mega*   | $M$        |
| $10^9$          | *Giga*   | $G$        |
| $10^{12}$       | *Tera*   | $T$        |

| ***Name***               | **Formelzeichen** | **SI-Einheit** |
| ------------------------ | ----------------- | -------------- |
| Elektrische Spannung     | $U$               | *Volt* $V$     |
| Elekrtische Stromstärke  | $I$               | *Ampere* $A$   |
| Elektrischer Wiederstand | $R$               | *Ohm* $\Omega$ |
| Kapazität                | $C$               | *Farad* $F$    |
| Induktivität             | $L$               | *Henry* $H$    |
| Frequenz                 | $f$               | *Hertz* $Hz$   |
| Leistung                 | $P$               | *Watt* $W$     |
| Ladung                   | $Q$               | *Couloumb* $C$ |

#### Beispiele zur Kürzung von Einheiten
##### 1d)
**Gegeben:** $W_{m} = 4mVAs$   |   $I = 2A$   |   $W_{m} = \frac{1}{2} \Phi \cdot I$ mit $[\Phi] = Vs$
*Formel umstellen:*$$W_{m} = \frac{1}{2} \Phi \cdot I \ \Longleftrightarrow \ \Phi = \frac{2 \cdot W_{m}}{I}$$*Werte einsetzen:* dabei Präfixe in Zehnerpotenzen umwandeln, z.B. $4mVAs \Leftrightarrow 4 \cdot 10^{-3}$ $$\Phi = \left( \frac{2 \cdot 4 \cdot 10^{-3}}{2} \right) \cdot \left( \frac{VAs}{A} \right)$$*Einheiten kürzen:* $$= 4 \cdot 10^{-3} \cdot Vs = \underline{4mVs}$$
⮩ ==Bemerkung:== Präfixe werden mit Potenziert $\implies (5mA)^2 = (5 \cdot 10^{-3} A)^2 = 25 \cdot 10^{-6} A^2$

___

# 1.2 Grundlagen der Netzwerktheorie

1. Beispiele für ***reale Quellen:***   *Batterie:* chemisch $\to$ elektrisch
				        *Generator:* mechanisch $\to$ elektrisch

2. ***Verbraucher*** wandeln 
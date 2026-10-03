#dap1

## Übersicht

| ***Methode***           | *Syntax*            | *Funktion*                           | *`const`–Relevanz*                                      | *Nutzen*                                  |
| ----------------------- | ------------------- | ------------------------------------ | ------------------------------------------------------- | ----------------------------------------- |
| ***Call-by-Value***     | `void f(int x)`     | **Kopie** des Wertes.                | `const` meist unnötig (schützt nur lokale Kopie).       | Primitive Typen (`int`, `bool`, `float`). |
| ***Call-by-Reference*** | `void f(string& s)` | **Alias** (Original). Kein Kopieren. | **Existenziell** (`const T&`) für Performance + Schutz. | Komplexe Objekte (`vector`, Klassen).     |
| ***Call-by-Pointer***   | `void f(int* p)`    | **Adresse** wird übergeben.          | Wichtig für Read-Only Arrays/Speicher.                  | C-Arrays, optionale Werte (`nullptr`).    |

---
---
## 1. Call-by-Value (Werteübergabe) ` `

Der Standard für kleine Datentypen.

- Mechanik: Der Wert wird in den Stack-Frame der Funktion kopiert.

- Const-Usage: void f(const int x)
	- Hinweis: Das const hier ist für den Aufrufer irrelevant. Es verhindert nur, dass du innerhalb der Funktion deine eigene lokale Kopie änderst.

- **Vorteil:** Maximale Kapselung. Das Original bleibt garantiert unberührt. 

> [!danger] Falle: Objekte mit dynamischem Speicher (z.B. new)
> 
> Wird ein Objekt, das Speicher verwaltet (wie ResizableArray), by-Value übergeben, passiert ohne Copy-Constructor folgendes:
> 
> 1. **Flache Kopie (Shallow Copy):** C++ kopiert nur den Zeiger, nicht den Inhalt dahinter. Original und Kopie zeigen auf **denselben Speicher**.
>     
> 2. **Destruktor-Problem:** Am Ende der Funktion zerstört der Destruktor der Kopie den Speicher (`delete[]`).
>     
> 3. **Crash:** Das Original versucht später, denselben (bereits gelöschten) Speicher zu löschen $\leadsto$ **Double Free**.

---
## 2. Call-by-Reference (Referenzübergabe) `&`

Der Standard für Objekte/Container in C++.

- Mechanik: Die Funktion arbeitet direkt auf dem Original-Speicherbereich (über einen Alias). Es wird kein Destruktor aufgerufen, da kein neues Objekt entsteht.

- Const-Usage ==WICHTIG==: `void f(const MyString& s)`
	- Dies ist die "Const Reference".
	- Nutzen: Du sparst das teure Kopieren (Performance) UND verhinderst das "Double Free"-Problem, verbietest aber Schreibzugriff.
	* Regel: Wenn du ein Objekt lesen, aber nicht ändern willst -> const T&.

- **Ohne Const:** `void f(MyString& s)` -> Nur nutzen, wenn die Funktion das Objekt verändern _soll_ (Out-Parameter).

---

## 3. Call-by-Pointer (Zeigerübergabe) `*`

Die "Low-Level" oder C-Kompatibilitäts-Variante.

- Mechanik: Übergabe der Speicheradresse. Verhält sich wie Referenz (keine Objekt-Kopie), aber Syntax ist anders (-> statt .).

- Const-Usage:
	- void f(int const* ptr) (oder const int* ptr)
	- Bedeutung: "Pointer auf konstante Daten". 
	- Nutzen: Die Funktion kann durch den Zeiger lesen, aber die Daten dahinter nicht überschreiben. Standard für Arrays (f(int const arr[], size_t n)).

- **Spezialfall:** Arrays zerfallen ("decay") bei der Übergabe immer zu Zeigern. `int arr[]` im Parameter ist technisch `int*`.

---
---

## Wann nehme ich was?

1.  **Kleiner Typ (int, double)?**
	⇨ f(int x) (Value)

2.  **Großes Objekt (Klasse, Vector) & Nur Lesen?**
	⇨ f(const MyClass& x) (Const Ref) $\to$ Verhindert Double-Free-Crash!

3.  **Großes Objekt & Ändern?**
	⇨ f(MyClass& x) (Ref)

4.  **Array oder "Kann nicht existieren" (nullptr)?**
	⇨ f(const int* ptr) (Const Pointer)
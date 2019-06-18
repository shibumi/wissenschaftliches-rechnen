# Aufgabenblatt 5
* Christian Rebischke (432108)
* Sajedeh Majdi (493981)

## Aufgabe 2
### Unteraufgabe 1
Da alle Knoten des Gitters konsekutiv durchnummeriert sind und die Anzahl a-priori bekannt ist wäre `array` eine gute Wahl.
Der Zugriff kann dadurch direkt über die konsekutive Nummer als Index erfolgen und die Größe wäre fix und bekannt.

### Unteraufgabe 2
Da die Pivotelemente in einer Stack-Struktur gespeichert werden sollen bietet sich `deque` an als STL Container zusammen
mit dem Container Adapter `stack`. Die eigentlichen Nutzdaten können dann einfach in einem `vector` abgelegt werden.

### Unteraufgabe 3
Da die Elemente einfach nur in einem FIFO zwischengespeichert werden müssen, bietet sich ein `deque` STL Container mit
`queue` als Container Adapter an. Ein anderer Container wäre irrelevant, da der Zugriff ja sowieso nur via FIFO erfolgt und
auch nichts durchsucht werden muss. Zumindest ist das aus der Aufgabe nicht ersichtlich.

### Unteraufgabe 4
Da es sich um Indizes und Werte an einem bestimmten Index (Knoten) handelt bietet sich eine `unordered map` als STL Container
an. Dadurch ist schnelles Suchen und schnelles Zugreifen möglich.

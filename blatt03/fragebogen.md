# Aufgabenblatt 3
* Christian Rebischke (432108)
* Sajedeh Majdi (493981)

## Übung 1
Die Frage ist etwas uneindeutig, deshalb gehe ich davon aus, dass geprüft werden soll ob die Expressions (Ausdrücke) Fehler werfen würden.

* `i + 1`; ist korrekt und hat den Datentyp `int`.
* `*p`; ist korrekt und der Datentyp ist `int`.
* `*p+3`; ist korrekt und der Datentyp ist `int`.
* `&i == p`; ist ein korrekter Vergleich zwischen der Adresse von `i` und der Adresse die der pointer `p` speichert. Datentyp von `p` ist `int *` und von `i` ist `int`. Somit ist `&i` der pointer auf eine Adresse zum Wert von `i`.
* `i == *p` vergleicht den Wert von `i` mit dem dereferenzierten Wert von `p`, also dem Wert auf dessen Adresse der Pointer `p` zeigt. Ausdruck ist korrekt. `i` ist `int` und `*p` ist ebenfalls `int`.
* `&p` ist korrekt und beinhaltet die Adresse vom Pointer die wiederum auf einen anderen Pointer zeigt.
* `p+1` ist die Adresse zu einem anderen Wert. Diese Adresse kann man durch 1 inkrementieren. Erscheint mir korrekt.
* `&p == i` Dieser Ausdruck ist falsch, da eine Adresse im Speicher mit einem Integer verglichen werden soll.
* `**(&p)` Dieser Ausdruck ist korrekt und sinngleich mit `*p`, der Datentyp wäre `int`.
* `*p + i > i` erscheint mir korrekt, da `*p` auf einen `int` Wert dereferenziert dieser mit `i` (ebenfalls `int`) addiert wird und mit einem `int` verglichen wird.

## Übung 2
Ich empfinde die Fragestellung leider als sehr schwammig. Schöner wäre es echten Code zu haben und zu sagen wieso dieser funktioniert oder was er tut.

* Der Destruktor einer Klasse C ist dafür verantwortlich alle Objekte der Klasse C wegzuräumen; Diese Aussage ist falsch, da der Destruktor immer nur ein Objekt der instanzierten Klasse wegräumt und der Destruktor einer Instanz nicht Zugriff auf den Destruktor einer anderen Instanz hat.
* Der Destruktor einer Klasse C ist dafür verantwortlich Objekte der Klasse C im Heap wegzuräumen; Diese Aussage ist korrekt, wenn man davon ausgeht, dass nur ein Objekt bzw eine Instanz der Klasse C gemeint ist. Der Zusammenhang mit Heap ist nicht ganz richtig, eigentlich spricht man im sprachlichen Zusammenhang von sogenannten `Storage Classes`.
* Der Destruktor einer Klasse C ist dafür verantwortlich alle Komponenten von Objekten der Klasse C wegzuräumen; Diese Aussage ist richtig, der Destruktor einer Klasse kann dazu verwendet werden einzelne Komponenten innerhalb der Klasse die beispielsweise via `malloc` allokiert worden sind freizugeben und so wegzuräumen. Dies muss allerdings explizit im Destruktor selbst programmiert werden.
* Der Destruktor einer Klasse C ist dafür verantwortlich Komponenten von Objekten der Klasse C, die im Heap liegen, wegzuräumen; Ich verstehe hier den Unterschied zu der Frage davor nicht.. die Fragen sind wie gesagt zu schwammig formuliert. Siehe Antwort zur Frage davor. Eigentlich spricht man im sprachlichen Zusammenhang von `Storage Classes` oder ist hier explizit mit `malloc` allokierter Speicher gemeint der im Destruktor freigegeben wird?
* Diese Aussage ist korrekt.

Die Fragestellung ist schwammig, da `Heap` nicht genau das gleiche ist wie der `Free Store` der bei `Storage Classes` verwenden wird. Siehe auch: http://www.gotw.ca/gotw/009.htm . Ich vermute aber mal, hier ist das Gleiche gemeint. Der C++ Standard spricht ebenfalls von einem Unterschied zwischen `Heap` und `Free Store`: https://github.com/cplusplus/draft Dies sind allerdings Implementierungs details.

## Übung 3

1. Das erste Beispiel ist die sinnvollere Methode da nur dort Speicher vom `Free Store` bzw `Heap` allokiert wird. Hinzuzufügen ist, dass durch die erste Methode `memory leaks` entstehene können, wenn man den allokierten Speicher nicht wieder via `delete` freigibt. Der allokierte Speicher bleibt erhalten auch beim Wechseln des `Scope`, also dem Verlassen der Funktion. Bei der zweiten Variante wird nur Speicher auf dem Stack allokiert, welcher bei Funktionsende verloren geht, da der `Scope` sich ändert. Der `Stack` ist außerdem kleiner, weshalb bei viel angeforderten Speicher es zum `Stack Overflow` kommen kann. Dies ist zu vermeiden.
2. Ich vermute mal es ist gemeint mit den Befehlen `malloc` (`Heap`) oder `new` (`Free Store`) Speicher zu allokieren und diesen Speicher mit einer Variable zu kennzeichnen. Ja dies ist möglich. Über den Variablen Namen kann dann auf den Speicher zugegriffen werden. Die Variable hat dann als Inhalt die Adresse zum allokierten Speicher. Diese Adresse ist eindeutig.
3. a) `p` hat den Wert 0 da der Speicher freigegeben wird und `*p` behält die alte Adresse bei, die beim Speicher allokieren vergeben worden ist.
   b) beim ersten Beispiel kann der allokierte Speicher nicht mehr freigegeben werden, da die Adresse vom Pointer zum Speicher verloren geht. Das zweite Beispiel ist jedoch sinnvoll, da so ein Pointer als `invalid` markiert werden kann.

## Übung 4

1. Das besondere ist, dass der Pointer als `invalid` markiert wird, da er auf keine gültige Speicheradresse zeigt.
5. Es kommt zu einem sogenannten `Double free`. Dabei wird versucht Speicher mehrmals freizugeben. Das Problem dahinter ist, dass beide Listen auf die gleichen Speicherbereiche zeigen, da ein `copy-by-reference` stattfand, statt ein `copy-by-value` in dem nur die Listen Werte kopiert werden.

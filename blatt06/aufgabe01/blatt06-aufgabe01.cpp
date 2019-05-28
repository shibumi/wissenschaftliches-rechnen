//
// Christian Rebischke
// Matrikelnummer: 432108
//
// Sajedeh Majdi
// Matrikelnummer: 493981
//
// Die Zahlen an Zeilenende von Kommentaren geben die Reihenfolge der Durchführung wieder

#include <exception>

// Klasse Ball ist eine Exception, da sie von std::exception erbt
class Ball: public std::exception {};

class P {
public:
    P *target; // Pointer auf ein P Object
    P(P *target): target(target){}; // 2,4
    void aim(Ball* ball) { // 7, 12, 17, 22, 27
        // aim() bekommt eine exception als parameter
        // diese exception wird versucht zu 'werfen'
        // falls dies failed wird die exception weitergereicht an das Ziel
        // Beim Ziel angekommen wiederholt sich der Prozess
        try { // 8, 13, 18, 23, 28
            throw *ball; // 9, 14, 19, 24, 29
        } catch(Ball &ball) { // 10, 15, 20, 25, 30
            target->aim(&ball); // 11, 16, 21, 26, 31 Hier kommt es zum Schluss zu einem Segmentation Fault
        }
    }
};

int main() {
    // parent ist sozusagen die Wurzel im Baum
    P parent = new P(nullptr); // 1
    // child hat parent als Ziel aka leitet die Exception an das Ziel weiter
    P child = new P(parent); // 3
    // parent setzt child als Ziel, leitet die exception also wieder an das child weiter
    parent.target = &child; // 5
    // Methodenaufruf um das Ballspiel zu starten
    parent.aim(new Ball()); // 6
}

/*
 * Was tut das Programm?
 * Das Programm erzeugt Objekte der Klasse P (child und parent)
 * Durch die aim() Methode wird die Exception "Ball" zwischen diesen Objekten
 * solange hin und her übergeben, bis this auf NULL zeigt.
 * Wenn dies geschieht kommt es zu einem Segmentation Fault, da versucht wird
 * auf einen Speicherbereich zuzugreifen, welcher nicht mehr existiert.
 */



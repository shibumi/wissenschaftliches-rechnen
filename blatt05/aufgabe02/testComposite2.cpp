//
// Created by chris on 5/22/19.
//

#include <vector>
#include <iostream>
#include <cmath>
#include "NumVectorComposite.cpp"
void vectorTest(std::vector<double>& v){}
int main(){
    NumVector v(3);
    v.resize(2); // Darf wie andere std::vector Funktionen nicht sichtbar sein!
    vectorTest(v); // Hier muss auch ein Compiler Fehler auftreten!
}

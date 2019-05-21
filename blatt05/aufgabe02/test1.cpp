//
// Created by chris on 5/21/19.
//

#include <vector>
#include <iostream>
#include <cmath>
#include "NumVector.cpp"
int main(){
    NumVector v(3);
    v[0]=1; v[1]=3, v[2]=4;
    const NumVector& w=v;
    std::cout<<"norm is "<<w.norm()<<std::endl;
    std::cout<<"vector is ["<<w[0]<<", "<<w[1]<<", "<<w[2]<<"]"<<std::endl;
}

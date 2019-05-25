//
// Created by chris on 5/25/19.
//


#include <exception>

class Ball: public std::exception {};

class P {
public:
    P *target;
    P(P *target): target(target){};
    void aim(Ball* ball) {
        try {
            throw ball;
        } catch(Ball ball) {
            target->aim(&ball);
        }
    }
};

int main() {
    P parent = new P(nullptr);
    P child = new P(parent);
    parent.target = &child;
    parent.aim(new Ball());
}



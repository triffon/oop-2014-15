#include <iostream>
#include "Monster.h"

int main() {
    std::cout<<"On."<<std::endl;

    Monster sheep("Sheep", 100, 50, 40);

    Monster sheep2 = sheep;

    Monster goo("Goo", 100, 20, 70);

    Monster slime("Slime", 100, 10, 5);

    goo = slime;

    return 0;
}

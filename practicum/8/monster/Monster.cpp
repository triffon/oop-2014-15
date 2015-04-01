#include <cstring>
#include <iostream>
#include "Monster.h"

void Monster::copy(const Monster& other) {
    setName(other.name);
    health = other.health;
    attack = other.attack;
    defense = other.defense;
}

void Monster::destroy() {
    if(name != NULL) {
        delete[] name;
    }
}

//Тук има една тънкост, която често се изпуска и влизаме в if-a на setName,
//което води до опит за изтриване на чужда памет
//
//name по default няма да е NULL и затова трябва да го сетнем на NULL тук  VVVVVV
Monster::Monster(char* _name, int _health, int _attack, int _defense) :name(NULL), health(_health), attack(_attack), defense(_defense) {
    setName(_name);
    std::cout<<_name<<" has spawned!"<<std::endl;
}

//Тук правим същата врътка с name
Monster::Monster(const Monster& other) :name(NULL) {
    copy(other);
    std::cout<<name<<" has been cloned!"<<std::endl;
}

Monster& Monster::operator=(const Monster& other) {
    std::cout<<name<<" turned into "<<other.name<<"!"<<std::endl;
    copy(other);
    return *this;
}

Monster::~Monster() {
    std::cout<<name<<" has died!"<<std::endl;
    destroy();
}

char* Monster::getName() const {
    return name;
}

void Monster::setName(char* value) {
    if(name != NULL) {
        delete[] name;
    }
    name = new char[strlen(value) + 1];
    strcpy(name, value);
}

int Monster::getHealth() const {
    return health;
}

void Monster::setHealth(int value) {
    health = value;
}

int Monster::getAttack() const {
    return attack;
}

int Monster::getDefense() const {
    return defense;
}

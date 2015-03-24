#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

class Monster {
    private:
        char* name;
        int health;
        int attack;
        int defense;

        void copy(const Monster&); //Копира данните от обекта зададен като параметър в this
        void destroy(); //Почиства заделената динамична памет (използва се в деструктора)

    public:
        //Голяма четворка
        Monster(char* = "", int = 0, int = 0, int = 0); //Конструктор с параметри по подразбиране(върши работа като конструктори с 0, 1, 2, 3 и 4 параметъра)
        Monster(const Monster&); //Конструктор за копиране
        Monster& operator=(const Monster&); //Оператор =
        ~Monster(); //Деструктор - Тук се извършват "предсмъртни" за обекта действия + почистване на заделената динамична памет

        //get + set методи
        char* getName() const;
        void setName(char*);
        int getHealth() const;
        void setHealth(int);
        int getAttack() const;
        int getDefense() const;

        //Тези двете функции не са еднакви за всички, така че не съм ги писал
        void hit(Monster&); //Атака
        void defend(); //Защита
};


#endif // MONSTER_H_INCLUDED

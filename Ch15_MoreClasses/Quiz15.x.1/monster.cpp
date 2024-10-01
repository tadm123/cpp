/*  
https://www.learncpp.com/cpp-tutorial/chapter-15-summary-and-quiz/ 
Grab the “Random.h” code from 8.15 -- Global random numbers (Random.h) and save it as Random.h. 
Then use Random::get() to generate a random monster type, random name, random roar, and random hit points (between 1 and 100).
*/
  

#include <iostream>
#include <string>
#include <string_view>
#include "Random.h"

class Monster
{
public:
    enum Type
    {
        dragon, //0
        goblin, //1
        ogre,   //2
        orc,    //3
        skeleton,   //4
        troll,  //5
        vampire,    //6
        zombie, //7
        max_monster_types,
    };

private:
    Type m_type{};
    std::string m_name{};
    std::string m_roar{};
    int m_hit_points{};

public:
    Monster (Type type, std::string_view name, std::string_view roar, int hit_points)
    : m_type{type}
    , m_name{name}
    , m_roar{roar}
    , m_hit_points{hit_points}
    {
    }

    std::string_view getTypeString(Type type)
    {
        switch (type)
        {
            case(dragon): return "dragon";
            case(goblin): return "goblin";
            case(ogre): return "ogre";
            case(orc): return "orc";
            case(skeleton): return "skeleton";
            case(troll): return "troll";
            case(vampire): return "vampire";
            case(zombie): return "zombie";
            default: return "???";

        }
    }

    void print ()
    {
        if (m_hit_points == 0)
            std::cout << m_name << " the " << getTypeString(m_type) << " is dead.\n";
        else
            std::cout << m_name << " the " << getTypeString(m_type) << " has " << m_hit_points << " hit points and says " << m_roar << ".\n";
    }
};


namespace MonsterGenerator
{
    std::string_view getName(int num) //takes a number between 0<= x <=  5 and returns a name of your choice
    {
        switch (num)
        {
            case(0): return "Igor";
            case(1): return "Mark";
            case(2): return "Frank";
            case(3): return "Alan";
            case(4): return "Jenna";
            case(5): return "Daniel";
            default: return "Invalid";
        }
    }
    std::string_view getRoar(int num) //takes a number between 0<= x <=  5 and returns a roar (string) of your choice
    {
        switch (num)
        {
            case(0): return "Hoot Hoot";
            case(1): return "Roar!";
            case(2): return "Skittles";
            case(3): return "Ahhh!";
            case(4): return "Woof";
            case(5): return "Chirp Chirp";
            default: return "Invalid";
        }
    }

    Monster generate()
    {
        return   Monster{ static_cast<Monster::Type>(Random::get(0, Monster::max_monster_types-1)),
                          getName(Random::get(0, 5)),
                          getRoar(Random::get(0, 5)),
                          Random::get(1, 100    )
                         };
    }
}

int main()
{
    Monster m{ MonsterGenerator::generate() };
    m.print();

    return 0;
}


#include <iostream>
#include <string_view>  //for std::string_view
#include <array>  //for std::array
#include <string> //for std::string
#include "Random.h"


namespace Potion {
    enum Type {
        healing, //0
        mana,    //1
        speed,   //2
        invisibility, //3
        max_potions, //4
    };

    constexpr std::array potion_types{healing, mana, speed, invisibility};  //an array of our enumerators


    using namespace std::string_view_literals;
    constexpr std::array<std::string_view, max_potions> potion_names{"healing"sv, "mana"sv, "speed"sv,
                                                                     "invisibility"sv};

    constexpr std::array<int, max_potions> potion_cost{20, 30, 12, 50};


    //check assert if elements are not biggere than max number of animals
    static_assert(std::size(potion_types) == max_potions);
    static_assert(std::size(potion_names) == max_potions);
    static_assert(std::size(potion_cost) == max_potions);
}

class Player  //for individual player
{
    private:       //making it private since this is the personal information of a player
        std::string m_player_name{};    //the name will be a string
        int m_player_gold{Random::get(80,120)};            //total gold that we have (so we can use it to purchase potions)
        std::array<int, Potion::max_potions> m_inventory{0};  // It's an array of integers
        //ex m_inveotory = {2, 1, 4, 1}, this means 2x healing, 1x mana, 4x speed, 1x invisibility

    public:

        //default constructor
        Player() = default;

    //make a constructor
        Player (std::string& player_name, int player_gold, std::array<int, Potion::max_potions> inventory)
        : m_player_name {player_name}
        , m_player_gold {player_gold}
        , m_inventory {inventory}
        {
        }

        //do a setter function for player_name, we can yse stringvoew because you're not modifying playr_name, rather m_player_name
        void setName(std::string_view player_name){ m_player_name=player_name; }

        //do a getter function for player name
        std::string_view getName() {return m_player_name;}

        //do a setter function for player_name, we can yse stringvoew because you're not modifying playr_name, rather m_player_name
        void setGold(int player_gold){ m_player_gold=player_gold; }

        //do a getter function for player name
        int getGold() const {return m_player_gold;}



        //let's say a player bought a healing potion (speed //2)
        void buy (int enumerated_type)  //buy enum 2
        {
            m_inventory[enumerated_type] +=1;
        }

        int inventory(int p) const { return m_inventory[p]; }
};

void printInventory(Player& player)   //you want to pass the class
{

    std::cout << "Your inventory contains:\n";

    for (auto const& a : Potion::potion_types) //potion_types = {0,1,2,3}
        std::cout << player.inventory(a) << "x potion of " << Potion::potion_names[a] << '\n';  //send 3 integer, returns m_inventpry[3], which should be

    std::cout << "You escaped with " << player.getGold() << " remaining.\n";

}

int charNumToInt(char c)
{
    return c - '0';
}

void shop(Player& player)
{
    std::cout << "Hello, " << player.getName()<< ", you have " << player.getGold() << " gold" << '\n' << '\n';

    while(true)
    {
        std::cout << "Here is our selection for today: " << '\n';

        for (const auto& p : Potion::potion_types)
            std::cout << p << ") " << Potion::potion_names[p] << " costs " << Potion::potion_cost[p] << '\n';


        std:: cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
        char a{};
        std::cin >> a;

        int aInt{charNumToInt(a)}; //converts character into integer

        //handle errors
        if (!std::cin)
            std::cin.clear();

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if ( a == 'q' )
            break;

        //if user enters valid number (between 0-3), then proceed
        if ( (aInt >= 0) && (aInt <= 3) )
        {
            if (Potion::potion_cost[aInt] > player.getGold()) //you can't afford it
                std::cout << "You can not afford that.\n";

            else
            {
                player.buy(aInt);

                std::cout << "You purchased a potion of " << Potion::potion_names[aInt] << ". ";

                //deducting quantity of our gold
                player.setGold( player.getGold() - Potion::potion_cost[aInt]);

                std::cout << "You have " << player.getGold() << " gold left.";
                std::cout << '\n';
            }
        }

        else
            std::cout << "This is an invalid input. Try again: \n";

        std::cout << '\n';
    }

}

int main() 
{

    //initiaze a class with your name
    Player me{};

    std::cout << "Welcome to Roscoe's potion emporium!" << '\n';
    std::cout << "Enter your name: ";

    std::string my_name{};
    std::getline(std::cin >> std::ws, my_name);

    me.setName(my_name);

    shop(me);

    printInventory(me);

    std::cout << '\n';
    std::cout << "Thanks for shopping at Roscoe's potion emporium!";
    
    return 0;
}

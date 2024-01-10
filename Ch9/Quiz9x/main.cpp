#include <iostream>
#include <random.h>

void ignoreLine() //this handles extra characters
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// returns true if the user won, false if they lost
bool playGame(int guesses, int number)
{
    // Loop through all of the guesses
    for (int count{ 1 }; count <= guesses; ++count)
    {
        std::cout << "Guess #" << count << ": ";
        int guess{};

        std::cin >> guess;

        if (!std::cin) // if the previous extraction failed
        {
            std::cin.clear(); // put us back in 'normal' operation mode
            ignoreLine();     // and remove the bad input
            std::cout << "Oops, that input is invalid.  Please try again.\n";
            continue;
        }
        else                //if extraction was successful but may or not have extraneous characters
            ignoreLine(); // remove any extraneous input if there's any

        if ( (guess <1) || (guess >100) )
            std::cout << "Your number is out of bounds. Try again\n";

        else
        {
            if (guess > number)
                std::cout << "Your guess is too high.\n";

            else if (guess < number)
                std::cout << "Your guess is too low.\n";
            else // guess == number
                return true;
        }
    }

    return false; // if the user lost
}

bool playAgain()
{
    // Keep asking the user if they want to play again until they pick y or n.
    while (true)
    {
        char ch{};
        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> ch;

        ignoreLine(); // clears anyextraneous input

        switch (ch)
        {
            case 'y': return true;
            case 'n': return false;
        }
    }
}


int main()
{
    constexpr int guesses{ 7 }; // the user has this many guesses

    do
    {
        int number{ Random::get(1,100) }; // this is the number the user needs to guess

        std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have " << guesses << " tries to guess what it is.\n";

        bool won{ playGame(guesses, number) };
        if (won)
            std::cout << "Correct! You win!\n";
        else
            std::cout << "Sorry, you lose. The correct number was " << number << '\n';
    } while (playAgain());

    std::cout << "Thank you for playing.\n";

    return 0;
}

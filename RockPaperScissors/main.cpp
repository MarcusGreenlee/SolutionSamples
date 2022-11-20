// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define PAPER 0
#define ROCK 1
#define SCISSORS 2

#define USERWON 0
#define TIE 1
#define COMPWON 2

bool playGame()
{
    std::string choice;

    std::cout << "Would you like to play?\n";
    std::cout << "(Y) Yes\n";
    std::cout << "(N) No\n";
    std::cin >> choice;

    if (choice == "y" || choice == "Y")
    {
        std::cout << "Excellent! Let's begin!\n";
        return true;
    }
    else
    {
        std::cout << "Sorry to hear that. Goodbye!\n";
        return false;
    }
}

int selectUserWeapon()
{
    std::string input;
    int weapon = 0;  // default weapon is paper

    std::cout << "[ -- Make Your Selection -- ]\n";
    std::cout << "[ -------(P) Paper -------- ]\n";
    std::cout << "[ -------(R) Rock --------- ]\n";
    std::cout << "[ -------(S) Scissors ----- ]\n";
    std::cin >> input;

    if ((input[0] == 'R') || (input[0] == 'r'))
        weapon = 1;
    else if ((input[0] == 'S') || (input[0] == 's'))
        weapon = 2;

    return weapon;
}

int selectComputerWeapon()
{
    int weapon = rand() % 3; 
    return weapon;
}

std::string convertWeaponToString(int weapon)
{
    std::string strWeapon[] = { "Paper", "Rock", "Scissors" };
    return strWeapon[weapon];
}

int main()
{
    bool playing = true;
    int winTable[3][3] =
    // User:
    //  Paper,     Rock,     Scissors
    {                                  // Computer: 
        {TIE,      USERWON,  COMPWON}, // Paper
        {COMPWON,  TIE,      USERWON}, // Rock 
        {USERWON,  COMPWON,  TIE}      // Scissors
    };

    std::string howToWin[3] =
    {
         "Paper covers Rock! ",
         "Rock smashes Scissors! ",
         "Scissors cuts Paper! "
    };

    // Initialize the random number generator
    srand((unsigned int) time(NULL));  

    // Welcome
    std::cout << "Hello User! Let's play a game!!\n";
    std::cout << "You might have heard about this game before\n";
    std::cout << "It is called Paper, Rock, Scissors!\n";

    // Play request
    playing = playGame();
    if (!playing)
        return 0;

    int compWeapon;
    int userWeapon;
    while (playing == 1) 
    {
        compWeapon = selectComputerWeapon();
        userWeapon = selectUserWeapon();

        std::cout << "You picked " << convertWeaponToString(userWeapon) << " and the Computer has picked " << convertWeaponToString(compWeapon) << "! ";
        int winner = winTable[userWeapon][compWeapon];
        switch (winner)
        {
            case USERWON:
            {
                std::cout << howToWin[userWeapon];
                std::cout << "You win!\n";
                break;
            }

            case TIE:
            {
                std::cout << "It's a tie!\n";
                break;
            }

            case COMPWON:
            {
                std::cout << howToWin[compWeapon];
                std::cout << "You lose!\n";
                break;
            }
        }

        playing = playGame();
        if (playing)
        { 
            std::cout << "Excellent! Let's have another round!\n";
        }
    } // end of game while loop

    std::cout << "Thank you for playing!";

    return 0;
}
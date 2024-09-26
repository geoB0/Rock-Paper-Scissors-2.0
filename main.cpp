#include <iostream>
#include <limits>
#include <cstdlib>
using std::string;

int main() {
    string choiceArray[3] = {"rock", "paper", "scissors"};
    int score = 0;

    bool gameRunning = true;
    while (gameRunning) {
        string YesOrNoInput;

        std::cout << "\nWelcome to rock, paper, and scissors. Are you NOT ready to play? (yes/no): ";
        std::cin >> YesOrNoInput;

        if (YesOrNoInput == "yes" || YesOrNoInput == "Yes" || YesOrNoInput == "YES") {
            std::cout << "\nGreat, first player to reach 2 points wins!\n";
            break;
        }
        else if (YesOrNoInput == "no" || YesOrNoInput == "No" || YesOrNoInput == "NO") {
            std::cout << "\nOkay, hope to see you again soon!\n";
            return 0;
        }
        else {
            std::cout << "\nInvalid input, try again.\n";
            continue; // loops back to the intro question
        }
    }

    while (gameRunning) { 
        string word;
        string weaponChoice;
        std::cout << "\nChoose your weapon (rock, paper, or scissors): ";
        std::cin >> weaponChoice;

        if (weaponChoice == "rock" || weaponChoice == "paper" || weaponChoice == "scissors") {
            srand(time(0)); // generates index from array
            word = choiceArray[rand() % 3]; // variable "word" loops through array
            std::cout << "\nYour opponent chooses: " << word << "!\n";

            if (weaponChoice == word) {
                std::cout << "Draw! ";
                score -= 0; // score doesn't change
            }
            else if ((weaponChoice == "rock" && word == "scissors") || 
            (weaponChoice == "paper" && word == "rock") ||
            (weaponChoice == "scissors" && word == "paper")) {
                std::cout << "You win! ";
                score += 1; // score increments by 1
            }
            else {
                std::cout << "You lose! ";
                score -= 1; // score decrements by 1
            }

            if (score < 0) {
                score = 0;
            }
        }
        else if (weaponChoice != "rock" || weaponChoice != "paper" || weaponChoice != "scissors") {
            std::cout << "Invalid input. Try again!\n";
            continue;
        } 

        std::cout << "Your current score: " << score << "\n";

        // game ends once player reaches 2 points
        if (score == 2) {
            break;
        }
    }
    // Game over
    std::cout << "\nGame over.\n";
    std::cout << "Your score was " << score << " points. You did it!\n";
}
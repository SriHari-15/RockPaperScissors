#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

// Function to clear the terminal screen (Linux only)
void clearScreen()
{
    system("clear");  // For Linux/Unix-based systems
}

std::string getChoiceName(int choice)
{
    if (choice == 1) return "Rock";
    if (choice == 2) return "Paper";
    if (choice == 3) return "Scissors";
    return "Invalid choice";
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(0))); // Seed for random number generator
    std::string playAgain;

    do {
        std::cout << "1. Rock\n2. Paper\n3. Scissors\n";
        std::cout << "Choose (1, 2, or 3): ";
        int user;
        std::cin >> user;

        // Clear the input buffer to avoid issues with getline. Thanks ChatGPT
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (user < 1 || user > 3) {
            std::cout << "Invalid choice!" << std::endl;
            continue;
        }

        int comp = std::rand() % 3 + 1; // Random choice for computer

        std::cout << "\nYou chose: " << getChoiceName(user)
                  << "\nComputer chose: " << getChoiceName(comp) << std::endl;

        if (user == comp) {
            std::cout << "\nIt's a tie!" << std::endl;
        } else if ((user == 1 && comp == 3) || // Rock beats Scissors
                   (user == 2 && comp == 1) || // Paper beats Rock
                   (user == 3 && comp == 2)) { // Scissors beat Paper
            std::cout << "You win!" << std::endl;
        } else {
            std::cout << "You lose!" << std::endl;
        }

        std::cout << "\nPress Enter to play again or type 'quit' to exit: ";
        std::getline(std::cin, playAgain);

        if (playAgain != "quit") {
            clearScreen();
        }

    } while (playAgain != "quit");

    std::cout << "Thanks for playing!" << std::endl;
    return 0;
}
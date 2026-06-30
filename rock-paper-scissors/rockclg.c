#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int rounds;
    int userChoice, computerChoice;
    int userScore = 0;
    int computerScore = 0;

    cout << "===== ROCK PAPER SCISSORS =====\n";
    cout << "How many rounds do you want to play? ";
    cin >> rounds;

    for (int i = 1; i <= rounds; i++) {
        cout << "\n--- Round " << i << " ---\n";
        cout << "1. Rock\n";
        cout << "2. Paper\n";
        cout << "3. Scissors\n";
        cout << "Enter your choice: ";
        cin >> userChoice;

        computerChoice = rand() % 3 + 1;

        cout << "Computer chose: ";

        if (computerChoice == 1)
            cout << "Rock\n";
        else if (computerChoice == 2)
            cout << "Paper\n";
        else
            cout << "Scissors\n";

        if (userChoice == computerChoice) {
            cout << "Draw!\n";
        }
        else if ((userChoice == 1 && computerChoice == 3) ||
                 (userChoice == 2 && computerChoice == 1) ||
                 (userChoice == 3 && computerChoice == 2)) {
            cout << "You win this round!\n";
            userScore++;
        }
        else {
            cout << "Computer wins this round!\n";
            computerScore++;
        }

        cout << "Score -> You: " << userScore
             << " | Computer: " << computerScore << "\n";
    }

    cout << "\n===== FINAL RESULT =====\n";
    cout << "Your Score: " << userScore << endl;
    cout << "Computer Score: " << computerScore << endl;

    if (userScore > computerScore)
        cout << "You are the overall winner!\n";
    else if (computerScore > userScore)
        cout << "Computer is the overall winner!\n";
    else
        cout << "The game is a draw!\n";

    return 0;
}
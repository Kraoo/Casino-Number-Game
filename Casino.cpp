#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void displayWelcomeMessage();
void displayRules();
void playGame(string playerName, int& balance);
bool isValidBet(int betAmount, int balance);
int getUserGuess();
int rollDice();
void displayResult(string playerName, int guess, int dice, int betAmount, int& balance);
void displayFinalBalance(int& balance);

int main() {
    string playerName;
    int balance;

    srand(time(0));

    displayWelcomeMessage();
    cout << "What's your name? ";
    getline(cin, playerName);

    cout << "Enter the starting balance to play the game: $";
    cin >> balance;

    playGame(playerName, balance);

    return 0;
}

void displayWelcomeMessage() {
    cout << "\n\t\t========WELCOME TO CASINO WORLD=======\n\n";
}

void displayRules() {
    cout << "\t\t======CASINO NUMBER GUESSING RULES!======\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}

void playGame(string playerName, int& balance) {
    char choice;

    do {
        system("cls");
        displayRules();
        cout << "\n\nYour current balance is: $" << balance << "\n";

        int betAmount;
        do {
            cout << "Hey, " << playerName << ", enter amount to bet: $";
            cin >> betAmount;
        } while (!isValidBet(betAmount, balance));

        int guess = getUserGuess();
        int dice = rollDice();
        displayResult(playerName, guess, dice, betAmount, balance);

        if (balance == 0) {
            displayFinalBalance(balance);
            if (balance == 0) {
                cout << "You have no money left to play.\n";
                break;
            }
        }

        cout << "\n\nDo you want to play again (y/n)? ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    displayFinalBalance(balance);
}

bool isValidBet(int betAmount, int balance) {
    if (betAmount <= 0) {
        cout << "Bet amount should be greater than 0. Please re-enter.\n";
        return false;
    } else if (betAmount > balance) {
        cout << "Betting amount cannot be more than your current balance. Please re-enter.\n";
        return false;
    }
    return true;
}

int getUserGuess() {
    int guess;
    do {
        cout << "Guess any number between 1 & 10: ";
        cin >> guess;
    } while (guess <= 0 || guess > 10);
    return guess;
}

int rollDice() {
    return rand() % 10 + 1;
}

void displayResult(string playerName, int guess, int dice, int betAmount, int& balance) {
    cout << "The winning number was: " << dice << "\n";
    if (dice == guess) {
        cout << "Congratulations! You have won $" << betAmount * 10 << "\n";
        balance += betAmount * 10;
    } else {
        cout << "Better luck next time! You lost $" << betAmount << "\n";
        balance -= betAmount;
    }
    cout << playerName << ", your balance is: $" << balance << "\n";
}

void displayFinalBalance(int& balance) {
    cout << "\n\nThanks for playing the game. Your final balance is: $" << balance << "\n\n";
    if (balance == 0) {
        char addMore;
        cout << "Your balance is 0. Do you want to add more money to continue playing? (y/n): ";
        cin >> addMore;
        if (addMore == 'Y' || addMore == 'y') {
            cout << "Enter the amount you want to add: $";
            int addAmount;
            cin >> addAmount;
            balance += addAmount;
            cout << "You have added $" << addAmount << ". Your current balance is: $" << balance << endl;
        }
    }
}

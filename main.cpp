#include <iostream>
#include <random>
using namespace std;

/*
 * Prompts user for how much money they would like to bet.
 * Has input validation to make sure the amount >= $0 and amount <= $1000.
 * Returns the amount.
 */
int getMoney();

/*
 * Prompts user for how many coin tosses they would like to simulate.
 * Has input validation to make sure the number >= 3 and number <= 20.
 * Returns the number.
 */
int getTosses();


/*
 * This function will simulate the game.
 * It takes in two parameters, which vary based on user input.
 * It runs through the amount of tosses and adjust the money,
 * storing each adjusted amount in the vector.
 * It returns the vector of the money.
 */
vector<double> game(int money, int tosses);

int main() {

    int money;
    int tosses;

    money = getMoney();
    tosses = getTosses();

    cout << "You will be betting $" + to_string(money) + " for " + to_string(tosses) + " coin tosses." << endl;

    game(money, tosses);

    return 0;
}

int getMoney() {
    int money;

    cout << "How much money would you like to bet? $";
    cin >> money;

    while (money < 1 || money > 1000) {
        cout << "Please enter a value between $1 and $1000: $";
        cin >> money;
    }

    return money;
}

int getTosses() {
    int tosses;

    cout << "How many coin tosses would you like to simulate? ";
    cin >> tosses;

    while (tosses < 3 || tosses > 20) {
        cout << "Please enter a value between 5 and 20: ";
        cin >> tosses;
    }

    return tosses;
}

vector<double> game(int money, int tosses) {
    vector<double> moneyAmounts;
    int randomNum;
    char headsTails;
    char choice;

    cout << "Welcome!" << endl;
    cout << "You will be prompted with the current money you have, the toss number you are on, and then whether"
            " you would like to pick heads ('H' or 'h') or tales ('T' or 't')." << endl;

    moneyAmounts.push_back(money);

    for (int i = 0; i < tosses; ++i) {
        cout << "Current money: $" + to_string(money) << endl;
        cout << "Toss number: " + to_string(i + 1) << endl;
        cout << "Heads or tales? ";
        cin >> choice;
        cout << endl;

        while (choice != 'H' && choice != 'h' &&
            choice != 'T' && choice != 't') {
            cout << "   Enter a valid character please (H/h or T/t): ";
            cin >> choice;
        }

        randomNum = 1 + rand() % 2;
        if (randomNum == 1) {
            headsTails = 'h';
        } else {
            headsTails = 't';
        }

        if (headsTails == 'h') {
            cout << "The result: HEADS" << endl;
            if (choice == 'H' || choice == 'h') {
                cout << "Well done!" << endl;
                money *= 2;
            } else {
                cout << "Unlucky." << endl;
                money /= 2;
            }
        } else {
            cout << "The result: TAILS" << endl;
            if (choice == 'T' || choice == 't') {
                cout << "Well done!" << endl;
                money *= 2;
            } else {
                cout << "Unlucky." << endl;
                money /= 2;
            }
        }
        moneyAmounts.push_back(money);
    }

    return moneyAmounts;
}
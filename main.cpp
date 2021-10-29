#include <iostream>
#include <iomanip>
#include <random>
#include <time.h>
using namespace std;

/*
 * Prompts user for how much money they would like to bet.
 * Has input validation to make sure the amount >= $1 and amount <= $1000.
 * Returns the amount.
 */
double getMoney();

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
vector<double> game(double money, int tosses);

int main() {

    double money;
    int tosses;
    vector<double> moneyAmounts;
    string command = "python3 ../graph.py ";
    string amountsStr;

    money = getMoney();
    tosses = getTosses();

    cout << "You will be betting $" << setprecision(2) << money << " for " << tosses << " coin tosses." << endl;

    moneyAmounts = game(money, tosses);
    for (double amount : moneyAmounts) {
        amountsStr += to_string(amount) + " ";
    }

    command += amountsStr;
    command += " ";
    command += to_string(tosses);

    system(command.c_str());

    return 0;
}

double getMoney() {
    double money;
    string junk;

    cout << "How much money would you like to bet? $";
    cin >> money;

    while (!cin || money < 1 || money > 1000) {
        cout << "   Please enter a value between $1 and $1000: $";
        cin.clear();
        getline(cin, junk);
        cin >> money;
    }

    return money;
}

int getTosses() {
    int tosses;
    string junk;

    cout << "How many coin tosses would you like to simulate? ";
    cin >> tosses;

    while (!cin || tosses < 3 || tosses > 20) {
        cout << "   Please enter a value between 3 and 20: ";
        cin.clear();
        getline(cin, junk);
        cin >> tosses;
    }

    return tosses;
}

vector<double> game(double money, int tosses) {
    vector<double> moneyAmounts;
    int randomNum;
    string headsTails;
    string choice;
    srand(time(nullptr));

    cout << "Welcome!" << endl;
    cout << "You will be prompted with the toss number you are on, the current money you have, and then whether"
            " you would like to pick heads ('H' or 'h') or tales ('T' or 't')." << endl;
    cout << endl << "-------------------------" << endl;

    moneyAmounts.push_back(money);

    for (int i = 0; i < tosses; ++i) {
        cout << endl;
        cout << "Toss number: " << i + 1 << endl;
        cout << "Current money: $" << fixed << setprecision(2) << money << endl;
        cout << "Heads or tales? ";
        getline(cin, choice);

        while (choice != "H" && choice != "h" &&
            choice != "T" && choice != "t") {
            cout << "   Enter a valid character please (H/h or T/t): ";
            getline(cin, choice);
        }

        randomNum = rand() % 2;
        if (randomNum == 0) {
            headsTails = "HEADS";
        } else if (randomNum == 1) {
            headsTails = "TAILS";
        }

        cout << endl;

        if (headsTails == "HEADS") {
            cout << "Coin Toss: HEADS" << endl;
            if (choice == "H" || choice == "h") {
                cout << "Well done!" << endl;
                money *= 2;
            } else {
                cout << "Unlucky." << endl;
                money /= 2;
            }
        } else {
            cout << "Coin Toss: TAILS" << endl;
            if (choice == "T" || choice == "t") {
                cout << "Well done!" << endl;
                money *= 2;
            } else {
                cout << "Unlucky." << endl;
                money /= 2;
            }
        }
        cout << endl << "-------------------------" << endl;
        moneyAmounts.push_back(money);
    }

    cout << "You finished the game with $" << money << endl;
    if (money < moneyAmounts[0]) {
        cout << "Unfortunately, you lost $" << moneyAmounts[0] - money << endl;
    } else if(money > moneyAmounts[0]) {
        cout << "Congratulations! You won $" << money - moneyAmounts[0] << endl;
    } else {
        cout << "You didn't win any money, but at least you didn't lose any money." << endl;
    }

    return moneyAmounts;
}
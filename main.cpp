#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int menuChoice;
string firstInput;
int invitedGuests;
bool menu1check = false;
bool menu2check = false;
bool menu4check = false;
int main();


int menu1 () {
    cout << "Please enter the number of guests: " << endl;
    cin >> invitedGuests;

    while (invitedGuests < 0) {
        cout << "The number entered is invalid.";
        cin >> invitedGuests;
    }
    return invitedGuests;
}

void menu2 (int guests, int &invitationCards, int &numberofSweets) {
    invitationCards = ceil(guests / 2);
    numberofSweets = guests * 1.2;
    cout << "You need " << invitationCards << "invitation cards, and " << numberofSweets << "number of sweets" << endl;

}

void menu3(int guests, int &tables) {
    int extraTable;
    tables = guests /6;
    extraTable = guests % 6;
    if (extraTable != 0) {
        tables += 1;
    }
    cout << "You need " << tables << "number of tables." << endl;
}


void menu4(int guests, int &coke_cases, int &water_cases) {
    menu4check = true;
    coke_cases = guests / 6;
    water_cases = guests / 2;
}


void menu5(int invitationcards, int &cost_of_cards) {
    cost_of_cards = invitationcards * 200;
    cout << "The cost of cards will be " << cost_of_cards << "NOK." << endl;
}

void menu6(int coke_cases, int water_cases, int &cost_of_drinks) {
    cost_of_drinks = coke_cases * 30 + water_cases * 20;
    cout << "The total cost of drinks will be " << cost_of_drinks << "NOK." << endl;

}


int main() {
    int numberofSweets, guests, invitationCards, tables, coke_cases, water_cases, cost_of_cards, cost_of_drinks;

    cout << "Welcome to the Wedding Planning Assistant. I am pleased to be at your service." << endl;
    cout << "To continue, and agree upon a $500 charge for this service, type wedding in the field below: " << endl;
    cout << "To quit, type q" << endl;
    cin >> firstInput;
    if (firstInput == "wedding") {
        cout << "You have agreed to a $500 charge";

    } else if (firstInput == "q") {
        cout << "Good bye!";
        exit(0);
    }

    do {
        cout << "1. Enter number of invited guests." << endl;
        cout << "2.Determine the number of invitation cards and sweets" << endl;
        cout << "3. Determine the number of tables needed" << endl;
        cout << "4. Determine drinks order" << endl;
        cout << "5. Cost of invitation cars" << endl;
        cout << "6. Cost of drinks" << endl;
        cout << "7. Display all information" << endl;
        cout << "8. Quit" << endl;
        cout << "Please choose an option: " << endl;

        cin >> menuChoice;
        if (menuChoice == 1) {
            menu1();
            guests = menu1();
            menu1check = true;
        } else if (menuChoice == 2) {
            if (menu1check = false) {
                menu1();
                guests = menu1();
            }
            menu2(guests, invitationCards, numberofSweets);
            menu2check = true;
        } else if (menuChoice == 3) {
            if (menu1check = true) {
                menu3(guests, tables);
            }
            else {
                cout << "You need to enter the number of invited guests. " << endl;
            }
            menu3(guests, tables);
        } else if (menuChoice == 4) {
            menu4(guests, coke_cases, water_cases);
            cout << "You will need " << coke_cases << "cases of coke, and " << water_cases << "cases of water." << endl;
        } else if (menuChoice == 5) {
            if (menu1check == true && menu2check == true) {
                menu5(invitationCards, cost_of_cards);
                cout << "The cost of the invitation cards is " << cost_of_cards << "NOK." << endl;
            }
            else {
                cout << "You need to enter numbers of guests in menu option 1 and determine invitation cards and sweets in menu option 2 first." << endl;
            }
        } else if (menuChoice == 6) {
            if (menu1check == true && menu4check == true) {
                menu6(coke_cases, water_cases, cost_of_drinks);
                cout << "The cost of drinks are " << cost_of_drinks << "NOK.";
            }
            else {
                cout << "You need to enter number of guests in menu option 1 and determine amount of drinks in menu option 4 first." << endl;
            }
        } else if (menuChoice == 7) {
            cout << "We will now display all information from this planning assistant." << endl << "You have "
                 << invitedGuests << "invited guests and you need " << invitationCards << "invitation cards." << endl;
            cout << "tables " << tables << "cases of coke: " << coke_cases << "cases of water " << water_cases << endl;
        } else if (menuChoice == 8) {
            cout << "Good bye!" << endl;
            break;
        } else {
            cout << "You need to enter a number from the menu. Try again." << endl;
            break;
        }
    }
    while (firstInput != "quit");

}






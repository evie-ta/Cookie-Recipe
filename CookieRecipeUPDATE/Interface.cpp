#include "Interface.h"
#include "CookieList.cpp"

#include <string>
#include <iostream>

using namespace std;

int validateSelection(CookieList& cookieList)
{
    bool wrongChoice = true;
    int selection = 0;
    while (wrongChoice)
    {
        cin >> selection;

        if (!cin || selection > cookieList.getCount() || selection <= 0)
        {
            cout << "Not a valid choice. Select between 1-12: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else
        {
            wrongChoice = false;
        }
    }
    return selection;
}

char validateYNInput()
{
    char input = 'y';
    bool wrong = false;

    while (!wrong)
    {
        cin >> input;
        input = tolower(input);

        if (input == 'y' || input == 'n')
            wrong = true;
        else
        {
            cout << "Not a valid choice. Select y/n: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    }
    return input;
}

void displayMenu()
{
    cout << "**************************************************************" << endl
    << "                        COOKIE RECIPES" << endl
    << "**************************************************************" << endl
    << endl;

    cout << "Select one of the following:" << endl << endl << "    a. Print all recipes"
    << endl << "    b. Print cookie recipe" << endl
    << "    c. Print cookie calories" << endl << "    d. Print limited calories"
    << endl << "    e. Print serving size" << endl << "    f. To exit" << endl << endl;
}

void processChoice(CookieList& cookieList)
{
    cout << "Enter your choice: ";

    bool isEmpty= false;
    bool notN = false;
    char input = 'y';
    size_t selection = 0;

    while (!notN && !isEmpty)
    {
        cin >> input;

        input = tolower(input);

        if (cookieList.isEmpty())
        {
            cerr << endl << "  => There are no recipes in the list." << endl
                << endl << "=============================================================="
                << endl << endl << "Please contact your administrator. Good bye!" << endl;
            isEmpty = true;
        }

        if (input < 97 || input > 102)
        {
            cout << endl << "  => Sorry. That is not a selection." << endl << endl;
            cout << "=============================================================="
                    << endl << endl << "Would you like to continue (y/n)? ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            input = validateYNInput();

            if (input == 'y')
            {
                displayMenu();
                cout << "Enter your choice: ";
            }
            else
            {
                cout << endl << "Thank you for using our software. Good bye!";
                notN = true;
            }
        }
        else
        {
            switch(input)
            {
                case 'a':
                    cout << endl << "--------------------------------------------------------------"
                        << endl << "    COOKIE RECIPES" << endl <<
                        "--------------------------------------------------------------" << endl
                        << endl;
                    cookieList.printAllCookies();
                    break;

                case 'b':
                    cout << endl << "--------------------------------------------------------------"
                        << endl << "    COOKIE RECIPE" << endl <<
                        "--------------------------------------------------------------" << endl
                        << endl << "Choose a cookie to view the recipe." << endl << endl;
                    cookieList.printCookiesSelection();
                    cout << "Your choice: ";

                    selection = validateSelection(cookieList);

                    cout << endl;
                    cookieList.printRecipe(selection);
                    cout << endl;
                    break;

                case 'c':
                    cout << endl << "--------------------------------------------------------------"
                            << endl << "    COOKIE CALORIES" << endl <<
                            "--------------------------------------------------------------" << endl
                            << endl << "Choose a cookie # to view number of calories." << endl
                            << endl;
                    cookieList.printCookiesSelection();
                    cout << "Your choice: ";

                    selection = validateSelection(cookieList);

                    cout << endl;
                    cookieList.printCalories(selection);
                    cout << endl;
                    break;

                case 'd':
                {
                    cout << endl << "--------------------------------------------------------------"
                        << endl << "    MAXIMUM CALORIES" << endl <<
                        "--------------------------------------------------------------" << endl
                        << endl << "What is the maximum # of calories (100-200)? ";

                    size_t maxCalories = 0;

                    cin >> maxCalories;
                    cout << endl;
                    cookieList.printLimitedCalories(maxCalories);
                    cout << endl;
                    break;
                }

                case 'e':
                    cout << endl << "--------------------------------------------------------------"
                            << endl << "    COOKIE SERVING SIZE" << endl <<
                            "--------------------------------------------------------------" << endl
                            << endl << "Choose a cookie # to view number of servings." << endl
                            << endl;
                    cookieList.printCookiesSelection();
                    cout << "Your choice: ";

                    selection = validateSelection(cookieList);

                    cout << endl;

                    cookieList.printServingSize(selection);
                    cout << endl;
                    break;

                case 'f':
                    cout << endl << "Thank you for using our software. Good bye!";
                    isEmpty = true;
                    break;
            }

            if (input != 'f')
            {
                cout << "=============================================================="
                << endl << endl << "Would you like to try again (y/n)? ";

                input = validateYNInput();

                if (input == 'y')
                {
                    cout << endl;
                    displayMenu();
                    cout << "Enter your choice: ";
                }
                else if (input == 'n')
                {
                    cout << endl << "Thank you for using our software. Good bye!";
                    notN = true;
                }
            }
        }
    }
}
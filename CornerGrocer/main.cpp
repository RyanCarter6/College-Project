/*
* Ryan Carter
* Project 3
* 02/16/2023
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

#include "CornerGrocer.h"

int main()
{
    //declares & initializes variables
    CornerGrocer grocer;
    int userInput = 0;

    //sets stock
    grocer.SetStock(grocer.GetFileInput());

    //stores stock to a seperate file
    grocer.BackupData(grocer.GetStock());

    //sets up loop for user input
    while (userInput != 4)
    {
        //prints menu
        grocer.PrintMenu();

        //gets user input
        cin >> userInput;

        //checks if input is a correct value
        if (userInput > 4 && userInput < 1)
        {
            cout << "Please enter a valid input." << endl;
            continue;
        }

        //does an action based on userInput
        switch (userInput)
        {
            //prompt user input for item and display item's quantity
        case 1:
            grocer.OptionOne(grocer.GetStock());
            break;

            //output list with item and item quantity (all items)
        case 2:
            grocer.OptionTwo(grocer.GetStock());
            break;

            //output histogram of item and item quantity then item name and asterisk representing item quantity
        case 3:
            grocer.OptionThree(grocer.GetStock());
            break;

        }
    }

    //prints that program finished
    cout << endl << "Program ended." << endl;

    return 0;
}
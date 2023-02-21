/*
* Ryan Carter
* Project 3
* 02/16/2023
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>
using namespace std;

#include "CornerGrocer.h"

//opens InputFile and returns contents
map<string, int> CornerGrocer::GetFileInput()
{
    //declares variables
    ifstream inFS;
    map<string, int> stockInput;
    string currWord;

    //opens input file then checks if it opened correctly
    inFS.open("InputFile.txt");
    if (!inFS.is_open())
    {
        cout << "File did not open properly, stock is wrong." << endl;
        return stockInput;
    }

    //reads file if it can still be read
    while (!inFS.eof())
    {
        inFS >> currWord;

        //checks map if item isnt in yet
        if (stockInput.count(currWord) == 0)
        {
            //add item to map
            stockInput.emplace(currWord, 1);
        }
        //if item is in
        else
        {
            //increase value by 1
            stockInput.at(currWord) += 1;
        }

    }

    //closes files and returns stock
    inFS.close();
    return stockInput;
}

//writes the data to a file
void CornerGrocer::BackupData(map<string, int> stock)
{
    //creates an opens a file
    ofstream outFS("frequency.dat");

    //checks if file opened properly
    if (!outFS.is_open())
    {
        cout << "Backup file failed to open." << endl;
        return;
    }

    //iterates through stock list
    map<string, int>::iterator it;
    for (it = stock.begin(); it != stock.end(); it++)
    {
        outFS << it->first << " " << it->second << endl;
    }

    //closes file
    outFS.close();
}

//prints a character a certain amount of times
string CornerGrocer::PrintChar(int amount, char chosenChar)
{
    //declares + initializes string var
    string m_list = "";

    //iterates through a specified num of tiemes
    for (int i = 0; i < amount; ++i)
    {
        //prints char
        m_list += chosenChar;
    }

    //returns string var
    return m_list;
}

//prints menu options
void CornerGrocer::PrintMenu()
{
    //prints header
    cout << PrintChar(10, ' ') << "Enter Input" << PrintChar(10, ' ') << endl;

    //prints first row
    cout << PrintChar(30, '*') << endl;

    //gets menu option based on i
    for (int i = 0; i < 4; ++i)
    {
        string optionTXT;
        switch (i)
        {
        case 0:
            optionTXT = "Search Stock";
            break;
        case 1:
            optionTXT = "Check Stock";
            break;
        case 2:
            optionTXT = "Graph Stock";
            break;
        case 3:
            optionTXT = "Exit";
            break;
        }

        //prints menu option
        cout << "* " << i + 1 << " - " << optionTXT << PrintChar(23 - optionTXT.size(), ' ') << '*' << endl;
    }

    //prints end row
    cout << PrintChar(30, '*') << endl;
}

//function for first option: search
void CornerGrocer::OptionOne(map<string, int> stock)
{
    //prints header
    cout << endl << "Enter a one-word search term: " << endl;

    //gets user input
    string searchTerm;
    cin >> searchTerm;

    //changes first letter to uppercase to match stock list
    searchTerm[0] = toupper(searchTerm[0]);

    //changes rest of letters to lowercase to match stocklist
    for (int i = 1; i < searchTerm.size(); ++i)
    {
        searchTerm[i] = tolower(searchTerm[i]);
    }

    //checks if stock has item to search for, then prints outcome
    if (stock.count(searchTerm) == 1)
    {
        cout << searchTerm << ": " << stock.at(searchTerm) << endl << endl;
    }
    else
    {
        cout << "Item not found." << endl << endl;
    }
}

//function for second option: list
void CornerGrocer::OptionTwo(map<string, int> stock)
{
    //prints header
    cout << "Full stock list: " << endl;
    cout << PrintChar(16, '-') << endl;

    //iterates through stock list and prints stock
    map<string, int>::iterator it;
    for (it = stock.begin(); it != stock.end(); it++)
    {
        cout << "\t" << it->first << " " << it->second << endl;
    }

    //ends with footer and newline
    cout << PrintChar(16, '-') << endl << endl;
}

//function for third option: graph
void CornerGrocer::OptionThree(map<string, int> stock)
{
    //prints header
    cout << "Graph of stock: " << endl;
    cout << PrintChar(15, '-') << endl;

    //iterates through stock list
    map<string, int>::iterator it;
    for (it = stock.begin(); it != stock.end(); it++)
    {
        //prints name of item
        cout << PrintChar(15 - it->first.size(), ' ') << it->first << " ";

        //prints a char for quantity of item
        for (int i = 0; i < it->second; ++i)
        {
            cout << "*";
        }

        //ends with newline
        cout << endl;
    }

    //ends with footer and newline
    cout << PrintChar(15, '-') << endl << endl;
}
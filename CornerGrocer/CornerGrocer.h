/*
* Ryan Carter
* Project 3
* 02/16/2023
*/

#ifndef CORNERGROCER_H
#define CORNERGROCER_H

#include <iostream>
#include <map>
#include <string>

using namespace std;

class CornerGrocer {
public:
	map<string, int> GetFileInput();
	void BackupData(map<string, int> stock);
	void PrintMenu();
	void OptionOne(map<string, int> stock);
	void OptionTwo(map<string, int> stock);
	void OptionThree(map<string, int> stock);
	map<string, int> GetStock() { return stock; }
	void SetStock(map<string, int> newStock) { stock = newStock; }
private:
	map<string, int> stock;
	string PrintChar(int amount, char chosenChar);
};

#endif

// Sorting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Sorting.h"
#include <iostream>
#include <time.h> 
//allows the use of namespace std and declares void to be used in the cpp file
using namespace std;

void DisplayUserCommands();
void bubbleSortTest();
void shellSortTest();

//main function that the program runs off of
int main()
{
	//stores the data to be used and creates a new list for the user
	int number;
	int listdata;
	sortingList <int> userlist;
	//welcomes the user
	cout << "Welcome to the double linked list assignment" << endl;
	//checkpoint that can be returnes to
start:
	//calling a function to display the list of user commands
	DisplayUserCommands();
	//get's the user's choice and does something based on it
	cout << "Please enter a number: " << endl;
	cin >> number;
	//does something based on the number the user picks
	switch (number)
	{
		//clears the system of outputs and then loads a function based on the number picked
	case 1:
		system("CLS");
		cout << "Please enter a number to add to the list" << endl;
		cin >> listdata;
		userlist.Add(listdata);
		goto start;
		break;
	case 2:
		system("CLS");
		cout << "Displaying all sets of data in list" << endl;
		userlist.Show();
		goto start;
		break;
	case 3:
		system("CLS");
		cout << "Sorting the list using a simple bubble sort algorithm" << endl;
		cin >> listdata;
		userlist.bubbleSort();
		goto start;
		break;
	case 4:
		system("CLS");
		cout << "Sorting the list using the shell sort algorithm" << endl;
		userlist.shellSort();
		goto start;
		break;
	case 5:
		system("CLS");
		cout << "Running the bubble sort automated test case" << endl;
		bubbleSortTest();
		goto start;
		break;
	case 6:
		system("CLS");
		cout << "Running the shell sort automated test case" << endl;
		shellSortTest();
		goto start;
		break;
	case 7:
		system("CLS");
		return 0;
		break;
	default:
		cout << "You chose an unavailable option. Program will close soon." << endl;
		break;
	}

	system("pause");
	return 0;
}
// funtion to display the list of user commands
void DisplayUserCommands() {
	cout << "List of choices:" << endl;
	cout << "1 Add to the sorting list" << endl;
	cout << "2 Show the sorting list data points" << endl;
	cout << "3 Sort using bubble sorting on the list" << endl;
	cout << "4 Sort using shell sorting ont the  list" << endl;
	cout << "5 Run the premade automated test for bubble sort" << endl;
	cout << "6 run the premade automated test for shell sort" << endl;
	cout << "7 Exit out of the program" << endl;
}
//test void that goes through the functions of the list and diplays the results at vaious points in the process
void bubbleSortTest()
{
	sortingList <int> bubbleSortTestList;

	bubbleSortTestList.bubbleSort();
	bubbleSortTestList.Show();
	bubbleSortTestList.Add(665);
	bubbleSortTestList.Add(479);
	bubbleSortTestList.Add(909);
	bubbleSortTestList.Add(887);
	bubbleSortTestList.Add(838);
	bubbleSortTestList.Add(786);
	bubbleSortTestList.Add(706);
	bubbleSortTestList.Add(312);
	bubbleSortTestList.Add(790);
	bubbleSortTestList.Add(961);
	bubbleSortTestList.Add(400);
	bubbleSortTestList.Add(580);
	bubbleSortTestList.Add(772);
	bubbleSortTestList.Add(825);
	bubbleSortTestList.Add(735);
	bubbleSortTestList.Add(841);
	bubbleSortTestList.Add(811);
	bubbleSortTestList.Add(573);
	bubbleSortTestList.Add(422);
	cout << "Displaying all nodes" << endl;
	bubbleSortTestList.Show();
	cout << "Adding new node" << endl;
	bubbleSortTestList.Add(853);
	bubbleSortTestList.Show();
	cout << "Proceding to sort list" << endl;
	bubbleSortTestList.bubbleSort();
	bubbleSortTestList.Show();

	system("Pause");
}

void shellSortTest()
{
	sortingList <int> shellSortTestList;

	shellSortTestList.shellSort();
	shellSortTestList.Show();
	shellSortTestList.Add(665);
	shellSortTestList.Add(479);
	shellSortTestList.Add(909);
	shellSortTestList.Add(887);
	shellSortTestList.Add(838);
	shellSortTestList.Add(786);
	shellSortTestList.Add(706);
	shellSortTestList.Add(312);
	shellSortTestList.Add(790);
	shellSortTestList.Add(961);
	shellSortTestList.Add(400);
	shellSortTestList.Add(580);
	shellSortTestList.Add(772);
	shellSortTestList.Add(825);
	shellSortTestList.Add(735);
	shellSortTestList.Add(841);
	shellSortTestList.Add(811);
	shellSortTestList.Add(573);
	shellSortTestList.Add(422);
	cout << "Displaying all nodes" << endl;
	shellSortTestList.Show();
	cout << "Adding new node" << endl;
	shellSortTestList.Add(853);
	shellSortTestList.Show();
	cout << "Proceding to sort list" << endl;
	shellSortTestList.shellSort();
	shellSortTestList.Show();

	system("Pause");
}

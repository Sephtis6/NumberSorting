#pragma once
#include "pch.h"
#include <iostream>
#include <time.h> 

using namespace std;
//template used
template <typename T>
//node of the linked list
struct node
{
	//data used
	T data;
	//pointers to next and previous nodes in list
	node <T> *next;
	node <T> *prev;
};

//template used
template <typename T>
//class used
class sortingList
{
	//private data used
private:
	//nodes for the head and tail of the linked list
	node <T> *head;
	node <T> *tail;
public:
	//sets the head and tail of the linked list to null
	sortingList()
	{
		head = nullptr;
		tail = nullptr;
	}
	//void for adding a new node to the list at the end
	void Add(T new_data)
	{
		//makes a new node and then uses that node to hold the new data
		//then takes that node and inputes it as either the head or id one is in the head already
		//it inputes it into the next slot and moves the tail futher back
		node<T> *temp = new node <T>;
		temp->data = new_data;
		temp->next = nullptr;
		if (head == nullptr)
		{
			head = temp;
			tail = temp;
			temp = nullptr;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
		return;
	}
	//void for showing the entire lists data
	void Show()
	{
		//if there is no list it displays that there is none for the user to show on screen
		if (head == nullptr)
		{
			cout << "There is no list to show" << endl;
			return;
		}
		//takes the data and inputes it into a temp node and then goes through the entire list while displaying
		//the data as an output and then tells the user when all nodes are shown
		node <T> *temp = new node <T>;
		temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << ", ";
			temp = temp->next;
		}
		cout << endl << "All nodes shown" << endl;
	}
	//void for sorting the list through a bubble sort algortihm
	void bubbleSort()
	{
		//if there is no list it displays that there is none for the user to sort on screen
		if (head == nullptr)
		{
			cout << "There is no list to sort through" << endl;
			return;
		}
		// clock allowing the time it takes to run be measures
		clock_t C;
		//starts the clock by memorizing the time it starts sorting
		C = clock();
		//point to loop to
	reRun:
		//creates a node and points it as head and creates a variable for future use
		node<T>* temp = head;
		T temp2;
		//while the tem is not the tail node runs through the funxtion
		while (temp != tail)
		{
			//if the data in the next node is higher then the data in the node before
			//if goes through and switches their data around and then continues on with the list
			if (temp->data > temp->next->data)
			{
				temp2 = temp->data;
				temp->data = temp->next->data;
				temp->next->data = temp2;
			}
			//then temp = the next node and runs through again
			temp = temp->next;
		}
		//otherwise when the temo node is == to the tail node
		if (temp == tail)
		{
		//resets the temp to head
			temp = head;
			//then runs through the entire list again to check and see if any data is still out of place
			while (temp != tail)
			{
				if (temp->data > temp->next->data)
				{
					temp = temp->next;
					break;
				}
				//if there is data out of place it loops to the rerun break and goes through the program again till it is sorted from least to greatest
				else
				{
					goto reRun;
				}
			}
			//finds how long the program ran bu taking the current time and removing the time when the list started sorting
			//then displays that info the the user that it took a certain amount of time for the program to sort the list
			C = clock() - C;
			cout << "It took the program " << C << " clicks (" << (((double)C) / CLOCKS_PER_SEC) << " seconds) to sort the list." << endl;

			//if the length of the list is less then 100 it will whow the entire list after sorting
			if (listLength() <= 100)
			{
				Show();
			}

			return;
		}

	}
	//void for the shell sort algorithm
	void shellSort()
	{
		//if there is no list it displays that there is none for the user to sort on screen
		if (head == nullptr)
		{
			cout << "There is no list to sort through" << endl;
			return;
		}

		// clock allowing the time it takes to run be measures
		clock_t C;
		//starts the clock by memorizing the time it starts sorting
		C = clock();
		//makes the variables to be used in the sorting process
		//along with creating an array to sort instead of trying to sort the list
		T arraySize = listLength();
		T *tempArray = new T [arraySize];
		node<T>* temp = head;
		//tempArray = new T tempArray[arraySize - 1];
		T spot = 0;
		//goes through the program initialy to copy all data from the lsit to and array
		while (temp != tail)
		{
			tempArray[spot] = temp->data;
			temp = temp->next;
			spot++;
		}
		if (temp == tail)
		{
			tempArray[spot] = temp->data;
		}
		//creates a temp int to use
		T tempInt;
		//runs through the array and checks each spot that is seperated by a set distance that eventually becomes 1
		//if a data point earlier is larger then the later it switches them otherwise it continues on sorting till the entire list should be sorted
		for (T size = spot / 2; size > 0; size /= 2)
		{
			for (T size2 = size; size2 < spot; size2++)
			{
				for (T size3 = size2 - size; size3 >= 0; size3 = size3 - size)
				{
					if (tempArray[size3 + size] >= tempArray[size3])
					{
						break;
					}
					else
					{
						tempInt = tempArray[size3];
						tempArray[size3] = tempArray[size3 + size];
						tempArray[size3 + size] = tempInt;
					}
				}
			}
		}

		//create another temp node and another spot int
		node<T>* temp2 = head;
		T spot2 = 0;
		//goes through the list again and takes the data from the array and moves it to the list in order to have the list sorted
		while (temp2 != tail)
		{
			temp2->data = tempArray[spot2];
			temp2 = temp2->next;
			spot2++;
		}
		if (temp2 == tail)
		{
			temp2->data = tempArray[spot2];
		}
		
		//finds how long the program ran bu taking the current time and removing the time when the list started sorting
		//then displays that info the the user that it took a certain amount of time for the program to sort the list
		C = clock() - C;
		cout << "It took the program " << C << " clicks (" << (((double)C) / CLOCKS_PER_SEC) << " seconds) to sort the list." << endl;

		//if the length of the list is less then 100 it will whow the entire list after sorting
		if (listLength() <= 100)
		{
			Show();
		}

		return;

	}

	//goes through the list and checks to see how many node are in the list for reference to be used in the program
	T listLength()
	{
		node<T>* temp = head;
		T length = 0;

		while (temp != tail)
		{
			length++;
			temp = temp->next;
		}
		if (temp == tail)
		{
			length++;
		}
		return length;
	}
};
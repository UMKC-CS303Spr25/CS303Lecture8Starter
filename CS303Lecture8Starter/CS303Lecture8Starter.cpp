// CS303Lecture8Starter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// CS303Lecture8b.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//https://github.com/UMKC-CS303Spr25/CS303Lecture8Starter


#include <iostream>
#include <string>
#include "functions.h"
using namespace std;

int main() {

	//Implementation 1: Using STL List
	LQ::ListQueue<string> customerQueue;

	//Implementation 2:Using LinkedList created previously
	//LLQ::LinkedListQueue<string> customerQueue;

	//Implementation 3: Using a Circular Array
	//CQ::CQueue<string> customerQueue;

	//Implementation 4: Using the Deque with Circular Arrays
	//DQ::Deque<string> customerQueue;

	string name;
	size_t index;
	int choice = -1;

	while (choice != 99) {
		choice = displayMenu();
		if (choice == 99) {
			cout << "Thank you" << endl;
			break;
		}
		try {
			switch (choice) {
			case 1:
				cout << "Enter Name to pushBack: ";
				getline(cin, name);
				customerQueue.pushBack(name);
				break;
			case 2:
				cout << "Show Front Entry: ";
				cout << customerQueue.front() << endl;
				break;
			case 3:
				cout << "Pop Front - Removing Customer: " << customerQueue.front() << " from the list." << endl;
				customerQueue.popFront();
				break;
			case 4:
				cout << "Show Queue Size: ";
				cout << customerQueue.size() << endl;
				break;

			case 5:
				cout << "Printing Current Queue: " << endl;
				customerQueue.printQueue();
				break;

			case 6:
				cout << "Enter the Index to Display: ";
				cin >> index;
				getline(cin, name);
				cout << "The value at index " << index << " is " << customerQueue[index] << endl;
				break;

				/*
				case 7:
					cout << "Enter Name to pushFront: ";
					getline(cin, name);
					customerQueue.pushFront(name);
					break;
				
				case 8:
					cout << "Removing Customer: " << customerQueue.back() << " from the list." << endl;
					customerQueue.popBack();
					break;
				case 9:
					cout << "Enter Name to Remove: ";
					getline(cin, name);
					customerQueue.removeItem(name);
					break;
				case 10:
					cout << "Enter Name to Add: ";
					getline(cin, name);
					customerQueue.pushPriority(name);
					break;
				*/
			default:
				cout << "Please enter a valid choice" << endl;
			}
		}
		catch (runtime_error& err) {
			cout << err.what() << endl;
		}
		catch (std::out_of_range& err) {
			cout << err.what() << endl;
		}
	}

}
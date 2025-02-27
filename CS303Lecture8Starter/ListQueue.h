#pragma once

#include<list>
#include <iostream>
namespace LQ {
	using namespace std;
	template <typename ItemType>
		class ListQueue {
		private:
			list <ItemType> LQueue;
			int numItems;
		public:
			ListQueue();
			void pushBack(const ItemType& item);
			void popFront();
			ItemType& front();
			int size();
			void printQueue();

			//Overloading the [] operator
			//PRE:  accepts an index
			//POST: verifies index value
			//      if invalid, throws an out_of_range error
			//      else returns the value at that index (using offset)
			ItemType operator[] (size_t n) {
				if (n > numItems - 1)
					throw exception("Accessing out of range\n");
				else if (numItems == 0)
					throw exception("No Elements in the list\n");
				typename list<ItemType>::iterator it = LQueue.begin();
				for (int i = 0; i < n; ++i)
					++it;
				return *it;
			}
		};

	//default constructor
	template <typename ItemType>
	ListQueue<ItemType>::ListQueue() {
		numItems = 0;
	}

	//PRE: accepts a new item
	//POST: adds item to the end of the list  
	//      increases numItems
	template <typename ItemType>
	void ListQueue<ItemType>::pushBack(const ItemType& item) {
		LQueue.push_back(item);
		++numItems;
	}

	//PRE:  none
	//POST: if the list is empty, throw runtime_error
	//      otherwise pop the first element from the queue 
	//      decrements numItems
	template <typename ItemType>
	void ListQueue<ItemType>::popFront() {
		if (numItems == 0)
			throw runtime_error("List is empty");
		LQueue.pop_front();
		--numItems;
	}

	//PRE: none
	//POST: if list is not empty, 
	//      return item at frontIndex
	template <typename ItemType>
	ItemType& ListQueue<ItemType>::front() {
		if (numItems == 0)
			throw runtime_error("List is empty");
		typename list<ItemType>::iterator it = LQueue.begin();
		return *it;
	}

	//PRE: none
	//POST: returns numItems 
	template <typename ItemType>
	int ListQueue<ItemType>::size() {
		return numItems;
	}
	
	//PRE:   none
	//POST: prints list to standard output 
	template <typename ItemType>
	void ListQueue<ItemType>::printQueue() {
		typename list<ItemType>::iterator it;
		for (it = LQueue.begin(); it != LQueue.end(); ++it)
			cout << '\t' << *it;
		cout << '\n';
	}
}
 
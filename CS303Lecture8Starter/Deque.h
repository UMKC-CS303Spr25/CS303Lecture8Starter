#pragma once
#include "CQueue.h"

namespace DQ {
	template <typename ItemType>
	class Deque {
	private:
		static const size_t BLOCK_SIZE = 4;
		size_t offset;
		size_t numItems;
		CQ::CQueue<ItemType*> theData;  

	public:
		Deque();
		ItemType& operator[] (size_t i);
		void pushBack(const ItemType& item);
		void popFront();
		ItemType& front();
		void pushFront(const ItemType& item);
		size_t size() { return numItems; }
		void printQueue();
	};

	//default constructor
	template<typename ItemType>
	Deque<ItemType>::Deque() {
		offset = BLOCK_SIZE / 2;
		numItems = 0;
		theData.pushBack(new ItemType[BLOCK_SIZE]);
	}

	//overloaded operator []
	//PRE:  accepts an index
	//POST: verifies index value
	//      if invalid, throws an out_of_range error
	//      else returns the value at that index (using offset)
	template<typename ItemType>
	ItemType& Deque<ItemType>::operator[](size_t index) {
		std::cout << "INDEX[] = " << index << "\t";
		if (index < 0 || index > numItems)
			throw std::out_of_range("Invalid index to queue");

		size_t blockIndex = (offset + index) / BLOCK_SIZE;
		size_t dataIndex = (offset + index) % BLOCK_SIZE;
		return theData[blockIndex][dataIndex];
	}
	
	//PRE:  none
	//POST: returns the value at 0th position of the queue
	template<typename ItemType>
	ItemType& Deque<ItemType>::front() {
		return (*this)[0];
	}

	//PRE: accepts the new item
	//POST: calculate the current capacity
	//      if we have filled the current block
	//          allocate a new block of space (array of size BLOCKSIZE)
	//			push the address onto theData
	//      add item to the new location
	//      increment numItems
	template<typename ItemType>
	void Deque<ItemType>::pushBack(const ItemType& item) {

		int capacity = theData.size() * BLOCK_SIZE;
		std::cout << "DQ: pushBack numItems: " << numItems << " offset: " << offset << " capacity: " << capacity << std::endl;
		if ((numItems + offset) == capacity) {
			ItemType* temp = new ItemType[BLOCK_SIZE];
			std::cout <<  "*address of new block = " <<  temp << std::endl;
			theData.pushBack(temp);
			//
			// theData.pushBack(new ItemType[BLOCK_SIZE]);
		}

		(*this)[numItems] = item;
		++numItems;
	}


	//PRE: accepts the new item
	//POST: calculate the current capacity
	//      if we have filled the current block
	//          allocate a new block of space (array of size BLOCKSIZE)
	//			push the address onto theData
	//      add item to the new location
	//      increment numItems
	template<typename ItemType>
	void Deque<ItemType>::pushFront(const ItemType& item) {

		//If the first block starts at 0
		//   Push an new block onto the front of theData
		std::cout << "DQ: pushFront numItems: " << numItems << " offset: " << offset << std::endl;
		if (offset == 0) {
			ItemType* temp = new ItemType[BLOCK_SIZE];
			std::cout << "*address of new block = " << temp << std::endl;
			theData.pushFront(temp);
			(*this)[BLOCK_SIZE - 1] = item;
			offset = BLOCK_SIZE - 1;
			++numItems;
			return;
		}
		--offset;
		(*this)[offset] = item;
		++numItems;
	}
	//PRE: none
	//POST: increment offset (effecively deleting the front)  
	//      if we are at blocksize we have exhausted the current block
	//      so, free up the old block (delete)
	//      get rid of front (popFront)
	//      reset the offset
	template<typename ItemType>
	void Deque<ItemType>::popFront() {
		offset++;
		if (offset == BLOCK_SIZE) {
			delete[] theData.front();
			theData.popFront();
			offset = 0;
		}
		numItems--;
	}

	//PRE:  none
	//POST: prints list to standard output  
	template<typename ItemType>
	void Deque<ItemType>::printQueue() {
		for (size_t i = 0; i < numItems; ++i)
			std::cout << (*this)[i] << " ";
		std::cout << std::endl;
	}
}
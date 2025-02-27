#pragma once
#include <iostream>

namespace CQ { // circular queue namespace
	// this 'queue' is implemented using a dynamic circular array

	template<typename ItemType>
	class CQueue {

	private:

		// Data fields
		static const size_t DEFAULT_CAPACITY = 2;
		size_t capacity;
		size_t numItems;
		int frontIndex;
		int rearIndex;
		ItemType* theData;

	public:
		CQueue();
		void pushBack(const ItemType& item);	//Menu Item #1
		ItemType& front();						//Menu Item #2
		const ItemType& front() const;			//Menu Item #2
		void popFront();						//Menu Item #3
		size_t size() const { return numItems; }		//Menu Item #4
		bool empty() const { return numItems == 0; }	//Menu Item #4

		void reallocate();						//TASK #1

		//TASK #2
		void printQueue();						//Menu Item #5
		ItemType& operator[](size_t i);			//Menu Item #6
		void pushFront(const ItemType& item);	//Menu Item #7
		void popBack();							//Menu Item #8
		ItemType& back();						//used in Menu Item #8

		//TASK #3
		void removeItem(const ItemType item);	//Menu Item #9

		//TASK #4
		void pushPriority(const ItemType& item); //Menu Item #10
	};

	//Overloading the [] operator
	//PRE:  accepts an index
	//POST: verifies index value
	//      if invalid, throws an out_of_range error
	//      else returns the value at that index (using offset)
	template<typename ItemType>
	ItemType& CQueue<ItemType>::operator[](size_t index) {

		if (index >= numItems) {
			throw std::out_of_range("Index out of bounds!");
		}
		return theData[(frontIndex + index) % capacity];
	}

	//default constructor
	template<typename ItemType>
	CQueue<ItemType>::CQueue() {
		std::cout << "Default constructor for CQueue\n";
		capacity = DEFAULT_CAPACITY;
		numItems = 0;
		frontIndex = 0;
		rearIndex = DEFAULT_CAPACITY - 1;
		theData = new ItemType[DEFAULT_CAPACITY];
	}

	//TASK 1
	//PRE: array must be resized
	//POST: double capacity, allocate new array 
	//      copy items from the frontIndex to 0 to end of list
	//      reset indexes, capacity, swap (move new into old & old into new)
	//      delete newData
	template<typename ItemType>
	void CQueue<ItemType>::reallocate() {
		std::cout << "Before resizing:  Front: " << frontIndex << " Back:" << rearIndex << "\n";
		// set new capacity

		// allocate new array

		//copy from frontIndex to 0th position each value from old array

		//reset frontIndex, rearIndex, capacity
		
		//swap newData with theData
		
		//delete newData
	}

	//PRE: none
	//POST: if list is not empty, 
	//      return item at frontIndex
	template<typename ItemType>
	ItemType& CQueue<ItemType>::front() {
		if (empty())
			throw std::runtime_error("List is empty");
		
		return theData[frontIndex];
	}


	//MENU ITEM #1
	//PRE: accepts item to be added to the back
	//POST: if list is full, allocate new space
	//      if list is empty, set indexes
	//      else update rear index, numItems & add data to array

	template<typename ItemType>
	void CQueue<ItemType>::pushBack(const ItemType& item) {
		std::cout << "CQ: pushBack: " << item << " numItems: " << numItems
			<< " capacity: " << capacity << std::endl;

		if (numItems == capacity) {
			reallocate();
		}
		
		numItems++;
		rearIndex = (rearIndex + 1) % capacity;
		theData[rearIndex] = item;
	}
	//MENU ITEM #2
	//PRE: none
	//POST: if list is not empty, 
	//      return item at frontIndex
	template<typename ItemType>
	const ItemType& CQueue<ItemType>::front() const {
		if (empty())
			throw std::runtime_error("List is empty");

		return theData[frontIndex];
	}


	//MENU ITEM #3
	//PRE: none
	//POST: if list is not empty, 
	//      remove item/advance frontIndex
	//      reduce numItems
	template<typename ItemType>
	void CQueue<ItemType>::popFront() {
		if (empty())
			throw std::runtime_error("List is empty");

		frontIndex = (frontIndex + 1) % capacity;
		numItems--;
	}


	//MENU ITEM #5
	//PRE: none
	//POST: prints the queue
	template<typename ItemType>
	void CQueue<ItemType>::printQueue() {
		
		//print items using 'circular queue' logic
		size_t j = frontIndex;
		
		for (size_t i = 0; i < numItems; i++) {
			std::cout << theData[j] << " ";
			j = (j + 1) % capacity;
		}
		std::cout << "\n";


	}

	//TASK 2 - MENU ITEM #7
	//PRE:  accepts an item to add to the queue
	//POST: if list is full, update capacity
	//      increment numItems, 
	//      calculate frontIndex (using circular logic)
	//      add item to location of frontIndex

	template<typename ItemType>
	void CQueue<ItemType>::pushFront(const ItemType& item) {
		std::cout << "pushFront: " << item << " numItems: " << numItems << " capacity: " << capacity << std::endl;
	}


	//TASK 2: MENU ITEM #8 (TO DISPLAY LAST ITEM IN QUEUE)
	//PRE: none
	//POST: if list is not empty, 
	//      return item at rearIndex
	template<typename ItemType>
	ItemType& CQueue<ItemType>::back() {
		//if listis empty - throw runtime_error

		//return the last item in theData
	}

	//TASK 2: MENU ITEM #8 
	//PRE: none
	//POST: if list is not empty, reset the rearIndex (using circular queue logic)
	//      decrement numItems
	template<typename ItemType>
	void CQueue<ItemType>::popBack() {


	}

	//TASK 3 - MENU ITEM #9

	template<typename ItemType>
	void CQueue<ItemType>::removeItem(const ItemType item) {

		//initialize to count #items deleted
		//save old size

		//loop until you get through old items in queue
		//if item is to be deleted
		//    increment delete count
		//else push item onto the list
		//pop old front



		//reset numItems
	}

	//TASK 4 - MENU ITEM #10
	//PRE: accepts new item to add
	//     assumes all previous elements were added as priority
	//     and list is ordered
	//POST: if list is full, add additional capcaity
	//      adds the new item at its appropriate location based on value

	template<typename ItemType>
	void CQueue<ItemType>::pushPriority(const ItemType& item) {
		std::cout << "pushPriority: " << item << " numItems: " << numItems << " capacity: " << capacity << std::endl;

		//if list is full add additional capacity


		//advance 'i' to the location of insertion
		// stopping when item > theData[index]
		// NOTE: advance index using circular logic

		//shift the elements from the 'end' to where new element is inserted to the right


		//increment numItems
		//place item at the 'i'th position from the front index
		//reset the rear index
	


}

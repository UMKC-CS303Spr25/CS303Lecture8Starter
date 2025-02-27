#include "functions.h"


//PRE: none
//POST: display menu, verify valid choice, return choice
int displayMenu() {

	std::string strIn = "A";
	int choice = -1;
	while (!(strIn.find_first_not_of("0123456789") == std::string::npos)){
		std::cout << "\n1(pushBack)\n2(front)\n3(popFront) ";
		std::cout << "\n4(size)\n5(print)\n6(index)\n7(pushFront) ";
		std::cout << "\n8(popBack)\n9(remove)\n10(pushPriority)\n99(quit)\n";
		std::cout << "enter your choice : ";
		std::getline(std::cin,strIn);
		if (strIn.find_first_not_of("0123456789") == std::string::npos) {
			choice = stoi(strIn);
			if (choice >= 1 && choice <= 10 || choice == 99)
				break;
		}
	}
	return choice;
}

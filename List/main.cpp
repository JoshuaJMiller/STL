#include <iostream>
#include <list>
#include <iterator>

void printList(std::list<int> p_list)
{
	for (std::list<int>::iterator it = p_list.begin(); it != p_list.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	std::cout << "--------------------" << std::endl;
}

//MAKE REPO BEFORE FINISHING

int main()
{

	std::list<int> numbers;
	int selection{ 0 };
	

	while (selection != 4)
	{
		std::cout << "MENU: \n1 - add number\n2 - erase number\n3 - display number(s)\n4 - quit\n5 - inset number\n>";
		std::cin >> selection;
		if (selection == 1)
		{
			std::cout << "enter number to add >";
			int number;
			std::cin >> number;
			numbers.push_back(number);
		}
		else if (selection == 2)
		{
			//add erase funtionality
		}
		else if (selection == 3)
		{
			printList(numbers);
		}
		else if (selection == 5)
		{
			std::cout << "insert where? >";
			int itIndex;
			std::cin >> itIndex;
			std::list<int>::iterator it = numbers.begin();
			std::advance(it, itIndex);
			std::cout << "insert what? >";
			int num;
			std::cin >> num;
			numbers.insert(it, num);
		}
	}

	printList(numbers);

	std::list<int>::iterator it2 = numbers.begin();

	++it2;

	numbers.insert(it2, 100);

	printList(numbers);

	it2 = numbers.erase(it2);

	printList(numbers);

	std::cout << *it2;

	return 0;
}
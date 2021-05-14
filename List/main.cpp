#include <iostream>
#include <list>
#include <iterator>
#include <fstream>
#include <string>

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
		std::cout << "MENU: \n1 - add number\n2 - erase number\n3 - display number(s)\n4 - quit\n5 - inset number\n6 - save list to file\n7 - load list from file\n>";
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
			std::cout << "delete which index? >";
			int itIndex;
			std::cin >> itIndex;
			std::list<int>::iterator it = numbers.begin();
			std::advance(it, itIndex);
			it = numbers.erase(it);
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
		else if (selection == 6)
		{
			std::ofstream outFile;
			std::string fileName;
			std::cout << "enter file name >";
			std::cin >> fileName;
			outFile.open(fileName);
			if (outFile.is_open())
			{
				for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
				{
					outFile << *it;
					if (*it != numbers.back())
					{
						outFile << std::endl;
					}
				}
				outFile.close();
			}
			else
			{
				std::cerr << "file :" << fileName << " not not open" << std::endl;
			}

		}
		else if (selection == 7)
		{
			std::cout << "save current list? (y/n) >";
			char saveSelection;
			std::cin >> saveSelection;
			if (saveSelection == 'y' || saveSelection == 'Y')
			{
				std::ofstream outFile;
				std::string fileName;
				std::cout << "enter file name >";
				std::cin >> fileName;
				outFile.open(fileName);
				if (outFile.is_open())
				{
					for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
					{
						outFile << *it;
						if (*it != numbers.back())
						{
							outFile << std::endl;
						}
					}
					outFile.close();
				}
				else
				{
					std::cerr << "file :" << fileName << " not not open" << std::endl;
				}
			}
			else if (saveSelection == 'n' || saveSelection == 'N')
			{
				std::cout << "current list erased" << std::endl;
			}

			numbers.clear();

			std::cout << "enter file name to load >";
			std::string inFileName;
			std::cin >> inFileName;
			std::ifstream inFile;
			inFile.open(inFileName);
			if (inFile.is_open())
			{
				int fileNum;
				std::string num;
				while (!inFile.eof())
				{
					getline(inFile, num);
					fileNum = std::stoi(num);
					numbers.push_back(fileNum);
				}
				inFile.close();
			}
			else
			{
				std::cerr << "error opening file " << inFileName << std::endl;
			}


		}
	}

	//printList(numbers);

	//std::list<int>::iterator it2 = numbers.begin();

	//++it2;

	//numbers.insert(it2, 100);

	//printList(numbers);

	//it2 = numbers.erase(it2);

	//printList(numbers);

	//std::cout << *it2;

	return 0;
}
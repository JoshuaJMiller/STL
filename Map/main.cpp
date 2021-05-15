#include <iostream>
#include <map>
#include <string>

class Person
{
public:
	Person(){};
	Person(std::string p_name, int p_age)
		: name(p_name), age(p_age)
	{};

	std::string getName()
	{
		return name;
	}
	int getAge()
	{
		return age;
	}

private:

	std::string name;
	int age;
};

std::ostream& operator<< (std::ostream &os, Person &p_person)
{
	os << "name: " << p_person.getName() << ", age: " << p_person.getAge();
	return os;
}

int main()
{
	/*std::map<std::string, int> ages;

	ages["BarniE"] = 12;
	ages["Lingy"] = 90;
	ages["ricky"] = 9;

	for (std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); ++it)
	{
		std::cout << it->first << " : " << it->second << std::endl;
	}
	
	std::cout << "-------------------" << std::endl;
	
	std::string findKey;

	std::cout << "enter key to find value > ";
	getline(std::cin, findKey);

	if (ages.find(findKey) != ages.end())
	{
		std::cout << "Found " << findKey << " : " << ages[findKey] << std::endl;
	}
	else
	{
		std::cout << findKey << " not found" << std::endl;
	}
	
	std::cout << "----------------------" << std::endl;

	std::cout << "add pair to map. enter key > ";
	std::string keyToAdd;
	getline(std::cin, keyToAdd);
	std::cout << "enter value of " << keyToAdd << " > ";
	int ageToAdd;
	std::cin >> ageToAdd;

	ages.insert(std::make_pair(keyToAdd, ageToAdd));

	for (std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); ++it)
	{
		std::cout << it->first << " : " << it->second << std::endl;
	}

	Person person1("Ron", 22);
	Person person2("Don", 24);
	Person person3("Puke", 28);

	std::cout << person1 << std::endl;*/

	std::string s{ "person" + 1 };
	std::cout << s << std::endl;

	std::map<int, Person> people;

	for (int i{ 0 }; i < 10; ++i)
	{
		people[i] = Person(("person" + std::to_string(i)), (10 + i));
	}

	for (auto person : people)
	{
		std::cout << person.first << " : " << person.second << std::endl;
	}

	return 0;
}
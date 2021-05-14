#include <iostream>
#include <vector>

int main()
{
	std::vector<int> ints{ 2, 4, 6, 8 };

	std::vector<std::vector<int>> grid(4, std::vector<int>(4, 8));

	for (size_t row{ 0 }; row < grid.size(); ++row)
	{
		for (size_t col{ 0 }; col < grid.at(row).size(); ++col)
		{
			std::cout << grid.at(row).at(col);
		}
		std::cout << std::endl;
	}

	return 0;
}
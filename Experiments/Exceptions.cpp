#include <iostream>
#include <vector>

void f_ex()
{
	try
	{
		std::vector<int> v {1,2,3};
		int a = v.at(4);
		std::cout << a << std::endl;
	}
	catch (std::exception& ex)
	{
		std::cout << "Error: " << ex.what() << std::endl;
		return;
	}
	std::cout << "Ok" << std::endl;
}


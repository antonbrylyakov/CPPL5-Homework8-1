#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#ifdef _WIN32
#include "windows.h"
#endif



template <typename T>
void makeDistinct(std::vector<T>& vec)
{
	// алгоритм по возможности сохранит порядок элементов
	std::unordered_set<T> uniques;
	auto removedIt = std::remove_if(vec.begin(), vec.end(),
		[&uniques](const auto x)
		{
			auto res = uniques.contains(x);
			if (!res)
			{
				uniques.insert(x);
			}

			return res;
		});

	vec.erase(removedIt, vec.end());
}

int main()
{
	setlocale(LC_ALL, "Russian");
#ifdef _WIN32
	SetConsoleCP(1251);
#endif

	std::vector<int> input{ 1, 1, 2, 5, 6, 1, 2, 4 };

	std::cout << "[IN]: ";
	for (auto& x : input)
	{
		std::cout << x << " ";
	}

	std::cout << std::endl;

	makeDistinct(input);

	std::cout << "[OUT]: ";
	for (auto& x : input)
	{
		std::cout << x << " ";
	}

	std::cout << std::endl;
}
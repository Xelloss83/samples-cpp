#include <iostream>
#include <functional>

size_t FibonacciSum(size_t less_than, const std::function<bool(size_t)>& pred = [](size_t) { return true; })
{
	size_t current = 0;
	size_t prev = 1;
	size_t result = 0;

	while (current < less_than)
	{
		if (pred(current))
			result += current;

		auto sum = prev + current;
		prev = current;
		current = sum;
	}

	return result;
}

void main()
{
	std::wcout << L"Sum of even Fibonacci numbers less than 1000: "
		<< FibonacciSum(1000, [](size_t val) { return val % 2 == 0; })
		<< std::endl;

	std::wcout << L"\n\nPress enter...";
	std::wcin.get();
}
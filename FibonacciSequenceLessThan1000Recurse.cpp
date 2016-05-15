#include <iostream>
#include <vector>

/*
Recursively fill passed container with Fibonacci numbers with values less than requested.
To save stack space during recursion (to not to pass limit and generated values)
class is introduced. Generated values and generation limit are stored as that class
fields, so only one pointer is stored on the stack on each level of recursion.
*/
template <typename Container>
class FibonacciSequenceGeneratorRecurse
{
public:
	explicit FibonacciSequenceGeneratorRecurse(Container& container, size_t less_than = 1000)
		: m_values(container)
		, m_limit(less_than)
	{
		if (less_than == 0)
			return;

		m_values.push_back(0);
		m_values.push_back(1);

		FillSequenceRecurse();
	}

	FibonacciSequenceGeneratorRecurse(const FibonacciSequenceGeneratorRecurse<Container>&) = delete;
	FibonacciSequenceGeneratorRecurse(const FibonacciSequenceGeneratorRecurse<Container>&&) = delete;
	FibonacciSequenceGeneratorRecurse& operator=(const FibonacciSequenceGeneratorRecurse<Container>&) = delete;
	FibonacciSequenceGeneratorRecurse& operator=(const FibonacciSequenceGeneratorRecurse<Container>&&) = delete;

private:
	void FillSequenceRecurse()
	{
		auto prev_it = --m_values.end();
		auto last_it = prev_it--;

		auto sum = *prev_it + *last_it;
		if (sum >= m_limit)
			return;

		m_values.push_back(sum);

		FillSequenceRecurse();
	}

	Container& m_values;
	size_t m_limit = 0;
};

void main()
{
	std::vector<size_t> fibonacci_numbers;
	{
		FibonacciSequenceGeneratorRecurse<std::vector<size_t>> gen(fibonacci_numbers, 1000);
	}

	std::wcout << "Fibonacci numbers less than 1000 obtained recursive:" << std::endl;
	for (auto& val : fibonacci_numbers)
		std::wcout << val << L" ";

	std::wcout << L"\n\nPress enter...";
	std::wcin.get();
}
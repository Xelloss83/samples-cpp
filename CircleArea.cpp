#include <iostream>

constexpr double PI = 3.141592653589793238463;

inline double AreaOfCircle(double radius)
{
	return PI * radius * radius;
}

void main()
{
	std::wcout << L"Area of circle with radius 2.5 is: "
		<< AreaOfCircle(2.5)
		<< std::endl;

	std::wcout << L"\n\nPress enter...";
	std::wcin.get();
}
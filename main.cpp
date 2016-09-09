#include <iostream>
#include <vector>
using namespace std;

void testVector();

int main()
{
	cout << "Hello, world!" << endl;
	return 0;
}

void testVector()
{
	std::vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	for (int i = 0; i < (int)numbers.size(); ++i)
		cout << i << endl;
}

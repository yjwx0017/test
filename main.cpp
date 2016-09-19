#include <iostream>
#include <vector>
#include <boost/lexical_cast.hpp>
#include <sstream>
using namespace std;

void testVector();
void testLexicalCast();

int main()
{
	cout << "Hello, world!" << endl;

	testLexicalCast();
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

void testLexicalCast()
{
	// 以下会抛出异常
	//cout << boost::lexical_cast<int>("  123  ") << endl;
	//cout << boost::lexical_cast<int>("123  ") << endl;
	//cout << boost::lexical_cast<int>("12 3") << endl;
	//cout << boost::lexical_cast<int>("1 2 3") << endl;

	// 空字符串会抛出异常
	//cout << boost::lexical_cast<int>("") << endl;

	// 不支持十六进制
	//cout << boost::lexical_cast<int>("0x0362") << endl;

	// 十六进制字符串转成整数 0x前缀可有可无
	// C++11 中的 std::stoi <string>
	stringstream ss;
	ss << hex << "0x0362f"; // 13871  
	int i;
	ss >> i;
	cout << i << endl;

	// 字符串转换为bool 只支持 0 和 1，不支持true或false或其他整数值
	//cout << boost::lexical_cast<bool>("true") << endl;
	//cout << boost::lexical_cast<bool>("false") << endl;
	//cout << boost::lexical_cast<bool>("True") << endl;
 	//cout << boost::lexical_cast<bool>("-1") << endl;
 	//cout << boost::lexical_cast<bool>("2") << endl;
 	cout << boost::lexical_cast<bool>("1") << endl;
 	cout << boost::lexical_cast<bool>("0") << endl;
}

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
	// ���»��׳��쳣
	//cout << boost::lexical_cast<int>("  123  ") << endl;
	//cout << boost::lexical_cast<int>("123  ") << endl;
	//cout << boost::lexical_cast<int>("12 3") << endl;
	//cout << boost::lexical_cast<int>("1 2 3") << endl;

	// ���ַ������׳��쳣
	//cout << boost::lexical_cast<int>("") << endl;

	// ��֧��ʮ������
	//cout << boost::lexical_cast<int>("0x0362") << endl;

	// ʮ�������ַ���ת������ 0xǰ׺���п���
	// C++11 �е� std::stoi <string>
	stringstream ss;
	ss << hex << "0x0362f"; // 13871  
	int i;
	ss >> i;
	cout << i << endl;

	// �ַ���ת��Ϊbool ֻ֧�� 0 �� 1����֧��true��false����������ֵ
	//cout << boost::lexical_cast<bool>("true") << endl;
	//cout << boost::lexical_cast<bool>("false") << endl;
	//cout << boost::lexical_cast<bool>("True") << endl;
 	//cout << boost::lexical_cast<bool>("-1") << endl;
 	//cout << boost::lexical_cast<bool>("2") << endl;
 	cout << boost::lexical_cast<bool>("1") << endl;
 	cout << boost::lexical_cast<bool>("0") << endl;
}

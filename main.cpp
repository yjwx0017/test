#include <boost/lexical_cast.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/tuple/tuple.hpp>
#include <sstream>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void testVector();
void testLexicalCast();
void testFunction();
void testBind();
void testLambda();
void testTuple();

int main()
{
	cout << "Hello, world!" << endl;

	//testLexicalCast();
	//testFunction();
	//testBind();
	//testLambda();
	testTuple();
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
	stringstream ss;
	ss << hex << "0x0362f"; // 13871  
	int i;
	ss >> i;
	cout << i << endl;

	// 十六进制字符串转成整数 C++11 中的 std::stoi <string>
	cout << std::stoi("0x0362f", 0, 16) << endl;
	cout << std::stoi("0362f", 0, 16) << endl;
	//cout << std::stoi("", 0, 16) << endl; // 抛出异常

	// 字符串转换为bool 只支持 0 和 1，不支持true或false或其他整数值
	//cout << boost::lexical_cast<bool>("true") << endl;
	//cout << boost::lexical_cast<bool>("false") << endl;
	//cout << boost::lexical_cast<bool>("True") << endl;
 	//cout << boost::lexical_cast<bool>("-1") << endl;
 	//cout << boost::lexical_cast<bool>("2") << endl;
 	cout << boost::lexical_cast<bool>("1") << endl;
 	cout << boost::lexical_cast<bool>("0") << endl;
	
	// test 
}

void func(int i)
{
	cout << i << endl;
}

class Test1
{
public:
	void func()
	{
		cout << "Test1::func()" << endl;
	}

	void func2(int i)
	{
		cout << "Test1::func()" << i << endl;
	}
};

void testFunction()
{
	boost::function<void (int)> f1 = &func;
	f1(12);

	Test1 t1;
	boost::function<void (Test1*)> f2 = &Test1::func;
	f2(&t1);

	boost::function<void (Test1*, int)> f3 = &Test1::func2;
	f3(&t1, 100);
}

void testBind()
{
	// auto c++11
	Test1 t1;
	auto f1 = boost::bind(&Test1::func2, &t1, _1);
	f1(100);
}

void testLambda()
{
	// c++11 Lambda表达式
	vector<int> vec;
	for (int i = 0; i < 5; ++i)
		vec.push_back(i);

	int a = 1;
	int b = 2;

	// []内的参数指的是Lambda表达式可以得到的外部变量
	// 如果在[]中传入=的话，表示可以取得所有的外部变量，如a、b
	// ()内的参数是每次调用函数时传入的参数
	// ->后加上的是Lambda表达式返回值的类型
	for_each(vec.begin(), vec.end(), [b](int& x){ cout << x + b << endl; });
	for_each(vec.begin(), vec.end(), [=](int& x){ cout << a + b << endl; });
	for_each(vec.begin(), vec.end(), [=](int& x)->int{ cout << a + b << endl; return x; });

}

void testTuple()
{
	boost::tuple<int, double> t1(1, 2.5);
	cout << t1.get<0>() << endl;
	cout << t1.get<1>() << endl;

}

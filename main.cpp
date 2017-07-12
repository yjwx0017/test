#include <boost/lexical_cast.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/any.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <sstream>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

void testVector();
void testLexicalCast();
void testFunction();
void testBind();
void testLambda();
void testTuple();
void testAny();
void testUUID();
void testBubbleSort();
void testInsertionSort();
void testRandomShuffle();

int main()
{
	cout << "Hello, world!" << endl;

	//testLexicalCast();
	//testFunction();
	//testBind();
	//testLambda();
	//testTuple();
	//testAny();
    //testUUID();
	testBubbleSort();
	testInsertionSort();
	testRandomShuffle();

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

void testAny()
{
	boost::any val = 12;
	cout << boost::any_cast<int>(val) << endl;

	val = 13.14;
	cout << boost::any_cast<double>(val) << endl;
}

void testUUID()
{
	boost::uuids::random_generator gen;
	boost::uuids::uuid u1 = gen();
	boost::uuids::uuid u2 = gen();
	cout << u1 << endl;
	cout << u2 << endl;
}

// 冒泡排序，从小到大排序
// 来自维基百科：
// https://zh.wikipedia.org/wiki/%E5%86%92%E6%B3%A1%E6%8E%92%E5%BA%8F
template<typename T>
void bubbleSort(T* arr, int len)
{
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}

void testBubbleSort()
{
	int arr[] = { 12, 45, 12, 8, 0, 6, 5, 90, 86 };
	int len = sizeof(arr) / sizeof(int);
	bubbleSort(arr, len);
	for (int i = 0; i < len; ++i)
		cout << arr[i] << ' ';
	cout << endl;
}

// 插入排序
// 维基百科：
// https://zh.wikipedia.org/wiki/%E6%8F%92%E5%85%A5%E6%8E%92%E5%BA%8F
template<typename T>
void insertionSort(T* arr, int len)
{
	for (int i = 1; i < len; ++i)
	{
		T temp = arr[i];
		int j = i - 1;
		for (; j >= 0 && arr[j] > temp; --j)
			arr[j + 1] = arr[j];

		arr[j + 1] = temp;
	}
}

void testInsertionSort()
{
	int arr[] = { 12, 45, 12, 8, 0, 6, 5, 90, 86 };
	int len = sizeof(arr) / sizeof(int);
	insertionSort(arr, len);
	for (int i = 0; i < len; ++i)
		cout << arr[i] << ' ';
	cout << endl;
}

template<typename T>
void randomShuffle(T* arr, int len)
{
	srand((unsigned int)time(NULL));
	for (int i = len - 1; i >= 1; --i)
	{
		std::swap(arr[i], arr[rand() % i]);
	}
}

void testRandomShuffle()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
	int len = sizeof(arr) / sizeof(int);
	randomShuffle(arr, len);
	for (int i = 0; i < len; ++i)
		cout << arr[i] << ' ';
	cout << endl;
}

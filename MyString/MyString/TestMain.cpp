#include "MyString.h"
#include <iostream>

using namespace STD;
using namespace std;

void consructors_test()
{
	string std_str = "std_string";
	MyString a;
	MyString a2("string");
	cout << a2 << endl << "Correct: string" << endl;
	MyString a3(std_str);
	cout << a3 << endl << "Correct: std_string" << endl;
	MyString a4{ 's', 't', 'r', 'i', 'n', 'g' };
	cout << a4 << endl << "Correct: string" << endl;
	MyString a5(4, 'c');
	cout << a5 << endl << "Correct: cccc" << endl;
	MyString a6("hello world", 4);
	cout << a6 << endl << "Correct: hell" << endl;
	MyString a7(a6);
	cout << a6 << endl << "Correct: hell" << endl;
}

void function_check()
{
	MyString s, str, s2;
	std::string std_str; 

	s = "aaaaa"; std_str = "aaaaa";
	s.insert(0, 1, '!'); std_str.insert(0, 1, '!');
	cout << s << endl << std_str << endl << endl;

	s.insert(3, 2, '@'); std_str.insert(3, 2, '@');
	cout << s << endl << std_str << endl << endl;

	s = "aaaaa"; std_str = "aaaaa";
	s.insert(1, "@@@@@"); std_str.insert(1, "@@@@@");
	cout << s << endl << std_str << endl << endl;

	s = "aaaaa"; std_str = "aaaaa";
	s.insert(1, "@@@@@", 2); std_str.insert(1, "@@@@@", 2);
	cout << s << endl << std_str << endl << endl;

	s = "aaaaa"; std_str = "aaaaa";
	string a = "@@@@@", b, c;
	s.insert(1, a); std_str.insert(1, a);
	cout << s << endl << std_str << endl << endl;

	s = "aaaaa"; std_str = "aaaaa";
	s.insert(1, "", 1); std_str.insert(1, "", 1);
	cout << s << endl << std_str << endl << endl;

	s = "aa@@@@@aaa"; std_str = "aa@@@@@aaa";
	s.erase(2, 3); std_str.erase(2, 3);
	cout << s << endl << std_str << endl << endl;

	str.clear(); std_str.clear();
	str.append(3, '!'); std_str.append(3, '!');
	cout << str << endl << std_str << endl << endl;

	str.append(3, '@'); std_str.append(3, '@');
	cout << str << endl << std_str << endl << endl;

	str.clear(); std_str.clear();
	str.append("hello "); std_str.append("hello ");
	cout << str << endl << std_str << endl << endl;

	str.append("world"); std_str.append("world");
	cout << str << endl << std_str << endl << endl;

	str.clear(); std_str.clear();
	str.append("hello world", 0, 6); std_str.append("hello world", 0, 6);
	cout << str << endl << std_str << endl << endl;

	str.append("hello world", 6, 5); std_str.append("hello world", 6, 5);
	cout << str << endl << std_str << endl << endl;

	a = "hello ";
	b = "world";
	str.clear();
	str.append(a);
	cout << str << "\nhello \n\n";
	str.append(b);
	cout << str << "\nhello world\n\n";

	str.clear(); std_str.clear();
	a = "hello world";
	str.append(a, 0, 6); std_str.append(a, 0, 6);
	cout << str << endl << std_str << endl << endl;
	str.append(a, 6, 5); std_str.append(a, 6, 5);
	cout << str << endl << std_str << endl << endl;

	s = "hello amazing world"; std_str = "hello amazing world";
	s.replace(6, 7, "wonderful"); std_str.replace(6, 7, "wonderful");
	cout << s << endl << std_str << endl << endl;

	s = "hello amazing world";
	a = "wonderful";
	s.replace(6, 7, a);
	cout << s << "\nhello wonderful world\n\n";

	s = "hello amazing world";
	s2 = s.substr(6);
	cout << s2 << "\namazing world\n\n";

	s = "hello amazing world";
	s2 = s.substr(6, 7);
	cout << s2 << "\namazing\n\n";

	s = "123123123412345"; std_str = "123123123412345";
	a = "1234";
	b = "123";
	cout << s.find("1234") << s.find("123", 1) << s.find(a) << s.find(b, 1);
	cout << std_str.find("1234") << std_str.find("123", 1) << std_str.find(a) << std_str.find(b, 1);

	cout << s.find("abc") << endl << std_str.find("abc") << endl << endl; 
	cout << s.find("") << endl << std_str.find("") << endl << endl;
	cout << s.find(c) << endl << std_str.find(c) << endl << endl;
}

void operator_check()
{
	MyString a, b, c, x, y;
	string s;

	x = "abcd";
	y = "efghi";
	a += x;
	cout << a << "\nabcd\n\n";
	a += y;
	cout << a << "\nabcdefghi\n\n";

	a.clear();
	s = "456";
	a += "123";
	a += s;
	cout << a << "\n123456\n\n";

	a.clear();
	a = x + c + y + "123" + s;
	cout << a << "\nabcdefghi123456\n\n";

	cout << a[0] << a[2] << a[4] << a[5] << a[7];
	cout << "\nacefh\n\n";

	a = b = x;
	cout << (a == b) << (a != b) << (a > b) << (a >= b) << (a < b) << (a <= b);
	cout << "\n100101\n\n";

	a = "abcd";
	b = "abce";
	cout << (a == b) << (a != b) << (a > b) << (a >= b) << (a < b) << (a <= b);
	cout << "\n010011\n\n";

	a = "abce";
	b = "abcd";
	cout << (a == b) << (a != b) << (a > b) << (a >= b) << (a < b) << (a <= b);
	cout << "\n011100\n\n";

	a = "abc";
	b = "abcd";
	cout << (a == b) << (a != b) << (a > b) << (a >= b) << (a < b) << (a <= b);
	cout << "\n011100\n\n";

	a = "abcd";
	b = "abc";
	cout << (a == b) << (a != b) << (a > b) << (a >= b) << (a < b) << (a <= b);
	cout << "\n010011\n\n";

	a.clear();
	cout << (a == b) << (a != b) << (a > b) << (a >= b) << (a < b) << (a <= b);
	cout << "\n011100\n\n";

	b.clear();
	cout << (a == b);
	cout << (a != b);
	cout << (a > b);
	cout << (a >= b);
	cout << (a < b);
	cout << (a <= b);
	cout << "\n100101\n\n";
}

int main()
{
	string s = "lala";
	//s.insert(1, "", 2);
	//cout << s; 
	function_check();
	operator_check();
	return 0;
}
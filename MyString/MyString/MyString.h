#ifndef MY_STRING_H
#define MY_STRING_H

#include <string> //this is for std::string constructor
#include <initializer_list> // std::initializer_list


namespace STD
{
	class MyString
	{
	public:
		static const size_t npos = -1;

	private:
		size_t _str_len = 0;     // length
		size_t _str_cap = 0;     // capacity
		char* _str = nullptr;   // c-string
		size_t _increaseBy = 1;

	public:
		MyString(); // default constructor
		MyString(const MyString&); //copy constructor
		MyString(const char*); // char array constructor
		MyString(std::string&); // std::string constructor. has a cast!!! string -> char[]
		MyString(size_t count, char c);
		MyString(const std::initializer_list<char>& list);
		MyString(const char*, size_t); 
	public:
		~MyString();

	//=
		MyString& operator = (const MyString&);
		MyString& operator = (const char*);
		MyString& operator = (const std::string&); //TESTIT
		MyString& operator = (char); //TESTIT

	// +=
	public:
		MyString& operator += (const MyString&); 
		MyString& operator += (const char*); 
		MyString& operator += (const std::string&);

	//+
	public:
		friend MyString operator+ (const MyString&, const MyString&); //friend???? friend.
		friend MyString operator+ (const MyString&, const char*);
		friend MyString operator+ (const MyString&, const std::string&);

	public:
		friend bool operator == (const MyString&, const MyString&);
		friend bool operator != (const MyString&, const MyString&);
		friend bool operator < (const MyString&, const MyString&);
		friend bool operator > (const MyString&, const MyString&);
		friend bool operator <= (const MyString&, const MyString&);
		friend bool operator >= (const MyString&, const MyString&);

	private:
		void _delete_str(char*& buffer); 
		void _setLength(const size_t len); 
		void _clear_str(const size_t pos);
		void _setCapacity(const size_t cap);
		void _increaseCapacity(const size_t cap);
		void _decreaseCapacity(const size_t cap);
		void _alloc_cstring(char*& buffer, const size_t count) const;
		void _fill_str(char* cchar_array, const size_t len, size_t pos, char c) const;
		void _append(const char* cchar_array, size_t n);
		void _append(const char* cchar_array);
		size_t _strlen(const char* cchar_array);
		bool _find_compare(const char* cchar_array, size_t len, size_t pos) const;
		int _compare(const MyString& other) const; //strcoll - it should be lexicographically comparing. maybe i should use classic strcmp?
		void _substr(char*& buffer, const char* cchar_array, size_t pos, size_t len) const;
		void _alloc_cstring(char*& buffer, const size_t count, char c) const;
		size_t _find(const char* cchar_array, size_t pos, size_t len) const;
		void _insert(size_t pos, const char* cchar_array, size_t count);
		void _erase(size_t pos, size_t count);
		void _replace(size_t pos, size_t count, const char* cchar_array);

		//	Element access
	public:
		const char& operator [] (size_t) const;
		char& operator [] (size_t);

	public:
		size_t length() const; // same as size
		size_t size() const; // return the number of char elements in string
		size_t capacity() const; // return the current amount of allocated memory for array
		bool empty() const;
		void clear(); //TESTIT
		const char* c_str() const;
		//TESTIT
		void shrink_to_fit(size_t cap); // reduce the capacity to size

		//In C++11 onwards, both functions are required to be the same.i.e.data is now required to be null - 
		//terminated.According to cppreference : "The returned array is null-terminated, that is, data() 
		//and c_str() perform the same function."
		const char* data() const; 
		

	public:
		size_t find(const char* cchar_array, size_t pos) const;
		size_t find(const char* cchar_array) const;
		size_t find(const std::string& std_string, size_t pos) const;
		size_t find(const std::string& std_string) const;

	public:
		MyString& append(const char* cchar_array); 
		MyString& append(const char* cchar_array, size_t index, size_t count); 
		MyString& append(const std::string& std_string);
		MyString& append(const std::string& std_string, size_t index, size_t count);
		MyString& append(size_t count, char c);
		void append2(const char* cchar_array); // a2 = a.append impossible
	public:
		MyString& insert(size_t index, const char* cchar_array);
		MyString& insert(size_t index, const char* cchar_array, size_t count);
		MyString& insert(size_t index, size_t count, char c);
		MyString& insert(size_t index, const std::string& std_string);
		MyString& insert(size_t index, const std::string& std_string, size_t count);
	public:
		MyString& erase(size_t index, size_t count);
	public:
		MyString& replace(size_t index, size_t count, const char* cchar_array);
		MyString& replace(size_t index, size_t count, const std::string& std_string);
	public:
		MyString substr(size_t index, size_t count); 
		MyString substr(size_t index);
	};

	//iostream
	std::ostream& operator<< (std::ostream& os, const STD::MyString& str);
	std::istream& operator>> (std::istream& is,  STD::MyString& str);


}
#endif MY_STRING_H // MY_STRING_H
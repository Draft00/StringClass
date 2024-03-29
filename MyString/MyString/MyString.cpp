#include "MyString.h"
#include <iostream>

namespace STD
{
	/*
		Constructors
	*/
	STD::MyString::MyString()
	{
		_setCapacity(0);
		_setLength(0);
	}
	STD::MyString::MyString(const MyString& other)
	{
		_append(other._str, other._str_len);
	}
	STD::MyString::MyString(const char* cchar_arr)
	{
		_append(cchar_arr);
	}
	STD::MyString::MyString(std::string& std_string)
	{
		_append(std_string.c_str());
	} 
	STD::MyString::MyString(const char* other, size_t count)
	{
		_append(other, count);
	}
	STD::MyString::MyString(size_t count, char c)
	{
		append(count, c);
	}
	STD::MyString::MyString(const std::initializer_list<char>& list)
	{
		size_t list_size = list.size();
		_increaseCapacity(list_size);
		_setLength(list_size);
		size_t i = 0;
		for (auto& element : list)
			operator[](i++) = element;
		operator[](_str_len) = '\0';
	}

	/*
		Element access
	*/
	char& STD::MyString::operator[](size_t i)
	{
		return *(_str + i);
	}
	const char& STD::MyString::operator[](size_t i) const
	{
		return *(_str + i);
	}

	/*
		Dectructor
	*/
	STD::MyString::~MyString()
	{
		delete[] this->_str;
		this->_str = nullptr;
		_str_len = 0;
		_str_cap = 0;
	}


	/*
		operator =
	*/
	MyString& STD::MyString::operator=(const MyString& other)
	{
		if (this != &other) 
		{
			_setLength(0);
			_append(other._str, other._str_len);
		}
		return *this;
	}

	MyString& STD::MyString::operator=(const char* cchar_array)
	{
		if (cchar_array != NULL)
		{
			_setLength(0);
			_append(cchar_array);
		}
		return *this;
	}
	MyString& STD::MyString::operator=(const std::string& std_string)
	{
		if (&std_string != NULL)
		{
			_setLength(0);
			_append(std_string.c_str());
		}
		return *this; 
	}
	MyString& STD::MyString::operator=(char c)
	{
		_setLength(0);
		_append(&c, 1);
		return *this;
	}


	/*
		operator +=
	*/
	MyString& STD::MyString::operator+=(const MyString& other)
	{
		_append(other._str, other._str_len);
		return *this; 
	}
	MyString& STD::MyString::operator+=(const char* cchar_array)
	{
		_append(cchar_array);
		return *this; 
	}
	MyString& STD::MyString::operator+=(const std::string& std_string)
	{
		_append(std_string.c_str());
		return *this; 
	}


	/*
		comparison operator
	*/
	bool STD::operator==(const MyString& left, const MyString& right)
	{
		return left._compare(right._str) == 0;
	}
	bool STD::operator!=(const MyString& left, const MyString& right)
	{
		return left._compare(right._str) != 0;
	}
	bool STD::operator<(const MyString& left, const MyString& right)
	{
		return left._compare(right._str) < 0;
	}
	bool STD::operator>(const MyString& left, const MyString& right)
	{
		return left._compare(right._str) > 0;
	}
	bool STD::operator<=(const MyString& left, const MyString& right)
	{
		return left._compare(right._str) <= 0;
	}
	bool STD::operator>=(const MyString& left, const MyString& right)
	{
		return left._compare(right._str) >= 0;
	}
	/*
		iostream
	*/
	std::ostream& STD::operator<<(std::ostream& os, const STD::MyString& str)
	{
		size_t length = str.length();
		for (size_t i = 0; i < length; ++i)
		{
			os << str[i];
		}
		return os; 
	}
	std::istream& STD::operator>>(std::istream& is, STD::MyString& str)
	{
		str.clear();
		char c;
		do {
			c = is.get();
			if (c == ' ' || c == '\n')
				break;
			str.append(1, c);
		} while (true);
		str.append(1, '\0');
		return is;
	}
	

	/*
	operator +
	*/
	MyString STD::operator+(const MyString& left_other, const MyString& right_other)
	{
		MyString result = left_other; 
		result += right_other;
		return result;
	}
	MyString STD::operator+(const MyString& left_other, const char* cchar_array)
	{
		MyString result = left_other;
		result += cchar_array;
		return result;
	}
	MyString STD::operator+(const MyString& left_other, const std::string& std_string)
	{
		MyString result = left_other;
		result += std_string;
		return result;
	}

	//class methods
	size_t STD::MyString::length() const
	{
		return _str_len;
	}
	size_t STD::MyString::size() const
	{
		return  _str_len;
	}
	size_t STD::MyString::capacity() const
	{
		return _str_cap;
	}
	bool STD::MyString::empty() const
	{
		return _str_len ? false : true;
	}
	void STD::MyString::shrink_to_fit(size_t cap)
	{
		_decreaseCapacity(_str_len);
	}
	void STD::MyString::clear()
	{
		_clear_str(0);
	}
	const char* STD::MyString::c_str() const
	{
		return _str;
	}
	const char* STD::MyString::data() const
	{
		return _str;
	}
	size_t STD::MyString::find(const char* cchar_array, size_t pos) const
	{
		return _find(cchar_array, pos, strlen(cchar_array));
	}
	size_t STD::MyString::find(const char* cchar_array) const
	{
		return _find(cchar_array, 0, strlen(cchar_array));
	}
	size_t STD::MyString::find(const std::string& std_string, size_t pos) const
	{
		return _find(std_string.c_str(), pos, std_string.length());
	}
	size_t STD::MyString::find(const std::string& std_string) const
	{
		return _find(std_string.c_str(), 0, std_string.length());
	}

	/*
		append
	*/
	MyString& STD::MyString::append(const char* cchar_array)
	{
		_append(cchar_array);
		return *this;
	}
	MyString& STD::MyString::append(const char* cchar_array, size_t index, size_t count)
	{
		if (index + count > strlen(cchar_array)) 
			throw;
		char* buffer = nullptr; 
		_substr(buffer, cchar_array, index, count);
		_append(buffer);
		_delete_str(buffer);
		return *this;
	}
	MyString& STD::MyString::append(const std::string& std_string, size_t index, size_t count)
	{
		size_t std_string_length = strlen(std_string.c_str());
		if (index + count > std_string_length)
			throw;
		char* buffer = nullptr;
		_substr(buffer, std_string.c_str(), index, count);
		_append(buffer);
		_delete_str(buffer);
		return *this;
	}
	MyString& STD::MyString::append(const std::string& std_string)
	{
		_append(std_string.c_str());
		return *this; 
	}
	MyString& STD::MyString::append(size_t count, char c)
	{
		char* buffer = nullptr;
		_alloc_cstring(buffer, count, c);
		_append(buffer, count);
		_delete_str(buffer);
		return *this; 
	}
	void STD::MyString::append2(const char* cchar_array)
	{
		_append(cchar_array);
	}

	/*
		insert
	*/
	MyString& STD::MyString::insert(size_t index, const char* cchar_array)
	{
		_insert(index, cchar_array, strlen(cchar_array));
		return *this;
	}
	MyString& STD::MyString::insert(size_t index, const char* cchar_array, size_t count)
	{
		_insert(index, cchar_array, count);
		return *this;
	}
	MyString& STD::MyString::insert(size_t index, size_t count, char c)
	{
		char* buffer = nullptr;
		_alloc_cstring(buffer, count, c);
		_insert(index, buffer, count);
		_delete_str(buffer);
		return *this;
	}
	MyString& STD::MyString::insert(size_t index, const std::string& std_string)
	{
		_insert(index, std_string.c_str(), strlen(std_string.c_str()));
		return *this;
	}
	MyString& STD::MyString::insert(size_t index, const std::string& std_string, size_t count)
	{
		_insert(index,std_string.c_str(), count);
		return *this;
	}

	/*
		erase
	*/
	MyString& STD::MyString::erase(size_t index, size_t count)
	{
		_erase(index, count);
		return *this; 
	}

	/*
		replace
	*/
	MyString& STD::MyString::replace(size_t index, size_t count, const char* cchar_array)
	{
		_replace(index, count, cchar_array);
		return *this; 
	}
	MyString& STD::MyString::replace(size_t index, size_t count, const std::string& std_string)
	{
		_replace(index, count, std_string.c_str());
		return *this;
	}

	/*
		substr
	*/
	MyString STD::MyString::substr(size_t index, size_t count)
	{
		if (index + count > _str_len)
			throw;
		char* buffer = nullptr;
		_substr(buffer, _str, index, count);

		//MyString result;
		//result = buffer; //not need to set length to 0
		MyString result(buffer);
		_delete_str(buffer);
		return result; 
	}

	MyString STD::MyString::substr(size_t index)
	{
		if (index > _str_len)
			throw;
		size_t count = strlen(_str) - index; 
		char* buffer = nullptr;
		_substr(buffer, _str, index, count);
		MyString result(buffer);
		_delete_str(buffer);
		return result;
	}

	void MyString::_setLength(const size_t len)
	{
		if (_str_len > len)
			_clear_str(len);
		else if (_str_cap < len)  
			_increaseCapacity(len);    
		_str_len = len;
	}
	void MyString::_clear_str(const size_t pos)
	{
		_fill_str(_str, _str_len, pos, '\0');
		_str_len = pos;
	}

	void MyString::_increaseCapacity(const size_t new_cap)
	{
		if (_str_cap > new_cap && _str)
			return;
		size_t cap = _str_cap;
		while (cap <= new_cap)
			cap += _increaseBy;

		_setCapacity(cap); 
	}
	void MyString::_alloc_cstring(char*& buffer, const size_t count) const
	{
		if (buffer)
		{
			throw;
		}
		buffer = new char[count + 1](); //the default constructor will fill the array with 0
	}
	void MyString::_fill_str(char* cchar_array, const size_t len, size_t pos, char c) const
	{
		size_t begin = pos;
		while (begin != len)
			cchar_array[begin++] = c;
		cchar_array[begin] = '\0';
	}

	void MyString::_delete_str(char*& buffer) //!!!! check this!!!!
	{
		delete[] buffer;
		buffer = nullptr;
	}

	void MyString::_setCapacity(const size_t cap)
	{
		if (_str_cap == cap && _str) 
			return;
		if (cap < _str_len) 
			return;

		_str_cap = cap; 

		char* buffer = _str;	 
		_str = nullptr; 
		_alloc_cstring(_str, _str_cap);
		if (buffer) { 
			for (size_t i = 0; i < _str_len; ++i)
				operator[](i) = buffer[i];
			operator[](_str_len) = '\0';

			_delete_str(buffer); //delete only not null-terminated
		}

	}

	size_t MyString::_strlen(const char* cchar_array)
	{
		size_t i = 0;
		while (cchar_array[i] != 0) i++;
		return i;
	}

	void MyString::_append(const char* cchar_array, size_t n)
	{
		_increaseCapacity(_str_len + n);
		size_t i = 0;
		for (; i < n; ++i)
			operator[](_str_len + i) = cchar_array[i];
		operator[](_str_len + i) = '\0';
		_setLength(_str_len + n);
	}
	void MyString::_append(const char* cchar_array)
	{
		_append(cchar_array, strlen(cchar_array));
	}
	void STD::MyString::_decreaseCapacity(const size_t cap)
	{
		if (_str_cap < cap)
			return; 

		_setCapacity(cap);
	}

	int STD::MyString::_compare(const MyString & other) const
	{
		if (_str_len < other._str_len)
			return -1;
		else if (_str_len > other._str_len)
			return 1;
		return strcmp(_str, other._str);
	}
	void STD::MyString::_substr(char*& buffer, const char* cchar_array, size_t pos, size_t len) const
	{
		if (cchar_array == nullptr)
			throw;
		_alloc_cstring(buffer, len);
		for (size_t i = 0; i < len; ++i)
			buffer[i] = cchar_array[pos + i];
	}
	bool STD::MyString::_find_compare(const char* cchar_array, size_t len, size_t pos) const
	{
		for (size_t i = 1; i < len; ++i)
		{
			if (operator[](pos + i) != *(cchar_array + i))
				return false;
		}
		return true;
	}
	void STD::MyString::_alloc_cstring(char*& buffer, const size_t count, char c) const
	{
		_alloc_cstring(buffer, count);
		_fill_str(buffer, count, 0, c);
	}
	size_t STD::MyString::_find(const char* cchar_array, size_t pos, size_t len) const
	{
		size_t ResultPos = npos;
		if (pos == npos)
			pos = _str_len - 1;
		if (len == 0)
			return 0;
			//return ResultPos;
		for (; pos <= _str_len - len; ++pos)
		{
			if (operator[](pos) == *cchar_array && _find_compare(cchar_array, len, pos))
			{
				ResultPos = pos;
				break;
			}
		}
		return ResultPos;
	}
	void STD::MyString::_insert(size_t pos, const char* cchar_array, size_t count)
	{
		if (count == 0 || cchar_array == nullptr)
			return;
		if (pos == _str_len)
			return _append(cchar_array, count);
		if (pos > _str_len)
			throw;

		_increaseCapacity(_str_len + count);

		if (_str == nullptr)
			return _append(cchar_array, count);

		char* buffer = nullptr;
		_substr(buffer, _str, pos, _str_len - pos);
		_clear_str(pos);
		_append(cchar_array, count);
		_append(buffer, strlen(buffer));
		_delete_str(buffer);

	}
	void STD::MyString::_erase(size_t pos, size_t count)
	{
		if (pos + count > _str_len)
			throw;
		if (_str == nullptr)
			throw;

		char* buffer = nullptr;
		_substr(buffer, _str, pos + count, _str_len - count);
		_clear_str(pos);
		_append(buffer, strlen(buffer));
		_delete_str(buffer);
	}
	void STD::MyString::_replace(size_t pos, size_t count, const char* cchar_array)
	{
		char* third_buffer = nullptr;
		_substr(third_buffer, _str, pos + count, _str_len);
		_clear_str(pos);
		char* second_buffer = nullptr;
		_substr(second_buffer, cchar_array, 0, strlen(cchar_array));
		_append(second_buffer);
		_append(third_buffer);
		_delete_str(third_buffer);
		_delete_str(second_buffer);
	}
}

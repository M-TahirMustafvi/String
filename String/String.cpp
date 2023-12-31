#include "String.h"

//Default constructor
String::String()
{
	size = 0;
	arr = new char[size];
	for (int i = 0; i < size; i++)
	{
		arr[size] = 0;
	}
}


//Parameterized Constructor
String::String(const char arr1[])
{
	int count = 0;
	while (arr1[count] != '\0')
	{
		count++;
	}
	size = count;
	arr = new char[size+1];
	for (int i = 0; i < size; i++)
	{
		arr[i] = arr1[i];
	}
	arr[size] = '\0';
}


//Copy Constructor
String::String(const String& that)
{
	this->size = that.size;
	delete[] arr;
	this->arr = new char[this->size+1];
	for (int i = 0; i < size; i++)
	{
		arr[i] = that.arr[i];
	}
	arr[size] = '\0';
}

//Overloaded assignment operator
String String::operator=(const String& obj)
{
	this->size = obj.size;
	delete[] arr;
	arr = new char[size+1];
	for (int i = 0; i < size; i++)
	{
		arr[i] = obj.arr[i];
	}
	arr[size] = '\0';
	return *this;
}


// Assignment boolean operator
bool String::operator==(const String& that)
{
	for (int i = 0; i < size; i++)
	{
		if (that.arr[i] != this->arr[i])
			return false;
	}
	return true;
}


// != boolean operator
bool String::operator!=(const String& that)
{
	for (int i = 0; i < size; i++)
	{
		if (that.arr[i] != this->arr[i])
			return true;
	}
	return false;
}


// >= boolean operator
bool String::operator>=(const String& that)
{
	if (size < that.size)
		return false;
	else if (size > that.size)
		return true;
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (this->arr[i] < that.arr[i])
				return false;
		}
		return true;
	}
}


// <= boolean operator
bool String::operator<=(const String& that)
{
	if (size < that.size)
		return true;
	else if (size > that.size)
		return false;
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (this->arr[i] > that.arr[i])
				return false;
		}
		return true;
	}
}


// < boolean operator
bool String::operator<(const String& that)
{
	if (size < that.size)
		return true;
	else if(size > that.size)
		return false;
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (this->arr[i] < that.arr[i])
				return true;
		}
		return false;
	}
	
}


// > boolean operator
bool String::operator>(const String& that)
{
	if (size > that.size)
		return true;
	else if(size < that.size)
		return false;
	else
	{
		for (int i = 0; i < size; i++)
		{

			if (this->arr[i] > that.arr[i])
				return true;
		}
		return false;
	}

}

char String::operator[](int i)
{
	if (i >= 0 || i < size)
		return arr[i];
	else
		cout << "out of range subscript";
}



//Stream extraction operator
ostream& operator<<(ostream& out, const String& obj)
{
	out << obj.arr;
	return out;
}

//Needs Improvements!
istream& operator>>(istream& in, String& obj)
{
	char temp[100];
	in >> temp;
	
	int i = 0;
	while (temp[i] != '\0')
	{
		i++;
	}

	obj.size = i;
	delete[] obj.arr;
	obj.arr = new char[obj.size + 1];
	for (int count = 0; count < obj.size; count++)
	{
		obj.arr[count] = temp[count];
	}
	obj.arr[obj.size] = '\0';
	return in;
}

//String length
int String::Strlen()
{
	return size;
}

//get Substring
String String::subString(const String)
{

}

//Destructor
String::~String()
{
	delete[] arr;
}


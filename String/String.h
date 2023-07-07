#pragma once
#include<iostream>
using namespace std;
class String
{
private:
	char* arr;
	int size;
public:
	String();
	String(const char []);
	String(const String&);
	~String();
	friend istream& operator>>(istream&, String&);
	friend ostream& operator<<(ostream&, const String&);
	String operator=(const String&);
	bool operator==(const String&);
	bool operator!=(const String&);
	bool operator>=(const String&);
	bool operator<=(const String&);
	bool operator<(const String&);
	bool operator>(const String&);
	char operator [](int);
	int Strlen();
	
};


#pragma once
#include<iostream>
#include"para.h"
using namespace std;
class character
{
	char* data;
	int encrypt;
	int count;
	char* deepcopy(const char* arr,int count)const;
public:
	character(const char*arr =nullptr,int count=0);
	~character();
	character(const character&);
	void setchar_data(const char*,int);
	char* getchar_data()const;
	void clear();
	void add(char);
	void converter(char*& data, bool flag, int key, bool flag1);
	character& operator+(const character&)const;
	character& operator*();
	character& operator +();
	character& operator -();
    character& operator%(int);
	bool operator==(const character&)const;
	character& operator++();
	character& operator++(int);
	character& operator--();
	character& operator--(int);
	character& operator=(const character&);
	friend ostream& operator<<(ostream&, const character&);
};
void regrow(char*& data,int &count, char val);
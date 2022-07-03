#pragma once
#include"character.h"
class word
{
	character* words;
	int encrypt;
	int count;
	character* deepcopy(const character* arr,int count)const;
public:
	word(const character* arr, int count);
	word();
	~word();
	word(const word&);
	void setwords_data(const character*, int);
	character* getwords_data()const;
	void clear();
	void add(char);
	word& operator+(const word&)const;
	word& operator*();
	word& operator +();
	word& operator -();
	word& operator%(int);
	bool operator==(const word&)const;
	word& operator++();
	word& operator++(int);
	word& operator--();
	word& operator--(int);
	word& operator=(const word&);
	friend ifstream& operator>>(ifstream& fin, word& obj);
	friend ostream& operator<<(ostream& cout, word& obj);
	friend ofstream& operator<<(ofstream& fout, word& obj);
};
void regrow(character*& data, int &count);
void converter(character*& arr, bool flag, int key, bool flag1);


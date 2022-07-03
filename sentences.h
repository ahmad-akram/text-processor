#pragma once
#include"word.h"
class sentences
{
	word* sentence;
	int encrypt;
	int count;
	word* deepcopy(const word* arr, int count)const;
public:
	sentences(const word* arr, int count);
	sentences();
	~sentences();
	sentences(const sentences&);
	void setsentencess_data(const word*, int);
	word* getsentencess_data()const;
	void clear();
	void add(char);
	sentences& operator+(const sentences&)const;
	sentences& operator*();
	sentences& operator +();
	sentences& operator -();
	sentences& operator%(int);
	bool operator==(const sentences&)const;
	sentences& operator++();
	sentences& operator++(int);
	sentences& operator--();
	sentences& operator--(int);
	sentences& operator=(const sentences&);
	friend ifstream& operator>>(ifstream& fin, sentences& obj);
	friend ostream& operator<<(ostream& cout, sentences& obj);
	friend ofstream& operator<<(ofstream& fout, sentences& obj);
};
void regrow(word*& data, int& count);


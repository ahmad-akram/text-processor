#pragma once
#include"sentences.h"
class paragraph
{
	sentences* paragraphs;
	int encrypt;
	int count;
	sentences* deepcopy(const sentences* arr, int count)const;
public:
	paragraph(const sentences* arr, int count);
	paragraph();
	~paragraph();
	paragraph(const paragraph&);
	void setparagraphs_data(const sentences*, int);
	sentences* getparagraphs_data()const;
	void clear();
	void add(char,ifstream&);
	paragraph& operator+(const paragraph&)const;
	paragraph& operator*();
	paragraph& operator +();
	paragraph& operator -();
	paragraph& operator%(int);
	bool operator==(const paragraph&)const;
	paragraph& operator++();
	paragraph& operator++(int);
	paragraph& operator--();
	paragraph& operator--(int);
	paragraph& operator=(const paragraph&);
	friend ifstream& operator>>(ifstream& fin, paragraph& obj);
	friend ostream& operator<<(ostream& cout, paragraph& obj);
	friend ofstream& operator<<(ofstream& fout, paragraph& obj);
};
void regrow(sentences*& data, int& count);
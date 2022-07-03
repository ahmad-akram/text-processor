#include "paragraph.h"
sentences* paragraph::deepcopy(const sentences* arr, int count)const {
	sentences* temp = new sentences[count];
	for (int i = 0; i < count; i++)
		temp[i] = arr[i];
	return temp;
}
paragraph::paragraph(const sentences* arr, int count) {
	this->paragraphs = deepcopy(arr, count);
	this->count = count;
}
paragraph::paragraph() {
	this->count = 0;
	this->paragraphs = nullptr;
	encrypt = 0;
	regrow(this->paragraphs, this->count);
}
paragraph::	~paragraph() {
	if (paragraphs != nullptr)
		delete[]paragraphs;
	paragraphs = nullptr;
}
paragraph::paragraph(const paragraph& obj) {
	this->paragraphs = deepcopy(obj.paragraphs, obj.count);
	this->count = obj.count;
}
void paragraph::setparagraphs_data(const sentences* paragraphs, int) {
	this->paragraphs = deepcopy(paragraphs, count);
	this->count = count;
}
sentences* paragraph::getparagraphs_data()const {
	sentences* temp = nullptr;
	if (this->paragraphs != nullptr)
		temp = deepcopy(this->paragraphs, this->count);
	return temp;
}
void paragraph::clear() {
	for (int i = 0; i < count; i++)
		paragraphs[i].clear();
}
void paragraph::add(char a,ifstream& fin) {
	int lo = 0;
	char a1;
	lo = fin.tellg();
	fin.get(a1);
	cout << a1;
	if (a1 == '\n')
		fin.get(a1);
	fin.seekg(lo);
	if (!(a == '.'))
		paragraphs[count - 1].add(a);
	else
		regrow(this->paragraphs, this->count);
}
void regrow(sentences*& data, int& count) {
	sentences* temp = new sentences[count + 1];
	for (int i = 0; i < count; i++)
		temp[i] = data[i];
	delete[] data;
	data = temp;
	count++;
	temp = nullptr;
}
paragraph& paragraph::operator*() {
	for (int i = 0; i < this->count; i++)
		*paragraphs[i];
	encrypt = 0;
	return*this;
}
paragraph& paragraph::operator +() {
	for (int i = 0; i < this->count; i++)
		+ paragraphs[i];
	return*this;
}
paragraph& paragraph::operator -() {
	for (int i = 0; i < this->count; i++)
		- paragraphs[i];
	return*this;
}
paragraph& paragraph::operator%(int) {
	for (int i = 0; i < this->count; i++)
		paragraphs[i] % encrypt;
	this->encrypt += encrypt;
	return*this;
}
bool paragraph::operator==(const paragraph& obj)const {
	int c = 0;
	if (this->count == obj.count)
		for (int i = 0; i < this->count; i++)
			if (obj.paragraphs[i] == this->paragraphs[i])
				c++;
	if (c == this->count)
		return true;
	return false;
}
paragraph& paragraph::operator++() {
	for (int i = 0; i < this->count; i++)
		paragraphs[i] ++;
	return*this;
}
paragraph& paragraph::operator++(int) {
	paragraph* temp = new paragraph;
	temp->paragraphs = deepcopy(this->paragraphs, this->count);
	temp->count = count;
	for (int i = 0; i < this->count; i++)
		paragraphs[i]++;
	return *temp;
}
paragraph& paragraph::operator--() {
	for (int i = 0; i < this->count; i++)
		--paragraphs[i];
	return*this;
}
paragraph& paragraph::operator--(int) {
	paragraph* temp = new paragraph;
	temp->paragraphs = deepcopy(this->paragraphs, this->count);
	temp->count = count;
	for (int i = 0; i < this->count; i++)
		paragraphs[i]--;
	return *temp;
}
paragraph& paragraph::operator=(const paragraph& obj) {
	this->paragraphs = deepcopy(obj.paragraphs, obj.count);
	this->count = obj.count;
	return*this;
}
ifstream& operator>>(ifstream& fin, paragraph& obj) {
	char a = '\0';
	if (fin.is_open()) {
		while (!fin.eof()) {
			fin.get(a);
			obj.add(a,fin);
		}
	}
	return fin;
}
ostream& operator<<(ostream& cout, paragraph& obj) {
	for (int i = 0; i < obj.count; i++)
		cout << obj.paragraphs[i] << " ";
	return cout;
}
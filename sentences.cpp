#include "sentences.h"
word* sentences::deepcopy(const word* arr, int count)const{
	word* temp = new word[count];
	for (int i = 0; i < count; i++)
		temp[i] = arr[i];
	return temp;
}
sentences::sentences(const word* arr, int count){
	this->sentence= deepcopy(arr, count);
	this->count = count;
}
sentences::sentences(){
	this->count = 0;
	this->sentence = nullptr;
	encrypt = 0;
	regrow(this->sentence, this->count);
}
sentences::	~sentences(){
	if (sentence != nullptr)
		delete[]sentence;
	sentence = nullptr;
}
sentences::sentences(const sentences&obj){
	this->sentence = deepcopy(obj.sentence, obj.count);
	this->count = obj.count;
}
void sentences::setsentencess_data(const word*sentence, int){
	this->sentence = deepcopy(sentence, count);
	this->count = count;
}
word* sentences::getsentencess_data()const{
	word* temp = nullptr;
	if (this->sentence != nullptr)
		temp = deepcopy(this->sentence, this->count);
	return temp;
}
void sentences::clear(){
	for (int i = 0; i < count; i++)
		sentence[i].clear();
}
void sentences::add(char a){
	if (!(a == '.'))
		sentence[count - 1].add(a);
	else
		regrow(this->sentence, this->count);
}
void regrow(word*& data, int& count) {
	word* temp = new word[count + 1];
	for (int i = 0; i < count; i++)
		temp[i] = data[i];
	delete[] data;
	data = temp;
	count++;
	temp = nullptr;
}
sentences& sentences::operator*(){
	for (int i = 0; i < this->count; i++)
		*sentence[i];
	encrypt = 0;
	return*this;
}
sentences& sentences::operator +(){
	for (int i = 0; i < this->count; i++)
		+ sentence[i];
	return*this;
}
sentences& sentences::operator -(){
	for (int i = 0; i < this->count; i++)
		- sentence[i];
	return*this;
}
sentences& sentences::operator%(int){
	for (int i = 0; i < this->count; i++)
		sentence[i] % encrypt;
	this->encrypt += encrypt;
	return*this;
}
bool sentences::operator==(const sentences&obj)const{
	int c = 0;
	if (this->count == obj.count)
		for (int i = 0; i < this->count; i++)
			if (obj.sentence[i] == this->sentence[i])
				c++;
	if (c == this->count)
		return true;
	return false;
}
sentences& sentences::operator++(){
	for (int i = 0; i < this->count; i++)
		sentence[i] ++;
	return*this;
}
sentences& sentences::operator++(int){
	sentences* temp = new sentences;
	temp->sentence = deepcopy(this->sentence, this->count);
	temp->count = count;
	for (int i = 0; i < this->count; i++)
		sentence[i]++;
	return *temp;
}
sentences& sentences::operator--(){
	for (int i = 0; i < this->count; i++)
		--sentence[i];
	return*this;
}
sentences& sentences::operator--(int){
	sentences* temp = new sentences;
	temp->sentence = deepcopy(this->sentence, this->count);
	temp->count = count;
	for (int i = 0; i < this->count; i++)
		sentence[i]--;
	return *temp;
}
sentences& sentences::operator=(const sentences& obj){
	this->sentence = deepcopy(obj.sentence, obj.count);
	this->count = obj.count;
	return*this;
}
ifstream& operator>>(ifstream& fin, sentences& obj){
	char a = '\0';
	if (fin.is_open()) {
		while (!fin.eof()) {
			fin.get(a);
			obj.add(a);
		}
	}
	return fin;
}
ostream& operator<<(ostream& cout, sentences& obj){
	for (int i = 0; i < obj.count; i++)
		cout << obj.sentence[i] << " ";
	return cout;
}
#include "word.h"
character* word::deepcopy(const character* arr,int count)const {
	character* temp = new character[count];
	for (int i = 0; i < count; i++)
		temp[i] = arr[i];
	return temp;
}
word::word()
{
	this->count = 0;
	this->words = nullptr;
	encrypt = 0;
	regrow(this->words,this->count);
}
word::word(const character* arr,int count)
{
	this->words = deepcopy(arr, count);
	this->count = count;
}
word::~word(){
	if (words != nullptr)
		delete[]words;
	words = nullptr;
}
word::word(const word&obj){
	this->words = deepcopy(obj.words,obj.count);
	this->count = obj.count;
}
void word::setwords_data(const character*words,int count){
	this->words = deepcopy(words, count);
	this->count = count;
}
character* word::getwords_data()const{
	character* temp = nullptr;
	if (this->words != nullptr)
		temp = deepcopy(this->words,this->count);
	return temp;
}
void word::clear(){
	for (int i = 0; i < count; i++)
		words[i].clear();
}
void word::add(char a){
	if (!(a == ' ' || a == '.'))
		words[count - 1].add(a);
	else
		regrow(this->words,this-> count);
}
void regrow(character*& data,int&count) {
	character* temp = new character[count + 1];
	for (int i = 0; i < count; i++)
		temp[i] = data[i];
	delete[] data;
	data = temp;
	count++;
	temp = nullptr;
}
word& word::operator+(const word&obj)const{
	word* temp = new word;
	temp->words = deepcopy(this->words, this->count);
	temp->count = this->count;
	cout << "hammad";
	for (int i = 0; i < obj.count; i++){
		temp->words[count - 1] = obj.words[i];
		regrow(temp->words, temp->count);
	}
	return *temp;
}
word& word:: operator*(){
	for (int i = 0; i < this->count; i++)
		 *words[i];
	encrypt=0;
	return*this;
}
word& word::operator +(){
	for (int i = 0; i < this->count; i++)
		+words[i];
	return*this;
}
word& word::operator -(){
	for (int i = 0; i < this->count; i++)
		-words[i];
	return*this;
}
word& word::operator%(int encrypt){
	for (int i = 0; i < this->count; i++)
		words[i] % encrypt;
	this->encrypt += encrypt;
	return*this;
}
bool word::operator==(const word&obj)const{
	int c = 0;
	if (this->count == obj.count)
		for (int i = 0; i < this->count; i++)
			if (obj.words[i] == this->words[i])
				c++;
	if (c == this->count)
		return true;
	return false;
}
word& word::operator++(){
	for (int i = 0; i < this->count; i++)
	 words[i] ++;
	return*this;
}
word& word::operator++(int){
	word* temp = new word;
	temp->words = deepcopy(this->words, this->count);
	temp->count = count;
	for (int i = 0; i < this->count; i++)
		words[i]++;
	return *temp;
}
word& word::operator--(){
	for (int i = 0; i < this->count; i++)
		-- words[i];
	return*this;
}
word& word::operator--(int){
	word* temp = new word;
	temp->words = deepcopy(this->words, this->count);
	temp->count = count;
	for (int i = 0; i < this->count; i++)
		words[i]--;
	return *temp;
}
word& word:: operator =(const word& obj) {
	this->words = deepcopy(obj.words, obj.count);
	this->count = obj.count;
	return*this;
}
ifstream& operator>>(ifstream& fin, word& obj){
	char a = '\0';
	if (fin.is_open()) {
		while (!fin.eof()) {
			fin.get(a);
			obj.add(a);
		}
    }
	return fin;
}
ostream& operator<<(ostream& cout, word& obj){
	for (int i = 0; i < obj.count; i++)
		cout << obj.words[i]<<" ";
	return cout;
}

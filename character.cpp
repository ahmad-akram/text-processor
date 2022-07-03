#include "character.h"
char* character::deepcopy(const char* data,int count)const{
	char* temp = new char[count];
	for (int i = 0;i<count ; i++)
		temp[i]=data[i];
	return temp;
}
character::character(const char*data,int count){
	if(data!=nullptr)
	this->data = deepcopy(data,count);
	else
	this->data = nullptr;
	this->count = count;
	encrypt = 0;
}
character::~character() {
	if (data != nullptr)
		delete[] data;
	data = nullptr;
}
character::character(const character&obj){
	this->data = deepcopy(obj.data,obj.count);
	this->count = count;
}
void character::setchar_data(const char*data,int count){
	this->data = deepcopy(data,count);
	this->count = count;
}
char* character::getchar_data()const{
	char* temp=nullptr;
	if (this->data != nullptr)
		temp = deepcopy(this->data,this->count);
	return temp;
}
void character::clear(){
	if (this->data != nullptr)
		for (int i = 0; this->data[i] != '\0'; i++)
			data[i] = '\0';
}
void regrow(char*& data, int& count, char val) {
	char* temp = new char[count + 1];
	for (int i = 0; i < count; i++)
		temp[i] = data[i];
	delete[] data;
	temp[count] = val;
	data = temp;
	count++;
	temp = nullptr;
}
void character::add(char val){
	regrow(this->data, count, val);
}  
character& character::operator+(const character&obj)const{
	  character* temp = new character;
	temp->data = deepcopy(this->data,this->count);
	temp->count = this->count;
	for (int i = 0; i<obj.count; i++)
		regrow(temp->data,temp->count, obj.data[i]);
	return *temp;
}
bool character::operator==(const character&obj)const{
	int c = 0;
	if (this->count == obj.count)
		for (int i = 0; i<this->count; i++)
			if (this->data[i] == obj.data[i])
				c++;
	if (c == this->count)
		return true;
	return false;
}
character& character::operator++(){
	for (int i = 0; i < count; i++)
		this->data[i]++;
	return *this;
}
character& character::operator++(int){
	character* ptr = new character;
	ptr->data = deepcopy(this->data,this->count);
	ptr->count = count;
	for (int i = 0; i < count; i++)
		this->data[i]++;
	return *ptr;
}
character& character::operator--(){
	for (int i = 0; i < count; i++)
		this->data[i]--;
	return *this;
}
character& character::operator--(int){
	character* ptr = new character;
	ptr->data = deepcopy(this->data,this->count);
	ptr->count = this->count;
	for (int i = 0; i < this->count; i++)
		this->data[i]--;
	return *ptr;
}
character& character::operator=(const character& obj){
	this->data = deepcopy(obj.data,obj.count);
	this->count = obj.count;
	return *this;
}
void character::converter(char*& data, bool flag, int key, bool flag1){
		for (int i = 0; i < this->count; i++){
			if (flag1 == true)
				upper_lower(data[i], flag, key);
			else
				encrypt_decrypt(data[i], flag, key);
		}
}
character& character::operator*() {
	converter(this->data, 0, encrypt, 0);
	this->encrypt = 0;
	return *this;
}
character& character::operator %(int encrypt) {
	this->encrypt += encrypt;
	converter(this->data, 1, encrypt, 0);
	return *this;
}
character& character::operator+()
{
	converter(this->data, 1, 32, 1);
	return *this;
}
character& character::operator-() {
	converter(this->data, 0, 32, 1);
	return *this;
}
ostream& operator<<(ostream&, const character&obj){
	for (int i = 0; i < obj.count; i++)
		cout << obj.data[i];
	return cout;
}
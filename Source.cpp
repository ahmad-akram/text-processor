#include"para.h"
#include"word.h"
#include"sentences.h"
#include<cstring>
int main() {
	para obj;
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	cout << "reading from file: \n";
	fin >> obj;
	cout << "writhing on the file\n";
	fout << obj;
	cout << obj;//display objects 
	cout << "encrypt: \n";
	obj % 2;
	cout << obj;
	cout << "decrypt: \n";
	*obj;
	cout << obj;
	cout << "upper: \n";
	+obj;
	cout << obj;
	cout << "lower: \n";
	-obj;
	cout << obj;
	cout << "copy data: \n";
	para obj1(obj);
	cout << obj1;
	cout << "addition: " << endl;
	para obj2=obj + obj1;
	cout << obj2;
	cout << "count of sentences in obj\n";
	cout << obj.getc_sentences()<<endl;
	cout << "count of word in obj\n";
	cout << obj.getc_word() << endl;
	cout << "count of character in obj\n";
	cout << obj.getc_character() << endl;
	char a = '\0';
	system("pause");
	system("cls");
	cout << "by class method" << endl;
	cout << "by word class" << endl;
	fin.close();
	ifstream fin1("input.txt");
	word obj4,obj5,obj6;
	while (!fin1.eof()) {
		fin1.get(a);
		obj4.add(a);
		obj5.add(a);
	}
	if (obj4 == obj5)
		cout << "true";
	obj6 = obj4 + obj5;
	cout << "obj6:\n" << obj6<<endl;
	cout <<"object:\n" <<obj5 << endl;
	cout << "upper:\n" << +obj4 << endl;
	cout << "lower:\n" << -obj4 << endl;
	cout << "encrypt: "<<obj4 % 3 << endl;
	cout << "decrypt: " << *obj4 << endl;
	fin1.close();
	system("pause");
	system("cls");
	cout << "by sentence class" << endl;
	 fin1.open("input.txt");
	sentences arr, arr1, arr2;
		fin1 >> arr;
		fin1.close();
		fin1.open("input.txt");
		fin1 >> arr1;
	if (arr == arr1)
		cout << "true";
	cout << "object:\n" << arr << endl;
	cout << "upper:\n" << +arr << endl;
	cout << "lower:\n" << -arr << endl;
	cout << "encrypt: " << arr % 3 << endl;
	cout << "decrypt: " << *arr << endl;
}
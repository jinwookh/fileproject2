#include <iostream>
#include <string>
#include "delim.h"

#define LENID 8
#define LENNUM 13
#define LENBIR 10
#define STDMAXBUF 256

using namespace std;

class Student{
private:
	char id[8];
	string name;
	char number[13];
	char birthday[10];
	string key;

public:
	Student();									//생성자
	Student(const char * new_id);
	Student(const Student & s);					//복사 생성자

	Student & operator = (const Student &s);	//대입 연산자 오버로딩
	bool operator == (const Student &s);		//비교 연산자 오버로딩
	bool operator != (const Student &s);		//다름 비교 연산자 오버로딩

	friend istream & operator >> (istream &is, Student &s);	//입력 스트림 오버로딩
	friend ostream & operator << (ostream &os, Student &s);	//출력 스트림 오버로딩

	void update_id(const char * new_id) { memcpy (id, new_id, 8); }
	void update_name(const string new_name) { name = new_name; }
	void update_number(const char * new_number) { memcpy(number,new_number,13); }
	void update_birthday(const char * new_birthday) { memcpy(birthday,new_birthday,10); }

	bool Pack (IOBuffer & Buffer) const;
	bool Unpack (IOBuffer &);

	char * Key();
};


istream & operator >> (istream &is, Student &s);
ostream & operator << (ostream &is, Student &s);
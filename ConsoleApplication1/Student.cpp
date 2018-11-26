#include "Student.h"
#include "recfile.h"
#include <sstream>
#include <vector>

Student::Student(){
}

Student::Student(const char * new_id){
	update_id(new_id);
}

Student::Student(const Student & s){
	update_id(s.id);
	update_birthday(s.birthday);
	update_name(s.name);
	update_number(s.number);
}

Student& Student::operator = (const Student &s){
	
	update_birthday(s.birthday);
	update_id(s.id);
	update_name(s.name);
	update_number(s.number);
	return *this;
	
}

bool Student::operator == (const Student &s){
	return !memcmp(id, s.id, 8);
}

bool Student::operator != (const Student &s){
	return 0 != memcmp(id, s.id, 8);
}

istream& operator >> (istream &is, Student &s){
	string st;

	is.exceptions(istream::failbit | istream::badbit);
	
	try {
		getline (is, st);
	} catch (istream::failure e) {
		// error
		return is;
	}

	istringstream iss (st);
	string token;

	getline (iss, token, '|');
	s.update_id (token.data ());
	getline (iss, token, '|');
	s.update_name (token);
	getline (iss, token, '|');
	s.update_number (token.data ());
	getline (iss, token, '|');
	s.update_birthday (token.data ());

	return is;
}

ostream& operator << (ostream &os, Student &s){
	string id (s.id, LENID);
	string number (s.number, LENNUM);
	string birthday (s.birthday, LENBIR);

	os << "ID : " << id << endl;
	os << "NAME : " << s.name << endl;
	os << "NUMBER : " << number << endl;
	os << "BIRTHDAY : " << birthday << endl;
	return os;
}

bool Student::Pack (IOBuffer & Buffer) const {
	int numBytes;
	
	Buffer.Clear ();
	
	string s_id (id, LENID);
	string s_number (number, LENNUM);
	string s_birthday (birthday, LENBIR);

	numBytes = Buffer.Pack (s_id.c_str ());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack (name.c_str ());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack (s_number.c_str ());
	if (numBytes == -1) return false;
	numBytes = Buffer.Pack (s_birthday.c_str ());
	if (numBytes == -1) return false;

	return true;
}

bool Student::Unpack (IOBuffer & Buffer) {
	int numBytes;
	char buf[STDMAXBUF];

	numBytes = Buffer.Unpack (id, LENID);
	if (numBytes == -1) return false;
	numBytes = Buffer.Unpack (buf);
	if (numBytes == -1) return false;
	name = buf;
	numBytes = Buffer.Unpack (number, LENNUM);
	if (numBytes == -1) return false;
	numBytes = Buffer.Unpack (birthday, LENBIR);
	if (numBytes == -1) return false;

	return true;
}

char * Student::Key() {
	key.assign(id, LENID);
	return (char *)(key.c_str());
}
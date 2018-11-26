#include "Student.h"
#include "recfile.h"
#include "textind.h"
#include "indfile.h"
#include "buffile.h"
#include "member.h"
#include "lecture.h"
#include "purchase.h"
#include <fstream>
#include <vector>
#include <string>

using namespace std;
void user();
void admin();

void memberSearch();
void memberDelete();
void memberAdd();
void memberAmend();
void lectureSearch();
void lectureDelete();
void lectureAdd();
void lectureAmend();
void purchaseSearch();
void purchaseDelete();
void purchaseAdd();
void purchaseAmend();



int main() {


	/*
	DelimFieldBuffer buffer('|', STDMAXBUF);
	RecordFile <Student> StudentFile(buffer);

	//Todo...
	TextIndex StudentIndex(10);

	StudentFile.Open("fileOfStudent.dat", ios::in);
	while (1) {		// �л� �����͸� �о �ε����� ����
		Student s;
		int recaddr = StudentFile.Read(s);
		if (recaddr == -1) break;
		//Todo...
		StudentIndex.Insert(s.Key(), recaddr);
		cout << recaddr << '\n' << s;
	}
	StudentFile.Close();

	// ������ �ε����� �ε��� ���Ϸ� ����
	//Todo...
	TextIndexBuffer idxbuf(LENID, 10);
	BufferFile StdIdxFile(idxbuf); //Todo...
		StdIdxFile.Create("fileOfStudent.ind", ios::out | ios::trunc);
	StdIdxFile.Rewind(); //��� ������ ù��° ���ڵ� ��ġ�� �̵�
	//Todo...
	idxbuf.Pack(StudentIndex);
	int result = StdIdxFile.Write();
	StdIdxFile.Close();

	// TextIndexedFile�� ����Ͽ� �б� �� ����
	DelimFieldBuffer buf('|', STDMAXBUF);
	TextIndexedFile<Student> StdIdxedFile(buf, LENID, 10);
	//Todo...

	StdIdxedFile.Open("fileOfStudent");

	Student s;
	StdIdxedFile.Read("20121234", s);		// Ű�� ����Ͽ� �б�
	cout << s;

	StdIdxedFile.Read(s);	// ���� ���ڵ� �б�
	cout << s;

	Student s_new;
	s_new.update_id("12345678");
	s_new.update_name("HongGilDong");
	s_new.update_birthday("1845/05/27");
	s_new.update_number("010-1234-5678");
	StdIdxedFile.Append(s_new);	// ���ο� ���ڵ� �߰�
	StdIdxedFile.Read(s_new.Key(), s);	// �߰��� ���ڵ� �б�
	cout << s;

	StdIdxedFile.Close();

	return 0;
	*/

string id;
string password;

while (1) {
	cout << "ID: ";

	getline(cin, id);

	if (id.compare("q") == 0)
		break;

	cout << "password: ";
	getline(cin, password);

	if (id.compare("admin") == 0 && password.compare("adminpass") == 0) {
		cout << "admin version booting...\n";
		admin();

	}

	else if (id.compare("TestUser") == 0 && password.compare("T1234") == 0) {
		cout << "user version booting...\n";
		user();
	}
	else {
		cout << "disqualified\n";
	}

}

}

void admin() {

	string choice;
	string choice2;

	while (1) {
		cout << "1. Memben\n";
		cout << "2. Lecture\n";
		cout << "3. Purchase\n";
		cout << "4. Quit\n";
		cout << "write number: ";
		getline(cin, choice);

		if (choice.compare("1") == 0) {
			while (1) {
				cout << "1.�˻�\n";
				cout << "2.����\n";
				cout << "3.����\n";
				cout << "4.����\n";
				cout << "5.quit\n";
				cout << "write number: ";
				getline(cin, choice2);

				if (choice2.compare("1") == 0) {
					memberSearch();
				}
				
				else if (choice2.compare("2") == 0) {
					memberDelete();
				}

				else if (choice2.compare("3") == 0) {
					memberAdd();

				}

				else if (choice2.compare("4") == 0) {
					memberAmend();
				}

				else if (choice2.compare("5") == 0) {
					break;
				}
			}
		}

		else if (choice.compare("2") == 0) {
			while (1) {
				cout << "1.�˻�\n";
				cout << "2.����\n";
				cout << "3.����\n";
				cout << "4.����\n";
				cout << "5.quit\n";
				cout << "write number: ";
				getline(cin, choice2);

				if (choice2.compare("1") == 0) {
					lectureSearch();
				}

				else if (choice2.compare("2") == 0) {
					lectureDelete();
				}

				else if (choice2.compare("3") == 0) {
					lectureAdd();

				}

				else if (choice2.compare("4") == 0) {
					lectureAmend();
				}

				else if (choice2.compare("5") == 0) {
					break;
				}
			}
		}

		else if (choice.compare("3") == 0) {
			while (1) {
				cout << "1.�˻�\n";
				cout << "2.����\n";
				cout << "3.����\n";
				cout << "4.����\n";
				cout << "5.quit\n";
				cout << "write number: ";
				getline(cin, choice2);

				if (choice2.compare("1") == 0) {
					purchaseSearch();
				}

				else if (choice2.compare("2") == 0) {
					purchaseDelete();
				}

				else if (choice2.compare("3") == 0) {
					purchaseAdd();

				}

				else if (choice2.compare("4") == 0) {
					purchaseAmend();
				}

				else if (choice2.compare("5") == 0) {
					break;
				}

			}
		}

		else if (choice.compare("4") == 0) {
			break;
		}



	}


}

void user() {
	string choice;
	string choice2;

	while (1) {
		cout << "1. My info\n";
		cout << "2. Lecture\n";
		cout << "3. My purchase\n";
		cout << "4. quit\n";
		cout << "write number: ";
		getline(cin, choice);

		if (choice.compare("1") == 0) {
			while (1) {
				cout << "1. ����\n";
				cout << "2. ����\n";
				cout << "3. quit\n";
				cout << "write number: ";
				getline(cin, choice2);

				if (choice2.compare("3") == 0) {
					break;
				}

				else if (choice2.compare("1") == 0) {
					//�ڽ��� ������ �����Ѵ�.


				}

				else if (choice2.compare("2") == 0) {
					//�ڽ��� ������ �����Ѵ�.


				}
			}
		}

		else if (choice.compare("2") == 0) {
			while (1) {
				cout << "1. �˻�\n";
				cout << "2. quit\n";
				cout << "write number: ";
				getline(cin, choice2);

				if (choice2.compare("2") == 0) {
					break;
				}

				else if (choice2.compare("1") == 0) {
					lectureSearch();
				}
			}
	
		}


		else if (choice.compare("3") == 0) {
			while (1) {
				cout << "1. �˻�\n";
				cout << "2. ����\n";
				cout << "3. ����\n";
				cout << "4. ����\n";
				cout << "5. quit\n";
				cout << "write number: ";
				getline(cin, choice2);

				if (choice2.compare("5") == 0) {
					break;
				}

				else if (choice2.compare("1") == 0) {
					//�ڽ��� purchase ����� �˻�
				}

				else if (choice2.compare("2") == 0) {
					//�ڽ��� purchase ����� ����
				}

				else if (choice2.compare("3") == 0) {
					//�ڽ��� purchase ����� ����
				}

				else if (choice2.compare("4") == 0) {
					//�ڽ��� purchase ����� ����
				}
			}
		}
		

		
		
		else if (choice.compare("4")== 0) {
			break;
		}
	}
}




void memberSearch() {
	//����ڿ��Լ� member �̸��� �Է¹ް�, member�� ������ �˻��Ѵ�.
	Member m;
	DelimFieldBuffer buffer('|', STDMAXBUF);
	RecordFile <Member> MemberFile(buffer);
	string id = "0";
	int r;

	cout << "ã���� �ϴ� member ID�� �Է����ּ���\n";
	cout << "ID: ";
	getline(cin, id);
	
	cout << id << "\n";
	
	MemberFile.Open("fileOfMember.dat", ios::in);
	for (; ; ) {
		Member s;
		r = MemberFile.Read(s);
		//���⼭ READ�� �ϸ� UNPACK�Լ��� ȣ��ȴ�
		if (s.bring_id().compare(id) == 0) {
			cout << s;
			cout << "\n";
			id = "0";
			break;
		}

		if (r == -2 || r == -1) break;
		
		
	}
	if (id.compare("0") != 0)
		cout << "No matched member found!\n";
	MemberFile.Close();



}
void memberDelete() {



}
void memberAdd() {
	//���ο� ����� ���� ������ �Է¹޾Ƽ� dat���Ͽ� �߰��Ѵ�. (dat������ ���ƾ��´�)
	Member m;
	DelimFieldBuffer buffer('|', STDMAXBUF);
	RecordFile <Member> MemberFile(buffer);
	string id;
	string password;
	string name;
	string phonenumber;
	string address;
	char mileage[10];
	string smileage;
	int r; // ���� ���� �˱� ���� ����
	vector <Member> new_list;

	cout << "���ο� ��� ������ �Է��ϼ���.\n";
	cout << "1.��� id (id length has to be 10. letter and number need to be mixed)\n: ";
	getline(cin, id);
	cout << "2.��й�ȣ\n: ";
	getline(cin, password);
	cout << "3. �̸�\n: ";
	getline(cin, name);
	cout << "4. �ڵ�����ȣ(11�ڸ��� ��������)\n: ";
	getline(cin, phonenumber);
	cout << "5. �ּ�(����� ��������)\n: ";
	getline(cin, address);
	cout << "6. mileage�� ��������(10�ڸ���.. ��: 000000312 \n: ";
	getline(cin, smileage);
	strncpy(mileage, smileage.c_str(), 10);
	

	/*
	MemberFile.Open("fileOfMember.dat", ios::in);
	for (; ; ) {
		Member m;
		r = MemberFile.Read(m);
		//���⼭ READ�� �ϸ� UNPACK�Լ��� ȣ��ȴ�
		

		if (r == -2 || r == -1) break;
		new_list.push_back(m);

	}
	MemberFile.Close();
	
	if (new_list.size() == 0) {
		cout << "error! \n";
		return;
	}
	*/
	m.update_id(id);
	m.update_password(password);
	m.update_name(name);
	m.update_phoneNumber(phonenumber);
	m.update_address(address);
	m.update_mileage(mileage);
	//new_list.push_back(m);


	

	MemberFile.Open("fileOfMember.dat", ios::out );
	//������ �� �� ��带 �������־�� �Ѵ�!!!!!!!!!!! ���� �߿� ex) ios::out
	r = MemberFile.Append(m);
	if (r == -1)
		cout << "Append has failed!!";
	
	MemberFile.Close();
	
	
	

}
void memberAmend() {



}
void lectureSearch() {
	//����ڿ��Լ� lecture �̸��� �Է¹ް�, lecture�� ������ �˻��Ѵ�.
	
	DelimFieldBuffer buffer('|', STDMAXBUF);
	RecordFile <Lecture> LectureFile(buffer);
	string id = "0";
	int r;

	cout << "ã���� �ϴ� lecture ID�� �Է����ּ���\n";
	cout << "ID: ";
	getline(cin, id);
	

	LectureFile.Open("fileOfLecture.dat", ios::in);
	for (; ;  ) {
		Lecture l;
		r = LectureFile.Read(l);
		//���⼭ READ�� �ϸ� UNPACK�Լ��� ȣ��ȴ�
		if (l.bring_id().compare(id) == 0) {
			cout << l;
			cout << "\n";
			id = "";
			break;
		}

		if (r == -1 || r == -2) break;

	}
	if (id.compare("") != 0)
		cout << "No matched lecture found!\n";
	LectureFile.Close();



}
void lectureDelete() {



}
void lectureAdd() {



}
void lectureAmend() {



}
void purchaseSearch() {
	//����ڿ��Լ� purchase �̸��� �Է¹ް�, purchase�� ������ �˻��Ѵ�.

	DelimFieldBuffer buffer('|', STDMAXBUF);
	RecordFile <Purchase> PurchaseFile(buffer);
	string id = "0";
	vector<Purchase> founded;
	int r;

	cout << "ã���� �ϴ� purchase ID�� �Է����ּ���\n";
	cout << "ID: ";
	getline(cin, id);
	

	PurchaseFile.Open("fileOfPurchase.dat", ios::in);
	for (; ; ) {
		Purchase p;
		r = PurchaseFile.Read(p);
		//���⼭ READ�� �ϸ� UNPACK�Լ��� ȣ��ȴ�
		if (p.bring_id().compare(id) == 0) {
			cout << p;
			cout << "\n";
			id = "";
			break;
		}

		if (r == -1 || r == -2) break;
	}
	if (id.compare("") != 0)
		cout << "No matched purchase found!\n";
	PurchaseFile.Close();



}
void purchaseDelete() {



}
void purchaseAdd() {
	//


}
void purchaseAmend() {



}
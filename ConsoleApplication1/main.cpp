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
	while (1) {		// 학생 데이터를 읽어서 인덱스를 생성
		Student s;
		int recaddr = StudentFile.Read(s);
		if (recaddr == -1) break;
		//Todo...
		StudentIndex.Insert(s.Key(), recaddr);
		cout << recaddr << '\n' << s;
	}
	StudentFile.Close();

	// 생성한 인덱스를 인덱스 파일로 저장
	//Todo...
	TextIndexBuffer idxbuf(LENID, 10);
	BufferFile StdIdxFile(idxbuf); //Todo...
		StdIdxFile.Create("fileOfStudent.ind", ios::out | ios::trunc);
	StdIdxFile.Rewind(); //헤더 다음의 첫번째 레코드 위치로 이동
	//Todo...
	idxbuf.Pack(StudentIndex);
	int result = StdIdxFile.Write();
	StdIdxFile.Close();

	// TextIndexedFile을 사용하여 읽기 및 쓰기
	DelimFieldBuffer buf('|', STDMAXBUF);
	TextIndexedFile<Student> StdIdxedFile(buf, LENID, 10);
	//Todo...

	StdIdxedFile.Open("fileOfStudent");

	Student s;
	StdIdxedFile.Read("20121234", s);		// 키를 사용하여 읽기
	cout << s;

	StdIdxedFile.Read(s);	// 다음 레코드 읽기
	cout << s;

	Student s_new;
	s_new.update_id("12345678");
	s_new.update_name("HongGilDong");
	s_new.update_birthday("1845/05/27");
	s_new.update_number("010-1234-5678");
	StdIdxedFile.Append(s_new);	// 새로운 레코드 추가
	StdIdxedFile.Read(s_new.Key(), s);	// 추가한 레코드 읽기
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
				cout << "1.검색\n";
				cout << "2.삭제\n";
				cout << "3.삽입\n";
				cout << "4.수정\n";
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
				cout << "1.검색\n";
				cout << "2.삭제\n";
				cout << "3.삽입\n";
				cout << "4.수정\n";
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
				cout << "1.검색\n";
				cout << "2.삭제\n";
				cout << "3.삽입\n";
				cout << "4.수정\n";
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
				cout << "1. 수정\n";
				cout << "2. 삭제\n";
				cout << "3. quit\n";
				cout << "write number: ";
				getline(cin, choice2);

				if (choice2.compare("3") == 0) {
					break;
				}

				else if (choice2.compare("1") == 0) {
					//자신의 정보를 수정한다.


				}

				else if (choice2.compare("2") == 0) {
					//자신의 정보를 삭제한다.


				}
			}
		}

		else if (choice.compare("2") == 0) {
			while (1) {
				cout << "1. 검색\n";
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
				cout << "1. 검색\n";
				cout << "2. 삭제\n";
				cout << "3. 삽입\n";
				cout << "4. 수정\n";
				cout << "5. quit\n";
				cout << "write number: ";
				getline(cin, choice2);

				if (choice2.compare("5") == 0) {
					break;
				}

				else if (choice2.compare("1") == 0) {
					//자신의 purchase 기록을 검색
				}

				else if (choice2.compare("2") == 0) {
					//자신의 purchase 기록을 삭제
				}

				else if (choice2.compare("3") == 0) {
					//자신의 purchase 기록을 삽입
				}

				else if (choice2.compare("4") == 0) {
					//자신의 purchase 기록을 수정
				}
			}
		}
		

		
		
		else if (choice.compare("4")== 0) {
			break;
		}
	}
}




void memberSearch() {
	//사용자에게서 member 이름을 입력받고, member의 정보를 검색한다.
	Member m;
	DelimFieldBuffer buffer('|', STDMAXBUF);
	RecordFile <Member> MemberFile(buffer);
	string id = "0";
	int r;

	cout << "찾고자 하는 member ID를 입력해주세요\n";
	cout << "ID: ";
	getline(cin, id);
	
	cout << id << "\n";
	
	MemberFile.Open("fileOfMember.dat", ios::in);
	for (; ; ) {
		Member s;
		r = MemberFile.Read(s);
		//여기서 READ를 하면 UNPACK함수가 호출된다
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
	//새로운 멤버에 대한 정보를 입력받아서 dat파일에 추가한다. (dat파일을 갈아엎는다)
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
	int r; // 파일 끝을 알기 위한 숫자
	vector <Member> new_list;

	cout << "새로운 멤버 정보를 입력하세요.\n";
	cout << "1.멤버 id (id length has to be 10. letter and number need to be mixed)\n: ";
	getline(cin, id);
	cout << "2.비밀번호\n: ";
	getline(cin, password);
	cout << "3. 이름\n: ";
	getline(cin, name);
	cout << "4. 핸드폰번호(11자리로 적으세요)\n: ";
	getline(cin, phonenumber);
	cout << "5. 주소(영어로 적으세요)\n: ";
	getline(cin, address);
	cout << "6. mileage를 적으세요(10자리로.. 예: 000000312 \n: ";
	getline(cin, smileage);
	strncpy(mileage, smileage.c_str(), 10);
	

	/*
	MemberFile.Open("fileOfMember.dat", ios::in);
	for (; ; ) {
		Member m;
		r = MemberFile.Read(m);
		//여기서 READ를 하면 UNPACK함수가 호출된다
		

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
	//파일을 열 때 모드를 설정해주어야 한다!!!!!!!!!!! 아주 중요 ex) ios::out
	r = MemberFile.Append(m);
	if (r == -1)
		cout << "Append has failed!!";
	
	MemberFile.Close();
	
	
	

}
void memberAmend() {



}
void lectureSearch() {
	//사용자에게서 lecture 이름을 입력받고, lecture의 정보를 검색한다.
	
	DelimFieldBuffer buffer('|', STDMAXBUF);
	RecordFile <Lecture> LectureFile(buffer);
	string id = "0";
	int r;

	cout << "찾고자 하는 lecture ID를 입력해주세요\n";
	cout << "ID: ";
	getline(cin, id);
	

	LectureFile.Open("fileOfLecture.dat", ios::in);
	for (; ;  ) {
		Lecture l;
		r = LectureFile.Read(l);
		//여기서 READ를 하면 UNPACK함수가 호출된다
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
	//사용자에게서 purchase 이름을 입력받고, purchase의 정보를 검색한다.

	DelimFieldBuffer buffer('|', STDMAXBUF);
	RecordFile <Purchase> PurchaseFile(buffer);
	string id = "0";
	vector<Purchase> founded;
	int r;

	cout << "찾고자 하는 purchase ID를 입력해주세요\n";
	cout << "ID: ";
	getline(cin, id);
	

	PurchaseFile.Open("fileOfPurchase.dat", ios::in);
	for (; ; ) {
		Purchase p;
		r = PurchaseFile.Read(p);
		//여기서 READ를 하면 UNPACK함수가 호출된다
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
#include <iostream>
#include <fstream>
#include "Workers.h"
#include "Exception.h"
using namespace std;
const int MAX = 5;

void PrintMenu();
void Make_permanent(Worker** w, int& index);
void Make_temporary(Worker** w, int& index);
void Make_salesPerson(Worker** w, int& index);
void Show_all(Worker** w, int index);
void Exceptions_fileIO(Worker** w, int index);
bool AccountDataStore(Worker** w, int index);
void CleanUp(Worker** w, int index);
bool Exceptions_memory(int index);

enum { PERMANENT = 1, TEMPORARY, SALESPERSON, SHOWALL, EXIT };

int main() {
	char choice1;
	int choice2;
	Worker* w[MAX] = { NULL };
	int index = 0;
	while (true) {
		PrintMenu();
		cout << "메뉴를 선택하세요 : ";
		cin >> choice1;
		cin.clear();
		cin.ignore();
		choice2 = choice1 - '0';
		switch (choice2) {
		case PERMANENT:
			if (Exceptions_memory(index) == true) {
				Make_permanent(w, index);
			}
			break;
		case TEMPORARY:
			if (Exceptions_memory(index) == true) {
				Make_temporary(w, index);
			}
			break;
		case SALESPERSON:
			if (Exceptions_memory(index) == true) {
				Make_salesPerson(w, index);
			}
			break;
		case SHOWALL:
			Show_all(w, index);
			break;
		case EXIT:
			Exceptions_fileIO(w, index);
			CleanUp(w, index);
			return 0;
		default:
			cout << "잘못 입력하셨습니다." << endl;
			break;
		}
	}
}
void PrintMenu() {
	cout << "========== 메뉴 ==========" << endl;
	cout << "1. 직원 입력[Permanent]" << endl;
	cout << "2. 직원 입력[Temporary]" << endl;
	cout << "3. 직원 입력[SalesPerson]" << endl;
	cout << "4. 모든 직원 급여 보기" << endl;
	cout << "5. 종 료" << endl;
}

void Make_permanent(Worker** w, int& index) {
	char name[20];
	int work_num;
	int money;
	cout << "이름: ";
	cin.getline(name, 20);
	cout << "사번: ";
	cin >> work_num;
	cout << "월급: ";
	cin >> money;
	for (int i = 0; i < index; i++) {
		if (work_num == w[i]->Get_work_num()) {
			cout << "중복된 사번이 존재합니다!" << endl;
			return;
		}
	}
	w[index] = new Permanent(money, name, work_num);
	index++;
}

void Make_temporary(Worker** w, int& index) {
	char name[20];
	int work_num;
	int time;
	int money;
	cout << "이름: ";
	cin.getline(name, 20);
	cout << "사번: ";
	cin >> work_num;
	cout << "시간: ";
	cin >> time;
	cout << "시급: ";
	cin >> money;
	for (int i = 0; i < index; i++) {
		if (work_num == w[i]->Get_work_num()) {
			cout << "중복된 사번이 존재합니다!" << endl;
			return;
		}
	}
	w[index] = new Temporary(money, name, work_num, time);
	index++;
}

void Make_salesPerson(Worker** w, int& index) {
	char name[20];
	int work_num;
	int money;
	int earn_money;
	cout << "이름: ";
	cin.getline(name, 20);
	cout << "사번: ";
	cin >> work_num;
	cout << "월급: ";
	cin >> money;
	cout << "벌어들인 금액: ";
	cin >> earn_money;
	for (int i = 0; i < index; i++) {
		if (work_num == w[i]->Get_work_num()) {
			cout << "중복된 사번이 존재합니다!" << endl;
			return;
		}
	}
	w[index] = new SalesPerson(money, name, work_num, earn_money);
	index++;
}

void Show_all(Worker** w, int index) {
	for (int i = 0; i < index; i++) {
		w[i]->show();
	}
}

void Exceptions_fileIO(Worker** w, int index) {
	try {
		if (AccountDataStore(w, index) == false) {
			FileIOException me(0);
			throw &me;
		}
	}
	catch (MyException* ep) {
		ep->report();
	}
}

bool AccountDataStore(Worker** w, int index) {
	char outfile[50] = "Accounts.txt";
	ofstream fout;
	fout.open(outfile, ios::out | ios::trunc);
	if (!fout) {
		cout << "이 Accounts.txt를 열 수 없습니다." << endl;
		return false;
	}
	for (int i = 0; i < index; i++) {
		if (w[i] != NULL) {
			fout << w[i]->Get_name() << ": " << w[i]->Get_money() << endl;
		}
	}
	fout.close();
	return true;
}

void CleanUp(Worker** w, int index) {
	for (int i = 0; i < index; i++) {
		if (w[i] != NULL) {
			delete w[i];
			w[i] = NULL;
		}
	}
}

bool Exceptions_memory(int index) {
	try {
		if (index >= MAX) {
			MemoryException me(index);
			throw &me;
		}
	}
	catch (MyException* ep) {
		ep->report();
		return false;
	}
	return true;
}

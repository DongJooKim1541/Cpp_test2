#include <iostream>
#include "Workers.h"
using namespace std;

void Worker::show() {

}
char* Worker::Get_name() {
	return name;
}
int Worker::Get_money() {
	return money;
}
int Worker::Get_work_num() {
	return work_num;
}

Worker::~Worker() {
	if (name) {
		delete[] name;
	}
}

void Permanent::show() {
	cout << "�̸�: " << name << endl;
	cout << "����: " << money << "��" << endl;
}
char* Permanent::Get_name() {
	return name;
}
int Permanent::Get_money() {
	return money;
}

void Temporary::show() {
	cout << "�̸�: " << name << endl;
	cout << "����: " << Calc1(money, time) << "��" << endl;
}
char* Temporary::Get_name() {
	return name;
}
int Temporary::Get_money() {
	return money;
}
void SalesPerson::show() {
	cout << "�̸�: " << name << endl;
	cout << "����: " << Calc2(money, earn_money) << "��" << endl;
}
char* SalesPerson::Get_name() {
	return name;
}
int SalesPerson::Get_money() {
	return money;
}
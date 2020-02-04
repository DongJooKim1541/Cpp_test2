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
	cout << "이름: " << name << endl;
	cout << "월급: " << money << "원" << endl;
}
char* Permanent::Get_name() {
	return name;
}
int Permanent::Get_money() {
	return money;
}

void Temporary::show() {
	cout << "이름: " << name << endl;
	cout << "월급: " << Calc1(money, time) << "원" << endl;
}
char* Temporary::Get_name() {
	return name;
}
int Temporary::Get_money() {
	return money;
}
void SalesPerson::show() {
	cout << "이름: " << name << endl;
	cout << "월급: " << Calc2(money, earn_money) << "원" << endl;
}
char* SalesPerson::Get_name() {
	return name;
}
int SalesPerson::Get_money() {
	return money;
}
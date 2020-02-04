#ifndef WORKERS_H
#define WORKERS_H
#include <iostream>
using namespace std;
class Worker {
protected:
	int money;
	char* name;
	int work_num;
public:
	Worker::Worker() {
		money = 0;
		name = NULL;
		work_num = 0;
	}
	Worker::Worker(int money1 = 0, char* name1 = NULL, int work_num1 = 0) {
		money = money1;
		name = new char[strlen(name1) + 1];
		strcpy_s(name, strlen(name1) + 1, name1);
		work_num = work_num1;
	}
	virtual void show();
	virtual char* Get_name();
	virtual int Get_money();
	int Get_work_num();
	virtual~Worker();
};
class Permanent :public Worker {
public:
	Permanent(int money1 = 0, char* name1 = NULL, int work_num1 = 0)
		:Worker(money1, name1, work_num1)
	{

	}
	void show();
	char* Get_name();
	int Get_money();
};
class Temporary :public Worker {
private:
	int time;
	int Calc1(int money1, int time1) {
		money = money1*time1;
		return money;
	}
public:
	Temporary(int money1 = 0, char* name1 = NULL, int work_num1 = 0, int time1 = 0)
		:Worker(money1, name1, work_num1)
	{
		time = time1;
	}
	void show();
	char* Get_name();
	int Get_money();
};
class SalesPerson :public Worker {
private:
	int earn_money;
	int Calc2(int money1, int earn_money1) {
		money = (int)(money1 + (earn_money1*0.15));
		return money;
	}
public:
	SalesPerson(int money1 = 0, char* name1 = NULL, int work_num1 = 0, int earn_money1 = 0)
		:Worker(money1, name1, work_num1)
	{
		earn_money = earn_money1;
	}
	void show();
	char* Get_name();
	int Get_money();
};
#endif
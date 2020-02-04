#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>
using namespace std;
class MyException {
public:
	char* description;
	int info;
	bool info1;
	MyException(char* description1, int info1) {
		description = description1; info = info1;
	}
	virtual void report() {

	}
};
class MemoryException :public MyException {
public:
	MemoryException(int index)
		:MyException("����� �ִ� ������ �ִ� ������ �ʰ��Ͽ����ϴ�.", index)
	{

	}
	void report() {
		cout << "���ܿ� ���� ����: " << description << endl;
		cout << "index: " << info << endl;
	}
};
class FileIOException :public MyException {
public:
	FileIOException(int _yn)
		:MyException("��������� �Ұ�", _yn)
	{

	}
	void report() {
		cout << "���ܿ� ���� ����: " << description << endl;
		cout << "Y/N: false" << endl;
	}
};
#endif
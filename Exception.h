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
		:MyException("만들수 있는 계좌의 최대 개수를 초과하였습니다.", index)
	{

	}
	void report() {
		cout << "예외에 대한 설명: " << description << endl;
		cout << "index: " << info << endl;
	}
};
class FileIOException :public MyException {
public:
	FileIOException(int _yn)
		:MyException("파일입출력 불가", _yn)
	{

	}
	void report() {
		cout << "예외에 대한 설명: " << description << endl;
		cout << "Y/N: false" << endl;
	}
};
#endif
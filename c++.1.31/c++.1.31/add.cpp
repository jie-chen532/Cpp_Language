#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string.h>
using namespace std;
#include"add.h"

//inline int add(int a, int b)
//{
//	return a + b;
//}

void Student::SetStudentInfo(const char* name, const char* gender, int age)
{
	strcpy(_name, name);
	strcpy(_gender, gender);
	_age = age;
}

void Student::PrintStudentInfo()
{
	cout << _name << " " << _gender << " " << _age << endl;
}
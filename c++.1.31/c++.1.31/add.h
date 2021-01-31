#define _CRT_SECURE_NO_WARNINGS 1


//inline int  add(int a, int b);


class Student
{public:	//成员函数
	void SetStudentInfo(const char* name, const char* gender, int age);

	void PrintStudentInfo();

private:
	//成员变量
	char _name[20];
	char _gender[3];
	int _age;
};
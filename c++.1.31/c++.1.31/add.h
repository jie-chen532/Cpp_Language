#define _CRT_SECURE_NO_WARNINGS 1


//inline int  add(int a, int b);


class Student
{public:	//��Ա����
	void SetStudentInfo(const char* name, const char* gender, int age);

	void PrintStudentInfo();

private:
	//��Ա����
	char _name[20];
	char _gender[3];
	int _age;
};
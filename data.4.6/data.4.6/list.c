#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef int LDataType;
//������
typedef struct ListNode
{
	LDataType data;
	struct ListNode* next;
}ListNode;


//��������
typedef struct List
{
	struct ListNode* head;
}List;

void InitList(List* lst)
{
	if (lst == NULL)
		return;
	lst->head = NULL;
}

ListNode* creatNode(LDataType val)
{
	struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
	node->next = NULL;
	node->data = val;
	return node;
}

//β��
void pushBackList(List* lst, LDataType val)
{
	if (lst == NULL)
		return;
	struct ListNode* newNode = creatNode(val);

	//������
	if (lst->head == NULL)
	{
		lst->head = newNode;
	}
	else
	{
		struct ListNode* cur = lst->head;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = newNode;
	}
}


//βɾ
void popBackList(List* lst)
{
	if (lst == NULL || lst->head == NULL)
		return;
	struct ListNode* prev = NULL;
	struct ListNode* cur = lst->head;
	while (cur->next != NULL)
	{
		prev = cur;
		cur = cur->next;
	}

	free(cur);
	if (prev == NULL)//ֻʣһ��Ԫ��
	{
		lst->head = NULL;
	}
	else
	{
		prev->next = NULL;
	}
}


//ͷ��
void pushFront(List* lst, LDataType val)
{
	if (lst == NULL)
		return;
	struct ListNode* newNode = creatNode(val);

	newNode->next = lst->head;
	lst->head = newNode;
}

//ͷɾ
void popFront(List* lst)
{
	if (lst == NULL || lst->head == NULL)
		return;
	struct ListNode* tail = lst->head->next;
	free(lst->head);
	lst->head = tail;
}

//������λ�ú����
void insertAfter(struct ListNode* node, LDataType val)
{
	struct ListNode* newNnode = creatNode(val);
	struct ListNode* tail = node->next;

	node->next = newNnode;
	newNnode->next = tail;
}

//������λ�ú�ɾ��
void eraseAfter(struct ListNode* node)
{
	if (node->next == NULL)
		return;
	struct ListNode* tail = node->next->next;
	free(node->next);
	node->next = tail;
}

//��ĳһ������ֵ
struct ListNode* findList(List* lst, LDataType val)
{
	if (lst == NULL || lst->head == NULL)
		return NULL;
	struct ListNode* cur = lst->head;
	while (cur)
	{
		if (cur->data == val)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

//��������
void destoryList(List* lst)
{
	if (lst == NULL || lst->head == NULL)
		return;
	struct ListNode* cur = lst->head;
	while (cur != NULL)
	{
		struct ListNode* tail = cur->next;
		free(cur);
		cur = tail;
	}
	lst->head = NULL;
}

void printList(List* lst)
{
	if (lst == NULL || lst->head == NULL)
		return;
	struct ListNode* cur = lst->head;
	while (cur)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}


void test()
{
	List lst;
	InitList(&lst);
	pushFront(&lst, 1);
	pushFront(&lst, 2);
	pushFront(&lst, 3);
	pushFront(&lst, 4);
	pushFront(&lst, 5);
	printList(&lst);//5 4 3 2 1
	struct ListNode* node = findList(&lst, 3);
	insertAfter(node, 7);
	printList(&lst);//5 4 3 7 2 1
	node = findList(&lst, 5);
	eraseAfter(node);
	printList(&lst);//5 3 7 2 1
	destoryList(&lst);
}

//void test()
//{
//	List lst;
//	InitList(&lst);
//	pushFront(&lst, 7);
//	pushFront(&lst, 6);
//	pushFront(&lst, 5);
//	pushFront(&lst, 4);
//	pushFront(&lst, 3);
//	pushFront(&lst, 2);
//	pushFront(&lst, 1);
//	popFront(&lst);
//	popFront(&lst);
//	popFront(&lst);
//	popFront(&lst);
//	printList(&lst);
//}

//void test()
//{
//	List lst;
//	InitList(&lst);
//	pushBackList(&lst, 1);
//	pushBackList(&lst, 2);
//	pushBackList(&lst, 3);
//	pushBackList(&lst, 4);
//	pushBackList(&lst, 5);
//	pushBackList(&lst, 6);
//	popBackList(&lst);
//	popBackList(&lst);
//	popBackList(&lst);
//	pushBackList(&lst, 7);
//	pushBackList(&lst, 8);
//	pushBackList(&lst, 9);
//	printList(&lst);
//}

int main()
{
	test();
	return 0;
}
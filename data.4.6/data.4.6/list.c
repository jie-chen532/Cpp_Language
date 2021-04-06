#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef int LDataType;
//定义结点
typedef struct ListNode
{
	LDataType data;
	struct ListNode* next;
}ListNode;


//定义链表
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

//尾插
void pushBackList(List* lst, LDataType val)
{
	if (lst == NULL)
		return;
	struct ListNode* newNode = creatNode(val);

	//空链表
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


//尾删
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
	if (prev == NULL)//只剩一个元素
	{
		lst->head = NULL;
	}
	else
	{
		prev->next = NULL;
	}
}


//头插
void pushFront(List* lst, LDataType val)
{
	if (lst == NULL)
		return;
	struct ListNode* newNode = creatNode(val);

	newNode->next = lst->head;
	lst->head = newNode;
}

//头删
void popFront(List* lst)
{
	if (lst == NULL || lst->head == NULL)
		return;
	struct ListNode* tail = lst->head->next;
	free(lst->head);
	lst->head = tail;
}

//在任意位置后插入
void insertAfter(struct ListNode* node, LDataType val)
{
	struct ListNode* newNnode = creatNode(val);
	struct ListNode* tail = node->next;

	node->next = newNnode;
	newNnode->next = tail;
}

//在任意位置后删除
void eraseAfter(struct ListNode* node)
{
	if (node->next == NULL)
		return;
	struct ListNode* tail = node->next->next;
	free(node->next);
	node->next = tail;
}

//找某一个具体值
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

//销毁链表
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
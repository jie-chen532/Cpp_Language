#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<stdlib.h>
//双向带头循环链表
typedef int LDataType;
//结点
typedef struct ListNode
{
	LDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;

//链表
typedef struct List
{
	//指向头结点的指针
	struct ListNode* head;
}List;

void listInsert(ListNode* node, LDataType val);
void listErase(ListNode* node);

void InitList(List* lst)
{
	if (lst == NULL)
		return;
	lst->head = (struct ListNode*)malloc(sizeof(struct ListNode));
	lst->head->next = lst->head->prev = lst->head;
}

ListNode* creatNode(LDataType val)
{
	struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
	node->data = val;
	node->prev = node->next = NULL;
	return node;
}

//尾插
void pushBackList(List* lst, LDataType val)
{
	if (lst == NULL)
		return;
	//struct ListNode* newNode = creatNode(val);
	//struct ListNode* tail = lst->head->prev;

	//tail->next = newNode;
	//newNode->prev = tail;

	//lst->head->prev = newNode;
	//newNode->next = lst->head;
	listInsert(lst->head, val);
}


//尾删
void popBackList(List* lst)
{
	//删除不能破坏双向带头循环链表结构
	if (lst == NULL || lst->head->next == lst->head)
		return;
	//struct ListNode* tail = lst->head->prev;
	//struct ListNode* prev = tail->prev;

	//free(tail);
	//lst->head->prev = prev;
	//prev->next = lst->head;
	listErase(lst->head->prev);
}

//头插
void pushFrontList(List* lst, LDataType val)
{
	if (lst == NULL)
		return;
	//struct ListNode* newNode = creatNode(val);

	//struct ListNode* next = lst->head->next;
	//lst->head->next = newNode;
	//newNode->prev = lst->head;

	//newNode->next = next;
	//next->prev = newNode;
	listInsert(lst->head->next, val);
}


//头删
void popFrontList(List* lst)
{
	if (lst == NULL || lst->head->next == lst->head)
		return;
	//struct ListNode* tail = lst->head->next->next;

	//free(lst->head->next);
	//lst->head->next = tail;
	//tail->prev = lst->head;
	listErase(lst->head->next);
}

//在任意结点之前插入
void listInsert(ListNode* node, LDataType val)
{
	struct ListNode* newNode = creatNode(val);

	struct ListNode* prev = node->prev;
	prev->next = newNode;
	newNode->prev = prev;
	
	newNode->next = node;
	node->prev = newNode;
}


//任意删除某节点
void listErase(ListNode* node)
{
	struct ListNode* prev = node->prev;
	struct ListNode* next = node->next;

	free(node);
	prev->next = next;
	next->prev = prev;
}

//找到结点所在位置
struct ListNode* listFind(List* lst, LDataType val)
{
	if (lst == NULL || lst->head->next == lst->head)
		return NULL;
	struct ListNode* cur = lst->head->next;
	while (cur != lst->head)
	{
		if (cur->data == val)
			return cur;
		cur = cur->next;
	}
	return NULL;
}


//销毁
void listDestory(List* lst)
{
	if (lst == NULL)
		return;
	struct ListNode* cur = lst->head->next;
	while (cur != lst->head)
	{
		struct ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(lst->head);
	lst->head = NULL;
}

void printList(List* lst)
{
	if (lst == NULL || lst->head == NULL)
		return;
	struct ListNode* cur = lst->head->next;
	while (cur != lst->head)
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
	pushBackList(&lst, 1);
	pushBackList(&lst, 2);
	pushBackList(&lst, 3);
	pushBackList(&lst, 4);
	pushBackList(&lst, 5);
	pushBackList(&lst, 6);
	popBackList(&lst);
	popBackList(&lst);
	popBackList(&lst);
	popBackList(&lst);
	popBackList(&lst);
	popBackList(&lst);
	pushFrontList(&lst, 2);
	pushFrontList(&lst, 3);
	pushFrontList(&lst, 4);
	pushFrontList(&lst, 5);
	pushFrontList(&lst, 6);
	pushFrontList(&lst, 7);
	popFrontList(&lst);
	popFrontList(&lst);
	popFrontList(&lst);
	popFrontList(&lst);
	//listDestory(&lst);
	printList(&lst);
}

//void test()
//{
//	List lst;
//	InitList(&lst);
//	pushFrontList(&lst, 1);
//	pushFrontList(&lst, 2);
//	pushFrontList(&lst, 3);
//	pushFrontList(&lst, 4);
//	pushFrontList(&lst, 5);
//	pushFrontList(&lst, 6);
//	popFrontList(&lst);
//	popFrontList(&lst);
//	popFrontList(&lst);
//	popFrontList(&lst);
//	popFrontList(&lst);
//	popFrontList(&lst);
//	pushFrontList(&lst, 10);
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
//	popBackList(&lst);
//	popBackList(&lst);
//	popBackList(&lst);
//	pushBackList(&lst, 10);
//	printList(&lst);
//}

int main()
{
	test();
	return 0;
}
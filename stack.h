#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define capty 20

#define MALLOC(type,number) (type*)malloc(sizeof(type)*number)
#define REALLOC(type,position,number) (type*)realloc(position,sizeof(type)*number)
typedef struct stack {
	int* ps;
	int capacity;
	int top; //栈顶元素的下一个位置
}stacknode;

void init(stacknode* p);
void push(stacknode* p, int x);
void pop(stacknode* p);
int printtop(stacknode* p);
void destroy(stacknode* p);
int judgeempty(stacknode* p);
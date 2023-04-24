#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<stdbool.h>

typedef int datatype;
#define	MALLOC(type,num) (type*)malloc(sizeof(type)*num)

typedef struct queue {
	datatype data;
	struct queue* tail;
	struct queue* next;  //������һ�����н��
}queue;

queue* QueueCreate();
void QueuePush(queue* obj, datatype a);
datatype Queuefront(queue* obj);
void QueuePop(queue* obj); 
bool QueueEmpty(queue* obj);
#define _CRT_SECURE_NO_WARNINGS

#include"queue.h"

queue* QueueCreate() {  //�ڱ�λ
	queue* obj = MALLOC(queue, 1);
	obj->data = 0;
	obj->next = obj->tail = NULL;
	return obj;
}

void QueuePush(queue* obj, datatype a) {
	queue* newnode = MALLOC(queue, 1);
	newnode->data = a;
	newnode->next = NULL;

	if (obj->next == NULL) {
		obj->next = obj->tail = newnode;
	}
	else {
		obj->tail->next = newnode;
		obj->tail = newnode;
	}
}

datatype Queuefront(queue* obj) {
	return obj->next->data;
}

void QueuePop(queue* obj) {
	queue* tmp = obj->next;//��һ����Ч���
	if (!QueueEmpty(obj)) {
		queue* next = tmp->next;  
		free(tmp);
		tmp = next;
	}
}

bool QueueEmpty(queue* obj) {
	if (obj->next == NULL) {
		return true;
	}
	return false;
}
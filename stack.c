#define _CRT_SECURE_NO_WARNINGS

#include"stack.h"

void init(stacknode* p) {
	p->ps = MALLOC(int, capty);
	p->capacity = capty;
	p->top = 0;
}
int judgeempty(stacknode* p) {
	assert(p);
	return p->top == 0;
}
void push(stacknode* p, int x) {
	assert(p);
	if (p->top == p->capacity) {
		int* tmp = REALLOC(int, p->ps, p->capacity * 2);
		p->ps = tmp;
		p->capacity *= 2;
	}
	p->ps[p->top++] = x;
}
void pop(stacknode* p) {
	assert(p);
	assert(p->top);
	p->top--;
}
int printtop(stacknode* p) {
	assert(p);
	return p->ps[p->top - 1];
}
void destroy(stacknode* p) {
	free(p->ps);
	p->top = 0;
	p->capacity = 0;
}
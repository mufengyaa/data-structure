#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int HPDataType;
#define MALLOC(type,num) (type*)malloc(num*sizeof(type))
#define REALLOC(obj,type,num) (type*)realloc(obj,num*sizeof(type))

typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity; 
}Heap;
 
void HeapCreate(Heap* hp, HPDataType* a, int n);// �ѵĹ���
void HeapDestory(Heap* hp);   // �ѵ�����
void HeapPush(Heap* hp, HPDataType x); // �ѵĲ���
void adjustup(Heap* hp,HPDataType* a, int child);  //���ϵ���
void HeapPop(Heap* hp);   // �ѵ�ɾ��
void adjustdown(Heap* hp,HPDataType* a, int n,int child);  //���µ��� 
HPDataType HeapTop(Heap* hp); // ȡ�Ѷ�������
int HeapSize(Heap* hp);  // �ѵ����ݸ���
int HeapEmpty(Heap* hp);  // �ѵ��п�
void print(Heap* hp, int n);  //��ӡ����
void swap(HPDataType* x, HPDataType* y);  //��������
 
// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
void PrintTopK(int* a, int n, int k);
void TestTopk();
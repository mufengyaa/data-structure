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
 
void HeapCreate(Heap* hp, HPDataType* a, int n);// 堆的构建
void HeapDestory(Heap* hp);   // 堆的销毁
void HeapPush(Heap* hp, HPDataType x); // 堆的插入
void adjustup(Heap* hp,HPDataType* a, int child);  //向上调整
void HeapPop(Heap* hp);   // 堆的删除
void adjustdown(Heap* hp,HPDataType* a, int n,int child);  //向下调整 
HPDataType HeapTop(Heap* hp); // 取堆顶的数据
int HeapSize(Heap* hp);  // 堆的数据个数
int HeapEmpty(Heap* hp);  // 堆的判空
void print(Heap* hp, int n);  //打印函数
void swap(HPDataType* x, HPDataType* y);  //交换数字
 
// TopK问题：找出N个数里面最大/最小的前K个问题。
// 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
// 需要注意：
// 找最大的前K个，建立K个数的小堆
// 找最小的前K个，建立K个数的大堆
void PrintTopK(int* a, int n, int k);
void TestTopk();
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"堆.h"

void swap(HPDataType* x, HPDataType* y) {
	HPDataType t;
	t = *x;
	*x = *y;
	*y = t;
}
Heap* init(int n) {
	Heap* hp = MALLOC(Heap, 1);
	hp->_a = MALLOC(HPDataType, n);
	hp->_capacity = n;
	hp->_size = 0;
	return hp;
}
int HeapSize(Heap* hp) {
	return hp->_size;
}
int HeapEmpty(Heap* hp) {
	return hp->_size == 0;
}

void adjustup(Heap* hp,HPDataType* a,int child) {
	assert(a);
	assert(!HeapEmpty(hp));

	int parent = (child - 1) / 2;
	while (child > 0) {
		if (a[parent] < a[child]) {
			swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}
void adjustdown(Heap* hp,HPDataType* a,int n,int parent) {
	assert(a);
	assert(!HeapEmpty(hp));

	int child = parent * 2 + 1; //左孩子
	int flag = 0;
	while (child < n && flag==0) {
		HPDataType tmp = parent;
		if (a[child] > a[tmp]) {
			tmp = child;
		}
		if (child + 1 < n) {  //有右孩子
			if (a[child + 1] > a[tmp]) {
				tmp = child + 1;
			}
		}
		if (tmp == parent) {
			flag = 1;
		}
		else {
			swap(&a[tmp], &a[parent]);
			parent = tmp;
			child = parent * 2 + 1;
		}	
	}
}

void HeapPush(Heap* hp, HPDataType x) {
	assert(hp);

	hp->_a[hp->_size++] = x;
	adjustup(hp,hp->_a, hp->_size-1);
	if (hp->_size == hp->_capacity) {
		HPDataType* tmp = REALLOC(hp->_a, HPDataType, hp->_capacity * 2);
		hp->_a = tmp;
		hp->_capacity *= 2;
	}
}
void HeapPop(Heap* hp) {
	assert(hp);
	assert(!HeapEmpty(hp));

	swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	adjustdown(hp,hp->_a,HeapSize(hp),0);
}

HPDataType HeapTop(Heap* hp) {
	assert(hp);
	assert(!HeapEmpty(hp));

	return hp->_a[0];
}

void HeapCreate(Heap* hp, HPDataType* a, int n) {
	assert(hp);
	assert(a);

	for (int i = 0; i < n; i++) {
		HeapPush(hp, a[i]);
	}
}
void print(Heap* hp,int n) {
	assert(hp);

	for (int i = 0; i < n; i++) {
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}
void HeapDestory(Heap* hp) {
	assert(hp);
	free(hp->_a);
	free(hp);
}

void siftdown(HPDataType* a, int n, int parent) {
	assert(a);

	int child = parent * 2 + 1; //左孩子
	int flag = 0;
	while (child < n && flag == 0) {  //维护大堆
		HPDataType tmp = parent;
		if (a[child] > a[tmp]) {
			tmp = child;
		}
		if (child + 1 < n) {  //有右孩子
			if (a[child + 1] > a[tmp]) {
				tmp = child + 1;
			}
		}
		if (tmp == parent) {
			flag = 1;
		}
		else {
			swap(&a[tmp], &a[parent]);
			parent = tmp;
			child = parent * 2 + 1;
		}
	}  
//	while (child < n && flag == 0) {   //维护小堆
//		HPDataType tmp = parent;
//		if (a[child] < a[tmp]) {
//			tmp = child;
//		}
//		if (child + 1 < n) {  //有右孩子
//			if (a[child + 1] < a[tmp]) {
//				tmp = child + 1;
//			}
//		}
//		if (tmp == parent) {
//			flag = 1;
//		}
//		else {
//			swap(&a[tmp], &a[parent]);
//			parent = tmp;
//			child = parent * 2 + 1;
//		}
//	}
}
void PrintTopK(HPDataType* a, int n, int k) {
	HPDataType t = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &t);
		if (i < k) {  //将k个元素先导入数组中
			a[i] = t;
			if (i == k - 1) {  //当数组中已有k个元素后,向下调整
				for (int j = (i - 1) / 2; j >= 0; j--) {
					siftdown(a,k,j);
				}
			}
		}
		else {
			if (t < a[0]) {  //头是最大数
				swap(&t, &a[0]);  //将小的那个数字与头互换
				siftdown(a, k, 0);  //维护大堆
			}
			//			if (t > a[0]) {  //头是最小数
			//				swap(&t, &a[0]);  //将大的那个数字与头互换
			//				siftdown(a, k, 0);  //维护小堆
			//			}
		}
	}
}
void TestTopk() {   //找最小/大的前k个  
	int n = 0, k = 0, t = 0;
	scanf("%d%d", &n, &k);
	HPDataType* arr = MALLOC(HPDataType, k);
	PrintTopK(arr, n, k);
	for (int i = 0; i < k; i++) {  //打印
		printf("%d ", arr[i]);
	}
	free(arr);
}

void test() {
	//初始数据
	HPDataType arr[100] = { 0 };
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	//初始化堆
	Heap* hp = init(n);
	HeapCreate(hp, arr, n);
	print(hp, HeapSize(hp));

	//删除
	HeapPop(hp);
	print(hp, HeapSize(hp));

	//插入
	HeapPush(hp, 100);
	print(hp, HeapSize(hp));

	HPDataType tmp = HeapTop(hp);
	printf("%d\n", tmp);
	HeapDestory(hp);
}
int main() {  
	//test(); //最大堆
	TestTopk();//最大的前k个
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

////������������С��������(��ά����С��,��Ϊ�Ӵ�С����)
//int h[100];
//int n = 0;
//void swap(int x, int y) {
//	int t = 0;
//	t = h[x];
//	h[x] = h[y];
//	h[y] = t;
//}
//void siftdown(int i,int n) {   //ά������
//    int flag = 0;
//	int parent = i, child = parent * 2 + 1;
//	while (child < n && flag == 0) {   //���ý���ж���
//		int t = parent;
//		if (h[parent] < h[child]) {
//			t = child;   //��¼�������
//		}
//		if (child + 1 < n) {   //�����Ҷ���
//			if (h[t] < h[child + 1]) {
//				t = child + 1;
//			}
//		}
//		if (t != parent) {
//			swap(t, parent);
//			parent = t;
//			child = parent * 2 + 1;
//		}
//		else {
//			flag = 1;
//		}
//	}
//}
//void siftup(int i) {
//	int child = i, parent = (child - 1) / 2;
//	while (child < n) {
//		if (h[parent] < h[child]) {
//			swap(parent, child);
//			child = parent;
//			parent = (child - 1) / 2;
//		}
//		else {
//			break;
//		}
//	}
//}
//void create() {
//	for (int i = 0; i < n; i++) {
//		scanf("%d", &h[i]);
//	}
//	for (int i = (n - 1 - 1) / 2; i >= 0; i--) {  //���½���  ʱ�临�Ӷ�:n
//		siftdown(i, n);  //�����һ�����ĸ��ڵ㿪ʼ���µ��� 2^(h-2)*1+2^(h-3)*2...+2^1*(h-2)+2^0*(h-1) 
//						 //����2^(h-2)Ϊ�����ڶ���Ľ�����,1Ϊ�����Ҫ�����Ĵ���(�����ڶ�������ֻ��һ��,���ֻ��1��)
//	}
//	//for (int i = 0; i < n; i++) {
//	//	scanf("%d", &h[i]);
//	//}
//	//for (int i = 1; i < n; i++) {  	//���Ͻ���  ʱ�临�Ӷ� : nlogn
//	//	siftup(i, n);  ////�ӵڶ����һ����㿪ʼ���ϵ��� 2^1*1+2^2*2...+2^(h-1)*(h-1)
//	//				   //����2^1Ϊ�ڶ���Ľ�����,1Ϊ�����Ҫ�����Ĵ���(�ڶ�������ֻ��һ��,���ֻ��1��)
//	//}
//}
//void heapsort() {
//	int num = n;
//	for(int i = 0;i < n;i++) {  //ʱ�临�Ӷ�:nlogn
//		swap(0, num - 1);  //����ͷβ��ֵ(�Ѿ��Ƕ�,ֱ�ӳ�)
//		num--;
//		siftdown(0,num);  //����ά��
//	}
//}
//int main() {
//	scanf("%d", &n);
//	create();
//	heapsort();
//	for (int i = 0; i < n; i++) {
//		printf("%d ", h[i]);
//	}
//	return 0;
//}

////���kС����
//typedef long long ll;
//#define max 5000000
//ll arr[max];
//int n = 0, m = 0;
//void swap(ll x, ll y) {
//	ll t = 0;
//	t = arr[x];
//	arr[x] = arr[y];
//	arr[y] = t;
//}
//void siftdown(int i) {
//	int t = 0, flag = 0;
//	while (i * 2 <= n && flag == 0) {
//		if (arr[i] < arr[i * 2]) {
//			t = i * 2;
//		}
//		else {
//			t = i;
//		}
//		if (arr[t] < arr[i * 2 + 1]) {
//			t = i * 2 + 1;
//		}
//		if (i != t) {
//			swap(i, t);
//			i = t;
//		}
//		else {
//			flag = 1;
//		}
//	}
//}
//int main() {
//	scanf("%d%d", &n, &m);
//	m++;
//	int i = 0;
//	ll t = 0, tmp = 0;
//	for (i = 1; i <= n; i++) {
//		scanf("%lld", &t);
//		if (i <= m) {
//			arr[i] = t;
//		}
//		else if (i == m) {
//			siftdown(1);   	//����һ��m��С�Ķ�
//		}
//		else {
//			if (t < arr[1]) {
//				tmp = t;
//				t = arr[1];
//				arr[1] = tmp;
//				siftdown(1);
//			}
//		}
//	}
//	printf("%lld", arr[1]);
//	return 0;
//}
////���k�����
//typedef long long ll;
//#define max 5000000
//ll arr[max];
//int n = 0, m = 0;
//void swap(ll x, ll y) {
//	ll t = 0;
//	t = arr[x];
//	arr[x] = arr[y];
//	arr[y] = t;
//}
//void siftdown(int i) {
//	int t = 0, flag = 0;
//	while (i * 2 <= n && flag == 0) {
//		if (arr[i] > arr[i * 2]) {
//			t = i * 2;
//		}
//		else {
//			t = i;
//		}
//		if (arr[t] > arr[i * 2 + 1]) {
//			t = i * 2 + 1;
//		}
//		if (i != t) {
//			swap(i, t);
//			i = t;
//		}
//		else {
//			flag = 1;
//		}
//	}
//}
//int main() {
//	scanf("%d%d", &n, &m);
//	m++;
//	int i = 0;
//	ll t = 0, tmp = 0;
//	for (i = 1; i <= n; i++) {
//		scanf("%lld", &t);
//		if (i <= m) {
//			arr[i] = t;
//		}
//		else if (i == m) {
//			siftdown(1);   	//����һ��m��С�Ķ�
//		}
//		else {
//			if (t > arr[1]) {
//				tmp = t;
//				t = arr[1];
//				arr[1] = tmp;
//				siftdown(1);
//			}
//		}
//	}
//	printf("%lld", arr[1]);
//	return 0;
//}
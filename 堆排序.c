#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

////建立最大堆来从小到大排序(若维护最小堆,则为从大到小排序)
//int h[100];
//int n = 0;
//void swap(int x, int y) {
//	int t = 0;
//	t = h[x];
//	h[x] = h[y];
//	h[y] = t;
//}
//void siftdown(int i,int n) {   //维护最大堆
//    int flag = 0;
//	int parent = i, child = parent * 2 + 1;
//	while (child < n && flag == 0) {   //若该结点有儿子
//		int t = parent;
//		if (h[parent] < h[child]) {
//			t = child;   //记录最大结点编号
//		}
//		if (child + 1 < n) {   //若有右儿子
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
//	for (int i = (n - 1 - 1) / 2; i >= 0; i--) {  //向下建堆  时间复杂度:n
//		siftdown(i, n);  //从最后一个结点的父节点开始向下调整 2^(h-2)*1+2^(h-3)*2...+2^1*(h-2)+2^0*(h-1) 
//						 //其中2^(h-2)为倒数第二层的结点个数,1为最差需要调整的次数(倒数第二层下面只有一层,因此只需1次)
//	}
//	//for (int i = 0; i < n; i++) {
//	//	scanf("%d", &h[i]);
//	//}
//	//for (int i = 1; i < n; i++) {  	//向上建堆  时间复杂度 : nlogn
//	//	siftup(i, n);  ////从第二层第一个结点开始向上调整 2^1*1+2^2*2...+2^(h-1)*(h-1)
//	//				   //其中2^1为第二层的结点个数,1为最差需要调整的次数(第二层上面只有一层,因此只需1次)
//	//}
//}
//void heapsort() {
//	int num = n;
//	for(int i = 0;i < n;i++) {  //时间复杂度:nlogn
//		swap(0, num - 1);  //交换头尾数值(已经是堆,直接出)
//		num--;
//		siftdown(0,num);  //进行维护
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

////求第k小的数
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
//			siftdown(1);   	//创建一个m大小的堆
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
////求第k大的数
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
//			siftdown(1);   	//创建一个m大小的堆
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
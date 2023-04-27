#define _CRT_SECURE_NO_WARNINGS

//二维数组保存顶点到顶点的连接关系

#include"vertextable.h"

void creategraph_matrix() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = maxsize;  
		}
	}
	int a, b, c;
	//for (int i = 0; i < m; i++) {  //有向图
	//	scanf("%d%d%d", &a, &b, &c);
	//	if (c < arr[a][b]) {
	//		arr[a][b] = c;
	//	}
	//}
	for (int i = 0; i < m; i++) {  //无向图
		scanf("%d%d%d", &a, &b, &c);
		if (a != b) {   //处理一下数值,oj题中数据可能会给 自己到自己 或 给重复路径
			//if (c < arr[a][b] || c < arr[b][a]) {  //找重复路径中最小值
			//	arr[a][b] = c;
			//	arr[b][a] = c;
			//}
			if (c > arr[a][b] || c > arr[b][a]) {  //找重复路径中最大值
				arr[a][b] = c;
				arr[b][a] = c;
			}
		}
	}
}

////图的广搜
//struct que {
//	int x;  //顶点
//	int s;   //步数(计算 从给定起点到终点 的最小步数)
//}q[51];
//int main() {
//	int map[51][51] = { 0 }, book[51] = { 0 };
//	int n = 0, m = 0, start = 0, end = 0, cur = 0;
//	int head = 1, tail = 1;
//	int a = 0, b = 0;
//	int flag = 0;
//	scanf("%d%d%d%d", &n, &m,&start,&end);
//	int i = 0, j = 0;
//	for (i = 1; i <= n; i++) {
//		for (j = 1; j <= n; j++) {
//			if (i != j) {
//				map[i][j] = 99999999;
//			}
//		}
//	}
//	for (i = 1; i <= m; i++) {
//		scanf("%d%d", &a, &b);
//		map[a][b] = 1;
//		map[b][a] = 1;
//	}
//	book[start] = 1;
//	q[tail].x = start;
//	q[tail].s = 0;
//	tail++;
//	while (head < tail) {
//		cur = q[head].x;
//		for (j = 1; j <= n; j++) {
//			if (map[cur][j] == 1 && book[j] == 0) {
//				q[tail].x = j;
//				q[tail].s = q[head].s + 1;
//				tail++;
//				book[j] = 1;
//			}
//			if (q[tail-1].x == end) {
//				flag = 1;
//				break;
//			}
//		}
//		if (flag == 1) {
//			break;
//		}
//		head++;
//	}
//	printf("%d", q[tail-1].s);
//	return 0;
//}




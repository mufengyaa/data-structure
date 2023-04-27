#define _CRT_SECURE_NO_WARNINGS

#include"vertextable.h"

//dijkstra
//基于已经求得的最短路径,求源点到更远的顶点的最短路径(和prim思路类似)
//6
//8
//1 5 30
//1 6 100
//4 6 10
//5 4 20
//2 3 5
//3 4 50
//1 3 10
//5 6 60
void dijkstra() {
	int map[51][51] = { 0 }, book[51] = { 0 };
	int dfs[51] = { 0 };
	int n = 0, m = 0;
	scanf("%d%d", &n, &m);
	int i = 0, j = 0, k = 0;
	int a = 0, b = 0, c = 0, t = 0;
	int min = 0;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i != j) {
				map[i][j] = maxsize;
			}
		}
	}
	for(i = 0;i < m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		map[a][b] = c;  //有向图
	}
	for (i = 1; i <= n; i++) {
		dfs[i] = map[1][i];  //将1号顶点作为源点
	}
	book[1] = 1;
	for (i = 1; i <= n; i++) {
		min = maxsize;
		for (j = 1; j <= n; j++) {   //找出离源点最近的顶点
			if (dfs[j] < min && book[j] == 0) {  //并且未加入最短路径的构成里
				min = dfs[j];
				t = j;  //记录下标
			}
		}
		book[t] = 1;
		for (j = 1; j <= n; j++) {   //更新dfs最短路径数组
			if (map[t][j] < maxsize) {
				if (dfs[j] > dfs[t] + map[t][j]) {  //如果原先记录的最短路径 大于 通过t中转得到的路径,就更新
					dfs[j] = dfs[t] + map[t][j];
				}
			}
		}
	}
	for (i = 1; i <= n; i++) {
		printf("%d ", dfs[i]);
	}
}
//floyd
int distance[51][51] = { 0 }, path[51][51] = { 0 };
void floyd() {
	int n = 0, m = 0;
	scanf("%d%d", &n, &m);
	int i = 0, j = 0, k = 0;
	int a = 0, b = 0, c = 0;
	int start = 0, end = 0;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i != j) {
				distance[i][j] = maxsize;
			}
		}
	}
	while (m--) {
		scanf("%d%d%d", &a, &b, &c);
		distance[a][b] = c;
	}
	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (distance[i][j] > distance[i][k] + distance[k][j]) {
					distance[i][j] = distance[i][k] + distance[k][j];
					path[i][j] = k;  //指i到j的道路通过k中转
				}
			}
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", distance[i][j]);
		}
		printf("\n");
	}
}
int main() {
	dijkstra();
	floyd();
	return 0;
}
 



////bellman-ford  对边没有要求，可以处理负权边与负权回路。缺点是时间复杂度过高，高达O(VE), V为顶点数，E为边数
//int main() {
//	int n = 0, m = 0;
//	scanf("%d%d", &n, &m);
//	int u[51] = { 0 }, v[51] = { 0 }, w[51] = { 0 }, dfs[51] = { 0 }, check[51] = { 0 };
//	int i = 0, j = 0, flag = 0;
//	for (i = 1; i <= m; i++) {
//		scanf("%d%d%d", &u[i], &v[i], &w[i]);
//	}
//	for (i = 2; i <= n; i++) {
//		dfs[i] = 99999999;
//	}
//	for (i = 1; i <= n - 1; i++) {
//		for (j = 1; j <= n; j++) {
//			check[j] = dfs[j];
//		}
//		for (j = 1; j <= m; j++) {
//			if (dfs[v[j]] > dfs[u[j]] + w[j]) {
//				dfs[v[j]] = dfs[u[j]] + w[j];
//			}
//		}
//		flag = 0;
//		for (j = 1; j <= n; j++) {
//			if (check[j] != dfs[j]) {   //检查是否更新
//				flag = 1;
//				break;
//			}
//		}
//		if (flag == 0) {
//			break;   //一轮后若未改变则已经是最短
//		}
//	}
//	//判断是否有负权回路
//	flag = 0;
//	for (j = 1; j <= m; j++) {
//		if (dfs[v[j]] > dfs[u[j]] + w[j]) {
//			flag = 1;
//			break;
//		}
//	}
//	if (flag == 1) {
//		printf("存在负权回路\n");
//	}
//	else {
//		for (i = 1; i <= n; i++) {
//			printf("%d ", dfs[i]);
//		}
//	}
//	return 0;
//}

////bellman-ford的队列优化
//int main() {
//	int first[51] = { 0 }, next[51] = { 0 },u[51] = { 0 }, v[51] = { 0 }, w[51] = { 0 }, dfs[51] = { 0 };
//	int i = 0, j = 0, flag = 0, k = 0;
//	int q[51] = { 0 }, book[51] = { 0 };
//	int n = 0, m = 0;
//	int head = 1, tail = 1;
//	scanf("%d%d", &n, &m);
//	for (i = 1; i <= n; i++) {
//		dfs[i] = 99999999;
//		first[i] = -1;
//	}
//	dfs[1] = 0;
//	for (i = 1; i <= m; i++) {
//		scanf("%d%d%d", &u[i], &v[i], &w[i]);
//		next[i] = first[u[i]];
//		first[u[i]] = i;
//	}
//	q[tail] = 1;   //q储存顶点
//	tail++;
//	while (head < tail) {
//		k = first[q[head]];
//		while (k != -1) {
//			if (dfs[v[k]] > dfs[u[k]] + w[k]) {
//				dfs[v[k]] = dfs[u[k]] + w[k];
//				if (book[v[k]] == 0) {
//					book[v[k]] = 1;
//					q[tail] = v[k];
//					tail++;
//				}
//			}
//			k = next[k];
//		}
//		book[q[head]] = 0;
//		head++;
//	}
//	for (i = 1; i <= n; i++) {
//		printf("%d ", dfs[i]);
//	}
//	return 0;
//}
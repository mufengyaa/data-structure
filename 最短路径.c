#define _CRT_SECURE_NO_WARNINGS

#include"vertextable.h"

//dijkstra
//�����Ѿ���õ����·��,��Դ�㵽��Զ�Ķ�������·��(��prim˼·����)
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
		map[a][b] = c;  //����ͼ
	}
	for (i = 1; i <= n; i++) {
		dfs[i] = map[1][i];  //��1�Ŷ�����ΪԴ��
	}
	book[1] = 1;
	for (i = 1; i <= n; i++) {
		min = maxsize;
		for (j = 1; j <= n; j++) {   //�ҳ���Դ������Ķ���
			if (dfs[j] < min && book[j] == 0) {  //����δ�������·���Ĺ�����
				min = dfs[j];
				t = j;  //��¼�±�
			}
		}
		book[t] = 1;
		for (j = 1; j <= n; j++) {   //����dfs���·������
			if (map[t][j] < maxsize) {
				if (dfs[j] > dfs[t] + map[t][j]) {  //���ԭ�ȼ�¼�����·�� ���� ͨ��t��ת�õ���·��,�͸���
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
					path[i][j] = k;  //ָi��j�ĵ�·ͨ��k��ת
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
 



////bellman-ford  �Ա�û��Ҫ�󣬿��Դ���Ȩ���븺Ȩ��·��ȱ����ʱ�临�Ӷȹ��ߣ��ߴ�O(VE), VΪ��������EΪ����
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
//			if (check[j] != dfs[j]) {   //����Ƿ����
//				flag = 1;
//				break;
//			}
//		}
//		if (flag == 0) {
//			break;   //һ�ֺ���δ�ı����Ѿ������
//		}
//	}
//	//�ж��Ƿ��и�Ȩ��·
//	flag = 0;
//	for (j = 1; j <= m; j++) {
//		if (dfs[v[j]] > dfs[u[j]] + w[j]) {
//			flag = 1;
//			break;
//		}
//	}
//	if (flag == 1) {
//		printf("���ڸ�Ȩ��·\n");
//	}
//	else {
//		for (i = 1; i <= n; i++) {
//			printf("%d ", dfs[i]);
//		}
//	}
//	return 0;
//}

////bellman-ford�Ķ����Ż�
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
//	q[tail] = 1;   //q���涥��
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
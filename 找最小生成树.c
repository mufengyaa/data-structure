#define _CRT_SECURE_NO_WARNINGS

#include"vertextable.h"

//prim算法
//先将第一个顶点纳入生成树,之后找与它相连的顶点中的最短路径,并且每纳入一个新顶点,都要将它更新生成树数组
int findmin(int x, int y) {
	return x < y ? x : y;
}
int minispantree_prim() {
	int lowcost[100] = { 0 }, book[100] = { 0 };  //lowcost记录 当前顶点 到 前一个顶点 的距离
	int ans = 0;
	for (int i = 1; i <= n; i++) {  //初始化
		lowcost[i] = maxsize;
	}
	for (int i = 1; i <= n; i++) {
		lowcost[i] = arr[1][i];  //将1作为前一个结点
	}
	book[1] = 1; 
	for (int i = 2; i <= n; i++) {
		int j = 2, t = -1;
		int min = maxsize;
		while (j <= n) {
			if (lowcost[j] < min && book[j] == 0) {  //找 与它相连的顶点 中有 最短路径的,且 未加入生成树 的顶点
				min = lowcost[j];
				t = j;
			}
			j++;
		}
		if (t == -1) {  //如果t==-1,说明该生成树无法连通
			return -1;
		}
		book[t] = 1; ans += lowcost[t];
		j = 2;
		while (j <= n) {  //用找到的顶点更新lowcost(为后续找点搭桥)
			lowcost[j] = findmin(lowcost[j], arr[t][j]);  //当前顶点为t,计算 其他顶点 到 t 的距离最小值  更新完之后将t顶点视作前一个顶点
			j++;
		}
	}
	return ans;
}

////kruskal算法
////先从最小权值入手(因此需要将权值排序),但需要判断纳入该顶点是否会成环(并查集判断)
//typedef struct node {
//	int begin;
//	int end;
//	int data;
//}node;
//int f[200], count;
//int book[200] = { 0 };
//node v[5000] = { 0 };
//int judge(int x) {
//	while (f[x] != x) {
//		x = f[x];
//	}
//	return x;
//}
//int cmp(const void* x, const void* y) {
//	return ((node*)x)->data - ((node*)y)->data;
//}
//int minispantree_kruskal() {
//	for (int i = 1; i <= m; i++) {
//		int a, b, c;
//		scanf("%d%d%d", &a, &b, &c);
//		v[i].begin = a;
//		v[i].end = b;
//		v[i].data = c;
//	}
//	for (int i = 1; i <= n; i++) {
//		f[i] = i;
//	}
//	int ans = 0;
//	qsort(v+1, m, sizeof(v[0]), cmp);
//	for (int i = 1; i <= m; i++) {
//		int p = judge(v[i].begin);
//		int q = judge(v[i].end);
//		if (p != q) {
//			f[q] = p;
//			ans += v[i].data;
//			count++;
//		}
//		if (count == n - 1) {
//			return ans;
//		}
//	}
//	return -1;  //没有被连通,连通的顶点数(除第一个加入的顶点)不够n-1
//}
//int main() {
//	scanf("%d%d", &n, &m);  //顶点个数,边数
//	creategraph_matrix();
//	int ans = minispantree_prim();
//
//	int ans = minispantree_kruskal();
//	printf("%d", ans);
//	return 0;
//}

////题目描述:
////国防部计划用无线网络连接若干个边防哨所。2 种不同的通讯技术用来搭建无线网络；
////每个边防哨所都要配备无线电收发器；有一些哨所还可以增配卫星电话。
////任意两个配备了一条卫星电话线路的哨所（两边都ᤕ有卫星电话）均可以通话，无论他们相距多远。而只通过无线电收发器通话的哨所之间的距离不能超过D，这是受收发器的功率限制。
////收发器的功率越高，通话距离 D 会更远，但同时价格也会更贵。
////收发器需要统一购买和安装，所以全部哨所只能选择安装一种型号的收发器。换句话说，每一对哨所之间的通话距离都是同一个D。你的任务是确定收发器必须的最小通话距离
////D，使得每一对哨所之间至少有一条通话路径（直接的或者间接的）。
////输入格式:
////从 wireless.in 中输入数据第 1 行，2 个整数S 和P，S 表示可安装的卫星电话的哨所数，P 表示边防哨所的数量。
////接下里P 行，每行两个整数,x，y 描述一个哨所的平面坐标(x, y)，以 km 为单位。
////输出格式:
////第 1 行，1 个实数D，表示无线电收发器的最小传输距离，精确到小数点后两位
//
////就是要保证每个站点可以连通(其中有s个站点可以不用考虑),且要找到 建立连通的 每个站点之间距离的最大值(保证在最小通话距离的情况下可以连通)
//#include<math.h>
//typedef struct node {
//	int begin;
//	int end;
//	double data;
//}node;
//int f[200], count;
//int arr[100][2];
//node v[5000] = { 0 };  //注意这里一定要开很大,这里存储边,而该图为完全图
//int judge(int x) {
//	while (f[x] != x) {
//		x = f[x];
//	}
//	return x;
//}
//int cmp(const void* x, const void* y) {
//	return (((node*)x)->data - ((node*)y)->data)>0;
//}
//int main() {
//	int n, m;
//	scanf("%d%d", &m, &n);
//	//卡住我的就是存图该怎么存,要么先存坐标再算距离,要么一边存一边算
//	//先存(就面临如何遍历的问题,就得存个三维数组
//	//一边存一边算呢?
//	int k = 1;
//	for (int i = 1; i <= n; i++) {
//		scanf("%d%d", &arr[i][0], &arr[i][1]);
//		for (int j = 1; j <= i && i != j; j++) {
//			v[k].begin = i;
//			v[k].end = j;
//			v[k++].data = sqrt(pow(abs(arr[i][0] - arr[j][0]), 2) + pow(abs(arr[i][1] - arr[j][1]), 2));	
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		f[i] = i;
//	}
//	int ans = 0; double max = 0.0;
//	qsort(v + 1, k - 1, sizeof(v[0]), cmp);
//	for (int i = 1; i <= k - 1; i++) {
//		int a = judge(v[i].begin);
//		int b = judge(v[i].end);
//		if (a != b) {
//			f[b] = a;
//			count++;
//			if (v[i].data > max) {
//				max = v[i].data;
//			}
//			if (count == n - m) { //这里不能是n-m-1,假设n=4,m=2,只能保证其中两个可以任意距离通话,也可以保证普通的两个可以通话,但普通和高级的没有连接
//				printf("%.2lf", max);
//			}
//		}
//	}
//	return 0;
//}

////题目描述:
////A 国有n 座城市，编号从1 到n，城市之间有m 条双向道路。每一条道路对车辆都有重量限制，简称限重。
////现在有q 辆货车在运输货物， 司机们想知道每辆车在不超过车辆限重的情况下，最多能运多重的货物。
////输入格式:
////第一行有两个用一个空格隔开的整数n, m，表示 A 国有n 座城市和m 条道路。
////接下来m 行每行三个整数x, y, z，每两个整数之间用一个空格隔开，表示从x 号城市到y 号城市有一条限重为z 的道路。
////注意：x ≠ y，两座城市之间可能有多条道路。
////接下来一行有一个整数q，表示有q 辆货车需要运货。
////接下来q 行，每行两个整数,x, y，之间用一个空格隔开，表示一辆货车需要从x 城市运输货物到y 城市，保证x≠y
////输出格式:
////共有q 行，每行一个整数，表示对于每一辆货车，它的最大载重是多少。如果货车不能到达目的地，输出−1。
//
////因为有多组输入,所以需要在输入的时候存储最大值(找最大载重->最大限重)
////深搜//好难
//int n, m;
//int arr[100][100], book[100];
//int maxcost[100];
//int begin, end, max;
//void dfs(int i, int ans) {
//	if (i == end) {
//		if (ans > max) {
//			max = ans;
//		}
//	}
//}
//int main() {
//	scanf("%d%d", &n, &m);
//	creategraph_matrix();
//	int q;
//	scanf("%d", &q);
//	int ans = 0;
//	for (int i = 0; i < q; i++) {
//		scanf("%d%d", &begin, &end);
//		for (int j = 1; j <= n; j++) {
//			maxcost[j] = arr[begin][j];
//		}
//		book[begin] = 1;
//		dfs(begin, ans);
//	}
//}
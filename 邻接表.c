#define _CRT_SECURE_NO_WARNINGS

//顶点表+边表
//每个顶点后相连一条边表链
//在边表中头插与 该顶点 相连的顶点

#include"vertextable.h"

void creategraph_table(vertex* vertex_table) {
	for (int i = 1; i <= n; i++) {  //初始化
		vertex_table[i].data = i;
		vertex_table[i].nextnode = NULL;
	}
	for (int k = 0; k < m; k++) {
		int i = 0, j = 0;
		scanf("%d%d", &i, &j);

		edgenode* edge_table = MALLOC(edgenode, 1);
		edge_table->vertexi = j; //终点,起点已经由顶点表保存
		edge_table->next = NULL;
		//头插
		edge_table->next = vertex_table[i].nextnode;
		vertex_table[i].nextnode = edge_table;

		////若为无向表
		//edgenode* edge_table = MALLOC(edgenode, 1);
		//edge_table->vertexi = i; //终点,起点已经由顶点表保存
		////头插
		//edge_table->next = vertex_table[j].nextnode;
		//vertex_table[j].nextnode = edge_table;
	}
}

void printgraph(vertex* vertex_table) {
	for (int i = 0; i < n; i++) {
		printf("%d->", vertex_table[i].data);
		edgenode* tmp = vertex_table[i].nextnode;
		while (tmp != NULL) {
			printf("%d->", tmp->vertexi);
			tmp = tmp->next;  //别忘了往后轮
		}
		printf("NULL\n");
	}
}

//int main() {
//	scanf("%d%d", &n, &m);  //顶点个数,边数
//	vertex* vertex_table = MALLOC(vertex, n);  //为顶点表创建空间,用i来表示顶点编号
//	creategraph_table(vertex_table);
//	printgraph(vertex_table);
//	return 0;
//}

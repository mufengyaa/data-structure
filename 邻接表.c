#define _CRT_SECURE_NO_WARNINGS

//�����+�߱�
//ÿ�����������һ���߱���
//�ڱ߱���ͷ���� �ö��� �����Ķ���

#include"vertextable.h"

void creategraph_table(vertex* vertex_table) {
	for (int i = 1; i <= n; i++) {  //��ʼ��
		vertex_table[i].data = i;
		vertex_table[i].nextnode = NULL;
	}
	for (int k = 0; k < m; k++) {
		int i = 0, j = 0;
		scanf("%d%d", &i, &j);

		edgenode* edge_table = MALLOC(edgenode, 1);
		edge_table->vertexi = j; //�յ�,����Ѿ��ɶ������
		edge_table->next = NULL;
		//ͷ��
		edge_table->next = vertex_table[i].nextnode;
		vertex_table[i].nextnode = edge_table;

		////��Ϊ�����
		//edgenode* edge_table = MALLOC(edgenode, 1);
		//edge_table->vertexi = i; //�յ�,����Ѿ��ɶ������
		////ͷ��
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
			tmp = tmp->next;  //������������
		}
		printf("NULL\n");
	}
}

//int main() {
//	scanf("%d%d", &n, &m);  //�������,����
//	vertex* vertex_table = MALLOC(vertex, n);  //Ϊ��������ռ�,��i����ʾ������
//	creategraph_table(vertex_table);
//	printgraph(vertex_table);
//	return 0;
//}

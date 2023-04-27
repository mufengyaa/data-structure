#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define MALLOC(type,num) (type*)malloc(sizeof(type)*num)

#ifndef maxsize
#define maxsize 9999999
#endif

typedef int datatype;
typedef int edgetype;

typedef struct edgenode {
	int vertexi;
	struct edgenode* next;
	//edgetype data; //´øÈ¨Öµ
}edgenode;
typedef struct vertex {
	datatype data;
	edgenode* nextnode;
}vertex;

int m, n;
int arr[100][100];

int findmin(int x, int y);
void printgraph(vertex* vertex_table);

void creategraph_table(vertex* vertex_table);
void creategraph_matrix();

int minispantree_prim();
int minispantree_kruskal();

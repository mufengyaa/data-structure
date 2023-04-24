#pragma once

#define n 20
#include<time.h>
#include<string.h>

// ��������
void InsertSort(int* arr,int size);

// ϣ������
void ShellSort(int* arr);

// ѡ������
void SelectSort(int* arr);

// ������
void AdjustDwon(int* arr,int size, int root);
void HeapSort(int* arr);

// ð������
void BubbleSort(int* arr);

// ��������ݹ�ʵ��
int getmidi(int* arr, int left, int right);
int PartSort1(int* arr, int left, int right);// ��������hoare�汾
int PartSort2(int* arr, int left, int right);// ���������ڿӷ�
int PartSort3(int* arr, int left, int right);// ��������ǰ��ָ�뷨
void QuickSort(int* arr, int left, int right);

// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* arr, int left, int right);

//�鲢����
void _MergeSort(int* arr, int* tmp, int left, int right);

// �鲢����ǵݹ�ʵ��
void MergeSort(int* arr, int left, int right);

// ��������
void CountSort(int* arr);
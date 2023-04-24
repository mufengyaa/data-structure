#pragma once

#define n 20
#include<time.h>
#include<string.h>

// 插入排序
void InsertSort(int* arr,int size);

// 希尔排序
void ShellSort(int* arr);

// 选择排序
void SelectSort(int* arr);

// 堆排序
void AdjustDwon(int* arr,int size, int root);
void HeapSort(int* arr);

// 冒泡排序
void BubbleSort(int* arr);

// 快速排序递归实现
int getmidi(int* arr, int left, int right);
int PartSort1(int* arr, int left, int right);// 快速排序hoare版本
int PartSort2(int* arr, int left, int right);// 快速排序挖坑法
int PartSort3(int* arr, int left, int right);// 快速排序前后指针法
void QuickSort(int* arr, int left, int right);

// 快速排序 非递归实现
void QuickSortNonR(int* arr, int left, int right);

//归并排序
void _MergeSort(int* arr, int* tmp, int left, int right);

// 归并排序非递归实现
void MergeSort(int* arr, int left, int right);

// 计数排序
void CountSort(int* arr);
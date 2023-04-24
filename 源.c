#define _CRT_SECURE_NO_WARNINGS

#include"test.h"
#include"stack.h"

void swap(int* x, int* y) {
	int t;
	t = *x;
	*x = *y;
	*y = t;
}
void printarr(int* arr) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void ShellSort(int* arr) {  //ʹ����һ��һ����������,�����һ�εĲ��������дﵽ����������  O(nlogn)
	int gap = n;
	while (gap > 1) {
		gap /= 2;
		for (int i = gap; i < n; i++) {
			int end = i - gap, tmp = arr[i];
			while (end >= 0) {
				if (tmp < arr[end]) {
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else {
					break;
				}
			}
			arr[end + gap] = tmp;
		}
	}
	printarr(arr);
}
void InsertSort(int* arr,int size) {  //O(n^2)
	int end, tmp;
	for (int i = 1; i < size; i++) {
		end = i - 1, tmp = arr[i];
		while (end >= 0) {
			if (tmp < arr[end]) {
				arr[end + 1] = arr[end];
				end--;
			}
			else {
				break;
			}
		}
		arr[end + 1] = tmp;
	}
}

int getmidi(int* arr, int left, int right) {  //��ֹ��һ������̫С,ʹ���鲻�ܶ�����
	int mid = (left + right) / 2;
	if (arr[left] < arr[mid]) {  //mid > left
		if (arr[mid] < arr[right]) {  //right���
			return mid;
		}
		else if (arr[left] > arr[right]) {  //mid���
			return left;
		}
		else {
			return right;
		}
	}
	else {  //mid < left
		if (arr[left] < arr[right]) {  //right��С
			return left;
		}
		else if (arr[mid] > arr[right]) {  //left���
			return mid;
		}
		else {
			return right;
		}
	}
}
int PartSort1(int* arr, int left, int right) {  
	int begin = left, end = right;
	int keyi = left;
	int midi = getmidi(arr, left, right);
	if (midi != keyi) {
		swap(&arr[midi], &arr[keyi]);
	}
	while (begin < end) {
		while (begin < end && arr[end] >= arr[keyi]) {
			end--;
		}
		while (begin < end && arr[begin] <= arr[keyi]) {
			begin++;
		}
		swap(&arr[begin], &arr[end]);
	}
	swap(&arr[keyi], &arr[begin]);
	return begin;
}
int PartSort2(int* arr, int left, int right) {  
	int begin = left, end = right;
	int mid = getmidi(arr, left, right);
	if (mid != left) {
		swap(&arr[mid], &arr[left]);
	}
	int key = arr[left];
	int tmp = left;  //��λλ��
	while (begin < end) {
		while (begin < end && arr[end] >= key) {
			end--;
		}  //������endλ�þ�Ϊһ����
		arr[tmp] = arr[end];
		tmp = end;
		while (begin < end && arr[begin] <= key) {
			begin++;
		}
		arr[tmp] = arr[begin];
		tmp = begin;
	}
	arr[tmp] = key;
	return tmp;
}
int PartSort3(int* arr, int left, int right) {
	int prev = left, cur = left + 1;
	int midi = getmidi(arr, left, right);
	if (midi != left) {
		swap(&arr[midi], &arr[left]);
	}
	int keyi = left;
	while (cur <= right) {   //ע������,�����ǻ�ָ������,���cur�ǲ��ܳ���ǰ�������ֵ,������n
		if (arr[cur] < arr[keyi]) {
			prev++;
			if (cur != prev) {
				swap(&arr[cur], &arr[prev]);
			}
		}
		cur++;
	}
	swap(&arr[prev], &arr[keyi]);
	return prev;
}
//���ַ�����
void PartSort_mid(int* arr,int left, int right) {
	int mid = (left + right) / 2;
	int i = left, j = right;
	int tmp = arr[mid];
	do {
		while (arr[i] < tmp) {
			i++;
		}
		while (arr[j] > tmp) {
			j--;
		}
		if (i <= j) {
			swap(&arr[i], &arr[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (left < j) {
		PartSort_mid(arr,left, j);
	}
	if (i < right) {
		PartSort_mid(arr,i, right);
	}
}
//��Ի���һ�µ����ݵĳ�ʱ,ȡ�����׼��
int PartSort_rand(int* arr, int left, int right) {
	srand((unsigned int)time(NULL));
	int begin = left, end = right;
	int keyi = left;
	int randi = left + (rand() % (right - left + 1));
	swap(&arr[left], &arr[randi]);
	while (begin < end) {
		while (begin < end && arr[end] >= arr[keyi]) {
			end--;
		}
		while (begin < end && arr[begin] <= arr[keyi]) {
			begin++;
		}
		swap(&arr[begin], &arr[end]);
	}
	swap(&arr[keyi], &arr[begin]);
	return begin;
}
void QuickSort(int* arr, int left, int right) {  //�����Խ���С�����Ż�(����󼸲�ĵݹ��ɲ�������,���ٵݹ����+����Ч��,С����ʹ�ÿ���Ч�ʲ���)
	if (left >= right) {
		return;
	}
	if (right - left > 20) {
		//int keyi = PartSort1(arr, left, right);//hoare�汾
        //int keyi = PartSort2(arr, left, right);//�ڿӷ�
		int keyi = PartSort3(arr, left, right);//ǰ��ָ�뷨
		QuickSort(arr, left, keyi - 1);
		QuickSort(arr, keyi + 1, right);
	}
	else {
		InsertSort(arr+left, right - left + 1);
	}
}
void QuickSortNonR(int* arr, int left, int right) {//��ջ�������,�ȴ��������,�ٴ��������,����ֵ,����ֵ,����ȡ�����ľ�����ȷ��˳��
	stacknode a;
	init(&a);
	push(&a, right);
	push(&a, left);
	while (!judgeempty(&a)) {
		int begin = printtop(&a);
		pop(&a);
		int end = printtop(&a);
		pop(&a);
		int keyi = PartSort3(arr, begin, end);
		if (end - (keyi + 1) > 0) {  //ע��:����ֵ���Ϊ1ʱ,������������Ԫ�ص�!
			push(&a, end);
			push(&a, keyi + 1);
		}
		if ((keyi - 1) - begin > 0) {
			push(&a, keyi - 1);
			push(&a, begin);
		}
	}
	printarr(arr);
	destroy(&a);
}

void AdjustDwon(int* arr,int size, int root) {  //ά�����->��С��������
	int parent = root, child = parent * 2 + 1;
	while (child < size) {
		int tmp = parent;
		if (arr[tmp] < arr[child]) {
			tmp = child;
		}
		if (child + 1 < size && arr[tmp] < arr[child + 1]) {
			tmp = child + 1;
		}
		if (tmp == parent) {
			break;
		}
		else {
			swap(&arr[tmp], &arr[parent]);
			parent = tmp;
			child = parent * 2 + 1;
		}
	}
}
void HeapSort(int* arr) {  //O(nlogn)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--) { //����
		AdjustDwon(arr,n,i);  
	}
	int size = n;
	for (int i = 0; i < n; i++) {
		swap(&arr[0], &arr[size - 1]);
		size--;
		AdjustDwon(arr,size,0);
	}
	printarr(arr);
}

void BubbleSort(int* arr) {
	for (int j = 0; j < n; j++) {
		int flag = 0;
		for (int i = 1; i < n-j; i++) {
			if (arr[i - 1] > arr[i]) {
				swap(&arr[i - 1], &arr[i]);
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}
	}
	printarr(arr);
}

void SelectSort(int* arr) {  //O(n^2)
	int maxi, mini;
	int left = 0, right = n - 1;
	while (left < right) {
		maxi = mini = left;
		for (int i = left + 1; i <= right; i++) {
			if (arr[i] < arr[mini]) {
				mini = i;
			}
			if (arr[i] > arr[maxi]) {
				maxi = i;
			}
		}
		swap(&arr[left], &arr[mini]);
		if (left == maxi) {
			maxi = mini;
		}
		swap(&arr[right], &arr[maxi]);
		left++; right--;
	}
	printarr(arr);
}

void _MergeSort(int* arr,int* tmp, int left, int right) {
	if (left >= right) {
		return;
	}
	int mid = (left + right) / 2;
	_MergeSort(arr,tmp, left, mid);
	_MergeSort(arr,tmp, mid + 1, right);
	//�鲢
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2) {
		if (arr[begin1] < arr[begin2]) {
			tmp[i++] = arr[begin1++];
		}
		else {
			tmp[i++] = arr[begin2++];
		}
	}
	while (begin1 <= end1) {
		tmp[i++] = arr[begin1++];
	}
	while (begin2 <= end2) {
		tmp[i++] = arr[begin2++];
	}
	memcpy(arr + left, tmp + left, (right - left + 1) * sizeof(int));
}
void MergeSort(int* arr,int left,int right) {
	int* tmp = MALLOC(int, n);
	_MergeSort(arr, tmp, left, right);
	free(tmp);
	printarr(arr); 
}
void MergeSortnonr(int* arr, int left, int right) {
	int* tmp = MALLOC(int, n);
	int gap = 1, j = 0;
	while (gap < n) {
		j = 0;
		for (int i = 0; i < n; i += gap * 2) {
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + gap * 2 - 1;
			if (end1 >= n || begin2 >= n) {
				break;
			}
			else if (end2 >= n) {
				end2 = n - 1;
			}
			while (begin1 <= end1 && begin2 <= end2) {
				if (arr[begin1] < arr[begin2]) {
					tmp[j++] = arr[begin1++];
				}
				else {
					tmp[j++] = arr[begin2++];
				}
			}
			while (begin1 <= end1) {
				tmp[j++] = arr[begin1++];
			}
			while (begin2 <= end2) {
				tmp[j++] = arr[begin2++];
			}
			memcpy(arr + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}
		gap *= 2;
	}
	free(tmp);
	printarr(arr);
}
void CountSort(int* arr) {
	int max, min;
	max = min = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	int range = max - min + 1;
	int* tmp = MALLOC(int, range);
	memset(tmp, 0, sizeof(int) * range);
	for (int i = 0; i < n; i++) {
		tmp[(arr[i] - min)]++;
	}
	int j = 0;
	for (int i = 0; i < range; i++) {
		while (tmp[i]--) {
			arr[j++] = i + min;
		}
	}
	printarr(arr);
}

void test() {
	int* arr = MALLOC(int, n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	srand((unsigned int)time(NULL));
	//InsertSort(arr);
	//printarr(arr);
	//ShellSort(arr);
	//SelectSort(arr);
	//HeapSort(arr);
	//BubbleSort(arr);
	//QuickSort(arr, 0, n - 1);
	PartSort_mid(arr, 0, n - 1);
	printarr(arr);
	//QuickSortNonR(arr, 0, n - 1);
	//MergeSort(arr, 0, n - 1);
	//MergeSortnonr(arr, 0, n - 1);
	/*CountSort(arr);*/
}
int main() {
	test();
	return 0;
}
/*
���������㷨��
(0)��������
(1)�۰��������
(2)ϣ������
(3)ð������
(4)��������
*/

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;



/*ֱ�Ӳ���������������ʱ�临�Ӷ�O(n) ƽ��ʱ�临�Ӷ�O(n^2)
  �ȶ�����  ������˳��������  �������λ��ʱ��ǰ����Ѱ��
*/
template<typename T>
void InsertSort(vector<T> &array)
{
	if (array.size() == 0)
		return;
	//�ڱ� ����Ĵ洢�ռ�O(1)
	T temp;
	int i, j;
	for (i = 1; i < array.size(); i++)
	{
		temp = array[i];
		for (j = i-1; j >=0&&array[j]>temp; j--)//�ȶ�
		{
			array[j + 1] = array[j];//����
		}
		array[j + 1] = temp;
	}
}


/*�۰��������  ƽ��ʱ�临�Ӷ�O(n^2)
ֻ���Ż��˲��Ҳ���λ��  �ȶ�
*/
template<typename T>
void Partition_InsertSort(vector<T> &array)
{
	if (array.size() == 0)
		return;
	//�ڱ�
	T temp;
	int i;
	for (i = 1; i < array.size(); i++)
	{
		temp = array[i];
		int start = 0;
		int end = i - 1;
		int mid;
		while (start <= end) {
			mid = (start + end) / 2;
			if (array[mid]>temp)
				end = mid - 1;
			else 
				start = mid + 1;
		}
		for (int a =i-1; a > end; a--)
			array[a + 1] = array[a];//����
		array[end+1] = temp;
	}
}

//����
template<typename T>
void swap(T* a, T*b) {
	T temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


/*ϣ������(����swap)  ƽ��ʱ�临�Ӷ�O(n^1.3) �O(n^2) 
���ȶ�
*/
template<typename T>
void ShellSort(vector<T>& array) {
	if (array.size() == 1)
		return;
	int increment = array.size() / 2;
	int i;
	for (increment; increment >= 1; increment /= 2) {
		cout << "increment:" << increment<<endl;
		for (int i = increment; i < array.size(); i++)
		{
			int j = i;
			while (j - increment >= 0 && array[j] < array[j - increment]) {
				swap(array[j], array[j - increment]);
				j -= increment;
			}
		}
	}
}


/*ð������ O(n^2)
�ȶ�  ÿһ�����򶼻���һ��Ԫ��������λ����
*/
template<typename T>
void BubbleSort(vector<T>& array)
{
	if (array.size() < 2)
		return;
	bool flag = false;//����Ƿ�������
	for (int i = 0; i < array.size() - 1; i++) {
		flag = false;
		for (int j = 0; j < array.size() - i - 1; j++)
		{
			if (array[j] > array[j + 1]) {
				swap(array[j], array[j + 1]);
				flag = true;
			}
		}
		if (flag == false)
			return;
	}
}


/*���� ��ε����
�ռ临�Ӷ�: �O(n) ƽ��:O(logn)
ʱ�临�Ӷ�: �O(n^2) ƽ��O(nlogn)
���ȶ�
*/
template<typename T>
void QuickSort(vector<T>& array, int low, int high)
{
	if (low < high) {
		int pivot = Partition2(array, low, high);
		QuickSort(array, low, pivot - 1);
		QuickSort(array, pivot + 1, high);
	}
}

template<typename T>
int Partition(vector<T>& array,int low,int high){
	int pivot = array[low];
	while (low < high) {
		while (low < high&&array[high] >= pivot)
			high--;
		//swap(array[low], array[high]);
		array[low] = array[high];
		while (low < high&&array[low] <= pivot)
			low++;
		//swap(array[low], array[high]);
		array[high] = array[low];
	}
	array[low] = pivot;
	return low;
}

/*���ѡȡpivot*/
template<typename T>
int Partition2(vector<T>& array, int low, int high) {
	int pivot_number = low + rand() % (high - low + 1);
	T pivot = array[pivot_number];
	swap(array[high], array[pivot_number]);
	int small =low-1;
	for (int i = low; i <= high; i++)
	{
		if (array[i] < pivot)
		{
			small++;
			swap(array[small], array[i]);
		}
	}
	small++;
	swap(array[small], array[high]);
	return small;//����ȷ������Ŧֵ
}

/*ѡ������ ÿ��ѡ����С��
ʱ�临�Ӷ�O(n^2)
���ȶ�
*/
template<typename T>
void SelectSort(vector<T>& array) {
	if (array.size() == 0)
		return;
	for (int i = 0; i < array.size() - 1; i++)
	{
		int minindex = i;
		for (int j = i + 1; j < array.size(); j++)
		{
			if (array[j] < array[minindex])
				minindex = j;
		}
		if (minindex != i)
			swap(array[minindex], array[i]);
	}
}
int main()
{
	vector<int> v{6,5,4,3,2,1,2324,2,543,53,5,1,1,23,13,14,235,345,4};
	//ShellSort(v);
	//BubbleSort(v);
	//QuickSort(v, 0,v.size()-1);
	SelectSort(v);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
    return 0;
}


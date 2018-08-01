/*
各种排序算法：
(0)插入排序
(1)折半插入排序
(2)希尔排序
(3)冒泡排序
(4)快速排序
*/

#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;



/*直接插入排序最好情况下时间复杂度O(n) 平均时间复杂度O(n^2)
  稳定排序  适用于顺序表或链表  链表查找位置时从前往后寻找
*/
template<typename T>
void InsertSort(vector<T> &array)
{
	if (array.size() == 0)
		return;
	//哨兵 额外的存储空间O(1)
	T temp;
	int i, j;
	for (i = 1; i < array.size(); i++)
	{
		temp = array[i];
		for (j = i-1; j >=0&&array[j]>temp; j--)//稳定
		{
			array[j + 1] = array[j];//后移
		}
		array[j + 1] = temp;
	}
}


/*折半插入排序  平均时间复杂度O(n^2)
只是优化了查找插入位置  稳定
*/
template<typename T>
void Partition_InsertSort(vector<T> &array)
{
	if (array.size() == 0)
		return;
	//哨兵
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
			array[a + 1] = array[a];//后移
		array[end+1] = temp;
	}
}

//交换
template<typename T>
void swap(T* a, T*b) {
	T temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


/*希尔排序(基于swap)  平均时间复杂度O(n^1.3) 最坏O(n^2) 
不稳定
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


/*冒泡排序 O(n^2)
稳定  每一趟排序都会有一个元素在最终位置上
*/
template<typename T>
void BubbleSort(vector<T>& array)
{
	if (array.size() < 2)
		return;
	bool flag = false;//标记是否发生交换
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


/*快排 严蔚敏版
空间复杂度: 最坏O(n) 平均:O(logn)
时间复杂度: 最坏O(n^2) 平均O(nlogn)
不稳定
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

/*随机选取pivot*/
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
	return small;//返回确定的枢纽值
}

/*选择排序 每趟选择最小的
时间复杂度O(n^2)
不稳定
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


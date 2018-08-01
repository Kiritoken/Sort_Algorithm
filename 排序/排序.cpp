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

int main()
{
	vector<double> v{6,5,4,3,2,1,3,32,32,3,4,52,432,12,313,5,1,4,12};
	//ShellSort(v);
	BubbleSort(v);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
    return 0;
}


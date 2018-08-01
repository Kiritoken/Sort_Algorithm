/*
各种排序算法：
（1）插入排序

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


/*折半插入排序*/
template<typename T>
void Partition_InsertSort(vector<T> &array)
{

}

int main()
{
	vector<double> v{ 6};
	InsertSort(v);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
    return 0;
}


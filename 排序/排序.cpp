/*
���������㷨��
��1����������

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


/*�۰��������*/
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


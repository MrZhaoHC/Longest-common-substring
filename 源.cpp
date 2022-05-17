#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define MAXSIZE 100

void opeart(char* a1, char* a2, int n1, int n2)
{
	int** a = (int**)malloc((n1 + 1) * sizeof(int*)); //建立二维数组，1字符串为行，2字符串为列
	for (int i = 0; i < n1 + 1; i++)
	{
		a[i] = (int*)malloc((n2 + 1) * sizeof(int));
	}
	for (int i = 0; i < n1 + 1; i++)//初始化二维数组，第0行，第0列为0
	{
		a[i][0] = 0;
	}
	for (int i = 0; i < n2 + 1; i++)
	{
		a[0][i] = 0;
	}
	for (int i = 1; i <= n1; i++)//填表格
	{
		for (int j = 1; j <= n2; j++)
		{
			if (a1[i] == a2[j])//如果字符相等
			{
				a[i][j] = a[i - 1][j - 1]+1;//找i-1，j-1位置的数值再加1
			}
			else//不相等
			{
				a[i][j] = a[i][j - 1] >= a[i - 1][j] ? a[i][j - 1] : a[i - 1][j];//找i-1位置和j-1位置，哪个大，吧哪个填入
			}
		}
	}
	//for (int i = 0; i <= n1; i++)    输出填好的表格
	//{
	//	for (int j = 0; j <= n2; j++)       //此时a[n1][n2]位置存储的就是最长公共子序列的长度
	//	{
	//		cout << a[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//找出最大的字串
	char* b = (char*)malloc((n1 + n2) * sizeof(char));//用来存储找到的公共子序列
	int n=0;
	int i, j;
	for (i = n1,j=n2; i >= 1&&n<a[n1][n2];)//此时a[n1][n2]位置存储的就是最长公共子序列的长度
	{
		if (a1[i] == a2[j])//如果当前位置a1[i]和a2[j]字符相等则将此字符存入b，并找到i-1，j-1的位置
		{
			b[n] = a1[i];
			n++;
			i = i - 1;
			j = j - 1;
		}
		else//如果不相等，就不存入到b,并找i-1和j-1谁的值大，则找到值大的位置
		{
			if (a[i][j - 1] > a[i - 1][j])
				j--;
			else
				i--;
		}
	}
	for (int i = n - 1; i >= 0; i--)//倒序输出最长公共子串
	{
		if (i != 0)
			cout << b[i]<<",";
		else
			cout << b[i];
	}
}

int main()
{
	char* a1 = (char*)malloc(100 * sizeof(char));//存储第一个字符串
	char* a2 = (char*)malloc(100 * sizeof(char));//存储第二个字符串
	char a;
	int n1 = 1;int n2 = 1;
	cout << "请输入两个字符串，每个字符串以（;）隔开，每个字符用（,）隔开：";
	cout << "(例如A,B,C;A,C,B)" << endl;
	do
	{
		cin >> a1[n1++];				//从数组1位置元素开始存储
	} while ((a = getchar()) != ';');
	n1--;								//第一个字符串字符的个数
	do
	{
		cin >> a2[n2++];				//从数组1位置元素开始存储
	} while ((a = getchar()) != '\n');
	n2--;
	//动态规划算法求解
	opeart(a1, a2, n1, n2);
}

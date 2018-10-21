/*************************************************************************
    > File Name: sort.c
    > Author: xfzhang
    > Mail: 923036400@1qq.com 
    > Created Time: 日 10/21 16:31:30 2018
 ************************************************************************/
#include "ctype.h"
#include "stdlib.h"
#include "stdio.h"
#include "common.h"
#define LOW 1
#define HIGHT 2

int print_ai(int *piValue,int iNum)
{
	int i = 0;
	printf("aIntValue:");
	for(i= 0;i < iNum;i++)
	{
		printf("%d ",piValue[i]);
	}
	printf("\n");
	return 0;
}
/* * * * * 
 * information: insert sort low to hight
 * type :
 * * * * * */
int insert_sort(int *piValue,int iNum)
{
	printf("sort by insert sort.\n");
	int i = 0, j = 0;
	int temp = 0;
	for(i = 1 ;i < iNum ;i++)
	{
		temp = piValue[i];
		for(j = i-1; j >= 0 && temp < piValue[j];j--)
		{
			piValue[j+1] = piValue[j];
		}
		piValue[j+1] = temp; /* 使用j+1下标赋值是因为for循环结束后j-- */
	}
	return 0;
}
/* * * * * 
 * information: selete min value low to hight
 * type :
 * * * * * */
int select_min_sort(int *piValue,int iNum)
{
	printf("sort by selete_min value.\n");
	int i = 0,j = 0,min = 0,temp;
	for(i = 0;i<iNum-1;i++)
	{
		min = i;
		for(j = i+1;j<iNum;j++)
		{
			if(piValue[min] > piValue[j])
			{
				min = j;
			}
		}
		temp = piValue[min];
		piValue[min] = piValue[i];
		piValue[i] = temp;
	}
	return 0;
}

int main(){
	int aiValue[]={
		3,2,5,7,2,4,1
	};
	print_ai(aiValue,7);
	//insert_sort(aiValue,7);
	select_min_sort(aiValue,7);
	print_ai(aiValue,7);
	return 0;
}


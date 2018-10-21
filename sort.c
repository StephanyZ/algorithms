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

int merge(int *piValue,int iStartNum,int iMidNum,int iEndNum);
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

int merge(int *piValue,int iStartNum,int iMidNum,int iEndNum)
{
	if(iStartNum +1 >= iEndNum)
	{
		int temp = 0;
		if(piValue[iStartNum]<piValue[iEndNum])
			return 0;
		temp=piValue[iStartNum];
		piValue[iStartNum]=piValue[iEndNum];
		piValue[iEndNum]=temp;
		return 0;
	}
	int *iLeftValue = NULL;
	int *iRightValue = NULL;
	int i = 0,iLeftNum = 0,iRightNum = 0;
	iLeftValue = (int *)malloc(sizeof(int)*(iMidNum-iStartNum+1));
	iRightValue = (int *)malloc(sizeof(int)*(iEndNum-iMidNum));
	merge(piValue,iStartNum,iStartNum+(iMidNum-iStartNum)/2,iMidNum);
	merge(piValue,iMidNum+1,iMidNum+1+(iEndNum-iMidNum)/2,iEndNum);	
	for(i = 0;i<(iMidNum-iStartNum+1);i++)
	{	
		iLeftValue[i] = piValue[iStartNum+i];
	}
	for(i = 0; i<(iEndNum-iMidNum);i++)
	{
		iRightValue[i] = piValue[iMidNum+i+1];
	}
	for(i = iStartNum;i<iEndNum+1;i++)
	{

		if(iLeftValue != NULL && iLeftNum<(iMidNum-iStartNum)+1 && (iLeftValue[iLeftNum]<iRightValue[iRightNum] || iRightNum>=(iEndNum-iMidNum)))
		{
			piValue[i]=iLeftValue[iLeftNum];
			iLeftNum++;
		}else if(iRightValue != NULL && iRightNum < (iEndNum-iMidNum) && (iLeftValue[iLeftNum]>=iRightValue[iRightNum] || iLeftNum >=(iMidNum-iStartNum+1)))
		{
			piValue[i]=iRightValue[iRightNum];
			iRightNum++;
		}
	}
	if(iLeftValue!= NULL)
		free(iLeftValue);
	if(iRightValue!=NULL)
		free(iRightValue);
	return 0;
}
int merge_sort(int *piValue,int iNum)
{
	printf("sort by merge sort\n");
	merge(piValue,0,(iNum-1)/2,iNum-1);
	return 0;
}
int main(){
	int aiValue[]={
		3,2,5,7,2,4,1
	};
	print_ai(aiValue,7);
	//insert_sort(aiValue,7);
	//select_min_sort(aiValue,7);
	merge_sort(aiValue,7);
	print_ai(aiValue,7);
	return 0;
}

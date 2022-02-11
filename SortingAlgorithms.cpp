#include <iostream>
using namespace std;

//The Bubble sort algorithm:

void bubbleSort(int a[], int l)
{
	for (int i=1; i<l;i++)
	{
		for (int j=0;j<l-i;j++)
		{
			if (a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

main ()
{	
	int a[8]={95,8,19,25,34,39,45,4};
	bubbleSort(a,8);
	for (int i=0;i<8;i++)
		cout<<a[i]<<" ";
}

//Algorithm Mergesort sorts an array of n elements in time O(n log n).

int const size=8;

void Merge(int A[], int p, int q, int r)
{
	int B[size];
	int s=p, t=q+1, k=p;
	while(s<=q && t<=r)
	{
		if (A[s]<=A[t] ) 
		{
			B[k]=A[s];
			s=s+1;
		}
		else
		{
			B[k]=A[t];
			t=t+1;
		}
		k=k+1;
	}
	if (s==q+1)
	{
		for (;k<=r;k++)
			B[k]=A[t++]	;	
	}
	else
	{
		for (;k<=r;k++)
			B[k]=A[s++];	
	}
	for (;p<=r;p++)
	{
		A[p]=B[p];
	}
}

void MergeSort(int A[], int low, int high)
{     
	if (low<high)
	{
		int mid=(low+high)/2;
		MergeSort(A,low,mid);
		MergeSort(A,mid+1,high);
		Merge(A,low,mid, high);
	}
}           

main ()
{
	int A[]={9,5,3,0,7,1,6,8};
	for (int i=0;i<size; i++)
		cout<<" "<<A[i];
	MergeSort(A,0,size-1);
	cout<<endl;
	for (int i=0;i<size; i++)
		cout<<" "<<A[i];
}

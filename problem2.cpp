#include<stdio.h>
#include<conio.h>
#include<vector>
#include<iostream>

using namespace std;

void merge_sort(vector<unsigned long> &arr, unsigned int l, unsigned int r)
{
	unsigned int m = l + (r - l)/2, n1 = m-l+1, n2 = r-m;
	long L[n1], R[n2];
	int i=0, j=0;
	for (i =0; i< n1; i++)
	{
		L[i] = arr[l+i];
	}
	for (j =0; j< n2; j++)
	{
		R[j] = arr[m+1+j];
	}
	i = 0, j =0;
	while (i < n1 && j < n2)
	{
		if( L[i]> R[j] )
		{
			arr[l+i+j] = R[j];
			j++;
		}
		else if( R[j] >= L[i])
		{
			arr[l+i+j] = L[i];
			i++;
		}
	}
	while( i < n1)
	{
		arr[l+i+j] = L[i];
		i++;
	}
	while( j < n2 )
	{
		arr[l+i+j] = R[j];
		j++;
	}
}

void sort(vector<unsigned long> &arr, unsigned int l, unsigned int r)
{
	if(l < r)
	{
		unsigned int m = l + (r - l)/2;
		sort(arr, l, m);
		sort(arr, m+1, r);
		merge_sort(arr, l, r);
	}
}

int main()
{
	int n = 0, m = 0, i = 0;
	unsigned long x=0;
	scanf("%d", &n);
	scanf("%d", &m);
	vector<unsigned long> arr;
	scanf("%ldu", &x);
	arr.push_back(x);
	i++;
	while(i<m)
	{
		scanf("%ld", &x);
		arr.push_back(x);
		i++; 
	}
	sort(arr, 0 , arr.size()-1);
	while(arr.size()>n)
	{
		arr[1]+=arr[0];
		arr.erase(arr.begin(), arr.begin()+1);
		if(arr[1]<arr[0])
		{
			x = arr[1];
			arr[1] = arr[0];
			arr[0] = x;
		}
	}
	printf("\n%ld", arr[0]);
	return 0;
	
}

#include<conio.h>
/*
	my hypothesis/ claim: number of distinct color = number of prime numbers less than or equal to that number
	Since, every other number can be expressed as a factor of these numbers, so the factors of numbers can't form coprime numbers among them .
*/


#include<stdio.h>
#include<vector>
#include<iostream>

using namespace std;


int main()
{
	int n;
	scanf("%d", &n);
	vector<int> prime_collection;
	vector<int>::iterator itr;
	prime_collection.push_back(2);
	for(int i=3; i<=n; i++)
	{
		for(itr = prime_collection.begin(); itr!= prime_collection.end(); ++itr)
		{
			if(i % *itr == 0)
			{
				break;
			}
			
		}
		if(itr == prime_collection.end())
			{
				prime_collection.push_back(i);
			}
	}
	n = prime_collection.size();
	long sum = (n * (n+1) )/2;
	printf("%ld\n", sum);
}

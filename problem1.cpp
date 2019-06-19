#include<conio.h>
#include<stdio.h>
#include<vector>
#include<math.h>

using namespace std;

int digit_sum(vector<char> ch)
{
	char str[13];
	long sum=0, n;
	int count = 1, i=0;
	while(1)
	{
		for(i=0; i< ch.size()-1; i++)
		{
			sum += int(ch[i]) - int('9') + 9;
		}
		if(sum < 10)break;
		ch.clear();
		count++;
		i =0;
		while(sum)
		{
			ch.push_back(sum%10 + '0');
			sum /= 10;	
		}
		ch.push_back('\n');
		sum =0;
	}
	return count;
	
}

int main()
{
	vector<char> ch;
	char x;
	int sum=0, count =0;
	long i= 0;
	scanf("%c", &x);
	ch.push_back(x);
	while(ch[i] != '\n')
	{
		x = getchar();
		ch.push_back(x);
		i++;
	}
	count = digit_sum(ch);
	printf("%d", count);
	return 0;
}

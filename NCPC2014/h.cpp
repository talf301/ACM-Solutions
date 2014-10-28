#include <iostream>
#include <algorithm>
using namespace std;
int v[4000000];

void table(int p[], int len)
{
	v[0] = -1;
	
	int cur = 0;
	for(int j = 1; j < len; j++)
	{
		cur = v[j-1];
		while(cur >= 0 && p[cur]!=p[j-1])
			cur = v[cur];
		v[j]=cur+1;
	}	
}

bool kmp(int p[], int text[], int n)
{
	table(text, n);
	int i = 0;
	int k = 0;
	while(i < 2*n)
	{
		if(k == -1)
		{
			i++;
			k = 0;
		}
		else if(p[i] == text[k])
		{
			i++;
			k++;
			if(k == n)
				return true;
		}
		else
			k = v[k];
	}
	return false;
}

int main()
{
	int n;
	cin >> n;
	int first[n];
	int second[n];
	for(int i = 0; i < n; i++)
		cin >> first[i];
	for(int i = 0; i < n; i++)
		cin >> second[i];
	sort(first, first+n);
	sort(second, second+n);
	int diff1[n];
	int diff2[2*n];
	
	for(int i = 0; i < n-1; i++)
		diff1[i] = first[i+1] - first[i];

	diff1[n-1] = first[0] - first[n-1] + 360000;

	for(int i = 0; i < n-1; i++)
		diff2[i] = second[i+1] - second[i];
	
	diff2[n-1] = second[0] - second[n-1] + 360000;
	
	for(int i = 0; i < n; i++)
		diff2[i+n] = diff2[i];
	
	if(kmp(diff2, diff1, n))
		cout << "possible" << endl;
	else
		cout << "impossible" << endl;
	return 0;
}

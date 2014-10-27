#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int hs[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &hs[i]);
	
	sort(hs, hs + n);
	int floor = 0;
	int back = n-1;
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		if(hs[i] == floor)
			continue;
		if(back < i)
			break;
		if(hs[back] - floor > back-i+1)
		{
			back -= 1;
			count += 1;
			i -= 1;
		}
		else
			floor = hs[i];
	}
	printf("%d\n", floor + count);	
	return 0;
}

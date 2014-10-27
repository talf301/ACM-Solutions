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
	int count = 0;
	if(n < hs[0])
		count = n;
	else
	for(int i = 0; i < n; i++)
	{
		if(i + 1 < n && hs[i] == hs[i+1])
			continue;
		floor = hs[i];
		if(n-i-1 < hs[i+1] - floor)
		{
			count = n-i-1;
			break;
		}
	}
	printf("%d\n", floor + count);	
	return 0;
}

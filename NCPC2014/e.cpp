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
	int ans = n; 
	for(int i = 0; i < n; i++)
	{
		ans = min(ans, hs[n-i-1] + i);	
	}
	printf("%d\n", ans);	
	return 0;
}

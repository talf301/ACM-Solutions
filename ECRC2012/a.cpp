#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int t = 0;
	while(true)
	{
		int n;
		cin >> n;
		if(n == 0)
			break;
		t++;
		int x[n], y[n], z[n];
		for(int i = 0; i < n; i++)
		{
			int ins[3];
			cin >> ins[0] >> ins[1] >> ins[2];
			sort(ins, ins+3);
			x[i] = ins[0];
			y[i] = ins[1];
			z[i] = ins[2];
		}

		int perms[n];
		for(int i = 0; i < n; i++)
			perms[i] = i;
		int maxn = 0;
		do
		{
			int d1 = z[perms[0]];
			int d2 = y[perms[0]];	
			int count = 1;
			for(int i = 1; i < n; i++)
			{
				if(z[perms[i]] <= d1 && y[perms[i]] <= d2)
				{
					d1 = z[perms[i]];
					d2 = y[perms[i]];
					count++;
				}
				else if(y[perms[i]] <= d1 && x[perms[i]] <= d2)
				{
					d1 = y[perms[i]];
					d2 = x[perms[i]];
					count++;
				}
			}
			maxn = max(maxn, count);

		} while(std::next_permutation(perms, perms+n));
		cout << "Case " << t << ": " << maxn << endl;
	}
	return 0;
}

#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
vector<int> g[1001];
vector<int> rg[1001];
set<int> visited;

vector<pair<int, int> > comps;

void buildcomp(int start)
{
	set<int> nvis;
	queue<int> q;
	int cycle = 0;
	int curr = start;
	//First find length of cycle
	while(true)
	{
		cycle += 1;
		curr = g[curr][0];
		if(curr == start)
			break;
	}
	int size = 0;
	//Now find size of entire component
	q.push(start);
	while(q.size() > 0)
	{
		int look = q.front();
		q.pop();
		if(nvis.find(look) != nvis.end())
			continue;
		nvis.insert(look);
		visited.insert(look);
		size += 1;
		for(int i = 0; i < rg[look].size(); i++)
			q.push(rg[look][i]);
	}
	comps.push_back(pair<int, int>(cycle, size));
}

int main()
{
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		int to;
		cin >> to;
		g[i].push_back(to);
		rg[to].push_back(i);
	}

	for(int i = 1; i <= n; i++)
	{
		if(visited.find(i) == visited.end())
		{
			int curr = i;
			while(true)
			{
				if(visited.find(curr) != visited.end())
				{
					buildcomp(curr);			
					break;
				}
				visited.insert(curr);
				curr = g[curr][0];
			}
		}
	}
	bool dp[comps.size()][k+1];
	for(int i = 0; i < comps.size(); i++)
	{
		for(int j = 0; j < k+1; j++)
			dp[i][j] = false;
	}

	dp[0][0] = true;
	for(int i = comps[0].first; i <= comps[0].second; i++)
		if(i < k+1)
			dp[0][i] = true;
	
	for(int i = 1; i < comps.size(); i++)
	{
		for(int j = 0; j < k+1; j++)
		{
			if(dp[i-1][j])
			{
				dp[i][j] = true;
				for(int s = comps[i].first; s <= comps[i].second; s++)
					if(j+s < k+1)
					{
						dp[i][j+s] = true;
					}
			}
		}
	}

	for(int i = k; i >= 0; i--)
	{
		if(dp[comps.size() -1][i])
		{
			cout << i << endl;
			break;
		}
	}
	return 0;
}

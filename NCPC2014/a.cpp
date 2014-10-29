#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
vector<pair<int, int> > g[2000001];
vector<vector<int> > comps;
vector<bool> determined;
int settings[200001];
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		g[a].push_back(pair<int,int>(b,c));
		g[b].push_back(pair<int,int>(a,c));
	}
	for(int i = 0; i < n+1; i++)
		settings[i] = -1;
	set<int> visited;
	//Find connected components
	for(int i = 1; i < n+1; i++)
	{
		if(visited.find(i) != visited.end())
			continue;
		queue<int> q;
		q.push(i);
		bool det = false;
		vector<int> currcomp;
		while(q.size() > 0)
		{
			int curr = q.front();
			q.pop();
			if(visited.find(curr) != visited.end())
				continue;
			visited.insert(curr);
			currcomp.push_back(curr);
			for(int j = 0; j < g[curr].size(); j++)
			{
				q.push(g[curr][j].first);
				if(g[curr][j].second != 1)
					det = true;
			}
		}
		determined.push_back(det);
		comps.push_back(currcomp);
	}
	int total = 0;
	bool possible = true;
	//Now solve each component
	for(int i = 0; i < comps.size(); i++)
	{
		if(determined[i])
		{
			while(true)
			{
				int changed = 0;
				for(int j = 0; j < comps[i].size(); j++)
				{
					int node = comps[i][j];
					for(int k = 0; k < g[node].size(); k++)
					{
						int neigh = g[node][k].first;
						int val = g[node][k].second;
						if(val == 2)
						{
							if(settings[node] == 0 || settings[neigh] == 0)
							{
								possible = false;
								break;
							}
							else
							{
								if(settings[node] != 1 || settings[neigh] != 1)
									changed++;
								settings[node] = 1;
								settings[neigh] = 1;
							}
						}
						else if(val == 1)
						{
							if(settings[node] != -1)
							{
								if(settings[node] == settings[neigh] && settings[node] != -1)
								{
									possible = false;
									break;
								}
								else
								{
									if(settings[neigh] != (settings[node] +1)%2)
										changed++;
									settings[neigh] = (settings[node] + 1)%2;
								}
							}
						}
						else
						{
							if(settings[node] == 1 || settings[neigh] == 1)
							{
								possible = false;
								break;
							}
							else
							{
								if(settings[node] != 0 || settings[neigh] != 0)
									changed++;
								settings[node] = 0;
								settings[neigh] = 0;
							}
						}
					}
					if(!possible)
						break;
				}
				if(!possible)
					break;
				if(changed == 0)
					break;

			}
			for(int j = 0; j < comps[i].size(); j++)
			{
				total += settings[comps[i][j]];
			}
		}
		//Here can assume all edge values are 1
		else
		{
			queue<int> q;
			set<int> vis;
			q.push(comps[i][0]);
			settings[comps[i][0]] = 1;
			while(q.size() > 0)
			{
				if(!possible)
					break;
				int curr = q.front();
				q.pop();
				if(vis.find(curr) != vis.end())
					continue;
				vis.insert(curr);
				for(int j = 0; j < g[curr].size(); j++)
				{
					int next = g[curr][j].first;
					if(settings[curr] == settings[next])
					{
						possible = false;
						break;
					}
					else
					{
						settings[next] = (settings[curr] + 1)%2;
						q.push(next);
					}
				}
			}

			int zerocount = 0;
			int onecount = 0;
			for(int j = 0; j < comps[i].size(); j++)
			{
				if(settings[comps[i][j]] == 1)
					onecount++;
				else
					zerocount++;
			}
			total += min(zerocount, onecount);
		}
		if(!possible)
			break;
	}
	if(!possible)
		cout << "impossible" << endl;
	else
		cout << total << endl;

	return 0;
}

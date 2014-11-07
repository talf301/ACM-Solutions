#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	int m;
	string s;
	getline(cin, s);
	istringstream buffer(s);
	buffer >> m;
	for(int t = 1; t <= m; t++)
	{
		string in;
		getline(cin, in);
	}
	return 0;
}

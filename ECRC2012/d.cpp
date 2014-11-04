#include <iostream>

using namespace std;

int main()
{
	int t = 0;
	while(true)
	{
		char in;
		cin >> in;
		if(in == 'e')
			break;
		t++;
		if(in == 'm')
		{
			int conf[6];
			for(int i = 0; i < 6; i++)
				cin >> conf[5-i];
			int counter = 0;
			int curr[6];
			for(int i = 1; i < 6; i++)
				curr[i] = 0;
			curr[0] = 15;
			while(curr[5] <= 15)
			{
				if(curr[0] == conf[0] && curr[1] == conf[1] && curr[2] == conf[2] && curr[3] == conf[3] && curr[4] == conf[4] && curr[5] == conf[5])
					break;
				counter++;
				if(curr[0] > 0)
				{
					curr[0]--;
					curr[1]++;
				}
				else
				{
					if(curr[1] > 0)
					{
						curr[0] = curr[1] - 1;
						curr[2]++;
						curr[1] = 0;
					}
					else
					{
						if(curr[2] > 0)
						{
							curr[0] = curr[2] - 1;
							curr[3]++;
							curr[2] = 0;
						}
						else
						{
							if(curr[3] > 0)
							{
								curr[0] = curr[3] - 1;
								curr[4]++;
								curr[3] = 0;
							}
							else
							{
								if(curr[4] > 0)
								{
									curr[0] = curr[4] - 1;
									curr[5]++;
									curr[4] = 0;
								}
							}
						}
					}
				}
			}
			cout << "Case " << t << ": " << counter << endl;
		}
		else if(in == 'u')
		{
			int req;
			cin >> req;
			int counter = 0;
			int curr[6];
			for(int i = 1; i < 6; i++)
				curr[i] = 0;
			curr[0] = 15;
			while(curr[5] <= 15)
			{
				if(counter == req)
					break;
				counter++;
				if(curr[0] > 0)
				{
					curr[0]--;
					curr[1]++;
				}
				else
				{
					if(curr[1] > 0)
					{
						curr[0] = curr[1] - 1;
						curr[2]++;
						curr[1] = 0;
					}
					else
					{
						if(curr[2] > 0)
						{
							curr[0] = curr[2] - 1;
							curr[3]++;
							curr[2] = 0;
						}
						else
						{
							if(curr[3] > 0)
							{
								curr[0] = curr[3] - 1;
								curr[4]++;
								curr[3] = 0;
							}
							else
							{
								if(curr[4] > 0)
								{
									curr[0] = curr[4] - 1;
									curr[5]++;
									curr[4] = 0;
								}
							}
						}
					}
				}
			}
			cout << "Case " << t << ": " << curr[5] << " " << curr[4] << " " << curr[3] << " " << curr[2] << " " << curr[1] << " " << curr[0] << endl;
		}
	}
	return 0;
}

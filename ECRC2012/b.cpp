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
        int mx[n];
        int my[n];
        int maxx = 0;
        int maxy = 0;
        for(int i = 0; i < n; i++)
        {
            int x,y;
            cin >> x >> y;
            mx[i] = x;
            my[i] = y;
            maxx = max(maxx, x);
            maxy = max(maxy, y);
        }

        //First for x
        int min = 100000000;
        int minloc = 0;
        for(int i = 0; i <= maxx; i++)
        {
            int dist = 0;
            for(int j = 0; j < n; j++)
                dist += abs(mx[j] - i);
            if(dist < min)
            {
                min = dist;
                minloc = i;
            }
        }
        int distx = min;
        int locx = minloc;
        //First for x
        min = 100000000;
        minloc = 0;
        for(int i = 0; i <= maxy; i++)
        {
            int dist = 0;
            for(int j = 0; j < n; j++)
                dist += abs(my[j] - i);
            if(dist < min)
            {
                min = dist;
                minloc = i;
            }
        }
        int locy = minloc;
        int disty = min;
        cout << "Case " << t << ": (" << locx << "," << locy << ") " << distx+disty << endl;
    }
    return 0;
}

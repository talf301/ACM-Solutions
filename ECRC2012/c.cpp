#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int q;
    cin >> q;
    for(int t = 1; t <= q; t++)
    {
        int sides[7][6];
        for(int i = 0 ; i < 7; i++)
        {
            for(int j = 0; j < 6; j++)
            {
                cin >> sides[i][j];
                //cerr << sides[i][j];
            }
        }
        //Center 1 at 0 index
        int ind;
        for(int i = 0; i < 6; i++)
            if(sides[0][i] == 1)
                ind = i;
        int new0[6];
        for(int i = 0; i < 6; i++)
            new0[i] = sides[0][(i+ind)%6];
        for(int i = 0; i < 6; i++)
            sides[0][i] = new0[i];

        int perms[] = {0,1,2,3,4,5,6};
        int inds[6];
        bool solved = false;
        do{
            int ind;
            for(int i = 0; i < 6; i++)
                if(sides[perms[0]][i] == 1)
                    ind = i;
            int new0[6];
            for(int i = 0; i < 6; i++)
                new0[i] = sides[perms[0]][(i+ind)%6];
            for(int i = 0; i < 6; i++)
                sides[perms[0]][i] = new0[i];

            bool correct = true;
            for(int i = 1; i <= 6; i++)
                for(int j = 0; j < 6; j++)
                    if(sides[perms[i]][j] == sides[perms[0]][i-1])
                        inds[i-1] = j;
            for(int i = 1; i <= 6; i++)
            {
                int adj;
                if(i == 6)
                    adj = perms[1];
                else
                    adj = perms[i+1];
                if(sides[perms[i]][(inds[i-1]-1+6)%6] != sides[adj][(inds[i%6]+1)%6])
                        correct = false;
            }
			//cerr << inds[0] << inds[1] << inds[2] << inds[3] << inds[4] << inds[5] << endl;
            if(correct)
            {
                solved = true;
                break;
            }
        } while (next_permutation(perms, perms+7));
		//cerr << sides[0][0] << " " << sides[0][1] << sides[0][2] << sides[0][3] << sides[0][4] << sides[0][5] << endl;
        if(solved)
            cout << "Case " << t << ": " << perms[0] << " " << perms[1] << " " << perms[2] << " " << perms[3] << " " << perms[4] << " " << perms[5] << " " << perms[6] << endl;
        else
            cout << "Case " << t << ": No solution" << endl;
    }
    return 0;
}

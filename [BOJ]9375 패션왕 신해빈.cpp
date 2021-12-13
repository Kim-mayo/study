#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        map<string, int> mp;
        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            string a, b;
            cin >> a >> b;
            if (mp.find(b) == mp.end())
            {
                mp.insert(make_pair(b, 2));
            }
            else
            {
                mp[b]++;
            }
        }
        int mul = 1;
        map<string, int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++)
        {
            mul *= (it->second);
        }
        mul -= 1;
        cout << mul << "\n";
    }

    return 0;
}
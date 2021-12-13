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

    int n, m;
    map<string, string> mp;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        mp.insert(make_pair(a, b));
    }
    for (int i = 0; i < m; i++)
    {
        string a;
        cin >> a;
        cout << mp.find(a)->second << "\n";
    }

    return 0;
}
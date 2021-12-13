#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    set<string> st;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        st.insert(a);
    }
    vector<string> ans;
    for (int i = 0; i < m; i++)
    {
        string b;
        cin >> b;
        if (st.find(b) != st.end())
        {
            ans.push_back(b);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}
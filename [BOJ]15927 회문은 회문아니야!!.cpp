#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    int cnt = 0;
    for (int i = 1; i < str.length(); i++)
    {
        if (str[0] == str[i])
            cnt++;
    }
    if (cnt == str.length() - 1)
    {
        cout << -1;
        return 0;
    }

    int flag = 0;
    string revstr = str.substr(flag, str.length());
    reverse(revstr.begin(), revstr.end());
    //cout << str << " " << revstr << "\n";
    bool same = true;
    if (str == revstr)
        cout << str.length() - 1;
    else
    {
        cout << str.length();
    }

    return 0;
}
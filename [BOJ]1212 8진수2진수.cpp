#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string eight;
    cin >> eight;
    string ans;
    for (int i = 0; i < eight.length(); i++)
    {
        int num = eight[i] - '0';
        string two;
        for (int j = 0; j < 3; j++)
        {
            two += (num % 2) + '0';
            num /= 2;
        }
        reverse(two.begin(), two.end());
        ans += two;
    }
    //cout << ans << "\n";
    bool check = false;
    for (int i = 0; i < ans.length(); i++)
    {
        if (ans[i] == '0' && !check)
            continue;
        else
            check = true;
        cout << ans[i];
    }
    if (check == false)
        cout << 0;

    return 0;
}
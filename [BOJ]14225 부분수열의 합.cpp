#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
int n;
bool number[2000001];
void sub(int idx, int sum)
{

    if (idx == n)
    {
        number[sum] = true;
        return;
    }

    sub(idx + 1, sum + arr[idx]);
    sub(idx + 1, sum);

    return;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    sub(0, 0);
    for (int i = 1; i < 2000001; i++)
    {
        if (!number[i])
        {
            cout << i;
            break;
        }
    }

    return 0;
}
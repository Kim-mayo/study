#include <iostream>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    if (n % 4 == 0 && (n % 100 != 0 || n % 400 == 0))
        cout << 1;
    else
        cout << 0;
}
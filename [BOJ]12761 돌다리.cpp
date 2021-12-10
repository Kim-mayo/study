#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
using namespace std;

int A, B, N, M;
bool visited[100001];
int solve()
{
    int ans = 0;
    queue<int> q;
    q.push(N);
    while (!q.empty())
    {
        int k = q.size();

        while (k--)
        {
            int curr = q.front();
            //cout << curr << "\n";
            if (curr == M)
                return ans;
            q.pop();
            if (curr < 0 || curr > 100000)
                continue;
            if (visited[curr])
                continue;
            visited[curr] = true;

            q.push(curr + 1);
            q.push(curr - 1);
            q.push(curr + A);
            q.push(curr - A);
            q.push(curr + B);
            q.push(curr - B);
            q.push(curr * A);
            q.push(curr * B);
        }
        ans++;
    }
    return visited[M];
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> A >> B >> N >> M;
    cout << solve();

    return 0;
}
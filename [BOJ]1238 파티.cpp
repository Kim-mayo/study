#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <unordered_set>
using namespace std;

int N, M, X;
vector<vector<pair<int, int> > > arr;

int Go(int start)
{
    vector<int> dist(N + 1, 1e9);
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));
    while (!pq.empty())
    {
        int curr = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if (dist[curr] != 1e9)
            continue;
        dist[curr] = -cost;
        if (curr == X)
            break;
        for (int i = 0; i < arr[curr].size(); i++)
        {
            int next = arr[curr][i].second;
            int ncost = arr[curr][i].first;
            if (dist[next] != 1e9)
                continue;
            pq.push(make_pair(-ncost + cost, next));
        }
    }
    return dist[X];
}
vector<int> Back()
{

    vector<int> dist(N + 1, 1e9);
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, X));
    while (!pq.empty())
    {
        int curr = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if (dist[curr] != 1e9)
            continue;
        dist[curr] = -cost;
        for (int i = 0; i < arr[curr].size(); i++)
        {
            int next = arr[curr][i].second;
            int ncost = arr[curr][i].first;
            if (dist[next] != 1e9)
                continue;
            pq.push(make_pair(-ncost + cost, next));
        }
    }
    return dist;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> X;
    arr.resize(N + 1);
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a].push_back(make_pair(c, b));
    }
    vector<int> back = Back();
    int ans = -1;
    for (int i = 1; i <= N; i++)
    {
        ans = max(ans, Go(i) + back[i]);
        cout << Go(i) << " " << back[i] << "\n";
    }
    cout << ans;
    return 0;
}
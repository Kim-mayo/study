#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <unordered_set>
using namespace std;

#define ll long long
#define INF 9223372036854775800
int N, M, K;
vector<vector<pair<ll, int> > > arr;
vector<vector<ll> > dist;
ll dijkstra()
{
    priority_queue<pair<ll, pair<int, int> > > pq;

    pq.push(make_pair(0, make_pair(1, 0)));
    dist[1][0] = 0;
    while (!pq.empty())
    {

        int curr = pq.top().second.first;
        ll cost = -pq.top().first;
        int pave = pq.top().second.second;
        pq.pop();
        if (dist[curr][pave] < cost)
            continue;
        for (int i = 0; i < arr[curr].size(); i++)
        {
            int next = arr[curr][i].second;
            ll ncost = arr[curr][i].first + cost;
            //포장X
            if (dist[next][pave] > ncost)
            {
                pq.push(make_pair(-ncost, make_pair(next, pave)));
                dist[next][pave] = ncost;
            }
            //포장O
            if (dist[next][pave + 1] > cost && pave + 1 <= K)
            {
                pq.push(make_pair(-cost, make_pair(next, pave + 1)));
                dist[next][pave + 1] = cost;
            }
        }
    }

    ll res = INF;
    for (int i = 0; i <= K; i++)
    {
        res = min(res, dist[N][i]);
    }
    return res;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    arr.resize(N + 1);
    dist.resize(N + 1, vector<ll>(K + 1, INF));
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        arr[a].push_back(make_pair(c, b));
        arr[b].push_back(make_pair(c, a));
    }
    cout << dijkstra();
    return 0;
}
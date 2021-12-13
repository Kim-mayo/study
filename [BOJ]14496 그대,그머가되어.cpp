#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <unordered_set>
using namespace std;

#define INF 1e9
int a, b, N, M;
vector<vector<int> > letter;
vector<int> dist;
int daijkstra()
{

    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, a));

    while (!pq.empty())
    {

        int curr = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (dist[curr] != INF)
            continue;
        dist[curr] = cost;
        for (int i = 0; i < letter[curr].size(); i++)
        {
            int next = letter[curr][i];
            pq.push(make_pair(-cost - 1, next));
        }
    }

    return dist[b] != INF ? dist[b] : -1;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> N >> M;
    letter.resize(N + 1);
    dist.resize(N + 1, INF);
    for (int i = 0; i < M; i++)
    {
        int x, y, z;
        cin >> x >> y;
        letter[x].push_back(y);
        letter[y].push_back(x);
    }
    cout << daijkstra();
    return 0;
}
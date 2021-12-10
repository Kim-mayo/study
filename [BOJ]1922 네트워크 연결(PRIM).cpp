#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<pair<int, int> > > line;
vector<int> dist;
void Prim()
{
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, 1));

    while (!pq.empty())
    {
        int curr = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        if (dist[curr] != 1e9)
            continue;
        dist[curr] = -cost;

        for (int i = 0; i < line[curr].size(); i++)
        {
            int next = line[curr][i].second;
            int ncost = line[curr][i].first;
            if (dist[next] != 1e9)
                continue;
            pq.push(make_pair(-ncost, next));
        }
    }
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    line.resize(N + 1);
    dist.resize(N + 1, 1e9);
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        line[a].push_back(make_pair(c, b));
        line[b].push_back(make_pair(c, a));
    }
    Prim();
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        sum += dist[i];
    }
    cout << sum;
    return 0;
}
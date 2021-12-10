#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<pair<int, pair<int, int> > > tree;
vector<int> parent;
int find(int v)
{
    if (parent[v] == v)
        return v;
    else
        return parent[v] = find(parent[v]);
}
bool merge(int a, int b)
{
    int A = find(a);
    int B = find(b);
    if (A == B)
        return true;
    parent[A] = B;
    return false;
}
int Kruskal()
{
    int res = 0;
    for (int i = 0; i < M; i++)
    {
        int cost = tree[i].first;
        int A = tree[i].second.first;
        int B = tree[i].second.second;
        if (merge(A, B))
            continue;
        res += cost;
    }
    return res;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    parent.resize(N + 1);
    for (int i = 1; i < N + 1; i++)
        parent[i] = i;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        tree.push_back(make_pair(c, make_pair(a, b)));
    }
    sort(tree.begin(), tree.end());
    cout << Kruskal();
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <unordered_set>
using namespace std;

int N;
int pos[1003][1003];
int ans = 0;
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
void draw(int a, int b, int c, int d, int idx)
{

    for (int i = a; i <= c; i++)
    {
        int curr = i;

        if (pos[curr][b] != -1)
        {
            merge(idx, pos[curr][b]);
        }
        pos[curr][b] = idx;
    }

    for (int i = b + 1; i <= d; i++)
    {
        int curr = i;

        if (pos[c][curr] != -1)
        {
            merge(idx, pos[c][curr]);
        }
        pos[c][curr] = idx;
    }

    for (int i = c - 1; i >= a; i--)
    {
        int curr = i;

        if (pos[curr][d] != -1)
        {
            merge(idx, pos[curr][d]);
        }
        pos[curr][d] = idx;
    }

    for (int i = d - 1; i > b; i--)
    {
        int curr = i;

        if (pos[a][curr] != -1)
        {
            merge(idx, pos[a][curr]);
        }
        pos[a][curr] = idx;
    }

    //cout << ans << "\n";
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    parent.resize(N + 1);
    for (int i = 0; i < N + 1; i++)
        parent[i] = i;
    memset(pos, -1, sizeof(pos));
    pos[500][500] = 0;
    for (int i = 0; i < N; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        draw(a + 500, b + 500, c + 500, d + 500, i + 1);
    }
    unordered_set<int> st;
    for (int i = 0; i < N + 1; i++)
    {
        st.insert(find(i));
    }
    cout << st.size() - 1;
    return 0;
}
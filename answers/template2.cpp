#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef pair<int,pair<int,int> > edge;
typedef long long ll;

#define INF 111111;

bool cmp(const ii& a,const ii& b)
{
    return a.first < b.first;
}

bool cmp2(const edge& a,const edge& b)
{
    return a.first < b.first;
}

class UnionFind {
public:
    vector <ll> par; // 各元の親を表す配列
    vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);  
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }

    // Member Function
    // Find
    ll root(ll x) { // 根の検索
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }

    // Union(Unite, Merge)
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool isSame(ll x, ll y) { // 連結判定
        return root(x) == root(y);
    }

    ll size(ll x) { // 素集合のサイズ
        return siz[root(x)];
    }
};


/*
Return:与えられたグラフのMSTの総コスト
*/
int kruskal(vector<int,ii>& EdgeList,int V)
{
    UnionFind uf(V);
    sort(EdgeList.begin(),EdgeList.end(),cmp2);
    int mstCost = 0;

    for(int i = 0;i<EdgeList.size();++i)
    {
        edge front = EdgeList[i];
        if(!uf.isSame(front.second.first,front.second.second))
        {
            mstCost += front.first;
            uf.merge(front.second.first,front.second.second);
        }
    }

    return mstCost;
}

/*
Initialization:AdjMat[i][j] = (i->jがあれば、その枝の重み。なければINF)
Return:AdjMat[i][j] = (i->jの最短距離)
*/
void warshallFloyd(vector<vector<int> >& AdjMat)
{
    int V = AdjMat.size();
    for(int i = 0;i < V;++i)
        for(int j = 0;j < V;++j)
            for(int k = 0;k < V;++k)
                AdjMat[i][j] = min(AdjMat[i][j],AdjMat[i][k]+AdjMat[k][j]);
                //AdjMat[i][j] |= AdjMat[i][k] && AdjMat[k][j] で、AdjMat[i][j] = 1のときiからjへのpathが存在。Initializetion:AdjMat[i][j] = (i->jがあれば、1。なければ0)
                //AdjMat[i][j] = min(AdjMat[i][j],max(AdjMat[i][k],AdjMat[k][j]))で、AdjMat[i][j]がiからjへのminmax経路の最大の重み
                //AdjMat[i][j] > 0 && AdjMat[j][i] > 0 なら、iとjは同じSCCにいる。
}

/*
Initialization:AdjMat[i][j] = (i->jがあれば、その枝の重み。なければINF),prev[i][j] = i
Return:AdjMat[i][j] = (i->jの最短距離),prev[i][j] = (i->jの最短経路におけるjに到達する直前の時に居る頂点)
Tips:(i->j)の最短経路は逆からたどるとj,prev[i][j],prev[i][prev[i][j]],prev[i][prev[i][prev[i][j]]],,,,,
*/
void warshallFloyd(vector<vector<int> >& AdjMat,vector<vector<int> >& prev)
{
    int V = AdjMat.size();
    for(int i = 0;i < V;++i)
        for(int j = 0;j < V;++j)
            for(int k = 0;k < V;++k)
            {
                if(AdjMat[i][k] + AdjMat[k][j] < AdjMat[i][j])
                {
                    AdjMat[i][j] = AdjMat[i][k]+AdjMat[k][j];
                    prev[i][j] = prev[k][j];
                }
            }
}


/*
Initialization:AdjList[i][j].first = (iを始点とする枝のもう一方の点),AdjList[i][j].second = (iを始点とし、AdjList[i][j].firstをもう一方の点とする枝の重み)
Return:dist[i] = ((s-> i)の最短距離)
*/
typedef pair<int,int> ii;
void dikstra(vector<int>& dist,vector<vector<ii> >& AdjList,int s)
{
    priority_queue<ii,vector<ii>,decltype(&cmp)> pq(cmp);
    pq.emplace(0,s);
    for(int i = 0;i < dist.size();++i)
        dist[i] = INF;
    dist[s] = 0;

    while(!pq.empty())
    {
        ii du = pq.top();pq.pop();
        if(du.first > dist[du.second]) continue;

        for(auto& vw:AdjList[du.second])
        {
            if(dist[du.second] + vw.second >= dist[vw.first]) continue;

            dist[vw.first] = dist[du.second] + vw.second;
            pq.emplace(dist[vw.first],vw.first);
        }
    }
}

/*
Initialization:AdjList[i][j].first = (iを始点とする枝のもう一方の点),AdjList[i][j].second = (iを始点とし、AdjList[i][j].firstをもう一方の点とする枝の重み)
Return:dist[i] = ((s-> i)の最短距離),parent[i] = ((s->i)までの最短経路において、iに到達する直前にいる頂点)
Tips:(i->j)の最短経路は逆からたどるとj,parent[j],parent[parent[j]],parent[parent[parent[j]]],,,,,,,
*/
typedef pair<int,int> ii;
void dikstra(vector<int>& dist,vector<vector<ii> >& AdjList,vector<int>& parent,int s)
{
    priority_queue<ii,vector<ii>,decltype(&cmp)> pq(cmp);
    pq.emplace(0,s);
    for(int i = 0;i < dist.size();++i)
        dist[i] = INF;
    dist[s] = 0;

    while(!pq.empty())
    {
        ii du = pq.top();pq.pop();
        if(du.first > dist[du.second]) continue;

        for(auto& vw:AdjList[du.second])
        {
            if(dist[du.second] + vw.second >= dist[vw.first]) continue;

            dist[vw.first] = dist[du.second] + vw.second;
            parent[vw.first] = du.second;
            pq.emplace(dist[vw.first],vw.first);
        }
    }
}


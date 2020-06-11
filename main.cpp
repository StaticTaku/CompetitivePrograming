#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
#define INF 111111;
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

bool cmp(const ii& a,const ii& b)
{
    return a.first < b.first;
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
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 7;

struct edge{
    int node1,node2,weight;
    edge(int x,int y, int z){
        node1=x;node2=y;weight=z;
    }
};

int n,m;
int s,t;
vector<edge> edgeLis[MAX];
void input(){
    cin>>n>>m;
    for(int i =0; i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        edgeLis[x].push_back(edge(x,y,z));
    }
    cin>>s>>t;
}

vector<int> iDist(MAX, INT_MAX);
void Dijkstra(int s,int t){
    iDist[s]=0;
    priority_queue<pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>> PQ;
    PQ.push(make_pair(iDist[s],s));
    while(!PQ.empty()){
        int u = PQ.top().second;
        PQ.pop();
        for(auto v:edgeLis[u]){
            int y = v.node2;
            int z= v. weight;
            if(z+iDist[u]<iDist[y]){
                iDist[y]= z+iDist[u];
                PQ.push(make_pair(iDist[y],y));
            }

        }
    }
    cout<<iDist[t];
}

int main(){
    input();
    Dijkstra(s,t);
}
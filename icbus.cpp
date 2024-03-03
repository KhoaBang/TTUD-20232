//c-bus or bus-intercity

//	y tuong:
//	dung BFS de tim duoc duong di ngan nhat tu 1 thanh pho toi cac tp con lai
//	ham calculate_dist() dung BFS tinh khoang cach ngan nhat tu cac thanh pho toi nha va lu vao mang dist[][] 
//	dijkstra thuong duoc dung de tim duong di ngan nhat tu 1 dinh tren do thi co trong so khong am,
//	trong truong hop nay, cost cua moi tuyen buyt duoc su dung thay cho trong so
#include<bits/stdc++.h>
using namespace std;
#define HNT ios_base::sync_with_stdio(false);  cin.tie(0);

typedef vector<int> vi;
typedef vector<vi> vii;
const int N = 5001;
int n, k;
int D[N], C[N];
vii a;
int dist[N][N];

void bfs(int source, int dist[]) {
    queue<int> Q;
    Q.push(source);
    for(int i = 1; i <= n; ++i) dist[i] = INT_MAX;
    dist[source] = 0;
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        for(int v : a[u]) {
            if(dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
}

void calculate_dist() {
    for (int u = 1; u <= n; ++u){
        bfs(u, dist[u]);
    }
}

int ans[N];
int visit[N];

void dijkstra() {
    for (int i = 0; i <= n; ++i) {
        ans[i] = INT_MAX;
    }
	visit[1] = 0;
    ans[1] = 0;
    int step = n;
    while (step--) {
        int u = 0;
        for (int i = 1; i <= n; ++i) {
            if (visit[i] == 0 && ans[u] > ans[i]) {
                u = i;
            }
        }
        if (u == 0) break;
        visit[u] = 1;
        for (int v = 1; v <= n; ++v) {
            if (dist[u][v] <= D[u]) {
                ans[v] = min(ans[v], ans[u] + C[u]);
            }
        }
    }
    cout << ans[n] << endl;
}

int main() {
    HNT
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> C[i] >> D[i];
    }

    a.resize(n + 1, vi(0));
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    calculate_dist();
    dijkstra();
    return 0;
}

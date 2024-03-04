#include<iostream>
#include <set>
#include <vector>
#include <queue>


using namespace std;

const int Max_mn = 1000;
int d[Max_mn][Max_mn];
bool visit[Max_mn][Max_mn];
int hang, cot, strow, strcol, val;
int moveX[] = { 0, 0, 1, -1 };
int moveY[] = { 1, -1, 0, 0 };
int matrix[Max_mn][Max_mn];;

void bfs(int sx, int sy)
{
    // set up mang khoang cach (d) va mang ghe tham (visit) = 0: khoang cach = 0
    for (int i = 1; i < hang+1; i++)
    {
        fill_n(d[i], cot+1, 0);
        fill_n(visit[i], cot+1, false);
    }
    //hang doi luu diem dang dinh xet 
    queue <pair<int, int>> q;
    q.push({ sx, sy });
    visit[sx][sy] = true;
    while (!q.empty())// khi trong hang cho con phan tu
    {
        //xet phan tu dau
        // luu tam phan tu dau
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        // neu va phai bien thi thoa luon
        if (x == 1 || x == hang)
        {   
            cout << d[x][y]+1;
            return;
        }
        if (y == 1 || y == cot) {
            cout << d[x][y]+1;
            return;
        }
            // di den neighbor
            for (int i = 0; i < 4; ++i) {
                int u = x + moveX[i];
                int v = y + moveY[i];
                if (u<0 || u>hang || v<0 || v>cot)
                {
                    continue;
                }
                if (matrix[u][v] == 1)
                {
                    continue;
                }
                if (!visit[u][v])// neu chua den diem (u,v) thi:
                    // distance tu diem (sx,sy) xet toi diem (u,v)
                {
                    d[u][v] = d[x][y] + 1;
                    visit[u][v] = true;
                    q.push({ u,v });//cap nhat (u,v) nhu diem se xet
                }
            }
        }
    cout << -1;
    }




 int main() {   
    //nhap va luu ma tran
    cin >> hang >> cot >> strow >> strcol;
    for (int i = 1; i < hang+1; i++)
    {
        for (int j = 1; j < cot+1; j++)
        {
            cin >> matrix[i][j];
        }
    }
    bfs(strow, strcol);
    return 0;}

#include <bits/stdc++.h>
using namespace std;

const int Max_mn = 1000;
int d[Max_mn][Max_mn]{{}};// khoang cach ngan nhat tu diem xuat phat toi diem (x,y) bat ky
bool visitt[Max_mn][Max_mn]{{}}; // mang danh dau cac dinh da qua
int hang, cot, strow, strcol;
int moveX[] = { 0, 0, 1, -1 }; // posible x moves
int moveY[] = { 1, -1, 0, 0 }; // possible y moves
int matrix[Max_mn][Max_mn]; // mang luu maze
queue <pair<int, int>> q; // queue de chay bfs

bool is_border(int x, int y){
    if (x == 1 || x == hang){
        cout << d[x][y]+1;
        return true;}

    if (y == 1 || y == cot) {
        cout << d[x][y]+1;
        return true;}
    return false;
}

bool is_neighbor_legit(int u, int v){// check neighbor co phai la diem co the di chuyen toi khong
    if (visitt[u][v]){ // tung di qua chua ?
        return false;
    }
    if (u<0 || u>hang || v<0 || v>cot){// neighbor nam ngoai maze
        return false;
    }
    if (matrix[u][v] == 1){// neighbor la hang rao
        return false;
    }
    return true;
}

void bfs(int sx, int sy) // thuat toan loang
{   // nap vi tri hien tai vao hang cho de xet
    q.push({ sx, sy });
    visitt[sx][sy] = true;
    while (!q.empty())// bfs loop
    {// nhac phan tu dau ra khoi queue de xet
        if(is_border(q.front().first,q.front().second)){
            return;
        }
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        // di den neighbor
        for (int i = 0; i < 4; ++i) {
            int u = x + moveX[i];
            int v = y + moveY[i];
            if(is_neighbor_legit(u,v)){
                d[u][v] = d[x][y] + 1;
                visitt[u][v] = true;
                q.push({ u,v });//cap nhat (u,v) nhu diem se xet
            }
        }
    }
    cout << -1;
}


int main() {
    //nhap va luu ma tran
    cin >> hang >> cot >> strow >> strcol;
    for (int i = 1; i < hang+1; i++){
        for (int j = 1; j < cot+1; j++){
            cin >> matrix[i][j];
        }
    }
    bfs(strow, strcol);
    return 0;}

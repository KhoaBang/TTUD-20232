#include <bits/stdc++.h>
using namespace std;

int n, load_max,load=0; // n khach, load cua xe bus
int journey[24]{}; // mang luu cac chang da di qua
bool visited[24]{}; // mang danh dau cac thanh pho da di qua
int c[24][24]; // ma tran khoang cach
int distance_passed=0;
int record=INT16_MAX;
int Cmin=INT16_MAX;
void input(){
    cin>>n>>load_max;
    for(int i =0; i<2*n+1;i++){
        for(int j =0;j<2*n+1;j++){
            cin>>c[i][j];
            if(c[i][j]<Cmin&&c[i][j]!=0){Cmin=c[i][j];}
        }
    }
}

bool check(int city){
    if(visited[city]) return false;
    if(city>n){
        if(!visited[city-n]){
            return false;
        }
    }
    if(city<=n){
        if(load>=load_max){
            return false;
        }
    }
    return true;
}

void UpdateRecord(){
    if(distance_passed+c[journey[2*n]][0]<record){
        record=distance_passed+c[journey[2*n]][0];
    }
}

void Try(int hop){
    for(int city =1; city<=2*n;city++){
        if(check(city)){
            visited[city]=true; // danh dau da den
            if(city>n)load--;else load++; // tang giam load cua xe
            journey[hop]=city; // ghi nhan hanh trinh
            distance_passed+= c[journey[hop-1]][city]; // tang tong quang duong
            if(hop==2*n) UpdateRecord(); // cap nhat record neu da toi dich

            if(distance_passed+(2*n+1-hop)*Cmin<record){ // khao sat chang tiep theo
                Try(hop+1);
            }
            //quay xe
            visited[city]=false;
            distance_passed-= c[journey[hop-1]][city];
            if(city>n)load++;else load--;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);  cin.tie(0);
    input();
    Try(1);
    cout<<record;
}

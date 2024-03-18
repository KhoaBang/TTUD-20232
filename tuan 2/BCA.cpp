#include <bits/stdc++.h>
using namespace std;
int n, m; // m giao vien, n mon hoc
int record_max_load=INFINITY;
int day[31]{}; // ghi lai giao vien day cua lop
int Load[11]{}; // ghi lai load cua tung giao vien
int current_max_load=0;
vector<int> can_teach[11]{}; // cac lop ma 1 GV co the day
int k; // so cap lop bi trung gio
unordered_set<int> conflicting[31]{}; // tap cac lop bi trung

void input(){
    cin>> m>>n;
    for(int i =1; i<m+1;i++){
        int t; cin>> t;
        for(int j=1;j<=t;j++){
            int t1; cin>>t1;
            can_teach[i].push_back(t1);
        }
    }
    cin>>k;
    for(int i =0; i<k;i++){
        int a1,a2;
        cin>>a1>>a2;
        conflicting[a1].insert(a2);
        conflicting[a2].insert(a1);
    }
}

bool check(int mon, int GV){
    // check GV co day dc mon nay khong
    if(find(can_teach[GV].begin(),can_teach[GV].end(),mon)==can_teach[GV].end()){
        return false;
    }
    // check Gv nay da day mon nao trung gio voi mon nay chua
    for(auto v : conflicting[mon]){
        if (day[v]==GV) {
            return false;
        }
    }
    return true;
}

void Try(int mon){ // co gan giao vien "GV" cho mon hoc "mon"
    for(int GV =1; GV<=m;GV++){
        if(check(mon,GV)){ // kiem tra tuong thich giua GV va mon
            day[mon]=GV; //
            Load[GV]++;
            int t=current_max_load;
            if(Load[GV]>current_max_load) {
                current_max_load=Load[GV];
            }
            if(mon == n){
                if (current_max_load<record_max_load) {
                    record_max_load=current_max_load;
                    //cout<<record_max_load<<endl;
                }
            }
            if (current_max_load<record_max_load){
                Try(mon+1);
            }
            current_max_load=t;
            Load[GV]--;
            day[mon]=0;
        }
    }
}

int main(){
    input();
    Try(1);
    cout<<record_max_load<<endl;
}

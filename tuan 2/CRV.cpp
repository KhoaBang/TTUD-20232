
#include <bits/stdc++.h>
using namespace std;

int client_num, truck_num, max_weight;
int weight[13]{};
int d[14][14]{};
int curr_load[6]{};
vector<int> route[6]{}; // luu route cua xe
int record =INT_MAX;
int current_travel_dist=0;

void input(){
    cin>>client_num>>truck_num>>max_weight;
    for(int i =1;i<=client_num;i++){
        cin>>weight[i];
    }
    for(int i =0; i<=client_num;i++){
        for (int j=0;j<=client_num;j++){
            cin>>d[i][j];
        }
    }
}

bool check_truck(int client, int truck ){
    if(curr_load[truck]+weight[client]>max_weight) return false;
    return true;
}

// sinh moi hoan vi cua vector
// bo so 0 o dau:
int dosomething(vector<int> a[], int size) {
    int MinDem = 0;
    for (int k = 1; k <= size; ++k) {
        vector<int>& bus = a[k];
        //bus.erase(bus.begin()); // Remove the first element (depot) from each route
        if(a[k].size()!=0){
            int mindem = INT_MAX;
            do {
                int dem = 0;
                for (int i = 0; i < bus.size(); i++) {
                    if (i == 0) {
                        dem += d[0][bus[i]];
                    } else {
                        dem += d[bus[i - 1]][bus[i]];
                    }
                    if(i==bus.size()-1){
                        dem += d[bus[i]][0];
                    }
                }
                if (dem < mindem) mindem = dem;
            } while (next_permutation(bus.begin(), bus.end()));
            MinDem += mindem;
        }
    }
    //cout<<go_home();
    return MinDem ;
}

void Try (int client){
    for(int truck =1; truck<=truck_num;truck++){
        if (check_truck(client, truck)){// kiem tra xem la co chon dc xe "truck" cho khach hang "client" khong (kiem tra load hien tai cua truck)
            int g=current_travel_dist;
            if(route[truck].empty()){
                current_travel_dist+=d[0][client];
            }
            else{
                current_travel_dist+=d[route[truck].back()][client]; // tang quang duong cua ca he thong
            }
            route[truck].push_back(client); // cap nhat vi tri hien tai cua truck
            curr_load[truck]+=weight[client]; // cap nhat load hien tai
            if(client==client_num){
                auto k=route;
                int a=dosomething(k,truck_num);
                // cout<<a<<' ';
                if(a < record){
                    record=a;
                }
            }
            if(current_travel_dist < record){ // dieu kien bua chinh chu cx ko hieu tai sao de vay no lai chay =))
                Try(client+1);
            }
            curr_load[truck]-=weight[client];
            route[truck].pop_back();
            current_travel_dist=g;
        }
        else continue;
    }
}

int main(){
    input();
    Try(1);
    cout<<record;
}




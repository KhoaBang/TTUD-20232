#include<bits/stdc++.h>
using namespace std;

// queries co dang call <from_number> <to_number> <date> <from_time> <end_time>
// call bat dau la khong can thiet luu vao 1 bien co dinh
struct data1{
    string sdt1,sdt2;
    string date;
    string from_time,end_time;
} ;

set<string> Myset;

int log_num=0;// number_total_call
// luu tong thoi gian goi tu moi dau sdt
unordered_map<string,int> Myunordered_map;
unordered_map<string,int> Myunordered_map1;

// kiem tra
//kiem tra so dienthoai
int sdt_invalid_state =1;
void checksdt(string sdt){
    if (sdt.length()!=10){
        sdt_invalid_state++;
    }
}

////tinh call time theo second
int calltime(string from_time, string end_time){
    int time1[3];
    int time2[3];
    stringstream ss1(from_time);
    stringstream ss2(end_time);
    string token;
    int i =0;
    while (getline(ss1,token,':')){
        time1[i]=stoi(token);
        i++;
    }
    i=0;
    while (getline(ss2,token,':')){
        time2[i]=stoi(token);
        i++;
    }
    // tinh thoi gian cuoc goi
    int calltime = (time2[0]-time1[0])*60*60 + (time2[1]-time1[1])*60 + (time2[2]-time1[2]);
    return calltime;
}

void input(){
    string a{};
    while(1){
        cin>>a;
        if(a=="#"){
        break;
        }

        data1 call{};
        cin>>call.sdt1>>call.sdt2>>call.date>>call.from_time>>call.end_time;
        //check sdt 10 so
        checksdt(call.sdt1);
        checksdt(call.sdt2);
        log_num++;
        // tong thoi gian goi xuat phat tu 1 so cho truoc
        if((Myset.insert(call.sdt1)).second){
            Myunordered_map[call.sdt1]= calltime(call.from_time,call.end_time);
            Myunordered_map1[call.sdt1]=1;
        }
        else{
            Myunordered_map[call.sdt1]+=calltime(call.from_time,call.end_time);
            Myunordered_map1[call.sdt1]+=1;
        }

    }
}


void queries() {
    string b;
        while (1) {
            cin >> b;
            if (b == "#") {
                break;
            }
            if (b == "?check_phone_number") {
                cout << sdt_invalid_state << "\n";
                continue;
            } else if (b == "?count_time_calls_from") {
                string c;
                cin >> c;
                cout << Myunordered_map[c] << "\n";
                continue;
            } else if (b == "?number_total_calls") {
                cout << log_num<<"\n";
                continue;
            } else if (b == "?number_calls_from") {
                string c;
                cin >> c;
                cout << Myunordered_map1[c] << "\n";
                continue;
            }

        }
    }

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);
    input();
    queries();
    return 0;
}


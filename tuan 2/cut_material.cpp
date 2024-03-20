#include <bits/stdc++.h>
using namespace std;
int max_height, max_width;
int num; // so luong subrectangle
bool state=false;

struct Sub_rect {
    int H,W; // height va width cua subrect
    bool reversed; // trang thai: false = sap, true = ngua (mac dinh la false)
    int x,y; // toa do
    Sub_rect(int H,int W, bool used=false, bool reversed=false):H(H),W(W),reversed(reversed){}
    int get_max_width(){ 
        if (reversed){
            return x+H;
        }
        else return x+W;
    };
    int get_max_height(){
        if (reversed){
            return y+W;
        }
        else return y+H;
    };
};

Sub_rect* arr[11];
vector<Sub_rect> sol;
void cleanup() {
    for (int i = 0; i < num; i++) {
        delete arr[i]; // Deallocate memory for each Sub_rect object
    }
}

void input(){
    cin>>max_height>>max_width;
    cin>>num;
    for(int i =0;i<num;i++){
        int h,w;
        cin>>h>>w;
        arr[i] = new Sub_rect(h, w);
    }
}

bool check_overlap( Sub_rect moi,Sub_rect cu){
    if((moi.y>=cu.get_max_height()||cu.y>=moi.get_max_height()||moi.x>=cu.get_max_width()||cu.x>=moi.get_max_width())
    &&moi.get_max_height()<=max_height&&moi.get_max_width()<=max_width){
        return true;
    }
    return false;
}

bool check(vector<Sub_rect> so, Sub_rect moi,int k){
    if (k==0){
        return true;
    }
    else{
        for(Sub_rect cu: so){
            if(!check_overlap(moi,cu)) return false;
        }
    }
    return true;
}

void Try (int k){ // thu subrectangle thu k
        //iterate tung gia tri x,y
       if(!state){
           for(int x=0;x<max_width;x++){
               for(int y=0;y<max_height;y++){
                   // tao dummy
                   Sub_rect a = *arr[k];
                   a.x=x; a.y=y;
                   if (check(sol,a,k)){// kiem tra xem co dat duoc khong
                       sol.push_back(a);
                       if(sol.size()==num){
                           state=true;
                       }
                       Try(k+1); // di chuyen toi subrectangle ke tiep
                       sol.pop_back();
                   }
                   else if (a.reversed=true&&check(sol,a,k)){
                       // thu dat reversed
                       sol.push_back(a);
                       if(sol.size()==num){
                           state=true;
                       }
                       Try(k+1);
                       a.reversed=false;
                       sol.pop_back();
                   }
                   else{
                       continue;}
               }
           }
       }

            }

int main(){
    input();
    Try(0);
    cout<<state;
    cleanup();
}
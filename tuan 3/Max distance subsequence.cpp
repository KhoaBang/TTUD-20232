#include <bits/stdc++.h>
using namespace std;
int t;
int n,m;
int source [100000]{};

// given a number, how to find its nearest number that exist in the array
// can iterate from the beginning, and compare the number to each element in the array, if the number is larger, return its index.
//int nearestv2(int k) { // can be upgraded by using binary search to find the nearest suitable element
//    int i;
//    for( i =0; i<n;i++){
//        if (source[i]>=k) break;
//    }
//    if(source[i]<k){
//        return -1;
//    }
//    cout<<source[i]<<' '<<k<<';'<<' '; return i;
//}

int nearestv2 (int k){ // using binary search
    int right=n-1,left=0;
    int mid;
    while (left<right){
        mid = left+(right-left)/2;
        if(source[mid]<k){
            left=mid+1;
        }
        else{
           right=mid;
        }
    }
    //cout<<source[left]<<' '<<k<<';'<<' ';
    if(source[left]<k) return -1;
    return left;
}

int sol[100000]{};
//given a gap, check if from that gap can construct a full solution
bool check(int kmax) {
    sol[0] = source[0];
    for (int i = 1; i < m; i++) {
        int tmp = nearestv2((sol[i - 1] + kmax));
        if (tmp == -1) return false;
        else{
            sol[i]=source[tmp];
        }
    }
    return true;
}


//find the gap given it upper-bound
// using binary search

int find_gap(){
    int right = int ((source[n-1]-source[0])/(m-1));
    int left =0;
    int mid;
    while(left<right){
        mid = left+ ((right-left+1)/2);
        //cout<<left<<' ' << right<<' '<<mid<<endl;
        if (check(mid)){
            left=mid;
        }
        else{
            right=mid-1;
        }
    }
    if(check(left)==-1) return -1;
    //cout<< check(96)<<endl;
    return left;
}

int main(){
    ios_base::sync_with_stdio(false);  cin.tie(0);
    cin>>t;
    for(int i =0;i<t;i++){
        cin>>n>>m;
        for(int j =0;j<n;j++){
            cin>>source[j];
        }
        sort(source,source+n);
        cout<<find_gap()<<endl;
    }
}
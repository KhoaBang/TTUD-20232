#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int>> segments;
void input(){
    cin>>n;
    for(int i =0; i<n;i++){
        int a,b;
        cin>>a>>b;
        segments.push_back(make_pair(a,b));
    }
}
/* idea: each segment have (left-bound, right-bound)
 * the segment is sorted in the order of increasing right-bound
 * (this is due to the fact that our objective is to pack as much satisfied segment as possible given a right-bound;
 * and right-bound is always bigger than left-bound)
 * iterate over the segment list
 * take the current segment right-bound, if the next segment left-bound is greater than the current right-bound
 * count++; else skip
 * --> this is GREEDY approach
 * */
struct {
    bool operator () (pair<int,int> a,pair<int,int> b ){
        return a.second < b.second;
    }
}CMP;

int main(){
    input();
    sort(segments.begin(), segments.end(),CMP);
    int dem =0,temp =-1;
    for (auto smt: segments){
       if (smt.first>temp){
           temp = smt.second;
           dem++;
       }
    }
    cout<<dem;
}
# include<bits/stdc++.h>
using namespace std;

int table [21][1000001];
int n,m;
int sum=0;
void preprocess(){
    int LOG = int(log2(n+1));
    for(int i =1;i<=LOG;i++){
        for(int j =0;j<n-(1<<i)+1;j++){
            table[i][j]=min(table[i-1][j],table[i-1][j+(1<<(i-1))]);
            //cout<<table[i][j]<<' ';
        }
            //cout<<endl;
        }
    }

int query_min(int left,int right){
    int k=int(log2(right-left+1));
    return min(table[k][left],table[k][right-(1<<(k))+1]);
}

void input(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>table[0][i];
    }
}

int main (){
    ios_base::sync_with_stdio(false);  cin.tie(0);
    input();
    //cout<<endl;
    for(int i=0;i<n;i++){
        //cout<<table[0][i]<<' ';
    }
    //cout<<endl;
    preprocess();
    cin >> m;
    for(int i =0;i<m;i++){
        int l,r;
        cin>>l>>r;
        sum+=query_min(l,r);
    }
    cout<<sum;


}
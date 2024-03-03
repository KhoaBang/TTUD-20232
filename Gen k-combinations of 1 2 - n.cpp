#include <bits/stdc++.h>
using namespace std;
int a, b;
int arr[100]{};

int solution(int k){
    if(k<a+1){
        for(int i =arr[k-1]+1; i<=b;i++){
            arr[k]=i;
            solution (k+1);
        }
    }
    else{
        for(int i =1;i<=a;i++){
            cout<<arr[i]<<' ';
        }
        cout<< endl;
    }
}

int main(){
    ifstream myfile("input.txt");
    myfile>>a>>b;
    solution(1);
    myfile.close();
}

#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
int main() {
    //fast I/0
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N,Q;
    cin>>N>>Q;
    
    vector<long long>A(N);
    for(int i=0; i<N; i++){
        cin>>A[i];
    }
    unordered_set<long long>numset(A.begin(),A.end());
    for(int i=0; i<Q; i++){
        int x;
        cin>>x;
        if(numset.find(x)!= numset.end()){
            cout<<"found"<<endl;
        }else{
            cout<<"not found"<<endl;
        }
    }
    return 0;
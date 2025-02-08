#include<iostream>
#include<vector>
using namespace std;
int main() {
    //fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N,Q;
    cin>>N>>Q;
    
    vector<long long>A(N);
    for (int i = 0; i<N; i++){
        cin>>A[i];
    }
    vector<long long>prefix(N+1,0);
    for(int i= 1; i<=N; i++){
        prefix[i] = prefix[i-1] + A[i-1];
    }
    while(Q--){
        int L,R;
        cin>>L>>R;
        cout<<prefix[R] - prefix[L-1]<<"\n";
    }
    return 0;
}
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


    //adcanced methode for faster results 
    #include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<long long> A(N);
    unordered_set<long long> numset;
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        numset.insert(A[i]);  // Insert directly instead of using range constructor
    }

    while (Q--) {
        int x;
        cin >> x;
        cout << (numset.count(x) ? "found\n" : "not found\n"); // Faster lookup
    }

    return 0;
}

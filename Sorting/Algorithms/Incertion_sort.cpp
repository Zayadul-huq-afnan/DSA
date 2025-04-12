#include<bits/stdc++.h>

using namespace std;

int main(){

    vector<int> v = {4,1,0,5,9,6};

    for(int i = 1; i < v.size(); i++){

        int curr = v[i];

        int j = i - 1;

        while(j >= 0 && v[j] > curr){
            v[j+1] = v[j];
            j--;
        }

        v[j+1] = curr;
    }

    for(auto x: v){
        cout<<x<<" ";
    }
    cout<<"\n";
}

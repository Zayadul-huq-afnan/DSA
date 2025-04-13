#include<bits/stdc++.h>

using namespace std;

int main(){

    vector<int> v = {4,1,0,5,9,6};

    for(int i = 0; i < v.size() - 1; i++){

        int minIndex = i;

        for(int j = i + 1; j < v.size(); j++){
            if(v[j] < v[minIndex]){
                minIndex = j;
            }
        }

        swap(v[i], v[minIndex]);
    }

    for(auto x: v){
        cout<<x<<" ";
    }
    cout<<"\n";
}

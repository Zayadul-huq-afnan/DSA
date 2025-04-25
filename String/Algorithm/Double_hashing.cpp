#include<bits/stdc++.h>

using namespace std;

int p1 = 110 , p2 = 127;

int mod1 = 1e9 + 7;
int mod2 = 1e9 + 9;

const int N = 1e5;

int power1[N];
int power2[N];

void pre(){

    power1[0] = 1;

    for(int i = 1; i < N; i++){
        power1[i] = (power1[i-1] * p1) % mod1;
    }

    power2[0] = 1;

    for(int i = 1; i < N; i++){
        power2[i] = (power2[i-1] * p2) % mod2;
    }

}

pair<int,int>hash_string(string str){

    int n = str.size();

    int hs1 = 0;

    for(int i = 0; i < n; i++){
        hs1 = (hs1 + (1LL * str[i] * power1[i])) % mod1;
        hs1 = hs1 % mod1;
    }

    int hs2 = 0;

    for(int i = 0; i < n; i++){
        hs2 = (hs2 + (1LL* str[i] * power2[i])) % mod2;
        hs2 = hs2 % mod2;
    }

    return {hs1, hs2};

}

int main(){

    string a,b;
    cin>>a>>b;
    pre();
    pair<int,int> x = hash_string(a);
    pair<int,int>y = hash_string(b);

    if(x == y){
        cout<<"YES"<<"\n";
    }
    else{
        cout<<"NO"<<"\n";
    }

}



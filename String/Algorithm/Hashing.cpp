#include<bits/stdc++.h>

using namespace  std;


const int p = 137 , mod = 1e9 + 7;


const int N = 1e5;

int power[N];

void pre(){
    power[0] = 1;

    //let string  = abc
    //where a , b , c will be represented with their ascii value
    // want to calculate , a * p^0 + b * p^1 + c * p ^ 2

    for(int i = 1; i < N; i++){
        power[i] = (1LL* power[i-1] * p) % mod;
    }
}

int hash_string(string str){

    int len = str.size();

    int hs = 0;

    for(int i = 0; i < len; i++){
        //str[i] return the ascii value of the character
        hs = (hs + (1LL* str[i] * power[i])) % mod;
        hs = hs % mod;
    }

    return hs;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pre();

    string a, b;
    cin>>a>>b;

    int x = hash_string(a);
    int y = hash_string(b);

    cout<<x<<" "<<y<<"\n";
}




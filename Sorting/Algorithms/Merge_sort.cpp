#include<bits/stdc++.h>
using namespace std;

using ll  = int64_t;
const int N = 1e5 + 9;
const ll nmax = 1e17;


void merge(int arr[] , int l , int m , int r){

    int k = l;

    int i = l;
    int j = m+1;

    auto *tmpArray = new int[r+1];

    while(i <= m && j <= r){

        if(arr[i] <= arr[j]){
            tmpArray[k] = arr[i];
            i++;
        }
        else{
            tmpArray[k] = arr[j];
            j++;
        }
        k++;
    }

    while(i <= m){
        tmpArray[k] = arr[i];
        i++;
        k++;
    }
    while(j <= r){
        tmpArray[k] = arr[j];
        j++;
        k++;
    }

    while(l <= r){
        arr[l] = tmpArray[l];
        l++;
    }

   delete[] tmpArray;
}

void mergeSort(int arr[] , int l , int r){

    if(l < r){
        int mid = (l+r) / 2;
        mergeSort(arr , l , mid);
        mergeSort(arr , mid+1 , r);
        merge(arr , l , mid , r);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();

    int arr[] = {4,5, 1, 0 , 56 , 2};

    int n = sizeof(arr) / sizeof(arr[0]);

    //cout<<n;

    mergeSort(arr , 0 , n-1);

    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }



}

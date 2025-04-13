#include<bits/stdc++.h>

using namespace std;

int cnt = 0;
int partition(int arr[] ,  int lb , int ub){

    int pivot = arr[lb];
    //cout<<pivot<<"\n";
   //cout<<lb<<" "<<ub<<" "<<arr[lb]<<" "<<arr[ub]<<"\n";

    int start = lb ;
    int finish = ub;

    while(start < finish){

        while(arr[start] <= pivot){
            start++;

            if(start == ub){
                break;
            }

        }

        while(arr[finish] > pivot){
            finish--;

            if(finish == lb){
                break;
            }
            //cout<<"f: "<<finish<<"\n";
        }

        //cout<<"s: "<<start<<" "<<finish<<"\n";

        if(start < finish){
            int tmp = arr[start];

            arr[start] = arr[finish];
            arr[finish] = tmp;
        }
    }

    swap(arr[finish] , arr[lb]);

    //cout<<finish<<"\n";
    return finish;
}

void quickSort(int arr[] , int lb , int ub){

    //cout<<"x\n";
    if(lb < ub){

        int pos = partition(arr, lb , ub);
        //cout<<lb<<" "<<pos<<" "<<ub<<"\n";
        quickSort(arr, lb , pos-1);
        quickSort(arr, pos+1 , ub);
    }

}

int main() {
  int arr[]={10,7,8,9,1,5};
  int n=sizeof(arr)/sizeof(arr[0]);
  // Function call
  quickSort(arr,0,n-1);
  //Print the sorted array
  cout<<"Sorted Array\n";
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  return 0;
}

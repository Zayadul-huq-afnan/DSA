#include<bits/stdc++.h>

using namespace std;

void counting_sort(int *arr ,int n) // n=size of array
{

    //first find out the highest and lowest negative value of the array

    int high = -1;
    int low=0;

    for(int i=0 ; i<n ; i++)
    {

        if(arr[i]>high)
        {
            high=arr[i];
        }
        if(arr[i]<low)
        {
            low=arr[i];
        }
    }


    if(low<0) // if there is negative value, then first normalize(make all the values positive)
    {
        for(int i=0 ; i<n ; i++)
        {
            arr[i]=arr[i]+abs(low);
        }

         for(int i=0 ; i<n ; i++)
        {
           if(arr[i]>high)
           {
               high=arr[i]; //find the new high after adjustment
           }
        }
    }

    int freq[high+1]; //to track the frequency of the elements

    for(int i=0 ; i<=high ; i++)
    {

        freq[i]=0;
    }

    for(int i=0 ; i< n ; i++) //counting the frequency
    {

        freq[arr[i]]++;
    }

    for(int i=1 ; i<=high ; i++) // now do a prefix sum to find the ending index of each element
    {

        freq[i]=freq[i-1]+freq[i];
    }


    int tmparr[n]; // create a dummy array to sort

    for(int i= n-1 ; i>-1 ; i--) //trevarse i reverse order to maintain stability
    {

        int element =arr[i];
        tmparr[--freq[element]]=element ;  //post reducing the frequency, cause index = frequency-1.
    }

    for(int i=0 ; i<n ; i++) //now assign the elements of the dummy array to our main array
    {

        arr[i]=tmparr[i];
    }

    if(low<0) //adjust the normalization
    {
        for(int i=0 ; i<n ; i++)
        {
          ;
             arr[i]=arr[i]-abs(low);
        }

    }

}




int main()
{
    int arr[] = {-4,-4,-2,-22,-11,-4,-9,-8,-7,-2};

    counting_sort(arr , 8); //pass the array and size of the array.

    for(int i=0 ; i<8 ; i++)
    {
        cout<<arr[i]<<" ";
    }


}

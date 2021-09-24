#include<iostream>
using namespace std;

void merge(int arr[] , int l , int mid , int r){
    //we have not received two arrays that we have to merge
    //rather
    //we will divide our array into two different arrays as we already have 
    //sorted array in those two portions
    //and then we will merge accordingly.

    int n1 = mid - l + 1;
    int n2 = r - mid;

    int L[n1];
    int R[n2];

    for(int i = 0; i < n1; ++i){
        L[i] = arr[l + i]; 
    }
    for(int i = 0; i < n2; ++i){
        R[i] = arr[mid + 1 + i];
    }


    int i = 0;
    int j = 0;
    int k = l;

    while( i < n1 && j < n2){
        if(L[i] < R[j]){
            arr[k] = L[i];
            ++i;
            ++k;
        }
        else{
            arr[k] = R[j];
            ++j;
            ++k;
        }
    }

    //if any one among i or j is at last and other not
    while(i < n1){
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while(j < n2){
     arr[k] = R[j];
        ++j;
        ++k;   
    }


}


void mergeSort(int arr[] , int l , int r){

    if(l < r){
        int mid = (l + r) / 2;

        mergeSort(arr , l , mid);
        mergeSort(arr , mid + 1 , r);

        merge(arr , l , mid , r);   
    }
}

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input1.txt" , "r" , stdin);
        freopen("output.txt" , "w" , stdout);
    #endif

    int t , n;
    cin >> t;
    while(t--){

        cin >> n;
        int arr[n];

        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }

        mergeSort(arr , 0 , n - 1);

        bool found = false;
        for(int i = 0; i < n; ++i){
            if(arr[i] == arr[i+1])
                found = true;
        }

        if(found)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }

    

    return 0;
}
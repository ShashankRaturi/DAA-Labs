#include<iostream>
using namespace std;

void showArray(int arr[] , int n){
    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void InsertionSort(int arr[] , int n){

    int i , j , shift = 0 , comparison = 0;

    //assuming the first element to be the part of sorted array ,  so unsorted array starts from index 1
    for(i = 1; i < n; ++i){

        int temp = arr[i];   // storing it it temp variable as it will help in swapping
        j = i - 1;

        while(++comparison && j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            ++shift;
            --j;
        }
        arr[j + 1] = temp;  //because after the above loop j has decremented before condition became false

    }

    showArray(arr , n);

    cout <<"comparsions = " << comparison <<"\nshifts = " << shift << endl;
}


int main(){

    
    #ifndef ONLINE_JUDGE
        freopen("input.txt" , "r" , stdin);
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

        InsertionSort(arr , n);
    }


    return 0;
}
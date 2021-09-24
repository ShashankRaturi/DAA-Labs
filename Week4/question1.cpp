#include<iostream>
using namespace std;

void showArray(int arr[] , int n){


    for(int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[] , int l , int mid , int r , int &inv , int &comp){
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
        
        ++comp;
        if(L[i] <= R[j]){

            arr[k] = L[i];
            ++i;
            ++k;
        }
        else{
            inv += (n1 - i) ;
            arr[k] = R[j];
            ++j;
            ++k;
        }
        //cout << inv << endl;
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


void mergeSort(int arr[] , int l , int r , int &inv , int &comp){

    if(l < r){
        int mid = (l + r) / 2;

        mergeSort(arr , l , mid , inv , comp);
        mergeSort(arr , mid + 1 , r , inv , comp);

        merge(arr , l , mid , r , inv , comp);   
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
        int comp = 0, inv = 0;
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }

        mergeSort(arr , 0 , n - 1 , inv , comp);

        showArray(arr , n);

        cout << "comparisons = " << comp << endl;
        cout << "inversions  = " << inv << endl;

    }

    

    return 0;
}
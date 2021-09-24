#include<iostream>
using namespace std;


void printArray(int arr[] , int n){

    for(int j = 0; j < n; ++j){
            cout << arr[j] << " ";
        }
        cout << endl;
}

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int arr[] , int n){
    int compariosn = 0 , sw = 0;
    for(int i = 0 ; i < n - 1; ++i){
        int min_index = i;
        for(int j = i + 1; j < n ; ++j){
            if (arr[j] < arr[min_index]){
                min_index = j;
            }
            ++compariosn;

        }
        swap(&arr[i] , &arr[min_index]);
        ++sw;
        
    }
    printArray(arr , n);
    cout << "comparisons = " << compariosn << "\nswaps = " << sw << endl;

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

        SelectionSort(arr , n);
    }

    return 0;
}



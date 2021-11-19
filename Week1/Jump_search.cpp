#include<iostream>
#include<cmath>
using namespace std;



void jumpSearch(int &arr , int n , int key){
    int found = 0;
    int m = sqrt(n); // setting the jump size
    int i = 0;

    while(key >= arr[m] && m < n){
        
        i = m;
        m += sqrt(n);

        if(m >= n){
            //element is not inside array
            return;
        }
    }

    //linear searching
    for(int x = i; i < m; ++x){
        if(arr[x] == key){
            cout << "Yes found at index " , x << endl;
            return;
        }
            
    }

    if(found == 0)
        cout << "Not found" << endl;

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
        int arr{n];
        int key;

        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }
        cin >> key;

        jumpSearch(arr , n , key);
    }

    return 0;
}
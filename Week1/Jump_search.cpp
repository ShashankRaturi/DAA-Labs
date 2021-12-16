#include<iostream>
#include<cmath>
using namespace std;



void jumpSearch(int arr[] , int n , int key){

    int found = 0;
    int m = sqrt(n); // setting the jump size
    int i = 0 , count = 0;

    

    while(arr[m] <= key && m < n){
        //cout << "i = " << i << " m = " << m << endl;
        i = m;
        m += sqrt(n);
        ++count;
        if(m > n - 1){
            //element is not inside array
            //cout <<"hii my size got increased" << endl;
            m = n - 1;
            break;
        }
    }
    //cout << "elements  " << endl;
    //linear searching
    for(int x = i;  x <= m; ++x){
        ++count;
        if(arr[x] == key){
            cout << "Yes found " << count << endl;
            return;
        }
            
    }

    if(found == 0)
        cout << "Not found " << count << endl;

}


int main(){

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt" , "r" , stdin);
    //     freopen("output.txt" , "w" , stdout);
    // #endif

    int t , n;
    cin >> t;

    while(t--){
        cin >> n;
        int arr[n];
        int key;

        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }
        cin >> key;

        jumpSearch(arr , n , key);
    }

    return 0;
}
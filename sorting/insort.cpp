#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,temp;
    cout << "enter the number of elements : ";
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cout << "enter the "<< i+1 <<" element :";
        cin >> arr[i];
    }
    for (int i=1; i<n;i++){
        temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
//for printing the sorted array
    for (int i=0;i<n;i++){
        cout << arr[i]<<" ";
    }
    return 0;
}

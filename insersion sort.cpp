#include <iostream>
#include <vector>
using namespace std;
int insertionSort(vector<int>& arr){
    for(int j=2;arr.size();j++){
        int key=arr[j];
        int i=j-1;
        while(i>0 && arr[i>key]){
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=key;
    }
}
int main(){

    vector<int> arr={5,2,4,6,1,3};
    insertionSort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
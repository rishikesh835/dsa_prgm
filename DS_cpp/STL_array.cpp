#include<iostream>
#include<array>
using namespace std;

int main(){
    array<int,6> arr = {1,2,3,4,6,8};
    arr[0] = 10;
    for(int i= 0;i < arr.size();i++){
        cout<<arr[i]<<" ";
    }
    //for Each loop
    for(int x : arr)
    cout<<x;
    

    return 0;
}

#include<iostream>

using namespace std;
int getIthBit(int n,int i){
    return n & (1<<i) > 0? 1: 0;
}
int setIthBit(int n,int i){
    int mask = (1<<i);
    n |= mask;
    return n;
}
int clearIthBit(int n,int i){
    int mask = ~(1<<i);
    n &= mask;
    return n;
}
//this function update the value of bit to given v
//first we clear the ith bit then we update it to v
int updateIthBit(int n,int i,int v){
    n = clearIthBit(n,i);
    int mask = (v << i);
    n |= mask;
    return n;
}
int clearLastIBits(int n,int i){
    int mask = (~0 << i);
    
    n &= mask;
    return n;
}
int clearBitsInRange(int n,int i,int j){
    int a = (~0)<<(j+1);
    int b = (1<<i) -1;
    int mask = a|b;
    n &= mask;
    return n;
}
bool powerOfTwo(int n){
    return (n & (n-1)) == 0;
}
int countSetBits(int n){
    int count = 0;
    while(n){
       count += n & 1;
       n >>= 1;
    }
    return count;
}
//this is an alternate method this clear the last set bit of n 
//although this takes same time in most cases but for numbers like 16 or 32 it's faster
int count_Bits(int n){
    int ans = 0;
    while(n > 0){
        n = n &(n-1);
        ans++;
    }
    return ans;
}
int decToBinary(int n){
    int ans = 0;
    int p = 1;
    while(n > 0){
        int last_bit = n & 1;
        ans += p * last_bit;
        p = p *10;
        n >>= 1;
    }
    return ans;
}
int main(){
    int n = 15;
    int i = 2;
    int j = 3;
    cout<<getIthBit(n,i)<<"\n";//1
    cout<<setIthBit(n,i)<<"\n";//15
    cout<<clearIthBit(n,i)<<"\n";//11
    cout<<updateIthBit(n,i,0)<<"\n";//11
    cout<<clearLastIBits(n,i)<<"\n";//12
    cout<<clearBitsInRange(n,i,j)<<"\n";//3
    cout<<powerOfTwo(16)<<"\n";//1
    cout<<countSetBits(n)<<"\n";//4
    cout<<decToBinary(n)<<"\n";
    return 0;
} 
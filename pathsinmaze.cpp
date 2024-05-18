#include <iostream>
using namespace std;
int countpathmaze(int n, int i, int j){
    if(i==n-1 && j==n-1){
        return 1;
    }
    else if(i==n || j==n){
        return 0;
    }
    int result = countpathmaze(n,i+1,j)+countpathmaze(n,i,j+1);
    return result;
}

int main(){
    cout<<countpathmaze(3,0,0);
    return 0;

}
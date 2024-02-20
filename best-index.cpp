#include <iostream>
using namespace std;
int main(){
    int n=7;
    // cin>>n;
    int array[n]={898, -891, -604, -343, -280, 876, 538};
    int grouping=1;
    int maxindex=0;
    int maxsum=0;
    int tempsum=0;
    int pos=0;
    int j=0;
    // for(int i=0;i<n;i++){
    //     cin>>array[i];
    // }
    for(int i=0;i<n;i++){
        while(pos+grouping<n){
            while(j<grouping){
                tempsum=tempsum+array[pos+j];
                j=j+1;
            }
            pos=pos+grouping;
            grouping=grouping+1;
            j=0;
        }
        if(tempsum>maxsum){
            maxsum=tempsum;
            maxindex=i+1;
        }
        grouping=1;
        pos=i+1;
    }
    cout<<maxindex<<endl;
    return 0;
    
}
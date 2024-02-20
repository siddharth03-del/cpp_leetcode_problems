#include <iostream>
#include <cmath>
using namespace std;
bool steps(int *arraya, int *arrayb, int *countsteps, int minnumber, int n){
    for(int i=0;i<n;i++){
        if(arraya[i]==minnumber){
            continue;
        }
        else{
            bool test=false;
            double num=(double(arraya[i]-minnumber)/arrayb[i]);
            if(floor(num)==ceil(num)){
                *countsteps+=num;
            }
            else{
                *countsteps=0;
                return false;
            }
        }
    }
    return true;
}
int main(){
    int n;
    bool test=false;
    cin>>n;
    int arraya[n];
    int arrayb[n];
    int count=0;
    int fatherofminnumber=0;
    int *countsteps=&count;
    for(int i=0;i<n;i++){
        cin>>arraya[i];
    }
    for(int i=0;i<n;i++){
        cin>>arrayb[i];
    }
    int minnumber=arraya[0];
    for(int i=0;i<n;i++){
        if(arraya[i]<minnumber){
            minnumber=arraya[i];
        }
    }
    for(int i=0;i<n;i++){
        if(arraya[i]==minnumber){
            if(arrayb[i]>fatherofminnumber){
                fatherofminnumber=arrayb[i];
            }
    }
    }

    if(steps(arraya,arrayb,countsteps,minnumber,n)){
        cout<<*countsteps;
        test=true;
    }
    else{
        minnumber=minnumber - fatherofminnumber;
        while(minnumber>=0){
            if(steps(arraya,arrayb,countsteps,minnumber,n)){
                cout<<*countsteps;
                test=true;
                break;

            }
            else{
            minnumber=minnumber - fatherofminnumber;      
            }
        }
    }
    if(!test){
        cout<<"-1";
    }
    return 0;
}
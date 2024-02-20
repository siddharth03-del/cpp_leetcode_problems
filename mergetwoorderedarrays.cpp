#include <iostream>
using namespace std;
int main(){
    int n;
    int m;
    cout<<"enter the size of array first"<<endl;
    cin>>n;
    cout<<"enter the size of second array"<<endl;
    cin>>m;
    int array1[n];
    int array2[m];
    for(int l=0;l<n;l++){
        cin>>array1[l];
    }
    for(int l=0;l<m;l++){
        cin>>array2[l];
    }
    int resarray[n+m];
    int pos=0;
    int res=0;
    for(int i=0;i<10;i++){
        if(array2[res]>array1[i]){
            resarray[pos]=array1[i];
            pos++;      
        }
        else if(array2[res]<array1[i]){
            resarray[pos]=array2[res];
            pos++;
            res++;
        }
        else{
            resarray[pos]=array1[i];
            pos++;
            resarray[pos]=array2[res];
            res++;
            pos++;
        }
        if(res==5){
            for(int r=pos;pos<m+n;pos++){
                resarray[pos]=array1[i];
                i++;
            }
        }
    }
    for(int k=0;k<(m+n);k++){
        cout<<resarray[k]<<" ";
    }
}
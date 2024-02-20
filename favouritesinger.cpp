#include <iostream>
using namespace std;

int main(){
    int n;
    bool test=false;
    int tempfreq=0;
    int freq=0;
    int favourite=0;
    int pos=0;
    cin>>n;
    int respos=0;
    int  resarray[n];
    int  array[n];
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    for(int i=0;i<n;i++){
        tempfreq=1;
        test=false;
        //check element should not be in resarray
        if(respos>0){
            for(int j=0;j<respos;j++){
            if(array[i]==resarray[j]){
                test = true;
            }
        }
        }
        if(test){
            continue;
        }
        resarray[respos]= array[i];
        respos+=1;
        for(int j=i+1;j<n;j++){
            
            if(array[i]==array[j]){
                tempfreq+=1;
            }
        }
        if(tempfreq>freq){
            freq=tempfreq;
            favourite=1;
        }
        else if(tempfreq==freq){
            favourite+=1;
        }
        
    }
cout<<favourite;
return 0;
}



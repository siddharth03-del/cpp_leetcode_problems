#include <iostream>
using namespace std;
int main(){
    int testcase;
    cin>>testcase;
    int arrayresult[testcase];
    for(int i=0; i<testcase;i++){
        int priceof1prize;
        cin>>priceof1prize;
        int priceof2prize;
        cin>>priceof2prize;
        int row;
        cin>>row;
        int competition1win=0;
        int competition2win=0;
        int res1;
        int res2;
        int array[row][2];
        for(int k=0;k<row;k++){
                cin>>array[k][0];
                cin>>array[k][1];

            }
        for(int k=0;k<row;k++){
                if(array[k][0]==1){
                    competition1win+=1;
                }
                if(array[k][1]==1){
                    competition2win+=1;
                }
        }
        res1=(competition1win*priceof1prize)+(competition2win*priceof2prize);
        res2=(competition1win*priceof2prize)+(competition2win*priceof1prize);
        if(res1<res2){
            arrayresult[i]=res1;
        }
        else{
            arrayresult[i]=res2;
        }


        
}
    for(int i=0;i<testcase;i++){
        cout<<arrayresult[i]<<endl;
    }
    return 0;
}
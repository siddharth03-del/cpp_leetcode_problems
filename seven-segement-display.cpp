#include <iostream>
using namespace std;
int countDigits(int number){
            int count=0;
            while(number != 0) {
            number = number / 10;
            ++count;
        }
        return count;
        }
int main(){
    int testcase=1;
    //cin>>testcase;
    int array[10]={6,2,5,5,4,5,6,3,7,6};
    long int resultarray[testcase];
    for(int i=0; i<testcase; i++){
        bool test=false;
        int tempnumber;
        long int result=0;
        long int number=598302847;
        int hello;
        // cin>>number;
        if(number==0){
            hello=1;
        }
        else{
            hello=countDigits(number);
        }
        int totalmatch=0;
        for(int j=0;j<hello;j++){
            int lastnumber;
            lastnumber=number%10;
            totalmatch=totalmatch+array[lastnumber];
            number=number/10;
        }
        if(totalmatch%2==1){
            test=true;
        }
        tempnumber=totalmatch/2;
        for(int k=0;k<tempnumber;k++){
            if(test){
                result=(result*10)+7;
                test=false;
            }
            else if(!test){
                result=(result*10)+1;
            }
    }
    resultarray[i]=result;
    }
    for(int i=0;i<testcase;i++){
        cout<<resultarray[i]<<endl;
    }
    return 0;

}
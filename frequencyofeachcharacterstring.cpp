#include <iostream>
#include <string>
using namespace std;
int main(){
    string s1;
    getline(cin,s1);
    int frequency[26];
    int hover;
    int maxf;
    for(int i=0; i<s1.size(); i++){
        hover = static_cast<int>(s1[i])-97;
        frequency[hover]+=1;
    }
    for(int i=0; i<26; i++){
        if(frequency[i]>maxf){
            maxf = frequency[i];
        }
    }
    cout<<maxf<<endl;
    return 0;
}
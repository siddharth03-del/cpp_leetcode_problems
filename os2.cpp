#include <iostream>
#include <unistd.h>
using namespace std;
int main(){
    pid_t p = fork();

    if(p < 0){
        cerr << "Focus failed" << endl;
        return -1;
    }
    else if(p == 0){
        cout << "Child processing Id" << getpid() << endl;
    }
    else{
        cout << "Parent Processing ID" << getpid() << endl;
    }
    return 0;
}
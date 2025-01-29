#include <iostream>
#include <unistd.h>
using namespace std;
int main(){
    pid_t p = fork();
    
    if(p < 0){
        cerr << "Fork failed" << endl;
        return -1;
    }
    else{
        cout << "Process PID" << getpid() << endl;
    }
    return 0;
}
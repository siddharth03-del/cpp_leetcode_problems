#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h>
#include <iostream>
using namespace std;
int main(){
    pid_t id = fork();
    if(id < 0){
        cout << "failed" << endl;
    }
    else if(id == 0){
        cout << "From child process" << getpid() << endl;
    }
    else{
        wait(NULL);
        cout << "From parent process" << getpid() << endl;
    }
    return -1;
}
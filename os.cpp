#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;
int main(){
    pid_t p = fork();

    if(p < 0){
        cerr << "Fork failed" << endl;
        return -1;
    }
    else if(p == 0){
        cout << "Child Processing ID =>" << getpid() << "Child is running" << endl;
    }
    else{
        cout << "Parent Processing ID =>" << getpid() << "Waiting for child to finish" << endl;
        wait(NULL);
        cout << "Parent processing ID =>" << getpid() << "Child has finished" << endl;
        
    }
}
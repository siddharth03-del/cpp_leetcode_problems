#include <vector>
using namespace std;
class MinStack{
    public:
    vector<int> stack;
    MinStack(){
        stack = {};
    }
    void push(int val){
        stack.push_back(val);
        int parent = (stack.size() - 2)/2;
        while(parent >= 0){
            if(stack[parent] < stack[stack.size() - 1]){
                int temp = stack[parent];
                stack[parent] = stack[stack.size() - 1];
                stack[stack.size() - 1] = temp;
            }else{
                parent = (parent-1)/2;
            }
        }
    }
    void pop(){
        stack[0] = stack[stack.size() - 1];
        stack.pop_back();
        int index = 0;
        while(index < stack.size()){
            int lc = index*2 + 1;
            int rc = index*2 + 2;
            int maxel = index;
            if(lc < stack.size() && stack[lc] < stack[maxel]){
                maxel = lc;
            }
            if(rc < stack.size() && stack[rc] < stack[maxel]){
                maxel = rc;
            }
            if(maxel == index){
                break;
            }
            else{
                int temp = stack[index];
                stack[index] = stack[maxel];
                stack[maxel] = temp;
                index = maxel;
            }
        }
    }
    int top(){
        return stack[0];
    }
    int getMin(){
        return stack[0];
    }
};
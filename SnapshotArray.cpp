#include <vector>
#include <unordered_map>
using namespace std;
class SnapshotArray {
public:
    int count;
    unordered_map<int , unordered_map<int, int>>changes;
    unordered_map<int, vector<int>>lastChange;
    SnapshotArray(int length) {
        count = 0;
    }
    void set(int index, int val) {
        int futuresnap_id = count;
        changes[futuresnap_id][index] = val;
        vector<int> last = lastChange[index];
        if(!last.empty()){
            int l = last.back();
            if(l != futuresnap_id){
                last.push_back(futuresnap_id);
            }
        }
        else{
            last.push_back(futuresnap_id);
        }
        lastChange[index] = last;
    }
    int snap() {
        count++;
        int currentsnap_id = count-1;
        return currentsnap_id;
    }
    
    int get(int index, int snap_id) {
        int original = 0;
        vector<int> last = lastChange[index];
        for(int i = last.size()-1; i >= 0; i--){
            if(last[i] <= snap_id){
                original = changes[last[i]][index];
                break;
            }
        }
        return original;
    }
};
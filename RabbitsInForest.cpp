#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int total = 0;
        unordered_map<int, int> colors;
        for(int i = 0; i < answers.size(); i++){
            if(colors.find(answers[i]) == colors.end()){
                colors[answers[i]] = 1;
            }else{
                if(colors[answers[i]] >= answers[i] + 1){
                    total += colors[answers[i]];
                    colors[answers[i]] = 1;
                }
                else{
                    colors[answers[i]]++;
                }
            }
        }
        for(const auto& it : colors){
            total += (it.first + 1);
        }
        return total;
    }
};
#include <iostream>
#include <vector>
using namespace std;
class Soution{
    public:
    int maxArea(vector<int>& height){
        int i = 0;
        int j = height.size() -1;
        int maxArea = 0;
        while(i >= j){
            if(height[i] >= height[j]){
                int area = (j - i) * height[j];
                if(area > maxArea) maxArea = area;
                j--;
            }else if(height[i] < height[j]){
                int area = (j - i) * height[i];
                if(area > maxArea) maxArea = area;
                i++;
            }
        }
        return maxArea;
    }
};
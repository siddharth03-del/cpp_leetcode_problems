#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
class Solution{
    public:
    unordered_map<int ,string> roman;
    void fillroman(){
        roman[1]="I";
        roman[5]="V";
        roman[10]="X";
        roman[50]="L";
        roman[100]="C";
        roman[500]="D";
        roman[1000]="M";
        roman[9] = "IX";
        roman[4] = "IV";
        roman[40] = "XL";
        roman[90] = "XC";
        roman[400] = "CD";
        roman[900] = "CM";
    }
    string intToRoman(int num){
        fillroman();
        string ans = "";
        while(num){
            if(num - 1000 >= 0){
                ans += roman[1000];
                num -= 1000;
            }
            else if(num - 900 >= 0){
                ans += roman[900];
                num -= 900;
            }
            else if(num - 500 >= 0){
                ans += roman[500];
                num -= 500;
            }
            else if(num - 400 >= 0){
                ans += roman[400];
                num -= 400;
            }
            else if(num - 100 >= 0){
                ans += roman[100];
                num -= 100;
            }
            else if(num - 90 >= 0){
                ans += roman[90];
                num -= 90;
            }
            else if(num - 50 >= 0){
                ans += roman[50];
                num -= 50;
            }
            else if(num - 40 >= 0){
                ans += roman[40];
                num -= 40;
            }
            else if(num - 10 >= 0){
                ans += roman[10];
                num -= 10;
            }
            else if(num - 9 >= 0){
                ans += roman[9];
                num -= 9;
            }
            else if(num - 5 >= 0){
                ans += roman[5];
                num -= 5;
            }
            else if(num - 4 >= 0){
                ans += roman[4];
                num -= 4;
            }
            else if(num - 1 >= 0){
                ans += roman[1];
                num -= 1;
            }
        }
        return ans;
    }
};
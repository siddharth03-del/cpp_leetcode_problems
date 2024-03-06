#include <iostream>
using namespace std;
int *Merge(int *left, int *right, int leftsize, int rightsize)
{
    int n = leftsize;
    int m = rightsize;
    int *result = new int[m + n];
    int i = 0;
    int j = 0;
    int res = 0;
    while (i < n || j < m)
    {
        if(i==n || j==m){
            if(i==n){
                for(j; j<m; j++){
                    result[res] = right[j];
                    res++;
                }
                
                return result;
            }
            else{
                for(i; i<n; i++){
                    result[res] = left[i];
                    res++;
                }
                
                return result;
            }
        }
        if (left[i] > right[j])
        {
            result[res] = right[j];
            res++;
            j++;
        }
        else if (left[i] < right[j])
        {
            result[res] = left[i];
            i++;
            res++;
        }
        else 
        {
            result[res] = right[j];
            res++;
            result[res] = left[i];
            res++;
            i++;
            j++;
        }
    }
    return result;
}
int *MergeHelper(int *arr, int start, int end)
{
    if (start == end)
    {
        int *result1 = new int[1];
        result1[0] = arr[start];
        return result1;
    }
    else
    {
        int mid = (start + end) / 2;
        int *left = MergeHelper(arr, start, mid);
        int *right = MergeHelper(arr, mid + 1, end);
        return Merge(left, right, mid - start + 1, end - mid);
    }
}

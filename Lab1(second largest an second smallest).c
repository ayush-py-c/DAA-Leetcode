// Write a program to find out the second smallest and second largest
// element stored in an array of n integers.

#include <stdio.h>
#include <limits.h>
int findSecondSmallest(int arr[], int n){
    int first=INT_MAX,second=INT_MAX; //ensures any other no. in the array will be smaller
    for(int i=0;i<n;i++){
        if (arr[i]<first){
            second=first;
            first=arr[i];
        } else if(arr[i]<second&& arr[i]!=first){
            second=arr[i];
        }
        
    }
    return second;
}
int findSecondLargest(int arr[], int n){
    int first=INT_MIN,second=INT_MIN;
    for(int i=0;i<n;i++){
        if (arr[i]>first){
            second=first;
            first=arr[i];
        } else if(arr[i]>second&& arr[i]!=first){
            second=arr[i];
        }
        
    }
    return second;
}
int main(){
    
    int arr[] = {1,2,3,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int secondSmallest = findSecondSmallest(arr, n);
    int secondLargest = findSecondLargest(arr, n);
    printf("Second Largest Element: %d\n", secondLargest);
    printf("Second Smallest Element: %d\n", secondSmallest);
}

// DRY RUN
// array {1, 2, 3, 4}:

// For findSecondSmallest:
// Initial:
// first = INT_MAX, second = INT_MAX

// Loop through each element:

// i=0, arr[0]=1:
// 1 < INT_MAX →
// second = INT_MAX, first = 1
// i=1, arr[1]=2:
// 2 < 1? No
// 2 < INT_MAX and 2 != 1 →
// second = 2
// i=2, arr[2]=3:
// 3 < 1? No
// 3 < 2? No
// i=2, arr[2]=3:
// 3 < 1? No
// 3 < 2? No
// (no change)
// i=3, arr[3]=4:
// 4 < 1? No
// 4 < 2? No
// (no change)
// Result:
// first = 1, second = 2
// Returns: 2
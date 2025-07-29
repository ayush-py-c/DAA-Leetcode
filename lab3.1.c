// 3.1. Write a program using a user-defined function to calculate the factorial of a given number 
// n, where n is taken as input from the user. Before implementing the program, analyze the 
// time complexity of the factorial function using the step count method for at least five 
// different values of n on paper. After completing the analysis, modify the factorial 
// function by introducing a count variable to track the number of computational steps 
// during execution, as discussed in class. This will help in validating the theoretical step 
// count with the actual implementation.
#include <stdio.h>
long int fact(int n);
int count = 0;
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    long int fa = fact(n);
    printf("\n %d! = %ld\n", n, fa);
    printf("No. of steps: %d\n", count);
    return 0;
}
long int fact(int n) {
   count = 0;
    long int f = 1;
    count++;
    count++;
     
    for(int i = 1; i <= n; i++,count++) {
        f *= i;
        count++; 
      }
      count++;
   //  printf("Total steps: %d\n", count);
    return f;
}



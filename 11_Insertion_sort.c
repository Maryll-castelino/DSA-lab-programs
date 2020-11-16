//Name : Maryll Castelino
//Class: 3BTCS B
//Reg no : 1960357
#include<stdio.h>

int main(){
   int i, j, n, temp, num[25];
   
   printf("Enter the number of elements:");
   scanf("%d", &n);

   printf("Enter the numbers:");
   for(i=0; i<n; i++)
      scanf("%d", &num[i]);

   for(i = 1; i < n; i++){
      temp = num[i];
      j = i - 1;
      while((temp < num[j]) && (j >= 0)){
         num[j+1] = num[j];
         j = j - 1;
      }
      num[j+1] = temp;
   }

   printf("Order of Sorted elements: ");
   for(i = 0; i < n - 1; i++)
   {
      printf(" %d",num[i]);
   }
   return 0;
}
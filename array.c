#include <stdio.h>

int main() {
    //declear the array and initialize the array max size = 100
    int arr[100];
     int max=100;
    int n=5;
    //putting 5 elemenmts in the array [1,2,3,4,5]
    for(int i =0;i<=4;i++){
        arr[i]=i+1;
    }
    //printing elements of the array 
    
    printf("\n[");
    for(int j =0; j<=4;j++){
        printf("\t%d", arr[j]);
    }
    printf("\t]");
    
    //inserting elemnt at position here max= 100, maximum number of element is 5 
    //need to insert 10 at position 3
   
    int element = 10;
    int pos =3 ;
    
    if(pos<=max){
     for(int k =n-1; k>=pos-1;k--){
         arr[k+1] = arr[k];
     }   
    arr[pos-1]=element;
    n++;
    //printing updated array
    printf("\n[");
    for(int j =0; j<n;j++){
        printf("\t%d", arr[j]);
    }
    printf("\t]");
    
    }
    else{
        printf("\nSorry!! only %d index are in the array", max);
    }
    
    //deleting element form the array
int del = 3;

if(del<=n){
    
    for(int d = del-1; d<n-1;d++){
        arr[d]=arr[d+1];
    }
    n--;
     //printing updated array
    printf("\n[");
    for(int j =0; j<n;j++){
        printf("\t%d", arr[j]);
    }
    printf("\t]");
    
}

else{
    printf(" Please enter valid input ");
}
    
  //searching element in the array and returning the index 

int e = 3;
int temp = 0;
int pos;
for(int s = 0; s<n ; s++){
    if(arr[s]==e){
        temp++;
        pos = s;
    }
    
}
if(temp!=0){
    printf(" \n The element is found at the index  %d", pos );
}
else {
    printf(" unable to find element");
}  

    
    return 0;
}
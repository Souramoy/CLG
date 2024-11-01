#include <stdio.h>
// declear a stack 
int max = 10;
int top = -1;
int stack[10];

void push(int data){
   if (top !=max-1){
        top ++;
        stack[top]= data;
        printf("\n %d is pushed in the stack ", data);
     
    }
    else {
        printf(" \n stack is full");
    }
     
    
}

void pop(){
if(top!=-1){
printf("\n %d is popped out of the stack",stack[top]);
top--;
}
else {
    printf(" \nnothing in the stack ");
}
}
void display(){
     printf("\n[");
    for(int i =top ;i >=0; i--){
        printf("\t%d",stack[i]);
    }
    printf("\t]");
}

int main() {

pop();
display();

    
    return 0;
}


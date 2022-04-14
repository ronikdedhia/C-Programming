#include <stdio.h>
/*
read an array of integer values and find sum, average, greatest number and lowest number
*/
int main(){
    int i,sum=0;
    int score[7] = {67,55,98,88,90,76,89};
    for(i = 0; i < 7; i++){
        sum = sum + score[i];
    }
    printf("Sum is %d\n",sum);
    printf("Average is %d\n",sum/7);
    int max=score[0];
    for(i = 0; i < 7; i++){
        if(score[i] > max){
            max = score[i];
        }
    }
    printf("Max number is %d\n",max);
    int min=score[0];
    for(i = 0; i < 7; i++){
        if(score[i] < min){
            min=score[i];
        }
    }
    printf("MIn number is %d\n",min);
    return 0;
}

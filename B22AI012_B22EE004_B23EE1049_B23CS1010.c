#include<stdio.h>
#include<math.h>
#include<stdbool.h>

float max(float a,float b,float c){
    float res;
    if(fabs(a) > fabs(b)){
        res = a;
    }
    if(fabs(c) > res){
        res = c;
    }
    return res;
}

float lev(float a[3][3],float y[3][1],float x[3][1]){

    y[0][0] = (a[0][0] * x[0][0]) + (a[0][1] * x[1][0]) + (a[0][2] * x[2][0]);
    y[1][0] = (a[1][0] * x[0][0]) + (a[1][1] * x[1][0]) + (a[1][2] * x[2][0]);
    y[2][0] = (a[2][0] * x[0][0]) + (a[2][1] * x[1][0]) + (a[2][2] * x[2][0]);
    
    
    float l1 = max(y[0][0],y[1][0],y[2][0]);

    for(int i = 0;i<3;i++){
        x[i][0] = y[i][0] / l1;
    }


    while(true){
        y[0][0] = (a[0][0] * x[0][0]) + (a[0][1] * x[1][0]) + (a[0][2] * x[2][0]);
        y[1][0] = (a[1][0] * x[0][0]) + (a[1][1] * x[1][0]) + (a[1][2] * x[2][0]);
        y[2][0] = (a[2][0] * x[0][0]) + (a[2][1] * x[1][0]) + (a[2][2] * x[2][0]);

        float l2 = max(y[0][0],y[1][0],y[2][0]);

        for(int i = 0;i<3;i++){
            x[i][0] = y[i][0] / l2;
        }

        float error = fabs(l2 - l1) / fabs(l2);

        l1 = l2;

        if(error < 0.0001){
            return l1;
        }
        
    }
}

int main(){

    float a[3][3];
    printf("Enter the elements of 3x3 matrix: \n");
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            scanf("%f",&a[i][j]);
        }
    }

    
    float y[3][1];
    float x[3][1] = {{1.0},{1.0},{1.0}};
    
    float largesteigenvalue = lev(a,y,x);

    float sum = (a[0][0] + a[1][1] + a[2][2]) - largesteigenvalue;
    float product = ((a[0][0] * a[1][1] * a[2][2]) - (a[0][0] * a[2][1] * 
    a[1][2]) - (a[0][1] * a[1][0] * a[2][2]) + (a[0][1] * a[2][0] * a[1][2]) + 
    (a[0][2] * a[1][0] * a[2][1]) - (a[0][2] * a[2][0] * a[1][1]))/largesteigenvalue;
    float dis = (sum * sum) - (4 * product);
    float l2 = (sum + sqrt(dis)) / 2;
    float l3 = (sum - sqrt(dis)) / 2;

    printf("The eigen values are : \n%f\n%f\n%f",largesteigenvalue,l2,l3);


    return 0;
}
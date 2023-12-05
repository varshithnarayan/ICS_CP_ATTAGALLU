#include<stdio.h>
#include<math.h>
#include<stdbool.h>
# define n 4

float max(float y[n][1]){
    float res=y[0][0];
    for(int i=0;i<n;i++){
        if(fabs(y[i][0])>fabs(res)){
            res=y[i][0];
        }
    }
    return res;
}

float lev(float a[n][n],float y[n][1],float x[n][1]){

   
    for(int i=0;i<n;i++){
        y[i][0]=0;
        for (int j=0;j<n;j++){
            y[i][0]+=a[i][j]*x[j][0];
        }
    }
    
    float l1 = max(y);

    for(int i = 0;i<n;i++){
        x[i][0] = y[i][0] / l1;
    }

    
    while(true){
          
        for(int i=0;i<n;i++)
        {
            y[i][0]=0;
            for (int j=0;j<n;j++){
                y[i][0]+=a[i][j]*x[j][0];
            }
        }
        float l2 = max(y);

        for(int i = 0;i<n;i++){
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
    
    

    float a[n][n];
    printf("Enter the %d*%d matrix: \n",n,n);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            scanf("%f",&a[i][j]);
        }
    }

    
    float y[n][1];
    float x[n][1];
   
    for (int i=0;i<n;i++){
        x[i][0]=1.0;
    }
    float largesteigenvalue = lev(a,y,x);

   

    printf("The eigen values are : \n%f",largesteigenvalue);


    return 0;
}

#include<stdio.h>

int main(){
    int i,j,s,n,m;
    printf("enter the collums");
    scanf("%d",&n);
    printf("\n enter the rows");
    scanf("%d",&m);
    int arr[n][m];
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("enter the element : ");
            scanf("%d",&arr[i][j]);
        }       
        }  
        printf("the matrix is \n ");
    for(i=0;i<m;i++){
        printf("\n");
        for(j=0;j<n;j++){
            printf("%d \t ",arr[i][j]);
        }
    }
          int z = 0 ,nz = 0 ;
   for(i=0;i<m;i++){
        for(j=0;j<n;j++){ 
    if(arr[i][j]==0){
        z++;
    }
    else{
        nz++;;
    } }} 
    if(z>nz){
        printf("this is a sparse matrix homie");
    } 
    else {
        printf("this is not sparse bb");
    }
    
}

#include <stdio.h> 
#include <stdlib.h> 
 
 void insert_element(int arr[], int n, int element, int position) {
    for (int i = n; i >= position; i--)
        arr[i] = arr[i-1];
    arr[position-1] = element;
}
int main() { 
    int size, *arr; 
    int i, max, min; 
 
    printf("Enter the size of the array: "); 
    scanf("%d", &size); 
 

    arr = (int*) malloc(size * sizeof(int)); 
 
    printf("Enter elements in the array:\n"); 
    for (i = 0; i < size; i++) { 
        scanf("%d", &arr[i]); 
    } 
 
    max = arr[0]; 
    min = arr[0]; 
 
     
    for (i = 1; i < size; i++) { 
        if (arr[i] > max) { 
            max = arr[i]; 
        } 
        if (arr[i] < min) { 
            min = arr[i]; 
        } 
    } 
 
    printf("Maximum element: %d\n", max); 
    printf("Minimum element: %d\n", min); 
 
    int element, position,n;
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            printf("Enter the position: ");
            scanf("%d", &position);
            insert_element(arr, n, element, position);
            n++;
            for(i=0;i<size;i++) {
                printf("%d",arr[i]);
            }
        
    return 0; 
}
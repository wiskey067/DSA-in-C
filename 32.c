//WAP to perform addition of two given sparse matrix in 3–tuple format.
#include<stdio.h>
#include<stdlib.h>
struct element
{
    int row;
    int col;
    int val;
};
struct sparse
{
    int row;
    int col;
    int n;
    struct element *ele;
};
void create(struct sparse *s)
{
    printf("Enter Dimensions:");
    scanf("%d%d",&s->row,&s->col);
    printf("Number of non-zero elements:");
    scanf("%d",&s->n);
    s->ele=(struct element *)malloc(s->n*sizeof(struct element));
    printf("Enter non-zero elements:");
    for(int i=0;i<s->n;i++)
        scanf("%d%d%d",&s->ele[i].row,&s->ele[i].col,&s->ele[i].val);
}
void display(struct sparse s)
{
    int k=0;
    for(int i=0;i<s.row;i++)
    {
        for(int j=0;j<s.col;j++)
        {
            if(i==s.ele[k].row && j==s.ele[k].col)
                printf("%d ",s.ele[k++].val);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
struct sparse * add(struct sparse *s1,struct sparse *s2)
{
    struct sparse *sum;
    sum=(struct sparse *)malloc(sizeof(struct sparse));
    sum->ele=(struct element *)malloc((s1->n+s2->n)*sizeof(struct element));
    int i=0,j=0,k=0;
    while(i<s1->n && j<s2->n)
    {
        if(s1->ele[i].row<s2->ele[j].row)
            sum->ele[k++]=s1->ele[i++];
        else if(s1->ele[i].row>s2->ele[j].row)
            sum->ele[k++]=s2->ele[j++];
        else
        {
            if(s1->ele[i].col<s2->ele[j].col)
                sum->ele[k++]=s1->ele[i++];
            else if(s1->ele[i].col>s2->ele[j].col)
                sum->ele[k++]=s2->ele[j++];
            else
            {
                sum->ele[k]=s1->ele[i];
                sum->ele[k++].val=s1->ele[i++].val+s2->ele[j++].val;
            }
        }
    }
    for(;i<s1->n;i++)sum->ele[k++]=s1->ele[i];
    for(;j<s2->n;j++)sum->ele[k++]=s2->ele[j];
    sum->row=s1->row;
    sum->col=s1->col;
    sum->n=k;

    return sum;
}
int main()
{
struct sparse s1,s2,*s3;

create(&s1);
create(&s2);

printf("First Matrix:\n");
display(s1);
printf("Second Matrix:\n");
display(s2);

s3=add(&s1,&s2);

printf("Resultant Matrix:\n");
display(*s3);

return 0;
}
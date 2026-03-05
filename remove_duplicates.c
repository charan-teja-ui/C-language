
#include <stdio.h>

int main() {
    int a[100],i,j,k,n;
    printf("enter the number of elements:");
    scanf("%d",&n);
    printf("\nenter the elements into an array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nbefore removing the duplicate the array is:");
     for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    int count=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]==a[j])
            {    count+=1;
                for(k=j;k<n-1;k++)
                {
                    a[k]=a[k+1];
                }
                n--;
                j--;
            }
        }
    }
    printf("\narray after removing duplicates:");
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    printf("\n%d number's are dublicated values");

    return 0;

}

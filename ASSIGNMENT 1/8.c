// PROGRAM TO DISPLAY N NUMBER OF ELEMENTS WHILE ALLOCATING MEMORY DYNAMICALLY USING CALLOC()
  #include<stdio.h>  
  #include<stdlib.h>  
 int main(){  
 int n,i,*ptr,sum=0;    
    printf("Enter number of elements: ");    
    scanf("%d",&n);    
    ptr=(int*)calloc(n,sizeof(int));  //memory allocated using calloc    
    if(ptr==NULL)                         
    {    
        printf("Sorry! unable to allocate memory");    
        exit(0);    
    }    
    printf("Enter elements of array: ");    
    for(i=0;i<n;++i)    
    {    
        scanf("%d",ptr+i);    
        sum+=*(ptr+i);    
    }    
    printf("Sum=%d",sum);    
    free(ptr);    
return 0;  
}

//rabin karp string matching
#include<stdio.h>
#include<string.h>
#include<math.h>
#define d 256
void matcher(char* text,char* pattern)
{
    int n=strlen(text);
    int m=strlen(pattern);
    int i,j,p=0,t=0,h=1,q=101;
    for(i=0;i<m-1;i++)
        h=(h*d)%q;
    for(i=0;i<m;i++)
    {
        p=(d*p+pattern[i])%q;
        t=(d*t+text[i])%q;
    }
    for(i=0;i<=n-m;i++)
    {
        if(p==t)
        {
            for(j=0;j<m;j++)
            {
                if(text[i+j]!=pattern[j])
                    break;
            }
            if(j==m)
                printf("Pattern found at index %d\n",i);
        }
        if(i<n-m)
        {
            t=(d*(t-text[i]*h)+text[i+m])%q;
            if(t<0)
                t+=q;
        }
    }
}
void main()
{
    char text[100],pattern[100];
    printf("Enter the text: ");
    scanf("%[^\n]%*c",text);
    printf("Enter the pattern: ");
    scanf("%s",pattern);
    matcher(text,pattern);
}
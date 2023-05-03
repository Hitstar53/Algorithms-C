#include<stdio.h>
//15 puzzle problem using branch and bound
int calculate(int initial[4][4],int goal[4][4])
{
    int count=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(initial[i][j]!=goal[i][j])
            {
                count++;
            }
        }
    }
    return count;
}
int check(int initial[4][4],int goal[4][4])
{
    int flag=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(initial[i][j]!=goal[i][j])
            {
                flag=1;
                break;
            }
        }
    }
    return flag;
}
int main()
{
    int initial[4][4],goal[4][4],temp[4][4];
    printf("Enter the initial state:\n");
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            scanf("%d",&initial[i][j]);
        }
    }
    printf("Enter the goal state:\n");
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            scanf("%d",&goal[i][j]);
        }
    }
    printf("The initial state is:\n");
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d ",initial[i][j]);
        }
        printf("\n");
    }
    printf("The goal state is:\n");
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d ",goal[i][j]);
        }
        printf("\n");
    }
    int count=0;
    while(check(initial,goal))
    {
        int min=calculate(initial,goal);
        int x,y;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(initial[i][j]==0)
                {
                    x=i;
                    y=j;
                    break;
                }
            }
        }
        if(x-1>=0)
        {
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    temp[i][j]=initial[i][j];
                }
            }
            temp[x][y]=temp[x-1][y];
            temp[x-1][y]=0;
            int c=calculate(temp,goal);
            if(c<min)
            {
                min=c;
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<4;j++)
                    {
                        initial[i][j]=temp[i][j];
                    }
                }
            }
        }
        if(x+1<4)
        {
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    temp[i][j]=initial[i][j];
                }
            }
            temp[x][y]=temp[x+1][y];
            temp[x+1][y]=0;
            int c=calculate(temp,goal);
            if(c<min)
            {
                min=c;
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<4;j++)
                    {
                        initial[i][j]=temp[i][j];
                    }
                }
            }
        }
        if(y-1>=0)
        {
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    temp[i][j]=initial[i][j];
                }
            }
            temp[x][y]=temp[x][y-1];
            temp[x][y-1]=0;
            int c=calculate(temp,goal);
            if(c<min)
            {
                min=c;
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<4;j++)
                    {
                        initial[i][j]=temp[i][j];
                    }
                }
            }
        }
        if(y+1<4)
        {
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    temp[i][j]=initial[i][j];
                }
            }
            temp[x][y]=temp[x][y+1];
            temp[x][y+1]=0;
            int c=calculate(temp,goal);
            if(c<min)
            {
                min=c;
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<4;j++)
                    {
                        initial[i][j]=temp[i][j];
                    }
                }
            }
        }
        printf("The state after %d step is:\n",count+1);
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                printf("%d ",initial[i][j]);
            }
            printf("\n");
        }
        count++;
    }
    printf("The number of steps required to reach the goal state is %d\n",count);
    return 0;
}
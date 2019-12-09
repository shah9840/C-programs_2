#include<stdio.h>
#include<stdlib.h>

int n, top=-1, front = -1, rear = -1, a[20], status[20], g[20][20];

/*
1----------not visited 
2----------visited not explored
3-----------start exploring 
*/
void push(int i)
{
    a[++top] = i;
}
void pop()
{
    printf("%d-->", a[top--]);
    
}

void enq(int i)
{
    if(front ==-1)
    {
        front =0;
        rear =0;
    }
    else
    {
        rear++;
    }
    a[rear] = i;
    
}

void deq()
{
    printf("%d-->", a[front]);
    if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
    
}

// use queue for BFS

void bfs(int v)
{
    int i, k;
    for(i=0; i<n; i++)
    {
        status[i] = 1; //not visited
    }
    enq(v);
    status[v] = 2; //visited
    while(front!=-1 && rear!=-1)
    {
        status[a[front]] = 3; // start exploring
        k = a[front];
        deq();
        for(i=0; i<n; i++)
        {
            if(g[k][i]==1 && status[i]==1)
            {
                status[i] = 2; 
                enq(i);
            }
        }
    }

}

void dfs(int v)
{
    int i, k;
    for(i=0; i<n; i++)
    {
        status[i] = 1; //not visited
    }
    push(v);
    status[v] = 2; //visited
    while(top!=-1)
    {
        status[a[top]] = 3; // start exploring
        k = a[top];
        pop();
        for(i=0; i<n; i++)
        {
            if(g[k][i]==1 && status[i]==1)
            {
                status[i] = 2; 
                push(i);
            }
        }
    }

}


void main()
{
    int v,c;
    printf("Enter num of vertices : ");
    scanf("%d", &n);
    printf("Enter %d graph edges in matrix form : ", n*n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%d", &g[i][j]);
        }
    }

    while(1)
    {

        printf("\n1.BFS\n2.DFS\n3.exit\n");
        scanf("%d", &c);
        switch(c)
        {
            case 1: printf("Enter starting vertex : ");
                    scanf("%d", &v);
                    bfs(v);
                    break;
            case 2: dfs(0);
                    break;
            case 3: exit(0);
                    break;
            default: printf("Enter valid input\n");
                    break;
        }
    }

}


























/*
 ============================================================================
 Name        : Bfs.c
 Author      : Raghu
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int q[MAX],front=-1,rear=-1,a[20][20],vis[20];

int delete();
void add(int item);
void bfs(int s,int n);


int main(void) {
	int n,i,s,j;
		char c,dummy;
		printf("ENTER THE NUMBER VERTICES ");
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				//printf("ENTER 1 IF %d HAS A NODE WITH %d ELSE 0 ",i,j);
				scanf("%d",&a[i][j]);
			}
		}
		printf("THE ADJACENCY MATRIX IS\n");
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				printf(" %d",a[i][j]);
			}
			printf("\n");
		}
		for(i=1;i<=n;i++)
			vis[i]=0;

		printf("ENTER THE SOURCE VERTEX :");
		scanf("%d",&s);

		bfs(s,n);
}



void bfs(int v,int n)
{
	int i;
	add(v);
	vis[v]=1;
	while(v!=0)
	{
		for(i=1;i<=n;i++)
		{
			if((a[v][i]!=0)&&(vis[i]==0))
			{
				add(i);
				vis[i]=1;
			}
		}
		v=delete();
		if(v!=0)
			printf(" %d ",v);
	}
	for(i=1;i<=n;i++)
		if(vis[i]==0)
			bfs(i,n);
}
void add(int item)
{
	if(rear==MAX-1)
		printf("QUEUE FULL");
	else
	{
		if(rear==-1)
		{
			q[++rear]=item;
			front++;
		}
		else
			q[++rear]=item;
	}
}
int delete()
		{
	int k;
	if((front>rear)||(front==-1))
		return(0);
	else
	{
		k=q[front++];
		return(k);
	}
		}



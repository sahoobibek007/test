#include<stdio.h>
#include<string.h>
void change(int n,char arr[][8],int i,int j);
void print(int n,char arr[][8]);
void count(int n,char arr[][8]);
void main()
{
	printf("#### REVERSI ####");
	printf("\n\nPlayer1(white) = O\nPlayer2(black) = X\n");
	
	int i,j,k,n=8,mov,ti,tj;
	
	char arr[n][n],ele;
	
	
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			arr[i][j]='n';
		}
	}
	arr[n/2][n/2]='O';
	arr[(n/2)-1][(n/2)-1]='O';
	arr[(n/2)-1][n/2]='X';
	arr[n/2][(n/2)-1]='X';
	
	i=0;
	
	print(n,arr);
	count(n,arr);

	while(i<((n*n)-4))
	{
		if(i%2==0)
		{
			printf("Player1, enter your move(i.e number) : ");
			scanf("%d\n",&mov);
			
			ti=mov/8;
			tj=mov%8;
			while(mov>63 || arr[ti][tj]=='O' || arr[ti][tj]=='X')
			{
				printf("Invalid Move\nPlayer1, enter your move(i.e number) : ");
				scanf("%d\n",&mov);
				ti=mov/8;
				tj=mov%8;
			}
			while(arr[ti-1][tj]=='n' && arr[ti-1][tj+1]=='n' && arr[ti][tj+1]=='n' && arr[ti+1][tj+1]=='n' && arr[ti+1][tj]=='n' && arr[ti+1][tj-1]=='n' && arr[ti][tj-1]=='n' && arr[ti-1][tj-1]=='n')
			{
				printf("Invalid Move(Neighbouring elements only)\nPlayer1, enter your move(i.e number) : ");
				scanf("%d\n",&mov);
				ti=mov/8;
				tj=mov%8;
			}
			arr[ti][tj]='O';
		}
		else if(i%2!=0)
		{
			printf("Player2, enter your move(i.e number) : ");
			scanf("%d\n",&mov);
			while(mov>63 || arr[ti][tj]=='O' || arr[ti][tj]=='X')
			{
				printf("Invalid Move\nPlayer2, enter your move(i.e number) : ");
				scanf("%d\n",&mov);
				ti=mov/8;
				tj=mov%8;
			}
			while(arr[ti-1][tj]=='n' && arr[ti-1][tj+1]=='n' && arr[ti][tj+1]=='n' && arr[ti+1][tj+1]=='n' && arr[ti+1][tj]=='n' && arr[ti+1][tj-1]=='n' && arr[ti][tj-1]=='n' && arr[ti-1][tj-1]=='n')
			{
				printf("Invalid Move(Neighbouring elements only)\nPlayer2, enter your move(i.e number) : ");
				scanf("%d\n",&mov);
				ti=mov/8;
				tj=mov%8;
			}
			ti=mov/8;
			tj=mov%8;
			arr[ti][tj]='X';
		}
		
		change(n,arr,ti,tj);
		print(n,arr);
		count(n,arr);
		i++;
	}
}
void change(int n,char arr[][8],int i,int j)
{
	int x,y,z;
	char ele;
	ele=arr[i][j];
	if(ele=='X')
	{
		x=i-1;y=j;
		while(arr[x][y]=='O')
			x--;
		if(arr[x][y]=='X')
		{
			while(x!=i)
			{
				arr[x][y]='X';
				x++;
			}
		}
		
		x=i-1;y=j+1;
		while(arr[x][y]=='O')
		{
			x--;
			y++;
		}
		if(arr[x][y]=='X')
		{
			while(x!=i && y!=j)
			{
				arr[x][y]='X';
				x++;
				y--;
			}
		}
		
		x=i;y=j+1;
		while(arr[x][y]=='O')
		{
			y++;
		}
		if(arr[x][y]=='X')
		{
			while(y!=j)
			{
				arr[x][y]='X';
				y--;
			}
		}
		
		x=i+1;y=j+1;
		while(arr[x][y]=='O')
		{
			x++;
			y++;
		}
		if(arr[x][y]=='X')
		{
			while(x!=i && y!=j)
			{
				arr[x][y]='X';
				x--;
				y--;
			}
		}
		
		x=i+1;y=j;
		while(arr[x][y]=='O')
		{
			x++;
		}
		if(arr[x][y]=='X')
		{
			while(x!=i)
			{
				arr[x][y]='X';
				x--;
			}
		}
		
		x=i+1;y=j-1;
		while(arr[x][y]=='O')
		{
			x++;
			y--;
		}
		if(arr[x][y]=='X')
		{
			while(x!=i && y!=j)
			{
				arr[x][y]='X';
				x--;
				y++;
			}
		}
		
		x=i;y=j-1;
		while(arr[x][y]=='O')
		{
			y--;
		}
		if(arr[x][y]=='X')
		{
			while(y!=j)
			{
				arr[x][y]='X';
				y++;
			}
		}
		
		x=i-1;y=j-1;
		while(arr[x][y]=='O')
		{
			x--;
			y--;
		}
		if(arr[x][y]=='X')
		{
			while(x!=i && y!=j)
			{
				arr[x][y]='X';
				x++;
				y++;
			}
		}
	}
	else
	{
		x=i-1;y=j;
		while(arr[x][y]=='X')
			x--;
		if(arr[x][y]=='O')
		{
			while(x!=i)
			{
				arr[x][y]='O';
				x++;
			}
		}
		
		x=i-1;y=j+1;
		while(arr[x][y]=='X')
		{
			x--;
			y++;
		}
		if(arr[x][y]=='O')
		{
			while(x!=i && y!=j)
			{
				arr[x][y]='O';
				x++;
				y--;
			}
		}
		
		x=i;y=j+1;
		while(arr[x][y]=='X')
		{
			y++;
		}
		if(arr[x][y]=='O')
		{
			while(y!=j)
			{
				arr[x][y]='O';
				y--;
			}
		}
		
		x=i+1;y=j+1;
		while(arr[x][y]=='X')
		{
			x++;
			y++;
		}
		if(arr[x][y]=='O')
		{
			while(x!=i && y!=j)
			{
				arr[x][y]='O';
				x--;
				y--;
			}
		}
		
		x=i+1;y=j;
		while(arr[x][y]=='X')
		{
			x++;
		}
		if(arr[x][y]=='O')
		{
			while(x!=i)
			{
				arr[x][y]='O';
				x--;
			}
		}
		
		x=i+1;y=j-1;
		while(arr[x][y]=='X')
		{
			x++;
			y--;
		}
		if(arr[x][y]=='O')
		{
			while(x!=i && y!=j)
			{
				arr[x][y]='O';
				x--;
				y++;
			}
		}
		
		x=i;y=j-1;
		while(arr[x][y]=='X')
		{
			y--;
		}
		if(arr[x][y]=='O')
		{
			while(y!=j)
			{
				arr[x][y]='O';
				y++;
			}
		}
		
		x=i-1;y=j-1;
		while(arr[x][y]=='X')
		{
			x--;
			y--;
		}
		if(arr[x][y]=='O')
		{
			while(x!=i && y!=j)
			{
				arr[x][y]='O';
				x++;
				y++;
			}
		}
	}
	
}
void count(int n,char arr[][8])
{
	int i,j,countb=0,countw=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(arr[i][j]=='O')
				countw++;
			else if(arr[i][j]=='X')
				countb++;
		}
	}
	printf("\nPlayer1(white)= %d\nPlayer2(black)= %d\n",countw,countb);
}
void print(int n,char arr[][8])
{
	int i,j,k;
	printf("\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			k=(i*n)+j;
			if(arr[i][j]=='n' && k<10)
				printf("%d  ",k);
			else if(arr[i][j]=='n')
				printf("%d ",k);
			else
				printf("%c  ",arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

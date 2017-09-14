#include<stdio.h>
#include<stdlib.h>

int i=0,j=0;
typedef struct
{
	int mem[10][10];
}new;
new set;

int display(new set)
	{
		int cell(int blockvalue,int cellvalue)
		{
			int i=0;
			{
				for(i=(1+((cellvalue-1)*3));i<=(3*cellvalue);i++)
				{
					printf(" %d ",set.mem[blockvalue][i]);
				}
				if(cellvalue%3!=0)
				{
					printf(" | ");
				}
			}
		}
		int blocklayer(int gridvalue)
		{
			for(i=(1+((gridvalue-1)*3));i<=(3*gridvalue);i++)
			{
				for(j=1;j<=3;j++)
				{
					//printf("%d %d |",i,j);
					cell(i,j);
				}
				printf("\n");
			}
		}
		int delete()
		{
			system("clear");
		}
		int grid()
		{
			delete();
			int i=1;
			printf("\n");
			//blocklayer(1);
			///*
			while(1)
			{
				blocklayer(i);
				if(i==3)
					break;
				printf("_________________________________\n\n");
				i++;
			}
			//*/
			printf("\n");	
		}
		
		printf("\n");
		grid();
	}


void main()
{

/*
	 0, 7, 5, 	0, 9, 0, 	0, 0, 6
 	 0, 2, 3, 	0, 8, 0, 	0, 4, 0
 	 8, 0, 0, 	0, 0, 3, 	0, 0, 1

	 5, 0, 0, 	7, 0, 2, 	0, 0, 0
 	 0, 4, 0, 	8, 0, 6, 	0, 2, 0
	 0, 0, 0, 	9, 0, 1, 	0, 0, 3

	 9, 0, 0, 	4, 0, 0, 	0, 0, 7
	 0, 6, 0, 	0, 7, 0, 	5, 8, 0
	 7, 0, 0, 	0, 1, 0, 	3, 9, 0

*/
/*
set.mem[1][1]=0;  set.mem[1][2]=7;  set.mem[1][3]=5;	set.mem[1][4]=0;  set.mem[1][5]=9;  set.mem[1][6]=0;	set.mem[1][7]=0;  set.mem[1][8]=0;  set.mem[1][9]=6;
set.mem[2][1]=0;  set.mem[2][2]=2;  set.mem[2][3]=3;	set.mem[2][4]=0;  set.mem[2][5]=8;  set.mem[2][6]=0;	set.mem[2][7]=0;  set.mem[2][8]=4;  set.mem[2][9]=0;
set.mem[3][1]=8;  set.mem[3][2]=0;  set.mem[3][3]=0;	set.mem[3][4]=0;  set.mem[3][5]=0;  set.mem[3][6]=3;	set.mem[3][7]=0;  set.mem[3][8]=6;  set.mem[3][9]=1;

set.mem[4][1]=5;  set.mem[4][2]=0;  set.mem[4][3]=0;	set.mem[4][4]=7;  set.mem[4][5]=0;  set.mem[4][6]=2;	set.mem[4][7]=0;  set.mem[4][8]=0;  set.mem[4][9]=0;
set.mem[5][1]=0;  set.mem[5][2]=4;  set.mem[5][3]=0;	set.mem[5][4]=8;  set.mem[5][5]=0;  set.mem[5][6]=6;	set.mem[5][7]=0;  set.mem[5][8]=2;  set.mem[5][9]=0;
set.mem[6][1]=0;  set.mem[6][2]=0;  set.mem[6][3]=0;	set.mem[6][4]=9;  set.mem[6][5]=0;  set.mem[6][6]=1;	set.mem[6][7]=0;  set.mem[6][8]=0;  set.mem[6][9]=3;

set.mem[7][1]=9;  set.mem[7][2]=0;  set.mem[7][3]=0;	set.mem[7][4]=4;  set.mem[7][5]=0;  set.mem[7][6]=0;	set.mem[7][7]=0;  set.mem[7][8]=0;  set.mem[7][9]=7;
set.mem[8][1]=0;  set.mem[8][2]=6;  set.mem[8][3]=0;	set.mem[8][4]=0;  set.mem[8][5]=7;  set.mem[8][6]=0;	set.mem[8][7]=5;  set.mem[8][8]=8;  set.mem[8][9]=0;
set.mem[9][1]=7;  set.mem[9][2]=0;  set.mem[9][3]=0;	set.mem[9][4]=0;  set.mem[9][5]=1;  set.mem[9][6]=0;	set.mem[9][7]=3;  set.mem[9][8]=9;  set.mem[9][9]=0;
*/
	
	int i=0,j=0,k=1;
	
	int data[81][2],count=0;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			if(set.mem[i][j]!=0)
			{
				data[count][0]=i;
				data[count][1]=j;
				count++;
			}
		}
	}
	//STACK
	struct node
        {
                int value;
                struct node* next;
        };
        struct node* head=malloc(sizeof(struct node));
        
        void disp()
	{
		struct node *ptr=malloc(sizeof(struct node));
		ptr=head;
		printf("\n[ ");
		while(ptr->next!='\0')
		{
			printf(" %d  ,",ptr->value);
			ptr=ptr->next;
		}
		printf("\b]");
	}
	
        void push(int v)
        {       
                struct node* new=malloc(sizeof(struct node));
                new->value=v;
                new->next=head;
                head=new;
        }
        
        int pop()
        {
                if(head!=NULL)
                {
                        struct node* temp=malloc(sizeof(struct node));
                        if(head->next!=NULL)
                        {       
                                temp=head;
                                head=temp->next;
                                return(temp->value);
                        }
                        else if(head->next==NULL)
                        {
                                temp=head;
                                head=NULL;
                                return(temp->value);
                        }
                }
                else if(head==NULL)
                {
                        printf("Empty stack!");
                }
                
        }
        
        int size()
        {
                int count=0;
                struct node* temp=malloc(sizeof(struct node));
                temp=head;
                while(temp->next!=NULL)
                {
                        count++;
                        temp=temp->next;
                }
                return count;
        }
        
        int top()
        {
                return head->value;
        }
	//STACK END
	
	/*
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			set.mem[i][j]=k;
			display(set);
			usleep(1000);
		}
	}
		display(set);
	*/
///*
	int checkbox[10][10];
	int checkvalue(int a, int b)
	{
		int x,y,priority;
		if(a<4)
			x=1;
		else if(a>6)
			x=3;
		else
			x=2;
		if(b<4)
			y=1;
		else if(b>6)
			y=3;
		else
			y=2;
		priority=x+(3*(y-1));
		return priority;
	}
	int prevalidate(int a,int b)
	{
		int priority=checkvalue(a,b);
		int i,flag;
		for(i=1;i<=9;i++)
		{
			if(checkbox[priority][i]==set.mem[a][b])
			{
				return 0;
			}
			else if(checkbox[priority][i]!=0)
			{
				checkbox[priority][i]=set.mem[a][b];
				return 1;
			}
		}
	}
	int validate(int a,int b)
	{
		if(prevalidate(a,b)==1)
		{
			int i;
			for(i=1;i<=9;i++)
			{
				if(i!=b)
				{
					if(set.mem[a][b]==set.mem[a][i])//COLUMN
					{
						return 0;
					}
				}
			}
			for(i=1;i<=9;i++)
			{
				if(i!=a)
				{
					if(set.mem[a][b]==set.mem[i][b])//ROW
					{
						return 0;
					}
				}
			}
			return 1;
		}
		else
			return 0;
	}	
	int check(int i,int j)
	{
		int p;
		for(p=0;p<=count;p++)
		{
			if(i==data[p][0]&&j==data[p][1])
				return 0;
		}
		return 1;
	}
	
	int solve(int i,int j)
	{
		if(check(i,j)==1)
		{
			if(set.mem[i][j]!=9)
			{
				set.mem[i][j]++;
			
				display(set);
				//usleep(100000);
				//sleep(1);
			
				if(validate(i,j)==1)
				{
					if(j<9)
					{
						//push(j);
						//push(i);
						j++;
						solve(i,j);
					}
					else if(j=9&&i<9)
					{
						//push(j);
						//push(i);
						i++;
						solve(i,1);
					}
				}
				else
				{
					solve(i,j);
				}
			}
			else if(set.mem[i][j]==9&&validate(i,j)!=0)
			{
				/*if(validate(i,j)==1)
				{
					if(j<9)
					{
						push(j);
						push(i);
						j++;
						solve(i,j);
					}
					else if(j=9&&i<9)
					{
						push(j);
						push(i);
						i++;
						solve(i,1);
					}
				}*/
				//else
				{
					int p,q;
					for(p=i;p<=9;p++)
					{
						for(q=j;q<=9;q++)
						{
							if(check(p,q)==1)
							{
								set.mem[p][q]=0;
							}
						}
					}
					//solve(pop(),pop());
				
					while(1)
					{
						if(j>1)
						{
							j--;
							solve(i,j);
						}
						else if(j=1&&i>1)
						{
							i--;
							solve(i,1);
						}
						if(check(i,j)==1)
						{
							solve(i,j);
							break;
						}
					}
				}
			}
		}
		else
		{
			if(j<9)
			{
				j++;
				solve(i,j);
			}
			else if(j=9&&i<9)
			{
				i++;
				solve(i,1);
			}
		}
	}
	solve(1,1);
	display(set);
}





































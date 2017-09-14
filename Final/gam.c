#include <stdio.h>
#include<stdlib.h>

void push(int);
int pop();
int size();
int top();

int i=0,j=0;

int display(int puzzle[][9])
{
	int cell(int blockvalue,int cellvalue)
	{
		int i=0;
		{
			for(i=(1+((cellvalue-1)*3));i<=(3*cellvalue);i++)
			{
				printf(" %d ",puzzle[blockvalue-1][i-1]);
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
			printf("________________________________\n\n");
			i++;
		}
		//*/
		printf("\n");	
	}
	
	printf("\n");
	grid();
}

struct node
{
	int value;
	struct node* next;
};
struct node* head=NULL;

/*void display()
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
}*/

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


int isAvailable(int puzzle[][9], int row, int col, int num)
{
	int rowStart = (row/3) * 3;
	int colStart = (col/3) * 3;
	int i, j;
	for(i=0; i<9; ++i)
	{
		if (puzzle[row][i] == num)
		{
			return 0;
		}
		if (puzzle[i][col] == num)
		{
			return 0;
		}

		if (puzzle[rowStart + (i%3)][colStart + (i/3)] == num)
		{
			return 0;
		}

	}	
	return 1;
}

int fillSudoku(int puzzle[][9], int row, int col)

{
	display(puzzle);
	usleep(100000);
	int i;
	if(row<9 && col<9)
	{
        	if(puzzle[row][col] != 0)
        	{
			if((col+1)<9)
			{
				fillSudoku(puzzle, row, col+1);
				return;
			}
		else if((row+1)<9)
		{
			fillSudoku(puzzle, row+1, 0);
			return;
		}

		else
		{
			push(1);
			return;
		}
        }
        else
        {

            for(i=0; i<9; ++i)

            {

                if(isAvailable(puzzle, row, col, i+1))

                {

                    puzzle[row][col] = i+1;

                    if((col+1)<9)

                    {
						fillSudoku(puzzle, row, col +1);
                        if(pop())
                        {
                        	push(1);
                        	return;
                    	}

                        else puzzle[row][col] = 0;

                    }

                    else if((row)<8)

                    {
						fillSudoku(puzzle, row+1, 0);
                        if(pop())
                        {
                        	push(1);
                        	return;
                    	}

                        else puzzle[row][col] = 0;

                    }

                    else 
                    {
                    	push(1);
                    	return;
                	}

                }

            }

        }
        push(0);
        return;
    }
    else
    {
    	push(1);
    	return;
    }	
}



int main()

{

    int i, j;

    /*int puzzle[9][9]={{0, 0, 0, 0, 0, 0, 0, 9, 0},

                      {1, 9, 0, 4, 7, 0, 6, 0, 8},

                      {0, 5, 2, 8, 1, 9, 4, 0, 7},

                      {2, 0, 0, 0, 4, 8, 0, 0, 0},

                      {0, 0, 9, 0, 0, 0, 5, 0, 0},

                      {0, 0, 0, 7, 5, 0, 0, 0, 9},

                      {9, 0, 7, 3, 6, 4, 1, 8, 0},

                      {5, 0, 6, 0, 8, 1, 0, 7, 4},

                      {0, 8, 0, 0, 0, 0, 0, 0, 0}};*/
                      
	int puzzle[9][9];
	int s,t;
	char c;
	
	FILE* file;
	file = fopen("data.txt", "r");
	
	for(s=0;s<9;s++)
	{
		for(t=0;t<9;t++)
		{
			c=getc(file);
			puzzle[s][t]=c-'0';
		}
	}
	fclose(file);


	fillSudoku(puzzle, 0, 0);
	
	if(pop())

	{

		display(puzzle);

	}

	else printf("\n\nNO SOLUTION\n\n");



	return 0;

}

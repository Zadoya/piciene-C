
#include <unistd.h>
#include <stdio.h>

typedef struct
{
  int row;
  int column;
}       cell;

int sudoku[9][9] =
 {{9, 0, 0, 0, 7, 0, 0, 0, 0},
	{2, 0, 0, 0, 9, 0, 0, 5, 3},
	{0, 6, 0, 0, 1, 2, 4, 0, 0},
	{8, 4, 0, 0, 0, 1, 0, 9, 0},
	{5, 0, 0, 0, 0, 0, 8, 0, 0},
	{0, 3, 1, 0, 0, 4, 0, 0, 0},
	{0, 0, 3, 7, 0, 0, 6, 8, 0},
	{0, 9, 0, 0, 5, 0, 7, 4, 1},
	{4, 7, 0, 0, 0, 0, 0, 0, 0}};


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_error(void)
{
	write(1, "Error\n", 6);
}
/*
int store_s(int sudoku[9][9], char **argv)
{
  int i;
  int j;

  i = 0;
  while (i < 9)
  {
    j = 0;
    while (j < 9)
    {
      if (argv[i + 1][j] >= '0' && argv[i + 1][j] <= '9')
        sudoku[i][j] = argv [i + 1][j] -'0';
      else if (argv[i + 1][j] == '.')
        sudoku[i][j] = 0;
      else 
          return(0);
      j++;
    }
    i++;
  }
  return(1);
}*/

void print_s(int sudoku[9][9])
{
  int i;
  int j;
  int k;
  
  i = 0;
  while (i < 9)
  {
    j = 0;
    while (j < 9)
    {
      if (sudoku[i][j] == 0)
        ft_putchar('.');
      if (sudoku[i][j] != 0)
        ft_putchar(sudoku[i][j] + '0');
      j++;
    }
    ft_putchar('\n');
    i++;
  }
}

int OdinTor(int argv[9][9], int i, int j)
{
  int l;

  l = 0;
  while (l != 9)
  {
    if (argv[l][j] == argv[i][j] && l != i )
      return (0);
    if (argv[i][l] == argv[i][j] && l != j)
      return (0);
    l++;
  }
  return (1);
}
int square(int argv[9][9], int i, int j)
{
  int line;
  int line2;
  int stolb;
  int stolb2;
  
  line = (i / 3 == 0 ? 0 : i / 3 == 1 ? 3 : 6);
  stolb = (j / 3 == 0 ? 0 : j / 3 == 1 ? 3 : 6);
  line2 = line + 3;
  stolb2 = stolb + 3;
  while (line < line2)
  {
    stolb = (j / 3 == 0 ? 0 : j / 3 == 1 ? 3 : 6);
    while(stolb < stolb2)
    {
      //printf("\n -%d %d- \n", i , j);
      printf("%d",argv[line][stolb]);
      
      if (argv[line][stolb] == argv[i][j] && line != i && stolb != j)
      {
        printf(" .    . \n");
        return (0);
      }
      
      stolb++;
    }
    printf("\n");
    line++;
  }
  return (1);
}

cell next_position(int sudoku[9][9], cell c)
{
  while (c.row < 9)
  {
    while (c.column < 9)
    {
        if (sudoku[c.row][c.column] == 0)
          return(c);
      c.column++;
    }
    c.column = 0;
    c.row++;
  }
  return (c);
}

int backtracking(int sudoku[9][9], cell c)
{
  int k;
  if (c.row >=9 && c.column >= 9)
    return(1);
  k = 0;
  if (sudoku[c.row][c.column] == 0)
    while(k++ < 9)
    {
      sudoku[c.row][c.column] = k;
     //printf("1\n");
      if (OdinTor(sudoku, c.row, c.column) && square(sudoku, c.row, c.column))
      {
        printf("                     2\n");
        if(backtracking(sudoku, next_position(sudoku, c)))
          {
        //   printf("3\n");
            return(1);
          }
      }
      sudoku[c.row][c.column] = 0;
    }
  //  printf("4\n");
    return(0);
}

int main()
{
  cell c;
  c.row = 0;
  c.column = 0;
  //int sudoku[9][9][10] = {{{1,2,3},{4,5,6}},{{7,8,9},{10,11,12}}};
  //store_s(sudoku, argv);
  //next_position(sudoku, c);
  backtracking(sudoku, next_position(sudoku, c));
  print_s(sudoku);
}

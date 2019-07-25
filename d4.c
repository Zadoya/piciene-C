#include <unistd.h>
#include <stdio.h>
#include <time.h>

void fill_cross(int board[2][2], int i, int j) //заполняю все возможные пересечения единицами
{
    int g = 0;
    int gl_diagonal = 2, dr_diagonal = 2;
    gl_diagonal = i - j; //если - то инвертирую и начинаю с j - равной главной и i = 0 и увеличиваю на 1 пока не выйду за границу
    dr_diagonal = (i + j) / 7; //если ниже диагонали, то начинаю с j -р равной другой и i = 7 и уменьшаю на 1 пока не выйду за границу
    while (g != 2) {
        board[i][g] = 1;
        board[g][j] = 1;
    }
    if (i + j > 2) {
        j = dr_diagonal;
        i = 2;
    }
    else {
        j = 2;
        i = dr_diagonal;
    }
    while (((j < 3) && (i < 3)) ||((i > 0) && (j > 0))) {
        board[i][j] = 1;
        j--;
        i--;
    }
    if (gl_diagonal >= 0){
        i = gl_diagonal;
        j = 0;
        
    }
    else{
        j = -1 * gl_diagonal;
        i = 0;
    }
    while ((j < 3) && (i < 3)) {
        board[i][j] = 1;
        j++;
        i++;
    }
}

int check_8(int board[2][2], int i, int j, int kletka)
{
    int g, result = 0;
    
    g = 1;
    board[i][j] = 1;
    fill_cross(board, i, j);
    while (g != 3)
    {
        while ((board[kletka % 3][kletka / 3] != 0) || (kletka =! 9))
            kletka++;
        g++;
        result += check_8(board, (kletka % 3), (kletka / 3) , kletka);
    }
    return result;
}

int queen(void)
{
    int counter = 0;
    int i = 0, j = 0, g = 0;
    int board[2][2];
    
    while (g != 9)
    {
        while (i != 3)
            while (j != 3)
                board[i][j] = 0; //обнуляю массив после того как нашёл комбинацию
        printf("XYI");
        counter += check_8(board, i, j, g); //чек возвращает количество комбинаций если первая королева на клетке g
        g++;
    }
    return counter;
}

int main(void)
{
    clock_t begin, end;
    begin = clock();
    printf ("%d\n", queen());
    end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf ("%f", time_spent);
    return (0);
}

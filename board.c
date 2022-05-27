#include "board.h"
#include <stdio.h>
#include <stdlib.h>

void board_init(board *self, int size)
{
    self->size = size;
    // char m[size * size];
    self->matrix = (char *)malloc(sizeof(char) * (size * size));

    for (int i = 0; i < size * size; i++)
    {
        self->matrix[i] = ' ';
    }
}

void board_destroy(board *self)
{
    free(self->matrix);
    free(self->interface);
}

void board_print(board *self)
{
    char i;
    for (i = 0; i < self->size * self->size; i++)
    {
        printf("_%c_", self->matrix[i]);
        if ((i + 1) % self->size == 0)
        {
            printf("\n");
        }
        else
        {
            printf("|");
        }
    }
}

int board_add(board *self, char c, int x, int y)
{
    int size = self->size;

    if ((y * size + x) >= size * size)
    {
        printf("Invalid position\n");
        return 0;
    }
    else if (self->matrix[y * size + x] != ' ')
    {
        printf("Position already taken\n");
        return 0;
    }
    else
    {
        self->matrix[y * size + x] = c;
        return 1;
    }
}

int board_check_win(board *self, char c)
{
    // check first row
    int good = 1;
    for (int i = 0; i < self->size; i++)
    {
        // printf("i: %d\tchar at: %c\t char curr: %c\n", i, self->matrix[i], c);
        //   break if inconsistent note then check col
        if (self->matrix[i] != c)
        {
            good = 0;
        }
        for (int y = 0; y < self->size; y++)
        {
            // printf("val: %c\t y: %d\n", self->matrix[y * self->size + i], y);

            // if inconsistent break else continue
            if (self->matrix[y * self->size + i] != c)
            {
                break;
            }
            else if (y == self->size - 1)
            {
                return 1;
            }
        }

        //  if end of row report found
        if (i >= self->size - 1 && good)
        {
            return 1;
        }
    }

    // check first column
    for (int i = 0; i < self->size; i++)
    {
        // if inconsistent note then check row
        if (self->matrix[i * self->size] != c)
        {
            good = 0;
        }
        // check row
        for (int x = 0; x < self->size; x++)
        {
            // printf("val: %c\t x: %d\n", self->matrix[i * self->size + x], x);

            if (self->matrix[i * self->size + x] != c)
            {
                break;
            }
            else if (x == (self->size - 1))
            {
                return 1;
            }
        }
        //  if end of column report found
        if (i >= self->size - 1 && good)
        {
            return 1;
        }
    }

    // top left corner diagonal
    for (int d = 0; d < self->size; d++)
    {
        if (self->matrix[d * self->size + d] != c)
        {
            break;
        }
        else if (d == self->size - 1)
        {
            return 1;
        }
    }

    // top right corner diagonal
    for (int d = self->size - 1; d < self->size * self->size; d += (self->size - 1))
    {
        // printf("d: %d\tval: %c\t ex: %c\n", d, self->matrix[d], c);
        if (self->matrix[d] != c)
        {
            break;
        }
        else if (d == self->size * (self->size - 1))
        {
            return 1;
        }
    }

    return 0;
}

board_interface board_i = {
    .init = board_init,
    .destroy = board_destroy,
    .print = board_print,
    .add = board_add,
    .check_win = board_check_win};

board con_board = {
    .interface = &board_i};
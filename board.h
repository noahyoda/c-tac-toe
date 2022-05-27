#pragma once

typedef struct board_ board;

typedef struct board_interface_
{
    void (*init)(board *self, int size);
    void (*destroy)(board *self);
    void (*print)(board *self);
    int (*add)(board *self, char c, int x, int y);
    int (*check_win)(board *self, char c);
    int (*check_draw)(board *self);
} board_interface;

struct board_
{
    int size;
    char *matrix;
    board_interface *interface;
};

extern board con_board;
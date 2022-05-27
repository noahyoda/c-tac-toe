#include "board.h"
#include <stdio.h>
#include <stdlib.h>

void prompt_start(char *player, char *c, char *taken);
void game_loop(board *board_m, board_interface *board_i, char *p1, char *p2, int turn);

int main(int argc, char **argv)
{
    printf("Welcome to tik-tac-toe\n");
    char a;
    char b;
    char *p1 = &a;
    char *p2 = &b;
    char taken = ' ';
    prompt_start("one", p1, &taken);
    // clear newline char for next prompt success
    getchar();
    prompt_start("two", p2, p1);

    if (*p1 == *p2)
    {
        printf("error, that character is already taken!\n");
        prompt_start("one", p2, p1);
    }

    board_interface *b_i = con_board.interface;
    b_i->init(&con_board, 3);

    game_loop(&con_board, b_i, p1, p2, 0);

    // clean up
    // b_i->destroy(&con_board);
}

void game_loop(board *board_m, board_interface *board_i, char *p1, char *p2, int turn)
{
    printf("Current game board:\n");
    board_i->print(board_m);
    char *p_turn;
    char *p_char;
    if (!turn)
    {
        p_turn = "one";
        p_char = p1;
    }
    else
    {
        p_turn = "two";
        p_char = p2;
    }

redo:
    printf("player %s where do you want to move?\nx: ", p_turn);
    int x;
    scanf("%d", &x);
    printf("y: ");
    int y;
    scanf("%d", &y);

    int add = board_i->add(board_m, *p_char, --x, --y);
    if (!add)
        goto redo;

    int win = board_i->check_win(board_m, *p_char);
    if (win)
    {
        board_i->print(board_m);
        printf("Congrats, player %s has won!\n", p_turn);
    }
    else
    {
        turn = ++turn % 2;
        game_loop(board_m, board_i, p1, p2, turn);
    }
}

void prompt_start(char *player, char *choice, char *taken)
{
    printf("Player %s enter your character: ", player);
    char tempA;
    char tempB = *taken;
    scanf("%c", &tempA);

    if (tempA == tempB)
    {
        printf("error, %c is already taken!\n", tempA);
        prompt_start(player, choice, taken);
    }
    else
    {
        *choice = tempA;
    }
}
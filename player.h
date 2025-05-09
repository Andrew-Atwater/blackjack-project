#ifndef PLAYER_H
#define PLAYER_H

typedef struct{
    Card *cards;
    int num_cards;
    int value;
    int has_aces;
} Hand;

#endif
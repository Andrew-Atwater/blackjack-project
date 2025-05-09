#ifndef PLAYER_H
#define PLAYER_H

typedef struct{
    int *cards;
    int num_cards;
    int value;
    int num_aces;
} Hand;

void init_hand(Hand *hand);
void free_hand(Hand *hand);
void print_hand(const char *label, Hand *hand);
void update_value(Hand *hand);

#endif
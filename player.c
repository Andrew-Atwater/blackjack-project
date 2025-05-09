#include <stdio.h>
#include <stdlib.h>
#include <player.h>

void init_hand(Hand *hand){
    hand->cards = malloc(sizeof(int) * 12) //maximum hand size
    hand->num_cards = 0;
    hand->value = 0;
    hand->num_aces = 0;
}

void free_hand(Hand *hand){
    if(hand->cards != NULL){
        free(hand->cards);
        hand->cards = NULL;
    }
    hand->num_cards = 0;
    hand->value = 0;
    hand->num_aces = 0;
}


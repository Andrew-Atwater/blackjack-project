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

void print_hand(const char *label, Hand *hand){
    printf("%s's Hand: ", label);
    for(int i = 0; i < hand->num_cards; i++){
        printf("[%d] ", hand->cards[i]);
    }
    printf("\nHand Total: %d\n", hand->value);
}

void update_value(Hand *hand){
    hand->value = 0;
    hand->num_aces = 0;
    
    for(int i = 0; i < hand->num_cards; i++){
        int current_value = hand->cards[i];
        hand->value += current_value;
        if(current_value == 11){
            hand->num_aces += 1;
        }
    }
    
    for(int i = 0; i < hand->num_cards && hand->value > 21; i++){
        if(hand->cards[i] = 11){
            hand->cards[i] = 1;
            hand->value -= 10;
        }
    }
    
}
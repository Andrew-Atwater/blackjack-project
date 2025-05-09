#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "deck.h"

void init_deck(Deck *deck){
    deck->size = 52;
    deck->index = 0;
    deck->cards = malloc(sizeof(int) * deck->size);

    int position = 0;

    //adding nums 2-9 to deck: 4 each = 32 cards
    for(int value = 2; value <= 9; value++){
        for(int i = 0; i < 4; i++){
            deck->cards[position++] = value;
        }
    }

    //adding all cards valued 10: 4 10's plus 4 each of jack, queen, and king = 16 cards
    for(int i = 0; i < 16; i++){
        deck->cards[position++] = 10;
    }

    //adding aces valued 11: 4 total 32 + 16 + 4 = 52 hooray
    for(int i = 0; i < 4; i++){
        deck->cards[position++] = 11;
    }

    shuffle(deck);
}

void shuffle(Deck *deck){ //uses fisher-yates algorithm (thank you stackoverflow)
    int i, j, temp;
    for(i = deck->size - 1; i > 0; i--){
        j = rand() % (i + 1);
        temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

int draw(Deck *deck){
    return deck->cards[deck->index++];
}

void free_deck(Deck *deck){
    if(deck->cards != NULL){
        free(deck->cards);
        deck->cards = NULL;
    }
    deck->size = 0;
    deck->index = 0;
}
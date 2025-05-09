#ifndef DECK_H
#define DECK_H

typedef struct{
    int *cards;
    int size;
    int index;
} Deck;

void init_deck(Deck *deck);
void shuffle(Deck *deck);
int draw(Deck *deck);
void free_deck(Deck *deck);

#endif
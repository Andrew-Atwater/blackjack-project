#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "deck.h"
#include "player.h"

void play_game();
int play_round();

void log(int round, char *result, int bet, int bal);

#endif
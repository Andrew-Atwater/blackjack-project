#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "deck.h"
#include "player.h"

void play_game();
int play_round();

void log_round(int round, char *result_str, int bet, int bal);

#endif
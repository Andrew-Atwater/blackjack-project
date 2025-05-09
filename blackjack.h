#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "deck.h"
#include "player.h"

void play_game();
void play_round();

int blackjack(Hand *hand);
int bust(Hand *hand);
int compare(Hand *player, Hand *dealer);

void log(const char *result, int bet, int net_change);

#endif
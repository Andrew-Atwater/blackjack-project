#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "player.h"
#include "blackjack.h"

int main(){
    Deck deck;
    Hand player_hand;

    init_deck(&deck);
    init_hand(&player_hand);

    deal_card(&player_hand, draw(&deck));
    deal_card(&player_hand, draw(&deck));

    print_hand("Player", &player_hand);

    free_hand(&player_hand);
    free_deck(&deck);
    
    return 0;
}
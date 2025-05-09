#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "blackjack.h"
#include "player.h"
#include "deck.h"

void play_game() {
    int playing = 1;
    while playing(){
        play_round();
        char choice;
        printf("Play another round? (y/n): \n");
        scanf("%c", &choice);
        if(choice != 'y' && choice != 'Y'){
            playing = 0;
        }
    }
}

void play_round() {
    Deck deck;
    Hand player_hand, dealer_hand;

    init_deck(&deck);
    init_hand(&player_hand);
    init_hand(&dealer_hand);

    deal_card(&player_hand, draw(&deck));
    deal_card(&dealer_hand, draw(&deck));
    deal_card(&player_hand, draw(&deck));
    deal_card(&dealer_hand, draw(&deck));

    print_hand("Player", &player_hand);
    if(dealer_hand.value == 21){
        print_hand("Dealer", &dealer_hand);
        printf("Dealer has blackjack! Dealer wins\n");
        return;
    } else {
        printf("Dealer's Hand: [%d] [??]\n", dealer_hand.cards[0]);
    }

}

int blackjack (Hand *hand){
    //handle blackjack
}

int bust (Hand *hand){
    //handle bust
}

int compare(Hand *hand){
    //handle dealer/player comparison and return accordingly
}

void log(const char *result, int bet, int net_change){
    //handle write out of w/l
    FILE *log = fopen("session-log.txt", "a");
    fclose(log);
}
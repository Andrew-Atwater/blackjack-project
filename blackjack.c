#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "blackjack.h"
#include "player.h"
#include "deck.h"

void play_game() {
    char choice = 'y';
    while(choice == 'y' || choice == 'Y'){
        play_round();
        printf("Play another round? (y/n): ");
        scanf(" %c", &choice);
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
        free_hand(&dealer_hand);
        free_hand(&player_hand);
        free_deck(&deck);
        return;
    } else {
        printf("Dealer's Hand: [%d] [??]\n", dealer_hand.cards[0]);
    }

    //start the actual game
    char choice;
    while(1){
        printf("Hit or stand? (h/s): ");
        scanf(" %c", &choice);

        //hit/stand logic

        if(choice == 'h' || choice == 'H'){
            deal_card(&player_hand, draw(&deck));
            print_hand("Player", &player_hand);

            if(player_hand.value > 21){
                printf("Player busts!\n");
                break;
            }
        } else if(choice == 's' || choice == 'S') {
            break;
        } else {
            printf("Invalid choice. Please enter either 'h' or 's'.\n");
        }
    }

        //Dealer's turn

    if(player_hand.value <= 21){
        print_hand("Dealer", &dealer_hand);
        while(dealer_hand.value < 17){
            deal_card(&dealer_hand, draw(&deck));
            print_hand("Dealer", &dealer_hand);
        }

        if(dealer_hand.value > 21){
            printf("Dealer Busts! You win!\n");
        } else {
            if(player_hand.value > dealer_hand.value){
                print_hand("Player", &player_hand);
                printf("You Win!\n");
            } else if(player_hand.value < dealer_hand.value){
                print_hand("Player", &player_hand);
                printf("Dealer Wins!\n");
            } else {
                print_hand("Player", &player_hand);
                printf("Push.\n");
            }
        }
    }
    free_hand(&player_hand);
    free_hand(&dealer_hand);
    free_deck(&deck);
}

/* void log(const char *result, int bet, int net_change){
    //handle write out of w/l
    FILE *log = fopen("session-log.txt", "a");
    fclose(log);
} */
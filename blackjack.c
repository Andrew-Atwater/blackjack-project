#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "blackjack.h"
#include "player.h"
#include "deck.h"

void play_game() {
    char choice = 'y';
    int bal = 100;
    int bet;
    while((choice == 'y' || choice == 'Y') && bal > 0){
        printf("What would you like your bet to be for this round? Balance: %d\n", bal);
        scanf(" %d", &bet);
        if(bet > bal || bet <= 0) {
            printf("Invalid bet, make sure your bet is less than your balance.\n");
        } else {
            int result = play_round();
            if(result == 1){
                bal += bet;
            } else if(result == -1){
                bal -= bet;
            }
            //log(result);
            if (bal == 0){
                printf("Account empty! Game over. Thanks for playing!\n");
                break;
            }
        }
        printf("Play another round? (y/n): ");
        scanf(" %c", &choice);
    }
    printf("Thanks for playing Blackjack!\n");
}

int play_round() {
    int result = 0; //win = 1, loss = -1, push = 0
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
        result = -1;
        return result;
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
                result = -1;
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
            result = 1;
        } else {
            if(player_hand.value > dealer_hand.value){
                print_hand("Player", &player_hand);
                printf("You Win!\n");
                result = 1;
            } else if(player_hand.value < dealer_hand.value){
                print_hand("Player", &player_hand);
                printf("Dealer Wins!\n");
                result = -1;
            } else {
                print_hand("Player", &player_hand);
                printf("Push.\n");
            }
        }
    }
    free_hand(&player_hand);
    free_hand(&dealer_hand);
    free_deck(&deck);
    return result;
}

/* void log(char result){
    //handle write out of w/l
    FILE *log = fopen("session-log.txt", "a");
    fclose(log);
} */
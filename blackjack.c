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
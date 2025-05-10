#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "deck.h"
#include "player.h"
#include "blackjack.h"

int main(){

    srand(time(NULL));
    play_game();
    
    return 0;
}
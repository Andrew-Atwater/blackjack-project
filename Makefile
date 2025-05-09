blackjack: main.o blackjack.o player.o deck.o
	gcc main.o blackjack.o player.o deck.o -o blackjack

main.o: main.c blackjack.h player.h deck.h
	gcc main.c -c -o main.o

blackjack.o: blackjack.c blackjack.h player.h deck.h
	gcc blackjack.c -c -o blackjack.o

player.o: player.c player.h
	gcc player.c -c -o player.o

deck.o: deck.c deck.h
	gcc deck.c -c -o deck.o

clean:
	rm -f blackjack
	rm -f *.o

run:
	./blackjack
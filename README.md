***playlist***

This program reads song names from a file called playlist.txt, stores them in a singly linked list, 
removes one track, adds a new one, prints the playlist, and then saves the updated list to a file called playlist-out.txt.

Each line in playlist.txt should contain one track name, and each name must be shorter than 60 characters. 

To use the program, place main.c, singly_linked_list.c, singly_linked_list.h, and playlist.txt in the same folder. 

Then compile the program with clang main.c singly_linked_list.c -o playlist and run it with ./playlist. 

The program does not ask for any input while running; it only uses the contents of playlist.txt.

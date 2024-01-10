#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 100

char arr[5][MAX_LENGTH] = {"kesariya\n", "blue bird\n", "tum hi ho\n", "lag ja gale\n", "nasamajh"};
char playlist[5][MAX_LENGTH];
int playlistSize = 0; 

void add() {
    printf("Present songs in the music player:\n");
    for (int i = 0; i < 5; i++) {
        printf(arr[i]);
    }

    printf("\nEnter the name of the song you want to add to the playlist:\n");
    char addSong[MAX_LENGTH];
    scanf(" %[^\n]", addSong);

    int found = 0;
    for (int j = 0; j < 5; j++) {
        if (strncmp(addSong, arr[j], strlen(addSong)) == 0) {
            found = 1;
            printf("%s is found in the player and added to the playlist\n", addSong);

            int alreadyInPlaylist = 0;
            for (int k = 0; k < playlistSize; k++) {
                if (strcmp(addSong, playlist[k]) == 0) {
                    alreadyInPlaylist = 1;
                    break;
                }
            }
            if (!alreadyInPlaylist && playlistSize < 5) {
                strcpy(playlist[playlistSize], addSong);
                playlistSize++;
            }

            break;
        }
    }
    if (!found) {
        printf("Song is not present in the player!\n");
    }
}
void delete() {
    printf("Present songs in the music player:\n");
    for (int i = 0; i < 5; i++) {
        printf(arr[i]);
    }

    if (playlistSize == 0) {
        printf("Playlist is empty. Nothing to delete.\n");
        return;
    }

    printf("Enter the name of the song you want to delete from the playlist:\n");
    char deleteSong[MAX_LENGTH];
    scanf(" %[^\n]", deleteSong);

    int found = 0;
    for (int i = 0; i < playlistSize; i++) {
        if (strcmp(deleteSong, playlist[i]) == 0) {
            found = 1;
            printf("%s is found in the playlist and deleted.\n", deleteSong);
            for (int j = i; j < playlistSize - 1; j++) {
                strcpy(playlist[j], playlist[j + 1]);
            }
            playlistSize--;
            break;
        }
    }

    if (!found) {
        printf("Song is not present in the playlist!\n");
    }
}

void show() {
    printf("Songs present in your playlist are:\n");
    for (int k = 0; k < playlistSize; k++) {
        printf("%s\n", playlist[k]);
    }
}

int main() {
    int ch = 0;

    while (ch != 4) {
        printf("Enter your choice:\n1. Add the song to the playlist\n2. Delete the song from the playlist\n3. Show the playlist\n4. Exit the playlist\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                add();
                break;
            case 2:
                delete();
                break;
            case 3:
                show();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Wrong input! Please try again.\n");
                break;
        }
    }

    return 0;
}
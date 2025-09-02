#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of Song structure
typedef struct Song {
    char title[50];
    char artist[50];
    struct Song* next;
} Song;

// Function prototypes
void addSong(Song** head, char title[], char artist[]);
void deleteSong(Song** head, char title[]);
void displayPlaylist(Song* head);
void playPlaylist(Song* head);
int searchSong(Song* head, char title[]);

// Add a song to the playlist
void addSong(Song** head, char title[], char artist[]) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    strcpy(newSong->title, title);
    strcpy(newSong->artist, artist);
    newSong->next = NULL;

    if (*head == NULL) {
        *head = newSong;
    } else {
        Song* temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newSong;
    }
    printf("Song '%s' by '%s' added.\n", title, artist);
}

// Delete a song by title
void deleteSong(Song** head, char title[]) {
    if (*head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    Song* temp = *head;
    Song* prev = NULL;

    if (strcmp(temp->title, title) == 0) {
        *head = temp->next;
        free(temp);
        printf("Song '%s' deleted.\n", title);
        return;
    }

    while (temp != NULL && strcmp(temp->title, title) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Song '%s' not found.\n", title);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Song '%s' deleted.\n", title);
}

// Display all songs in the playlist
void displayPlaylist(Song* head) {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    printf("\n--- Playlist ---\n");
    Song* temp = head;
    while (temp != NULL) {
        printf("Title: %s | Artist: %s\n", temp->title, temp->artist);
        temp = temp->next;
    }
}

// Simulate playing the playlist
void playPlaylist(Song* head) {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }

    printf("\nPlaying playlist...\n");
    Song* temp = head;
    while (temp != NULL) {
        printf("Now playing: '%s' by '%s'\n", temp->title, temp->artist);
        temp = temp->next;
    }
}

// Search for a song by title
int searchSong(Song* head, char title[]) {
    Song* temp = head;
    int index = 0;
    while (temp != NULL) {
        if (strcmp(temp->title, title) == 0)
            return index;
        temp = temp->next;
        index++;
    }
    return -1; // Not found
}

// Main menu-driven program
int main() {
    Song* head = NULL;
    int choice, pos;
    char title[50], artist[50];

    while (1) {
        printf("\n--- Music Playlist Menu ---\n");
        printf("1. Add a song\n2. Delete a song\n3. Display playlist\n4. Play playlist\n5. Search a song\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter song title: ");
                fgets(title, 50, stdin);
                title[strcspn(title, "\n")] = 0; // remove newline
                printf("Enter artist name: ");
                fgets(artist, 50, stdin);
                artist[strcspn(artist, "\n")] = 0;
                addSong(&head, title, artist);
                break;
            case 2:
                printf("Enter song title to delete: ");
                fgets(title, 50, stdin);
                title[strcspn(title, "\n")] = 0;
                deleteSong(&head, title);
                break;
            case 3:
                displayPlaylist(head);
                break;
            case 4:
                playPlaylist(head);
                break;
            case 5:
                printf("Enter song title to search: ");
                fgets(title, 50, stdin);
                title[strcspn(title, "\n")] = 0;
                pos = searchSong(head, title);
                if (pos != -1)
                    printf("Song '%s' found at position %d.\n", title, pos);
                else
                    printf("Song '%s' not found.\n", title);
                break;
            case 6:
                printf("Exiting program.\n");
                while (head != NULL) { // free memory
                    Song* temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}

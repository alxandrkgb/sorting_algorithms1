#include <stdlib.h>
#include <string.h>
#include "deck.h"

int compare_cards(const void *a, const void *b)
{
    const card_t *card_a = *(const card_t **)a;
    const card_t *card_b = *(const card_t **)b;

    if (card_a->kind != card_b->kind)
        return card_a->kind - card_b->kind;
    else
        return strcmp(card_a->value, card_b->value);
}

void sort_deck(deck_node_t **deck)
{
    size_t deck_size = 0;
    deck_node_t *current = *deck;

    // Count the number of cards in the deck
    while (current != NULL)
    {
        deck_size++;
        current = current->next;
    }

    // Create an array to store pointers to the cards
    card_t **cards = malloc(deck_size * sizeof(card_t *));
    if (cards == NULL)
    {
        // Handle memory allocation failure
        return;
    }

    // Populate the array with card pointers from the deck
    current = *deck;
    for (size_t i = 0; i < deck_size; i++)
    {
        cards[i] = (card_t *)current->card;
        current = current->next;
    }

    // Sort the array of card pointers
    qsort(cards, deck_size, sizeof(card_t *), compare_cards);

    // Rearrange the deck using the sorted array of card pointers
    current = *deck;
    for (size_t i = 0; i < deck_size; i++)
    {
        current->card = cards[i];
        current = current->next;
    }

    free(cards);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct item
{
    int itemID;
    char itemName[100];
    float price;
    int quantity;
    struct item* next;
}*itemStart = NULL;
struct s_card
{
    int cardID;
    char customerName[100];
    int points;
    int d_dob, m_dob, y_dob;
    int d_trans, m_trans, y_trans;
    char address[100];
    struct s_card* next;
    struct item* itemList;
}*s_cardStart = NULL;
struct s_card* getToCard(int cardId)
{
    struct s_card* card = s_cardStart;
    while (!card)
    {
        if (card->cardID == cardId)
            return card;
        card = card->next;
    }
    return NULL;
}

int isCardIdUnique(int cardId)
{
    struct s_card* card = NULL;
    card = getToCard(cardId);

    if (!card)
    {
        printf("Card ID Exists\n");
        return 0;
    }
    return 1;
}

int isItemIdUnique(int cardId, int itemId)
{
    struct s_card* card = NULL;
    card = getToCard(cardId);

    if (!card)
    {
        printf("Shopping Card not found\n");
        return 0;
    }
    struct item* item = card->itemList;
    while (!item)
    {
        if (item->itemID == itemId)
        {
            printf("Item ID Exists\n");
            return 0;
        }
        item = item->next;
    }
    return 1;
}

void update(char address[], int cardId)
{
    struct s_card* card = getToCard(cardId);
    if (!card)
    {
        printf("Shopping Card not found\n");
        return;
    }
    strcpy(card->address, address);
}

void points(char ch, struct s_card* card, int mrp)
{
    int add = mrp / 100;
    switch (ch)
    {
    case 'g':
        card->points += add;
        break;

    case 'G':
        card->points += (add * 5);
        break;

    case 'E':
        card->points += (add * 10);

    default:
        break;
    }
}
void displayCustomer()
{
    struct s_card* card = s_cardStart;
    while (!card)
    {
        printf("\nCard ID : %d", card->cardID);
        printf("\nCustomer Name : %s", card->customerName);
        printf("\nPoints : %d", card->points);
        printf("\nDate Of Birth : %d/%d/%d", card->d_dob, card->m_dob, card->y_dob);
        printf("\nDate Of Last Transcaction : %d/%d/%d", card->d_trans, card->m_trans, card->y_trans);
        printf("\nAddress : %s", card->address);
        card = card->next;
    }
}
void displayItem(struct s_card* card)
{
    struct item* item = card->itemList;
    while (!item)
    {
        printf("\nItem ID : %d", item->itemID);
        printf("\nItem Name : %s", item->itemName);
        printf("\nPrice : %d", item->price);
        printf("\nQuantity : %d", item->quantity);
        item = item->next;
    }
}
void addNewCustomer(int cardId, char name[], int d_dob, int m_dob, int y_dob, char address[])
{
    if (isCardIdUnique(cardId))
    {
        struct s_card* card = (struct s_card*)malloc(sizeof(struct s_card));
        card->cardID = cardId;
        strcpy(card->address, address);
        strcpy(card->customerName, name);
        card->d_dob = d_dob;
        card->m_dob = m_dob;
        card->y_dob = y_dob;
        card->points = 0;
        card->d_trans = card->m_trans = card->y_trans = 0;

    }
}
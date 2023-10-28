#include <stdio.h>
#include <stdlib.h>
#define T_SIZE 100

struct HashEntry
{
    int key;
    int val;
};

struct HashTable
{
    struct HashEntry *table[T_SIZE];
};

void init(struct HashTable **ht)
{
    for (int i = 0; i < T_SIZE; i++)
        (*ht)->table[i] = NULL;
}

int hash(int key)
{
    return key % T_SIZE; // Modulo hashing
}

void insert(struct HashTable **ht, int key, int val)
{
    int idx = hash(key);
    struct HashEntry *ne = (struct HashEntry *)malloc(sizeof(struct HashEntry));
    ne->key = key;
    ne->val = val;
    (*ht)->table[idx] = ne;
}

int search(struct HashTable **ht, int key)
{
    int idx = hash(key);
    if ((*ht)->table[idx] != NULL && (*ht)->table[idx]->key == key)
        return (*ht)->table[idx]->val;
    else
        return -1; // search unsuccessful
}

int main()
{
    struct HashTable *ht;
    init(&ht);

    insert(&ht, 5, 42);
    insert(&ht, 10, 73);
    insert(&ht, 15, 91);

    int keyToSearch = 10;
    int res = search(&ht, keyToSearch);
    printf("%d", res);

    return 0;
}
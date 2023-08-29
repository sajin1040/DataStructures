#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

struct HashNode 
{
    int key;
    int value;
    int occupied; 
};

struct HashTable 
{
    struct HashNode table[TABLE_SIZE];
};

void initialize(struct HashTable *ht) 
{
    for (int i = 0; i < TABLE_SIZE; i++) 
	{
        ht->table[i].occupied = 0;
    }
}

int hash(int key) 
{
    return key % TABLE_SIZE;
}


void insert(struct HashTable *ht, int key, int value) 
{
    int index = hash(key);

    while (ht->table[index].occupied) 
	{
       
        index = (index + 1) % TABLE_SIZE;
    }

    ht->table[index].key = key;
    ht->table[index].value = value;
    ht->table[index].occupied = 1;
}

int search(struct HashTable *ht, int key) 
{
    int index = hash(key);

    while (ht->table[index].occupied) 
	{
        if (ht->table[index].key == key) 
		{
            return ht->table[index].value; 
        }
        index = (index + 1) % TABLE_SIZE; 
    }

    return -1; 
}

int main() 
{
    struct HashTable ht;
    initialize(&ht);

    insert(&ht, 5, 42);
    insert(&ht, 15, 10);
    insert(&ht, 25, 55);

    int key_to_search = 15;
    int result = search(&ht, key_to_search);

    if (result != -1) 
	{
        printf("Value for key %d is %d\n", key_to_search, result);
    } 
	else 
	{
        printf("Key %d not found in the hash table\n", key_to_search);
    }

    return 0;
}


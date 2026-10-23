#include <stdbool.h>
#include <stdlib.h>

#define BUCKETS 769

typedef struct Node {
    int key;
    struct Node* next;
} Node;

typedef struct {
    Node* buckets[BUCKETS];
} MyHashSet;

MyHashSet* myHashSetCreate() {
    MyHashSet* obj = (MyHashSet*)malloc(sizeof(MyHashSet));
    for (int i = 0; i < BUCKETS; i++) {
        obj->buckets[i] = NULL;
    }
    return obj;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    int idx = key % BUCKETS;
    Node* curr = obj->buckets[idx];
    while (curr) {
        if (curr->key == key) return;
        curr = curr->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = obj->buckets[idx];
    obj->buckets[idx] = newNode;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int idx = key % BUCKETS;
    Node* curr = obj->buckets[idx];
    Node* prev = NULL;

    while (curr) {
        if (curr->key == key) {
            if (prev) {
                prev->next = curr->next;
            } else {
                obj->buckets[idx] = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

bool myHashSetContains(MyHashSet* obj, int key) {
    int idx = key % BUCKETS;
    Node* curr = obj->buckets[idx];
    while (curr) {
        if (curr->key == key) return true;
        curr = curr->next;
    }
    return false;
}

void myHashSetFree(MyHashSet* obj) {
    for (int i = 0; i < BUCKETS; i++) {
        Node* curr = obj->buckets[i];
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(obj);
}
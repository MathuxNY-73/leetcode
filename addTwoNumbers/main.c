#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char* readline();

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

typedef struct LinkedList {
    ListNode* head;
    ListNode* tail;
} LinkedList;

ListNode* create_singly_linked_list_node(int node_data) {
    ListNode* node = malloc(sizeof(ListNode));

    node->val = node_data;
    node->next = NULL;

    return node;
}

void insert_node_into_singly_linked_list(LinkedList** singly_linked_list, int node_data) {
    ListNode* node = create_singly_linked_list_node(node_data);

    if (!(*singly_linked_list)->head) {
        (*singly_linked_list)->head = node;
    } else {
        (*singly_linked_list)->tail->next = node;
    }

    (*singly_linked_list)->tail = node;
}

void print_singly_linked_list(ListNode* node, char* sep, FILE* fptr) {
    while (node) {
        fprintf(fptr, "%d", node->val);

        node = node->next;

        if (node) {
            fprintf(fptr, "%s", sep);
        }
    }
}

void free_singly_linked_list(ListNode* node) {
    while (node) {
        ListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

LinkedList* read_linked_list() {
    LinkedList* llist = malloc(sizeof(LinkedList));
    llist ->head = NULL;
    llist ->tail = NULL;

    char* llist_item_endptr;
    char* llist_item_str = readline();
    char delim[] = " ";
    char* ptr = strtok(llist_item_str, delim);

    while(ptr != NULL)
    {
        int llist_item = strtol(ptr, &llist_item_endptr, 10);
        if (llist_item_endptr == llist_item_str || *llist_item_endptr != '\0') { exit(EXIT_FAILURE); }
        insert_node_into_singly_linked_list(&llist, llist_item);
        ptr = strtok(NULL, delim);
    }

    return llist;
}

ListNode* copyLinkedList(ListNode* l1) {
    if(l1 == NULL)
    {
        return NULL;
    }

    ListNode* head = malloc(sizeof(ListNode));
    head->val = l1->val;
    head->next = NULL;

    ListNode* cur = l1->next;
    ListNode* cur_copy = head;
    while(cur != NULL) {
        ListNode* newNode = malloc(sizeof(ListNode));
        newNode->val = cur->val;
        newNode->next = NULL;

        cur_copy->next = newNode;
        cur_copy = newNode;
        cur = cur->next;
    }

    return head;
}

int addNumber(int* a, int b)
{
    int newVal = (*a + b);
    int ret = floor(newVal / 10.0);
    newVal -= ret * 10;
    *a = newVal;
    return ret;
}

ListNode* addTwoNumber(ListNode* l1, ListNode* l2)
{
    int ret = 0;

    if(l1 == NULL)
    {
        return copyLinkedList(l2);
    }

    ListNode* l1_copy = copyLinkedList(l1);
    ListNode* head = l1_copy;

    ListNode* l1_copy_next = l1_copy;
    ListNode* cur_l2 = l2;
    ListNode* cur_l2_next = cur_l2;
    while(l1_copy_next != NULL && cur_l2_next != NULL)
    {
        l1_copy = l1_copy_next;
        cur_l2 = cur_l2_next;

        ret = addNumber(&l1_copy->val, cur_l2->val + ret);

        l1_copy_next = l1_copy->next;
        cur_l2_next = cur_l2->next;
    }
    if(cur_l2_next != NULL) {
        l1_copy->next = copyLinkedList(cur_l2_next);
        l1_copy_next = l1_copy->next;
    }

    while(l1_copy_next != NULL)
    {
        l1_copy = l1_copy_next;

        ret = addNumber(&l1_copy->val, ret);

        l1_copy_next = l1_copy->next;
    }

    if(ret > 0)
    {
        ListNode* newNode = malloc(sizeof(ListNode));
        newNode->val = 0;
        newNode->next = NULL;
        l1_copy->next = newNode;
        l1_copy = newNode;

        ret = addNumber(&l1_copy->val, ret);
    }

    assert(ret == 0);

    return head;

}

int main(int argc, char* argv[])
{
    FILE* fptr = stdout;

    char* llist_count_endptr;
    char* llist_count_str = readline();
    int llist_count = strtol(llist_count_str, &llist_count_endptr, 10);

    if (llist_count_endptr == llist_count_str || *llist_count_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int i = 0; i < llist_count; ++i) {
        
        LinkedList* llist_a = read_linked_list();
        LinkedList* llist_b = read_linked_list();

        //print_singly_linked_list(llist_a->head, " ", fptr);
        //print_singly_linked_list(llist_b->head, " ", fptr);

        ListNode* llist_head = addTwoNumber(llist_a->head, llist_b->head);

        char *sep = " ";

        print_singly_linked_list(llist_head, sep, fptr);
        fprintf(fptr, "\n");

        free_singly_linked_list(llist_a->head);
        free_singly_linked_list(llist_b->head);
        free_singly_linked_list(llist_head);
    }

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

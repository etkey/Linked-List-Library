/**
 * Basic Linked List Library
 * @file linkedlist.h
 * @author Enes Talha Keleş
 * @date Tuesday 19th December, 2023
 */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
/**
 * @brief Node structure representing a single node in the linked list.
 */
typedef struct node{
	node *next; ///< Pointer to the next node in the list.
	int data; ///< Data stored in the node.
}Node;

/**
 * @brief Prints the elements of the linked list.
 * @param head Pointer to the head of the linked list.
 */
void print_list(Node *head);

/**
 * @brief Frees the memory allocated for the linked list.
 * @param head Pointer to the head of the linked list.
 */
void free_memory(Node *head);

/**
 * @brief Sorts the linked list using the bubble sort algorithm.
 * @param head Pointer to the head of the linked list.
 */
void bubblesort_list(Node *head);

/**
 * @brief Checks if a specific value is present in the linked list.
 * @param head Pointer to the head of the linked list.
 * @param search_value Value to search for in the list.
 * @return True if the value is found, false otherwise.
 */
bool is_value_in_list(Node *head, int search_value);

/**
 * @brief Inserts a new node with the given data at the beginning of the list.
 * @param head Pointer to the head of the linked list.
 * @param insert_data Data to be inserted into the new node.
 * @return Pointer to the new head of the linked list.
 */
Node *insert_at_head(Node *head, int insert_data);

/**
 * @brief Inserts a new node with the given data after the node with the specified data.
 * @param head Pointer to the head of the linked list.
 * @param insert_after_data Data value after which the new node should be inserted.
 * @param data_to_insert Data to be inserted into the new node.
 * @return Pointer to the head of the linked list.
 */
Node *insert_after_data(Node *head, int insert_after_data, int data_to_insert);

/**
 * @brief Inserts a new node with the given data at the end of the list.
 * @param head Pointer to the head of the linked list.
 * @param insert_data Data to be inserted into the new node.
 * @return Pointer to the head of the linked list.
 */
Node *insert_at_tail(Node *head, int insert_data);

/**
 * @brief Deletes the node at the beginning of the list.
 * @param head Pointer to the head of the linked list.
 * @return Pointer to the new head of the linked list.
 */
Node *delete_at_head(Node *head);

/**
 * @brief Deletes the node at the end of the list.
 * @param head Pointer to the head of the linked list.
 * @return Pointer to the head of the linked list.
 */
Node *delete_at_tail(Node *head);

/**
 * @brief Deletes the entire linked list and frees the memory.
 * @param head Pointer to the head of the linked list.
 * @return nullptr (an empty list after deletion).
 */

/**
 * @brief Deletes the entire linked list and frees the memory.
 * @param head Pointer to the head of the linked list.
 * @return nullptr (an empty list after deletion).
 */
Node *delete_list(Node *head);

/**
 * @brief Returns the length of the linked list.
 * @param head Pointer to the head of the linked list.
 * @return Length of the linked list.
 */
int list_length(Node *head);

/**
 * @brief Counts the occurrences of a specific data value in the linked list.
 * @param head Pointer to the head of the linked list.
 * @param search_data Data value to be counted.
 * @return Number of occurrences of the specified data value.
 */
int count_matches(Node *head, int search_data);

/**
 * @brief Replaces all occurrences of a specific data value in the linked list.
 * @param head Pointer to the head of the linked list.
 * @param to_be_replaced_data Data value to be replaced.
 * @param replace_data New data value to replace the existing value.
 */
void replace_matches(Node *head, int to_be_replaced_data, int replace_data);

/**
 * @brief Deletes the first node with the specified data from the linked list.
 * @param head Pointer to the head of the linked list.
 * @param data_to_delete Data value to be deleted from the list.
 * @return Pointer to the head of the linked list.
 */
Node *delete_first_matching_node(Node *head, int data_to_delete);

/**
 * @brief Deletes the node after the node with the specified data.
 * @param head Pointer to the head of the linked list.
 * @param delete_after_data Data value after which the next node should be deleted.
 * @return Pointer to the head of the linked list.
 */
Node *delete_after_data(Node *head, int delete_after_data);

/**
 * @brief Deletes all nodes with the specified data from the linked list.
 * @param head Pointer to the head of the linked list.
 * @param data_to_delete Data value to be deleted from the list.
 * @return Pointer to the head of the linked list.
 */
Node *delete_all_matching_nodes(Node *head, int data_to_delete);

/**
 * @brief Appends the second linked list to the end of the first linked list.
 * @param head1 Pointer to the head of the first linked list.
 * @param head2 Pointer to the head of the second linked list.
 * @return Pointer to the head of the combined linked list.
 */
Node *append_list(Node *head1, Node *head2);

/**
 * @brief Adds two linked lists element-wise and returns a new linked list.
 * @param head1 Pointer to the head of the first linked list.
 * @param head2 Pointer to the head of the second linked list.
 * @return Pointer to the head of the resulting linked list.
 */
Node *add_lists(Node *head1, Node *head2);

/**
 * @brief Duplicates the linked list and returns a new linked list.
 * @param head Pointer to the head of the linked list.
 * @return Pointer to the head of the duplicated linked list.
 */
Node *duplicate_list(Node *head);

/**
 * @brief Reverses the order of nodes in the linked list.
 * @param head Pointer to the head of the linked list.
 * @return Pointer to the new head of the reversed linked list.
 */
Node *reverse_list(Node *head);

#endif  

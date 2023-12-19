# Linked List Operations in C++

This C++ project demonstrates basic operations on a singly linked list. The `Node` structure represents individual elements in the linked list, and various functions have been implemented to manipulate and perform operations on the linked list.

## Table of Contents

- [Features](#features)
- [Usage](#usage)
- [Sample Test](#sample-test)

## Features

- **Insertion and Deletion:**
  - `insert_at_head`: Inserts a new node at the head of the linked list.
  - `insert_at_tail`: Inserts a new node at the tail of the linked list.
  - `delete_at_head`: Deletes the node at the head of the linked list.
  - `delete_at_tail`: Deletes the node at the tail of the linked list.
  - `delete_first_matching_node`: Deletes the first node with specific data.
  - `delete_all_matching_nodes`: Deletes all nodes with specific data.

- **List Manipulation:**
  - `append_list`: Appends two linked lists.
  - `add_lists`: Adds two linked lists element-wise and returns a new linked list.
  - `duplicate_list`: Duplicates the linked list and returns a new linked list.

- **Sorting and Searching:**
  - `bubblesort_list`: Sorts the linked list using the bubble sort algorithm.
  - `is_value_in_list`: Checks if a specific value is present in the linked list.

- **Element-wise Operations:**
  - `replace_matches`: Replaces all occurrences of a specific data value in the linked list.
  - `insert_after_data`: Inserts a new node with the given data after the node with the specified data.
  - `delete_after_data`: Deletes the node after the node with the specified data.

- **Information Retrieval:**
  - `print_list`: Prints the elements of the linked list.
  - `list_length`: Returns the length of the linked list.
  - `count_matches`: Counts the occurrences of a specific data value in the linked list.
  - `reverse_list`: Reverses the order of nodes in the linked list.

- **Memory Management:**
  - `free_memory`: Frees the memory allocated for the linked list.
  - `delete_list`: Deletes the entire linked list and frees the memory.

## Usage

To use this project, you can include the `linkedlist.h` header file and use the provided functions in your C++ program. Ensure that you manage memory properly and call the `free_memory` function when needed.

```cpp
#include <iostream>
#include "node.h"

int main() {
    Node *list_head = nullptr;
    Node *list_head2 = nullptr;
	Node *sum_list = nullptr;
    int search_value;
    int insert_data;
    int choice;
    int insert_after;
    int data_to_insert;
    int data_to_delete;
    int delete_after;
    do {
        std::cout << "\nLinked List Operations Menu:\n";
        std::cout << "1. Print List\n";
        std::cout << "2. Free Memory\n";
        std::cout << "3. Bubble Sort List\n";
        std::cout << "4. Is Value in List\n";
        std::cout << "5. Insert at Head\n";
        std::cout << "6. Insert After Data\n";
        std::cout << "7. Insert at Tail\n";
        std::cout << "8. Delete at Head\n";
        std::cout << "9. Delete at Tail\n";
        std::cout << "10. Delete First Matching Node\n";
        std::cout << "11. Delete After Data\n";
        std::cout << "12. Delete All Matching Nodes\n";
        std::cout << "13. Append List\n";
        std::cout << "14. Reverse List\n";
        std::cout << "15. Add Lists\n";
        std::cout << "16. Duplicate List\n";
        std::cout << "0. Exit\n";

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "List 1:\n";
                print_list(list_head);
                std::cout << "List 2:\n";
                print_list(list_head2);
                break;
            case 2:
                free_memory(list_head);
                free_memory(list_head2);
                list_head = nullptr;
                list_head2 = nullptr;
                std::cout << "Memory freed.\n";
                break;
            case 3:
                std::cout << "Sorting List 1:\n";
                bubblesort_list(list_head);
                std::cout << "Sorting List 2:\n";
                bubblesort_list(list_head2);
                std::cout << "Lists sorted.\n";
                break;
            case 4:
                std::cout << "Enter value to search: ";
                std::cin >> search_value;
                std::cout << "Value in List 1: " << is_value_in_list(list_head, search_value) << std::endl;
                std::cout << "Value in List 2: " << is_value_in_list(list_head2, search_value) << std::endl;
                break;
            case 5:
                std::cout << "Enter data to insert at head: ";
                std::cin >> insert_data;
                list_head = insert_at_head(list_head, insert_data);
                break;
            case 6:
                std::cout << "Enter data after which to insert: ";
                std::cin >> insert_after;
                std::cout << "Enter data to insert: ";
                std::cin >> data_to_insert;
                list_head = insert_after_data(list_head, insert_after, data_to_insert);
                break;
            case 7:
                std::cout << "Enter data to insert at tail: ";
                std::cin >> insert_data;
                list_head = insert_at_tail(list_head, insert_data);
                break;
            case 8:
                list_head = delete_at_head(list_head);
                break;
            case 9:
                list_head = delete_at_tail(list_head);
                break;
            case 10:
                std::cout << "Enter data to delete: ";
                std::cin >> data_to_delete;
                list_head = delete_first_matching_node(list_head, data_to_delete);
                break;
            case 11:
                std::cout << "Enter data after which to delete: ";
                std::cin >> delete_after;
                list_head = delete_after_data(list_head, delete_after);
                break;
            case 12:
                std::cout << "Enter data to delete all occurrences: ";
                std::cin >> data_to_delete;
                list_head = delete_all_matching_nodes(list_head, data_to_delete);
                break;
            case 13:
                std::cout << "Appending List 2 to List 1:\n";
                list_head = append_list(list_head, list_head2);
                break;
            case 14:
                std::cout << "Reversing List 1:\n";
                list_head = reverse_list(list_head);
                break;
            case 15:
                std::cout << "Adding Lists:\n";
                sum_list = add_lists(list_head, list_head2);
                std::cout << "Result of addition:\n";
                print_list(sum_list);
                break;
            case 16:
                std::cout << "Duplicating List 1:\n";
                list_head2 = duplicate_list(list_head);
                break;
            case 0:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 0);
    if (sum_list != nullptr) {
        free_memory(sum_list);
    }
    return 0;
}


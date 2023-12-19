#include <iostream>
#include "linkedlist.h"

Node *insert_at_head(Node *head, int insert_data){
	Node *new_node = new Node;
	new_node->data = insert_data;
	if (head == nullptr) return new_node;
	else{
	new_node->next = head;
	return new_node;
	}
}

Node *insert_at_tail(Node *head, int insert_data){
	
	Node *new_node = new Node;
	new_node->data = insert_data;
	if(head == nullptr) return new_node;
	else{
		Node *current = head;
		while(current->next != nullptr){
			current = current->next;
		}
		current->next = new_node;
		return head;
	}

}

Node *delete_at_head(Node *head){
	if(head == nullptr) return nullptr;
	else{
		Node *new_head = head->next;
		delete head;
		return new_head;
	}
}

Node *insert_after_data(Node *head, int insert_after_data, int data_to_insert){
	if(head == nullptr) return nullptr;	
	else{
		Node *current = head;
		while(current != nullptr){
			if(current->data == insert_after_data){
				Node *new_node = new Node;
				new_node->data = data_to_insert;
				new_node->next = current->next;
				current->next = new_node;
			}
			current = current->next;
		}
	}
	return head;
}

Node *delete_at_tail(Node *head){
	if(head == nullptr){
		return nullptr;
	}
	else if (head->next == nullptr){
		delete(head);
		return nullptr;
	}
	Node *current = head;
	Node *previous = nullptr;
	while(current->next != nullptr){
		previous = current;
		current = current->next;
	}
		previous->next = nullptr;
		delete current;
		return head;
}

Node *delete_first_matching_node(Node *head, int data_to_delete){
	if(head == nullptr) return nullptr;
	else{
		Node *current = head;
		Node *previous = nullptr;
		while(current != nullptr){
			if(current->data == data_to_delete){
				if(previous == nullptr){
					head = current->next;
					delete current;
					return head;
				}
				else {
				previous->next = current->next;
				}
				current->next = nullptr;
				delete current;
				return head;
			}
			previous = current;
			current= current->next;
		}
		return head;
	}
}

Node *delete_after_data(Node *head, int delete_after_data){
	if(head == nullptr) return nullptr;
	if(head->next == nullptr) return head;
	Node *current = head;
	while(current->next != nullptr){
		if(current->data == delete_after_data){
			Node *temp = current->next;
			current->next = temp->next;
			current = current->next;
			if(current == nullptr) break;
			delete temp;
		}
		else{
			current = current->next;
		}
	}
	return head;
}

Node *delete_all_matching_nodes(Node *head, int data_to_delete){
	if(head == nullptr) return nullptr;
	Node *current = head;
	Node *temp = nullptr;
	Node *new_head = nullptr;
	while(current->data == data_to_delete){
		temp = current;
		current = current->next;
		delete temp;
		if(current == nullptr) return new_head;
	}
	new_head = current;

	while(current->next != nullptr){
		if(current->next->data == data_to_delete){
			temp = current->next;
			current->next = current->next->next;
			delete(temp);
		}
		else{ 
			current = current->next;
		}
	}
	return new_head;
}

Node *delete_list(Node *head){	
	free_memory(head);
	return nullptr;
}

Node *append_list(Node *head1, Node *head2){
	if(head1 == nullptr && head2 != nullptr) return head2;
	else if(head1 != nullptr && head2 == nullptr) return head1;
	else if(head1 == nullptr && head2 == nullptr) return nullptr;
	else{
		Node *current = head1;
		while(current->next != nullptr){
			current = current->next;
		}
		current->next = head2;
		return head1;
	}
}

Node *reverse_list(Node *head){
	if(head == nullptr) return nullptr;
	if(head->next == nullptr) return head;
	else{
		Node *current = head;
		Node *previous = nullptr; 
		Node *next_node = nullptr;
		while(current != nullptr){
			next_node = current->next;
			current->next = previous;
			previous = current;
			current = next_node;
		}
		head = previous;
		return head;
	}
}

bool is_value_in_list(Node *head, int search_value){
	if (head == nullptr) return false;
	else{
		Node *current = head;
		while(current != nullptr){
			if(current->data == search_value) return true;
			current = current->next;
		}

		return false;
	}
}

void print_list(Node *head){
	int i = 0;
	Node *current = head;
	while(current != nullptr){
		std::cout << "Element " << i <<":" << current->data << std::endl;
		current = current->next;
		i++;
	}
}

void bubblesort_list(Node *head){
	if(head == nullptr) return;
	if(head->next == nullptr ) return;
	bool swapped = false;
	do{
		swapped = false;
		Node *current = head;
		Node *prev = nullptr;
		while(current->next != nullptr){
			prev = current;
			current = current->next;
			if(current != nullptr){
				if(current->data < prev->data){
					int temp;
					temp = prev->data;
					prev->data = current->data;
					current->data = temp;
					swapped = true;
				}
			}
		}
	}while(swapped);
}

int list_length(Node *head){
	int length = 0;
	Node *current = head;
	while(current != NULL){
	length++;
	current = current->next;
	}
	return length;
}

int count_matches(Node *head, int search_data){
	if(head == nullptr) return 0;
	else{
		int counter = 0;
		Node *current = head;
		while(current != nullptr){
			if(current -> data == search_data) counter++;
			current = current->next;
		}
		return counter;
	}
}
Node *add_lists(Node *head1, Node *head2){
	if(head1 == nullptr && head2 == nullptr) return nullptr;
	if(head1 == nullptr) return head2;
	if(head2 == nullptr) return head1;
	Node *result_head = new Node;
	Node *current1 = head1;
	Node *current2 = head2;
	Node *prev = new Node;
	result_head = nullptr;
	prev = nullptr;
	while(current1 != nullptr || current2 != nullptr){
		Node *new_node = new Node;
		int value1 = (current1 != nullptr) ? current1->data : 0;
		int value2 = (current2 != nullptr) ? current2->data : 0;
		new_node->data = value1 + value2;
		new_node->next = nullptr;
		if(result_head == nullptr) result_head = new_node;
		else prev->next = new_node;
		if(current1 != nullptr) current1 = current1->next;
		if(current2 != nullptr) current2 = current2->next;
		prev = new_node;
	}
	return result_head;
}

Node *duplicate_list(Node *head){
	if(head == nullptr) return nullptr;
	Node *current = head;
	Node *dup_head = new Node;
	Node *prev = new Node;
	prev = nullptr;
	dup_head = nullptr;
	while(current != nullptr){
		Node *new_node = new Node;
		new_node->data = current->data;
		new_node->next = nullptr;
		if(dup_head == nullptr) dup_head = new_node;
		else prev->next = new_node;
		prev = new_node;
		current = current->next;
	}
	return dup_head;
}
void replace_matches(Node *head, int to_be_replaced_data, int replace_data){
	Node *current = head;
	while(current != nullptr){
		if(current->data == to_be_replaced_data){
			current->data = replace_data;
		}
		current = current->next;
	}
}	
void free_memory(Node *head){
	while(head != nullptr){
		Node *temp = head;
		head = head->next;
		delete temp;
	}
}

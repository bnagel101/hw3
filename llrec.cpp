#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


//Splits the head linked list into two smaller ones with the smaller being
//nodes with values smaller than pivot and larger being one with nodes
//larger than pivot; uses struct node 
void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot){

	if(head == nullptr){
		smaller = nullptr;
		larger = nullptr;
		return;
	}

	if(head->next == NULL){
		if(head->val <= pivot){
			smaller = head;
			larger = NULL;
		}else{
			larger = head;
			smaller = NULL;
		}
		head = NULL;
	}
	else if(head->val <= pivot){
		smaller = head;
		head = head->next;
		smaller->next = NULL;
		llpivot(head, smaller->next, larger, pivot);
	}
	else if(head->val > pivot){
		larger = head;
		head = head->next;
		larger->next = NULL;
		llpivot(head, smaller, larger->next, pivot);
	}


}


#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);
	//printf("%s", "go for it\n");
	list_t* hmm = head;
	int done = 0;
	if((head->index) > (new_element->index))
	{  
		new_element->next = head;
		head = new_element;
	}
	else
	{
		//printf("%s", "Made it\n");
		while((!done )&& (hmm->next!=NULL))
		{
			//uint32_t b = hmm->index;
			//printf("%u",b);
			if ((hmm->index < new_element->index) && (hmm->next->index>new_element->index))
			{
				new_element->next = hmm->next;
				hmm->next = new_element;
				done = 1;
			}
			else
			{
			
			list_t* a = hmm->next;
			hmm = a;
			}
		
		}
		if(!done)
		{
		hmm->next = new_element;
		new_element->next = NULL;
		}
		//uint32_t b = hmm->index;
			//printf("%u",b);
	
	}
	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	list_t* rv1 = NULL;
	
    	while(head!=NULL)
    	{
    		list_t* temp = rv1; 
    		rv1 = head;
    		head = head->next;
    		rv1->next = temp;
    	}
    	head = rv1;

	return head;
}


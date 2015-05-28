#ifndef __DList_H__
#define __DList_H__

#include <iostream>
#include <assert.h>
#include "Swap.h"

template<class TYPE>
struct  DNode
{
	TYPE data;
	DNode<TYPE>* next;
	DNode<TYPE>* previous;
};

template<class TYPE>
class DList {

private:
	DNode<TYPE>* start;

public:
	DList<TYPE>()
	{
		start = NULL;
	}

	unsigned int Count() const
	{
		unsigned int counter = 0;
		DNode<TYPE>* tmp = start;

		while (tmp != NULL)
		{
			tmp = tmp->next;
			counter++;
		}

		return counter;
	}

	void Add(TYPE new_data)
	{
		DNode<TYPE>* new_node = new DNode<TYPE>;
		new_node->data = new_data;
		new_node->next = NULL;

		if (start != NULL)
		{
			DNode<TYPE>* tmp = start;

			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}
				
			tmp->next = new_node;
			new_node->previous = tmp;
		}

		else
		{
			new_node->previous = NULL;
			start = new_node;
		}
	}

	bool Del(DNode<TYPE>* delete_node)
	{
		if (start != NULL && delete_node != NULL)
		{
			if (start != delete_node)
			{
				DNode<TYPE>* tmp = start;

				while (tmp->next != delete_node)
				{
					tmp = tmp->next;
					if (tmp->next == NULL)
					{
						return false;
					}	
				}

				tmp->next = delete_node->next;

				if (delete_node->next != NULL)
				{
					delete_node->next->previous = tmp;
				}
				else
				{
					tmp->next = NULL;
				}
			}
			else
			{
				if (delete_node->next != NULL)
				{
					start = delete_node->next;
					delete_node->next->previous = NULL;
				}
				else
				{
					start = NULL;
				}
					
			}
			delete delete_node;
			return true;
		}
		return false;
	}

	bool DelList() 
	{
		if (start != NULL)
		{
			while (start->next != NULL)
			{
				DNode<TYPE>* node_to_delete = start;
				start = start->next;
				delete node_to_delete;
			}
			start = NULL;
			return true;
		}
		return false;
	}

<<<<<<< HEAD
	bool IsOnList(const DNode<TYPE> *node_to_check) const
	{
		if (start != NULL && node_to_check != NULL)
		{
			DNode<TYPE> *item = start;
			while (item != NULL)
			{
				if (item->data == node_to_check->data)
				{
					return true;
				}
					
				item = item->next;
			}
		}
		return false;
	}

	int Find(const TYPE& data)
	{
		DNode<TYPE>* tmp = start;
		unsigned int index = 0;

		while (tmp != NULL)
		{
			if (tmp->data == data)
			{
				return (index);
			}

			++index;
			tmp = tmp->next;
		}
		return (-1); //Doesn't exist nodes
	}

=======
>>>>>>> parent of ce86ce9... A
	DNode<TYPE> *getFirst() const
	{
		return start;
	}

	DNode<TYPE> *getLast() const
	{
		if (start != NULL)
		{
			DNode<TYPE>* tmp = start;
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}		
			return tmp;
		}
		return NULL;
	}

	DNode<TYPE>* getNodeAtPos(unsigned int position) const
		{
			if (start != NULL && position < Count())
			{
				unsigned int position_counter = 0;
				DNode<TYPE>* tmp = start;

				while (position_counter != position)
				{
					tmp = tmp->next;
					position_counter++;
				}
				return tmp;
			}
			return NULL;
		}

<<<<<<< HEAD
	unsigned int BubbleSort()
	{
		unsigned int counter;
		unsigned int counter_cmp = 0;

		do
		{
			DNode<TYPE>* item = start;
			counter = 0;
			while (item != NULL && item->next != NULL)
			{
				counter_cmp++;
				if (item->data > item->next->data)
				{
					Swap(item->data, item->next->data);
					counter++;
				}
			 item = item->next;
			}	
			
		} while (counter != 0);

	 return counter_cmp;
	}

	unsigned int BubbleSortPointer()
	{
		unsigned int counter;
		unsigned int counter_cmp = 0;

		do
		{
			DNode<TYPE>* item = start;
			counter = 0;
			while (item != NULL && item->next != NULL)
			{
				counter_cmp++;
				if (item->data > item->next->data)
				{
					SwapPoint(item, item->next;
					counter++;
				}
				item = item->next;
			}

		} while (counter != 0);

		return counter_cmp;
	}

	TYPE& operator[](unsigned int index)
=======
	TYPE& operator [](const unsigned int index)
>>>>>>> parent of e99993e... aa
	{
		unsigned int pos = 0;
		DNode<TYPE>* item = start;

		while (item != NULL)
		{
			if (pos == index)
			{
				break;
			}
		 pos++;
		 item = item->next;
		}
	 return item->data;
	}
};

#endif //__DList_H__
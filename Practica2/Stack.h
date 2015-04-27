#ifndef __Stack_H__
#define __Stack_H__

#include <iostream>
#include <assert.h>

template<class Type>
class Stack
{
public: 

	Type* data;
	unsigned int allocated_memory;
	unsigned int allocated_items;

	Stack() :data(NULL), allocated_memory(0), allocated_items(0) {}

	Stack(unsigned int mem_size) : data(NULL), allocated_items(0) { Reallocate(mem_size); }

	~Stack(){ if (data != NULL) delete[] data; }

	Type Peek(unsigned int position) const
	{
		assert(position < allocated_items);
		return data[position];
	}

	void Reallocate(unsigned int new_memory_size)
	{
		if (data != NULL)
		{
			Type* tmp = new Type[allocated_memory];

			for (unsigned int i = 0; i < allocated_items; i++)
			{
				tmp[i] = data[i];
			}

			delete[] data;
			allocated_memory = new_memory_size;
			data = new Type[allocated_memory];

			for (unsigned int i = 0; i < allocated_items; i++)
			{
				data[i] = tmp[i];
			}
		}
		else
		{
			delete data;
			allocated_memory = new_memory_size;
			data = new Type[allocated_memory];
		}
	}

	void Push(Type value)
	{
		if (data != NULL)
		{
			if (allocated_memory <= allocated_items)
			{
				Reallocate(allocated_memory + 1);
			}
			data[allocated_items] = value;
			allocated_items++;
		}
		else
		{
			Reallocate(1);
			data[allocated_items] = value;
			allocated_items++;
		}
	}

	bool Pop(Type& result)
	{
		if (allocated_items > 0)
		{
			result = data[--allocated_items];
			return true;
		}
		return false;
	}

};
#endif // __Stack_H__



#ifndef __Tree_H__
#define __Tree_H__

#include "DList.h"
#include "Stack.h"

//Class TreeNodes from Tree class
template<class TreeData>
class TreeNode
{

public:

	TreeData data;
	TreeNode* parent;
	DList<TreeNode*> children;

public:

	TreeNode(const TreeData& new_data)
	{
		data = new_data;
		parent = NULL;
	}

	void AddChild(TreeNode* node)
	{
		children.Add(node);
		node->parent = this;
	}

	bool RemoveChild(TreeNode* node)
	{
		bool ret = false;
		DNode<TreeNode*>* item = children.getFirst();

		for (; item != NULL; item = item->next)
		{
			TreeNode* son = item->data;

			if (node == son)
			{
				children.Del(item);
				node->parent = NULL;
				ret = true;
				break;
			}
		}

	return ret;
	}

	void PreOrderRecursive(DList<TreeNode<TreeData>*>* list)
	{
		list->Add(this);

		DNode<TreeNode*>* item = children.getFirst();

		for (; item != NULL; item = item->next)
		{
			item->data->PreOrderRecursive(list);
		}
			
	}

	void PostOrderRecursive(DList<TreeNode<TreeData>*>* list)
	{
		DNode<TreeNode*>* item = children.getFirst();

		for (; item != NULL; item = item->next)
		{
			item->data->PostOrderRecursive(list);
		}
			
		list->Add(this);
	}

	void InOrderRecursive(DList<TreeNode<TreeData>*>* list) //Leave odd TreeNode on right
	{
		DNode<TreeNode*>* item = children.getFirst();
		unsigned int mid = children.Count() / 2;

		for (unsigned int i = 0; i < mid; i++, item = item->next)
		{
			item->data->InOrderRecursive(list);
		}
			
		list->Add(this);

		for (; item != NULL; item = item->next)
		{
			item->data->InOrderRecursive(list);
		}	
	}

	TreeNode<TreeData>* FindRecursive(const TreeData& node) //To find any TreeNode
	{
		if (node == data)
		{
			return this;
		}
			
		TreeNode<TreeData>* result = NULL;
		DNode<TreeNode*>* item = children.getFirst();

		for (; item != NULL; item = item->next)
		{
			TreeNode* son = item->data;
			result = son->FindRecursive(node);

			if (result != NULL)
			{
				break;
			}	
		}
	return result;
	}

	void CollectAll(DList<TreeNode*>* list) //To collect all TreeNodes
	{
		list->Add(this);

		DNode<TreeNode*>* item = children.getFirst();

		for (; item != NULL; item = item->next)
		{
			TreeNode* son = item->data;
			son->CollectAll(list);
		}
	}

	void CollectAllData(DList<TreeData>* list)//To collect all TreeNodes data
	{
		list->Add(data);

		DNode<TreeNode*>* item = children.getFirst();

		for (; item != NULL; item = item->next)
		{
			TreeNode* son = item->data;
			son->CollectAllData(list);
		}
	}

};

//Tree class 
template<class TreeData>
class Tree
{
public:

	TreeNode<TreeData>	root_node;

public:

	Tree(const TreeData& new_data) : root_node(new_data)
	{}

	~Tree()
	{}

	//Recursive methods
	void PreOrderRecursive(DList<TreeNode<TreeData>*>* list)
	{
		root_node.PreOrderRecursive(list);
	}

	void PostOrderRecursive(DList<TreeNode<TreeData>*>* list)
	{
		root_node.PostOrderRecursive(list);
	}

	void InOrderRecursive(DList<TreeNode<TreeData>*>* list)
	{
		root_node.InOrderRecursive(list);
	}

	//Iterative methods
	void PreOrderIterative(DList<TreeNode<TreeData>*>* list)
	{
		Stack<TreeNode<TreeData>*> stack;
		TreeNode<TreeData>* node = &root_node;

		while (node != NULL || stack.Pop(node))
		{
			list->Add(node);
			DNode<TreeNode<TreeData>*>* item = node->children.getLast();

			for (; item != node->children.getFirst(); item = item->previous)
			{
				stack.Push(item->data);
			}
			
			if (item != NULL)
			{
				node = item->data;
			}
			else
			{
				node = NULL;
			}
		}
	}

	void PostOrderIterative(DList<TreeNode<TreeData>*>* list)
	{
		Stack<TreeNode<TreeData>*> stack;
		TreeNode<TreeData>* node = &root_node;

		while (node != NULL || stack.Pop(node))
		{
			DNode<TreeNode<TreeData>*>* item = node->children.getLast();

			if (item != NULL && list->Find(item->data) == -1)
			{
				stack.Push(node);

				for (; item != node->children.getFirst(); item = item->previous)
				{
					stack.Push(item->data);
				}

				node = item->data;
			}
			else
			{
				list->Add(node);
				node = NULL;
			}
		}
	}

	/*void InOrderIterative(DList<TreeNode<TreeData>*>* list)
	{
		Stack<TreeNode<TreeData>*> stack;
		TreeNode<TreeData>* node = &root_node;

		while (node != NULL || stack.Pop(node))
		{
			list->Add(node);
			DNode<TreeNode<TreeData>*>* item = node->children.getLast();

			for (; item != node->children.getFirst(); item = item->previous)
			{
				stack.Push(item->data);
			}

			if (item != NULL)
			{
				node = item->data;
			}
			else
			{
				node = NULL;
			}
		}
	}*/

	void Add(const TreeData& data)
	{
		TreeNode<TreeData>* new_node = new TreeNode<TreeData>(data);
		root_node.AddChild(new_node);
	}

	void Add(const TreeData& data, const TreeData& parent)
	{
		TreeNode<TreeData>* dad = root_node.FindRecursive(parent);
		TreeNode<TreeData>* new_node = new TreeNode<TreeData>(data);
		dad->AddChild(new_node);
	}

	void Clear()
	{
		DList<TreeNode<TreeData>*> nodes_deleted;
		root_node.CollectAll(&nodes_deleted);

		DNode<TreeNode<TreeData>*>* item = nodes_deleted.getFirst();

		for (; item != NULL; item = item->next)
		{
			TreeNode<TreeData>* son = item->data;

			if (son->parent)
			{
				son->parent->RemoveChild(son);
			}	
		}
	}

};

#endif // __Tree_H__
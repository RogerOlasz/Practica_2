#include "stdafx.h"
#include "CppUnitTest.h"

#include "../Practica2/Tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestTree
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TreeAdd)
		{
			Tree<int> tree1(0);

			tree1.Add(1, 0);
			tree1.Add(2, 0);
			tree1.Add(3, 0);

			tree1.Add(5, 1);
			tree1.Add(6, 1);
			tree1.Add(7, 2);

			tree1.Add(8, 7);
			tree1.Add(9, 7);
		}

		//Recursive methods test
		TEST_METHOD(PreOrderRecursive)
		{
			Tree<char> tree1('A');

			tree1.Add('B', 'A');
			tree1.Add('H', 'A');
			tree1.Add('C', 'B');
			tree1.Add('D', 'B');
			tree1.Add('E', 'B');
			tree1.Add('F', 'E');
			tree1.Add('G', 'E');
			tree1.Add('I', 'H');
			tree1.Add('J', 'I');

			DList<TreeNode<char>*> my_tree;
			tree1.PreOrderRecursive(&my_tree);

			Assert::IsTrue(my_tree.Count() == 10);

			//Result must be on alphabet order 
			Assert::IsTrue((char)my_tree[0]->data == 'A');
			Assert::IsTrue((char)my_tree[1]->data == 'B');
			Assert::IsTrue((char)my_tree[2]->data == 'C');
			Assert::IsTrue((char)my_tree[3]->data == 'D');
			Assert::IsTrue((char)my_tree[4]->data == 'E');
			Assert::IsTrue((char)my_tree[5]->data == 'F');
			Assert::IsTrue((char)my_tree[6]->data == 'G');
			Assert::IsTrue((char)my_tree[7]->data == 'H');
			Assert::IsTrue((char)my_tree[8]->data == 'I');
			Assert::IsTrue((char)my_tree[9]->data == 'J');
		}

		TEST_METHOD(PostOrderRecursive)
		{
			Tree<char> tree1('A');

			tree1.Add('B', 'A');
			tree1.Add('H', 'A');
			tree1.Add('C', 'B');
			tree1.Add('D', 'B');
			tree1.Add('E', 'B');
			tree1.Add('F', 'E');
			tree1.Add('G', 'E');
			tree1.Add('I', 'H');
			tree1.Add('J', 'I');

			DList<TreeNode<char>*> my_tree;
			tree1.PostOrderRecursive(&my_tree);

			Assert::IsTrue(my_tree.Count() == 10);

			Assert::IsTrue((char)my_tree[0]->data == 'C');
			Assert::IsTrue((char)my_tree[1]->data == 'D');
			Assert::IsTrue((char)my_tree[2]->data == 'F');
			Assert::IsTrue((char)my_tree[3]->data == 'G');
			Assert::IsTrue((char)my_tree[4]->data == 'E');
			Assert::IsTrue((char)my_tree[5]->data == 'B');
			Assert::IsTrue((char)my_tree[6]->data == 'J');
			Assert::IsTrue((char)my_tree[7]->data == 'I');
			Assert::IsTrue((char)my_tree[8]->data == 'H');
			Assert::IsTrue((char)my_tree[9]->data == 'A');
		}

		TEST_METHOD(InOrderRecursive)
		{
			Tree<char> tree1('A');

			tree1.Add('B', 'A');
			tree1.Add('H', 'A');
			tree1.Add('C', 'B');
			tree1.Add('D', 'B');
			tree1.Add('E', 'B');
			tree1.Add('F', 'E');
			tree1.Add('G', 'E');
			tree1.Add('I', 'H');
			tree1.Add('J', 'I');

			DList<TreeNode<char>*> my_tree;
			tree1.InOrderRecursive(&my_tree);

			Assert::IsTrue(my_tree.Count() == 10);

			Assert::IsTrue((char)my_tree[0]->data == 'C');
			Assert::IsTrue((char)my_tree[1]->data == 'B');
			Assert::IsTrue((char)my_tree[2]->data == 'D');
			Assert::IsTrue((char)my_tree[3]->data == 'F');
			Assert::IsTrue((char)my_tree[4]->data == 'E');
			Assert::IsTrue((char)my_tree[5]->data == 'G');
			Assert::IsTrue((char)my_tree[6]->data == 'A');
			Assert::IsTrue((char)my_tree[7]->data == 'H');
			Assert::IsTrue((char)my_tree[8]->data == 'I');
			Assert::IsTrue((char)my_tree[9]->data == 'J');
		}

		//Iterative methods test
		TEST_METHOD(PreOrderIterative)
		{
			Tree<char> tree1('A');

			tree1.Add('B', 'A');
			tree1.Add('H', 'A');
			tree1.Add('C', 'B');
			tree1.Add('D', 'B');
			tree1.Add('E', 'B');
			tree1.Add('F', 'E');
			tree1.Add('G', 'E');
			tree1.Add('I', 'H');
			tree1.Add('J', 'I');

			DList<TreeNode<char>*> my_tree;
			tree1.PreOrderIterative(&my_tree);

			Assert::IsTrue(my_tree.Count() == 10);

			//Result must be on alphabet order 
			Assert::IsTrue((char)my_tree[0]->data == 'A');
			Assert::IsTrue((char)my_tree[1]->data == 'B');
			Assert::IsTrue((char)my_tree[2]->data == 'C');
			Assert::IsTrue((char)my_tree[3]->data == 'D');
			Assert::IsTrue((char)my_tree[4]->data == 'E');
			Assert::IsTrue((char)my_tree[5]->data == 'F');
			Assert::IsTrue((char)my_tree[6]->data == 'G');
			Assert::IsTrue((char)my_tree[7]->data == 'H');
			Assert::IsTrue((char)my_tree[8]->data == 'I');
			Assert::IsTrue((char)my_tree[9]->data == 'J');
		}

		TEST_METHOD(PostOrderIterative)
		{
			Tree<char> tree1('A');

			tree1.Add('B', 'A');
			tree1.Add('H', 'A');
			tree1.Add('C', 'B');
			tree1.Add('D', 'B');
			tree1.Add('E', 'B');
			tree1.Add('F', 'E');
			tree1.Add('G', 'E');
			tree1.Add('I', 'H');
			tree1.Add('J', 'I');

			DList<TreeNode<char>*> my_tree;
			tree1.PostOrderIterative(&my_tree);

			Assert::IsTrue(my_tree.Count() == 10);

			Assert::IsTrue((char)my_tree[0]->data == 'C');
			Assert::IsTrue((char)my_tree[1]->data == 'D');
			Assert::IsTrue((char)my_tree[2]->data == 'F');
			Assert::IsTrue((char)my_tree[3]->data == 'G');
			Assert::IsTrue((char)my_tree[4]->data == 'E');
			Assert::IsTrue((char)my_tree[5]->data == 'B');
			Assert::IsTrue((char)my_tree[6]->data == 'J');
			Assert::IsTrue((char)my_tree[7]->data == 'I');
			Assert::IsTrue((char)my_tree[8]->data == 'H');
			Assert::IsTrue((char)my_tree[9]->data == 'A');
		}

		/*TEST_METHOD(InOrderIterative)
		{
			Tree<char> tree1('A');

			tree1.Add('B', 'A');
			tree1.Add('H', 'A');
			tree1.Add('C', 'B');
			tree1.Add('D', 'B');
			tree1.Add('E', 'B');
			tree1.Add('F', 'E');
			tree1.Add('G', 'E');
			tree1.Add('I', 'H');
			tree1.Add('J', 'I');

			DList<TreeNode<char>*> my_tree;
			tree1.InOrderIterative(&my_tree);

			Assert::IsTrue(my_tree.Count() == 10);

			Assert::IsTrue((char)my_tree[0]->data == 'A');
			Assert::IsTrue((char)my_tree[1]->data == 'B');
			Assert::IsTrue((char)my_tree[2]->data == 'C');
			Assert::IsTrue((char)my_tree[3]->data == 'D');
			Assert::IsTrue((char)my_tree[4]->data == 'E');
			Assert::IsTrue((char)my_tree[5]->data == 'F');
			Assert::IsTrue((char)my_tree[6]->data == 'G');
			Assert::IsTrue((char)my_tree[7]->data == 'H');
			Assert::IsTrue((char)my_tree[8]->data == 'I');
			Assert::IsTrue((char)my_tree[9]->data == 'J');
		}*/

		TEST_METHOD(TreeClear)
		{
			Tree<int> tree1(0);

			tree1.Add(10, 0);
			tree1.Add(20, 0);
			tree1.Add(30, 0);
			tree1.Add(400, 10);
			tree1.Add(500, 10);
			tree1.Add(600, 10);

			tree1.Clear();

			DList<TreeNode<int>*> list;
			tree1.root_node.CollectAll(&list);

			Assert::AreEqual((int)list.Count(), 1);
		}

	};
}
#include <iostream>
#include <array>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <deque>
#include <algorithm>
#include <string> 
#include <execution>
#include <numeric>
#include <iterator>
#include <unordered_set>


namespace BIGO
{
	int O1(int n)
	{
		return n+n;
	}

	void On(int n)
	{
		for(int i = 0; i<n; ++i)
		{
			std::cout << i << "\n";
		}
	}

	void On2(int n)
	{
		for(int i = 0; i<n; ++i)
		{
			for(int j = 0; j<n; ++j)
			{
				std::cout << i << j << "\n";
			}
		}
	}

	void Ologn(int n)
	{
		//using for searching, far more efficient than O(n), O(n**2) and O(nlong(n))
	}

	void Onlogn()
	{
		//using for sorting: merge sort and quick sort
	}

	void run()
	{
		
	}

}

namespace STL
{
	/*
	* std::list: doubly linked list
	* std::list is a container that support constant time insertions and deletions from anywhere in the list.
	* Its implemented as a doubly linked list, where each element is connected to its previous and next element.
	* Features: 
	 * Dynamic Size: Can grow or shrink in size dynamically.
	 * Bidirectional Iterators: Supports iterators that can traverse the list in both directions.
	 * Efficient Insertions and Deletions: Insertion and deletion of elements are efficient, as they do not require shifting elements.
	*/

	void iterate_with_iterators(const std::list<int>& list)
	{
		for(std::list<int>::const_iterator it=list.cbegin(); it!=list.cend(); ++it)
		{
			std::cout << "element: " << *it << "\n";
		}
		std::cout << "\n-----------------------\n";
	}

	void range_based_iteration(const std::list<int>& list)
	{
		for(const auto& element : list)
		{
			std::cout << "element: " << element << "\n";
		}
		std::cout << "\n-----------------------\n";
	}

	void list()
	{

		/*
		*   1 -> 2 -> 3 -> 4 -> nullptr
		   head           tail

		   * contigous in memeory
		   * Node-metodology: Node has value and next-pointer
		*/

		std::list<int> my_list {1,2,3,4,5};
		my_list.push_back(6);
		my_list.push_front(0);
		iterate_with_iterators(my_list);

		my_list.pop_back();
		my_list.pop_front();
		range_based_iteration(my_list);

		my_list.push_back(5);
		my_list.push_back(5);
		my_list.push_back(5);
		my_list.remove(5);
		iterate_with_iterators(my_list);
		
		// Inserting elements:
		auto it = my_list.begin();
		std::advance(it, 2);  // Move iterator to the 3rd position
		my_list.insert(it, 10); // Inserts 10 before the 3rd element
		iterate_with_iterators(my_list);

		// Sorting and Reversing:
		my_list.sort();
		iterate_with_iterators(my_list); 
		my_list.reverse(); 
		iterate_with_iterators(my_list);
	}
	
    namespace LinkedList{
		class Node
		{
			public:
				int value;
				Node* next;

				Node(int value) : value{value}, next{nullptr}
				{}
		};

		class LinkedList{
			public:
				LinkedList(int value)
				{
					//create new Node
					Node* newNode = new Node(value);
					head = newNode;
					tail = head;
					length = 1;

				}

				~LinkedList()
				{
					Node*  temp = head;
					while(temp)
					{
						head = head->next;
						delete temp;
						temp = head;
					}
				}
				
				void print()
				{
					Node* temp = head;
					while(temp != nullptr)
					{
						std::cout << temp->value << "\n";
						temp = temp->next;
					}
					std::cout << "-------------------\n";
				}

				void append(const int& value)
				{
					//create new Node and Node to end
					Node* newNode = new Node(value);
					if(length == 0)
					{
						head = newNode;
						tail = newNode;
					}
					else{
						tail->next = newNode;
						tail = newNode;
					}
					length++;

				}
				
				void deleteLast()
				{
					if(length == 0)
					{
						return;
					}
					Node* temp = head;
					if(length==1)
					{
						head = nullptr;
						tail = nullptr;
					}
					else
					{
						Node* pre = head;
						while(temp->next != nullptr)
						{
							pre = temp;
							temp = temp->next;
						}
						tail = pre;
						tail->next = nullptr;
					}
					length--;
					delete temp;
				}

				void prepend(int value)
				{
					// create new Node and Node to beginning
					Node* newNode = new Node(value);
					if(length == 0)
					{
						head = newNode;
						tail = newNode;
					}
					else{
						newNode->next = head;
						head = newNode;
					}
					length++;
				}

				void deleteFirst()
				{
					if(length == 0)
					{
						return;
					}

					Node* temp = head;
					if(length == 1)
					{
						head = nullptr;
						tail = nullptr;
					}
					else{
						head = head->next;
						delete temp;
					}

					length--;
				}

				Node* get(const int& index)
				{
					if(index<0 || index>=length)
					{
						return nullptr;
					}
					Node* temp = head;
					for(int i = 0; i<index; ++i)
					{
						temp = temp->next;
					}
					return temp;
				}

				bool set(const int& index, const int& value)
				{ 
					Node* temp = get(index);
					if(temp == nullptr)
					{
						return false;
					}
					temp->value = value;
					return true;
				}

				bool insert(const int& index, const int& value)
				{
					//create new Node and insert this Node to a desireed position
					if(index<0 || index>=length)
					{
						return false;
					}
					if(index == 0)
					{
						prepend(value);
						return true;
					}
					else if(index == length)
					{
						append(value);
						return true;
					}
					Node* newNode = new Node(value);
					Node* temp = get(index-1);

					newNode->next = temp->next;
					temp->next = newNode;

					length++;

					return true;
				}

				bool deleteNode(const int& index)
				{
					std::cout << "len: " << length << "\n";
					if(index<0 || index>= length)
					{
						return false;
					}
					if(index == 0)
					{
						deleteFirst();
					}
					else if(index == length-1)
					{
						deleteLast();
					}
					
					Node* temp = get(index-1);
					Node* to_delete = get(index);
					std::cout << "to delete value: " << to_delete->value << "\n";
					to_delete = nullptr;
					temp->next = temp->next->next;
					delete to_delete;
					length--;
				}

				void reverse()
				{
					Node* temp = head;
					head = tail;
					tail = temp;
					Node* after = temp->next;
					Node* before = nullptr;
					for(int i=0;i<length;++i)
					{
						after = temp->next;
						temp->next = before;
						before = temp;
						temp = after;
					}
				}

				void removeDuplicates() {
					std::unordered_set<int> values;
					Node* prev = nullptr;
					Node* current = head;
					while (current != nullptr)
					{
						auto res = values.insert(current->value);
						if(!res.second)
						{
							prev->next = current->next;
							delete current;
							current = prev->next;
							length--;
						}
						else{
							prev = current;
							current = current->next;
						}
					}
				}


			private:
				Node* head{nullptr};
				Node* tail{nullptr};
				int length{0};
		};


	}

	namespace DoublyLinkedList
	{
		class Node{
			public: 
				int value;
				Node* next;
				Node* prev;

				Node(int value) : value{value}, next{nullptr}, prev{nullptr}
				{}
				
		};

		class DoublyLinkedList{
			private:
				Node* head;
				Node* tail;
				int length;
			
			public:
				DoublyLinkedList(int value)
				{
					Node* newNode = new Node(value);
					head = newNode;
					head->prev == nullptr;
					tail = newNode;
					tail->next = nullptr;
					length = 1;
				}

				void printList()
				{
					Node* temp = head;
					while(temp)
					{
						std::cout << temp->value << "\n";
						temp = temp->next;
					}
					std::cout << "----------------------------------\n";
				}

				void append(int value)
				{
					Node* newNode = new Node(value);

					if(length == 0)
					{
						head = newNode;
						tail = newNode;
					}
					else{
						tail->next = newNode;
						newNode->prev = tail;
						tail = newNode;
						tail->next = nullptr;
					}
					length++;

				}

				void deleteLast()
				{
					if(length==0) 
					{
						return;
					}
					if(length == 1)
					{
						tail = nullptr;
						head = nullptr;
					}
					else{
						tail = tail->prev;
						tail->next = nullptr;
					}
					length--;
				}

				void prepend(int value)
				{
					if(length == 0)
					{
						append(value);
						return;
					}
					
					Node* newNode = new Node(value);
					head->prev = newNode;
					newNode->prev = nullptr;
					newNode->next = head;
					head = newNode;
					length++;

				}

				void deleteFirst()
				{
					if(length == 0){
						return;
					}

					if (length == 1)
					{
						head = nullptr;
						tail = nullptr;
						length--;
						return;
					}
					else 
					{
						head = head->next;
						head->prev = nullptr;
						length--; 
					}
				}

				Node* get(const int& index) const
				{
					if(index>length-1)
					{
						return nullptr;
					}

					if(index<length/2)
					{
						Node* temp = head;
						for(int i=0; i<index; ++i)
						{
							temp = temp->next;
						}
						return temp;
					}
					else {
						Node* temp = tail;
						for(int i=0; i<length-index-1; ++i)
						{
							temp = temp->prev;
						}
						return temp;
					}
				}

				bool set(const int& index, const int& value)
				{
					Node* node = get(index);
					if(node)
					{
						node->value = value;
						return true;
					}
					return false;
					
				}

				bool insert(const int& index, const int& value)
				{
					if(index > length)
					{
						return false;
					}
					if(index == 0)
					{
						append(value);
						return true;
					}

					if(index == length)
					{
						prepend(value);
						return true;
					}

					Node* newNode = new Node(value);
					Node* prev = get(value-1);

					newNode->next = prev->next;
					prev->next = newNode;
					newNode->prev = prev;

					length++;

				}

				bool deleteNode(const int& index)
				{
					if(index >= length)
					{
						return false;
					}	
					if(index==0)
					{
						deleteFirst();
						return true;
					}
					else if(index == length-1)
					{
						deleteLast();
						return true;
					}
					Node* temp = get(index);
					Node* prev = get(index-1);
					prev->next = temp->next;

					temp = nullptr;
					length--; 
					return true;
				}


				int getLength() const {
					return this->length;
				}
		};
	}
	
	namespace Stack{
		class Node{
			public:
				int value;
				Node* next;

				Node(int value):value{value}, next{nullptr} {}
		};

		class Stack
		{
			private:
				Node* top;
				int height;
			public:
				
				Stack(int value){
					Node* newNode = new Node(value);
					top = newNode;
					height = 1;
				}

				void push(int value)
				{
					Node* newNode = new Node(value);
					newNode->next = top;
					top = newNode;
					height++;
					
				}

				int pop()
				{
					if(height == 0) return INT_MIN;

					int popped_val = top->value;
					top = top->next;
					
					height--;
					return popped_val;
				}

				void printStack()
				{
					Node* temp = top;
					for(int i = 0; i < height; ++i)
					{
						std::cout << temp->value << "\n";
						temp = temp->next;
					}
					std::cout << "--------------------------------------\n";
				}


		};
	}

	namespace BinarySearchTree{
		
		/*
		* O(log n) search
		*/

		class Node{
			public:
				int value;
				Node* left;
				Node* right;
				Node(int value):value{value}, right{nullptr}, left{nullptr}
				{}
		};

		class BinarySearchTree{
			
			public:
				Node* root;
				BinarySearchTree() : root{nullptr} {}

				bool insert(int value){
					Node* newNode = new Node(value);
					if(root == nullptr) {
						root = newNode;
						return true;
					}				
					Node* temp = root;
					while(true)
					{
						if(temp->value == newNode->value)
						{
							std::cout << "Value exists already\n";
							return false;
						}
						if(newNode->value<temp->value)
						{
							if(temp->left == nullptr)
							{
								temp->left = newNode;
								return true;
							}
							temp = temp->left;

						}
						else {
							if(temp->right == nullptr)
							{
								temp->right = newNode;
								return true;
							}
							temp = temp->right;
						}
					}
				}
		
				bool contains(int value){
					
					if(root == nullptr) return false;

					Node* temp = root;
					while(temp){
						if(temp->value < value){  // going right
							temp = temp->right;
						}
						else if(temp->value > value){	// goindg left
							temp = temp->left;
						}
						else if(temp->value == value){
							return true; // found!!
						}
					}
					return false;
				}
		};
	}

	namespace HastTable{
		/*
		*	Adress space
		* 	key-value pair stored in this adress space
		* 	hash is performed on the key
		*/
		class Node{
			public:
				std::string key;
				int value;
				Node* next;
				Node(std::string key, int value):key{key}, value{value}, next{nullptr}
				{}
		};

		class HashTable{
			private:
				static const int SIZE = 7;
				Node* dataMap[SIZE];
			
			public:
				
				void printTable(){
					for (int i = 0; i<SIZE; ++i)
					{
						std::cout << i << ":\n";
						if(dataMap[i])
						{
							Node* temp = dataMap[i];
							while(temp)
							{
								std::cout << " {" << temp->key << ", " << temp->value << "}\n";
								temp = temp->next;
							}
						}
					}
				}

				int hash(std::string key){
					int hash = 0;

					for(int i=0; i < key.length(); ++i)
					{
						int ascii_value = int(key[i]);
						hash = (hash + ascii_value * 23) % SIZE; 
					}
					return hash;
				}

				void set(std::string key, int value)
				{
					int index = hash(key);
					Node* newNode = new Node(key, value);
					if(dataMap[index] == nullptr)
					{
						dataMap[index] = newNode;
					}
					else{
						
					}
				}
		

		};
	}

	void linked_list_run()
	{
		
		LinkedList::LinkedList* linked_list = new LinkedList::LinkedList(0);
		/*
		linked_list->print();

		linked_list->append(10);
		linked_list->print();
		
		linked_list->deleteLast();
		linked_list->print();
		
		linked_list->deleteLast();
		linked_list->print();
		
		linked_list->deleteLast();
		linked_list->print();
		
		linked_list->deleteLast();
		linked_list->print();
		
		linked_list->prepend(3);
		linked_list->prepend(2);
		linked_list->prepend(1);
		linked_list->print();
		
		linked_list->deleteFirst();
		linked_list->print();
		
		linked_list->deleteFirst();
		linked_list->print();
		
		linked_list->deleteFirst();
		linked_list->print();
		
		linked_list->append(1);
		linked_list->append(2);
		linked_list->append(4);
		linked_list->insert(2, 3);
		linked_list->print();
		linked_list->deleteNode(2);
		linked_list->print();
		
		linked_list->reverse();
		linked_list->print();
		*/
		linked_list->append(1);
		linked_list->append(1);
		linked_list->append(2);
		linked_list->append(3);
		linked_list->append(3);
		linked_list->append(4);
		linked_list->removeDuplicates();
		linked_list->print();

	}

	void doubly_linked_list_run()
	{
		DoublyLinkedList::DoublyLinkedList* dll = new DoublyLinkedList::DoublyLinkedList(0);
		/*
		dll->append(1);
		dll->append(2);
		dll->printList();
		
		dll->deleteLast();
		dll->printList();
		dll->deleteLast();
		dll->printList();
		dll->deleteLast();
		dll->printList();
		
		dll->prepend(1);
		dll->printList();
		dll->prepend(2);
		dll->printList();
		

		dll->append(1);
		dll->append(2);
		dll->deleteFirst();
		dll->printList();
		dll->deleteFirst();
		dll->printList();
		dll->deleteFirst();
		dll->printList();
		

		dll->append(5);
		dll->append(6);
		dll->append(7);
		dll->append(8);
		dll->append(9);
		dll->append(10);
		dll->append(11);
		dll->append(12);
		dll->append(13);

		std::cout << "element value:" << dll->get(0)->value << "\n";
		std::cout << "element value:" << dll->get(1)->value << "\n";
		std::cout << "element value:" << dll->get(2)->value << "\n";
		std::cout << "element value:" << dll->get(3)->value << "\n";
		std::cout << "element value:" << dll->get(4)->value << "\n";
		std::cout << "element value:" << dll->get(5)->value << "\n";
		std::cout << "element value:" << dll->get(6)->value << "\n";
		std::cout << "element value:" << dll->get(7)->value << "\n";
		std::cout << "element value:" << dll->get(8)->value << "\n";
		std::cout << "element value:" << dll->get(9)->value << "\n";
		

		dll->append(1);
		dll->append(2);
		dll->append(3);
		dll->set(1,4);
		dll->printList();
		*/

		dll->append(2);
		dll->append(3);
		dll->append(4);
		dll->append(5);
		dll->insert(1,1);
		dll->printList();

		dll->deleteNode(0);
		dll->printList();
		dll->deleteNode(1);
		dll->printList();
		dll->deleteNode(2);
		dll->printList();
		dll->deleteNode(1);
		dll->printList();
		dll->deleteNode(0);
		dll->printList();
		dll->deleteNode(3);
		dll->printList();
		dll->deleteNode(1);
		dll->printList();
		dll->deleteNode(0);
		dll->printList();
		dll->deleteNode(0);
		dll->printList();
	}

	void stack_run()
	{
		Stack::Stack* st = new Stack::Stack(1);
		st->push(2);
		st->push(3);
		st->printStack();
		st->pop();
		st->printStack();
		st->pop();
		st->printStack();

	}

	void binary_search_tree_run()
	{
		BinarySearchTree::BinarySearchTree* bst = new BinarySearchTree::BinarySearchTree();
		bst->insert(47);
		bst->insert(21);
		bst->insert(76);
		bst->insert(18);
		bst->insert(52);
		bst->insert(82);
		bst->insert(27);
		//std::cout << bst->root->left->right->value << "\n";

		std::cout << bst->contains(46) << "\n";
		std::cout << bst->contains(47) << "\n";
		std::cout << bst->contains(21) << "\n";
		std::cout << bst->contains(18) << "\n";
		std::cout << bst->contains(82) << "\n";
		std::cout << bst->contains(100) << "\n";

	}

	void hast_table_run()
	{
		HastTable::HashTable* ht = new HastTable::HashTable();
		ht->printTable();
	}

	void run(){
		
		//linked_list_run();
		//doubly_linked_list_run();
		//stack_run();
		//binary_search_tree_run();
		hast_table_run();
	}
}

namespace section2
{
	namespace arrays {

		void run()
		{
			int A[5]; // create in stack
			int B[5] = { 1,2,3,4,5 }; // initialization
			int C[] = { 1,2,3,4,5,6,7 };
			for (int i = 0; i < 5; ++i)
			{
				printf("%d\n", B[i]);
			}
			std::cout << "\n";
			std::cout << "size of an array: " << sizeof(B) / sizeof(int) << std::endl;
			for (auto i : C)
			{
				printf("%d\n", i);
			}
			std::cout << "size of an array: " << sizeof(C) / sizeof(int) << std::endl;

		}
	}

	namespace structures
	{
		/*
			* will be created in stack
		*/
		struct Rectangle {
			int lenght; //2 byte
			int breadth; // 2 byte
		};

		struct ComplexNumber {
			int real;
			int img;
		};

		struct Student {
			int roll;
			char name[25];
			char dept[10];
			char address[50];
		};



		void run()
		{
			Rectangle r; // 4 byte
			Rectangle e{ 1,2 };
		}
	}

	namespace Pointers {
#include <stdlib.h>	
		/*
		* There are 3 memory sections.
		*	stack
		*	heap
		*	code section
		* Program access directly to the code section and staack memory but cannot access to
		the heap memory. So we need pointers to access the heap memory. We need them also for accessing
		resources outside program or
		we need them to pass parameters
		*/
		void main()
		{
			int* p; // it will declerad in stack !!!
			p = (int*)malloc(5 * sizeof(int)); // allocates memory in heap for 5 ints, malloc return void*: this is C-way
			p = new int[5]; // C++ way
			p[0] = 1;
			delete[] p; // C++ way
			//free(p); //C-way

			int* a;
			char* b;
			double* c;

			std::cout << sizeof(a) << std::endl; // 8-bytes
			std::cout << sizeof(b) << std::endl; // 8-bytes
			std::cout << sizeof(c) << std::endl; // 8-bytes

		}
	}

	namespace References {

		// there is no reference in C.

		void main()
		{
			int a = 10;
			int& r = a; // must initialized while declaring
			std::cout << a << "\n"; // 10
			a++;
			std::cout << a << "\n"; // 11
			std::cout << r << "\n"; // 11

			int b = 24;
			r = b;

			std::cout << a << "\n"; // 24

		}
	}

	namespace PointertoStructer {
#include <stdlib.h>	
		struct Rectangle {
			int lenght;
			int breadth;
		};

		void main()
		{

			Rectangle r = { 1,2 };
			Rectangle* p = &r; // this is a static
			// p.lenght : wrong
			// *p.lenght : also wrong because . has higher precedence
			(*p).lenght; // this is correct
			// or beetter
			p->lenght;

			Rectangle* a; // created in the stack

			a = (Rectangle*)malloc(sizeof(Rectangle)); //allocating memory in heap, this is dynamic one
			//or
			a = new Rectangle; //allocating memory in heap, now pointer is pointing to somewhere in heap memory, this is dynamic one
			a->breadth;
			a->lenght;
		}
	}

	namespace Functions {

		/*
		* x,y,z are created in stack.
		* add functions is created in the stack also the parameters a,b,c
		* as soon as the function add returns the value, the stack memeory is deleted for add function
		*/

		int add(int a, int b)
		{
			int c;
			c = a + b;
			return c;
		}

		void main()
		{
			int x, y, z;
			x = 10; 
			y = 5;
			z = add(x,y);
			std::cout << z << "\n";
		}
	}

	namespace ArrayasParameter {
		/*
		* array cannot be passed as value, should be passed as adress(pointer)
		* If you make any change in the array, then it will effect the array also in the main function
		* 
		*/

		void goo(int A[])
		{	
			// pointer size is 8 bytes
			std::cout << sizeof(A) / sizeof(int) << "\n"; // this will print 8 bytes/ 4 bytes = 2 but whyyy ??? 
														  // because array will be pass by adress not by value,
														  // because sizeof(A) returns the sizeof int* 
														  // if you call this in the main, then it will print 5;
		}

		int* foo(int n)
		{
			// returns a pointer
			int* p;
			p = (int*)malloc(sizeof(int));
			return p;
		}

		void fun(int A[], int n)
		{
			for (int i = 0; i<n; ++i)
			{
				std::cout << A[i] << "\n";
			}	
		}

		
		void main()
		{
			int A[5] = { 1,2,3,4,5 };
			//fun(A, 5);

			//foo(5);

			goo(A);
		}
	}

	namespace TemplateClass{

		template <class T>
		class Arithmatic {
		private:
			T a;
			T b;

		public:
			Arithmatic(T a, T b)
			{
				this->a = a;
				this->b = b;
			}
			
			T add()
			{
				T c;
				c = a + b;
				return c;
			}
			T sub()
			{
				T c;
				c = a - b;
				return c;
			}

		};
		
		void main()
		{
			Arithmatic<double> a_obj(1.0, 2.0);
			std::cout << a_obj.add() << "\n";
		}

	}

}

namespace Section4 
{
	namespace StackHeapMemory
	{

		void stackfunc2(int i)
		{
			int a; // stack
			// after that the memoery is deleted
		}

		void stackfunc1()
		{
			int x{0}; // stack
			stackfunc2(x); // control goes there
			// after that the memoery is deleted
		}

		void run()
		{
			int a; // stack
			float b; // stack
			stackfunc1(); // control goes there
			// after that the memoery is deleted
		}
	}

	namespace DataStructures 
	{
		/*
		* Logical Data Structures:                			Physical:
		--------------------------                			-----------------
		1 - Stack: linear (LIFO)                            1 - array  
		2 - Queues: linear (FIFO)                        	2 - list
		3 - Trees: nonlinear
		4 - Graph: nonlinear
		5 - Hash table: Tabular
		*/
	}
}

namespace Algo 
{

	class Point {
	public:
		int x, y;
		Point(int x = 0, int y = 0) :x{ x }, y{ y }
		{}

		bool operator < (const Point& other)
		{
			return (x + y) < (other.x + other.y);
		}
	};

	std::vector<int> v1{ 0,1,2,3,4,5 };
	std::vector<int> v2{ 4,5,6,7,8,9 };
	std::vector<int> v3, v4, v5, v6;

	template<typename T>
	std::string print_vec(const std::vector<T>& vec)
	{
		std::string out{ "" };
		for (typename std::vector<T>::const_iterator it = vec.cbegin(); it != vec.end(); ++it)
		{
			out += std::to_string(*it) + " ";
		}
		return out;
	}

	void set_union()
	{
		std::set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(v3));
		std::cout << "set_union: " << print_vec<int>(v3) << "\n";
	}

	void set_intersection() {
		std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(v4));
		std::cout << "set_intersection: " << print_vec<int>(v4) << "\n";
	}

	void set_difference()
	{
		std::set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(v5));
		std::cout << "set_difference: " << print_vec<int>(v5) << "\n";
	}

	void set_symmetric_difference()
	{
		std::set_symmetric_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(v6));
		std::cout << "set_symmetric_difference: " << print_vec<int>(v6) << "\n";
	}

	void sort()
	{
		std::vector<int> vec{ 5,4,6,7,3,2,8,9,1 };
		std::sort(std::execution::par, vec.begin(), vec.end());
		for (const auto& element : vec)
		{
			printf("%d ", element);
		}
		std::cout << "\n";
		std::vector<int> vec2{ 5,4,6,7,3,2,8,9,1 };
		std::sort(vec2.begin(), vec2.end());
		for (const auto& element : vec2)
		{
			printf("%d ", element);
		}
		std::cout << "\n";

		std::vector<Point> vec_point{ {1,2}, {3,1}, {0,1} };
		std::sort(vec_point.begin(), vec_point.end());
		for (const auto& element : vec_point)
		{
			printf("{%d, %d} ", element.x, element.y);
		}
		std::cout << "\n";

		std::vector<int> vec3{ 5,4,6,7,3,2,8,9,1 };
		std::sort(vec3.begin(), vec3.end(), [](int a, int b) {return a < b; });
		for (const auto& element : vec3)
		{
			printf("%d ", element);
		}
		std::cout << "\n";

		std::vector<int> vec4{ 5,4,6,7,3,2,8,9,1 };
		std::sort(vec4.begin(), vec4.end(), std::greater<int>());
		for (const auto& element : vec4)
		{
			printf("%d ", element);
		}
		std::cout << "\n";

		std::vector<int> vec5{ 5,4,6,7,3,2,8,9,1 };
		std::sort(vec5.begin(), vec5.end(), std::less<int>());
		for (const auto& element : vec5)
		{
			printf("%d ", element);
		}

	}

	void is_sorted()
	{
		std::vector<int> vec{ 2,3,5,6,9,1,0,3 };
		bool result = std::is_sorted(vec.begin(), vec.end());
		std::cout << "result: " << result << "\n";
		std::vector<int> vec2{ 9,8,7,6,5,4,3,2,1,0 };
		result = std::is_sorted(vec2.begin(), vec2.end(), std::greater<int>());
		std::cout << "result: " << result << "\n";
		std::sort(vec2.begin(), vec2.end());
		result = std::is_sorted(vec2.begin(), vec2.end(), std::less<int>());
		std::cout << "result: " << result << "\n";
	}

	void partial_sort()
	{
		std::vector<int> vec{ 2,3,5,6,9,1,0,3 };
		std::partial_sort(vec.begin(), vec.begin() + 4, vec.end());
		for (const auto& el : vec)
		{
			std::cout << "el: " << el << "\n";
		}

	}

	void nth_element()
	{
		std::vector<int> vec{ 2,3,5,6,9,1,0,3 };
		std::nth_element(vec.begin(), vec.begin() + vec.size() / 2, vec.end());

	}

	void is_sorted_until()
	{
		std::vector<int> vec{ 2,3,5,6,9,1,0,3 };
		auto it = std::is_sorted_until(vec.begin(), vec.end());
		auto diff = std::distance(vec.begin(), it);
		std::cout << "diff: " << diff << "\n";

		it = std::is_sorted_until(vec.begin(), vec.end(), std::greater<int>());
		diff = std::distance(vec.begin(), it);
		std::cout << "diff: " << diff << "\n";
	}

	void iota()
	{
		std::list<int> list(10);
		std:iota(list.begin(), list.end(), -4);

	}

	void copy()
	{
		std::vector<int> from_vec(10);
		std::iota(from_vec.begin(), from_vec.end(), 0);
		std::vector<int> to_vec1;
		to_vec1.resize(from_vec.size());

		std::copy(from_vec.begin(), from_vec.end(), to_vec1.begin());
		std::cout << print_vec<int>(to_vec1) << "\n";

		std::vector<int> to_vec2;
		std::copy(from_vec.begin(), from_vec.end(), std::back_inserter(to_vec2));
		std::cout << print_vec<int>(to_vec2) << "\n";
	}

	void copy_if()
	{
		std::vector<int> from_vec(10);
		std::iota(from_vec.begin(), from_vec.end(), 0);
		std::vector<int> to_vec(5);
		std::copy_if(from_vec.begin(), from_vec.end(), to_vec.begin(), [](int x) {return (x % 2) == 1; });
		std::cout << print_vec<int>(to_vec) << "\n";

	}

	void run()
	{
		//set_union();
		//set_intersection();
		//set_difference();
		//set_symmetric_difference();

		//sort();
		//is_sorted();
		//partial_sort();
		//nth_element();
		//is_sorted_until();
		//copy();
		copy_if();
	}

}

namespace Virtual
{
	/*
	* without virtual dtor, the output is:
	*	ctor Base
		ctor derived
		dtor Base

	* so want to delete also derived, so because of that we need virtual dtor
	*/
	class Base {
	public:
		Base() {
			std::cout << "ctor Base\n";
		}

		virtual ~Base() {
			std::cout << "dtor Base\n";
		}
	};

	class Derived : public Base {
	public:
		Derived() {
			std::cout << "ctor derived\n";
		}
		~Derived() override {
			std::cout << "dtor derived\n";
		}
	};

	void run()
	{
		Base* b = new Derived();
		delete b;

	}
}


int main()
{
	//Algo::run();
	//Virtual::run();
	STL::run();
}


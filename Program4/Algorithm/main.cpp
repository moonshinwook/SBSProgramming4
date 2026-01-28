#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <Windows.h>

using namespace std;

// 탐색에서 더 효율적인 컨테이너.
// 트리 -> 계층을 갖는 vertex와 edge
// 이진트리. 이진 탐색
// 트리를 어떤 방식으로 순회 - BFS DFS
// [Pre, In, Post] Order

//		insert(10) 
//		insert(5) (10) (15)
//		root(10)
//			5	15
//	

void SetCursorPosition(int x, int y)
{
	// :: 전역으로 존재하는 것, 개인적으로 만든 것이 아님을 정의
	HANDLE output = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { static_cast<SHORT>(x),static_cast<SHORT>(y) };
	SetConsoleCursorPosition(output, pos);
}


struct Node
{
	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;
	int key = {};
};

class BinarySearchTree
{
public:

	void Print()
	{
		Print(_root, 10, 0);
	}

	void insert(int key)
	{
		// 첫번째 노드가 삽입됐을 때
		Node* newNode = new Node();
		newNode->key = key;

		if (_root == nullptr)
		{
			_root = newNode;
			return;
		}
		
		Node* node = _root;
		Node* parent = nullptr;

		while (node)	// 리프노드가 아니면 계속 반복해라. 리프(자식이 없는)
		{
			parent = node;
			if (key < node->key)
				node = node->left;
			else
				node = node->right;
		}
		 
		newNode->parent = parent;
		
		if (key < parent->key)
			parent->left = newNode;
		else
			parent->right = newNode;

	}
	Node* find(Node* node, int key)
	{
		if (node == nullptr || node->key)
			return node;

		if (key < node->key)
			return find(node->left, key);
		else
			return find(node->right, key);

	}

	Node* find(int key)
	{
		return find(_root, key);
	}

private:
	void Print(Node* node, int x, int y)
	{
		if (node == nullptr)
			return;

		SetCursorPosition(x, y);
		cout << node->key;
		Print(node->left, x - (5 / (y + 1)), y + 1);
		Print(node->right, x + (5 / (y + 1)), y + 1);
	}

private:
	Node* _root = nullptr;


};

// 탐색 -> BST [트리 불균형의 경우] -> N과 비슷. 잘 사용 안 함. -> 균형을 잡아주는 알고리즘을 활용하여 실용버전 필요.
// 대부분의 케이스에 logN 탐색으로 찾을 수 있다. 
// map << find logn으로 찾을 수 있다.


// Hash Table
// vector, unordered_map

int main()
{
	BinarySearchTree bst;

	bst.insert(20);
	bst.insert(10);
	bst.insert(30);
	bst.insert(50);
	bst.insert(70);
	bst.insert(15);
	bst.insert(90);
	bst.insert(110);


	// bst.Print();

	Node* findNode = bst.find(10);
	cout << findNode->key << endl;
}
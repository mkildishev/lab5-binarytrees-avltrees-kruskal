#pragma once

#include <iostream>
#include <queue>

using namespace std;

struct node
{
	int key;
	node *left;
	node *right;
	node *parent;
};

node* FindKey(node *root, int key);
node* FindMin(node *root);
node* FindMax(node *root);
node* FindNext(node *node);
node* FindPrevious(node *node);
void Push(node *&root, node *node);
void Remove(node *&root, int key);
void WorkAroundSearch(node *node);

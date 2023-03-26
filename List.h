#pragma once

#include <iostream>
#include <Windows.h>

using std::cin;
using std::cout;

struct Tree
{
	int data;
	Tree* right;
	Tree* left;
};

using pTree = Tree*;

pTree newTree(int x);
pTree Push(pTree root, int x);
void print_Tree(pTree root, int level, std::ostream& stream);
#pragma warning (disable : 4996)

#include"Bag.h"
#include"BinarySearch.h"
#include"LinkedBag.h"
#include"LinkedQueue.h"
#include"LinkedStack.h"
#include"Merge.h"
#include"MergeBU.h"
#include"MergeX.h"
#include"Queue.h"
#include"Quick.h"
#include"QuickFindUF.h"
#include"QuickUnionUF.h"
#include"ResizingArrayBag.h"
#include"Shell.h"
#include"Stack.h"
#include"StdRandom.h"
#include"UF.h"
#include"Vector.h"
#include"WeightedQuickUnionUF.h"

#include<vld.h>

using namespace algs4Cpp;


int main(int argc, char *argv[]) {
	Bag<int>::mainTest();
	Queue<int>::mainTest();
	LinkedStack<int>::mainTest();
	ResizingArrayBag<int>::mainTest();
	StdRandom::mainTest();
	Merge<int>::mainTest();
	BinarySearch<int>::mainTest();
	Quick<int>::mainTest();

	return 0;
}
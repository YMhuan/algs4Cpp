#pragma warning (disable : 4996)

#include"Average.h"
#include"Bag.h"
#include"BinarySearch.h"
#include"BST.h"
#include"LinkedBag.h"
#include"LinkedQueue.h"
#include"LinkedStack.h"
#include"Merge.h"
#include"MergeBU.h"
#include"MergeX.h"
#include"Queue.h"
#include"Quick.h"
#include"Quick3way.h"
#include"QuickFindUF.h"
#include"QuickUnionUF.h"
#include"QuickX.h"
#include"ResizingArrayBag.h"
#include"Shell.h"
#include"Stack.h"
#include"StdRandom.h"
#include"Stopwatch.h"
#include"StopwatchWin32.h"
#include"UF.h"
#include"Vector.h"
#include"WeightedQuickUnionUF.h"

#include<vld.h>

using namespace algs4Cpp;


int main(int argc, char *argv[]) {
	Average::mainTest();
	Bag<int>::mainTest();
	Queue<int>::mainTest();
	LinkedStack<int>::mainTest();
	ResizingArrayBag<int>::mainTest();
	StdRandom::mainTest();
	Merge<int>::mainTest();
	BinarySearch<int>::mainTest();
	Quick<int>::mainTest();
	QuickX<int>::mainTest();
	Quick3way<int>::mainTest();
	Stopwatch::mainTest();
	StopwatchWin32::mainTest();
	BST<int, int>::mainTest();

	return 0;
}
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



int main(int argc, char *argv[]) {
	algs4Cpp::Bag<int>::mainTest();
	algs4Cpp::Queue<int>::mainTest();
	algs4Cpp::LinkedStack<int>::mainTest();
	algs4Cpp::ResizingArrayBag<int>::mainTest();
	algs4Cpp::StdRandom::mainTest();
	algs4Cpp::Merge<std::string>::mainTest();

	return 0;
}
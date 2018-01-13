#include"Bag.h"
#include"Queue.h"
#include"LinkedStack.h"
#include"ResizingArrayBag.h"
#include<vld.h>



int main(int argc, char *argv[]) {
	algs4Cpp::Bag<int>::mainTest();
	algs4Cpp::Queue<int>::mainTest();
	algs4Cpp::LinkedStack<int>::mainTest();
	algs4Cpp::ResizingArrayBag<int>::mainTest();
	

	return 0;
}
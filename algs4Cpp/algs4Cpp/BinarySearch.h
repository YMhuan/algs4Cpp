#pragma once
#include<vector>
#include<fstream>
#include<algorithm>
#include<iostream>

namespace algs4Cpp {


	template<typename Item>class BinarySearch {
	public:
		BinarySearch(const BinarySearch &) = delete;
		BinarySearch &operator=(const BinarySearch &) = delete;
		~BinarySearch() = delete;

		static int indexOf(std::vector<Item> a, Item key) {
			int lo = 0;
			int hi = a.size() - 1;
			while (lo <= hi) {
				int mid = lo + (hi - lo) / 2;
				if (key < a[mid]) hi = mid - 1;
				else if (key > a[mid]) lo = mid + 1;
				else return mid;
			}
			return -1;
		}

		static int rank(Item key, std::vector<Item> a) {
			return indexOf(a, key);
		}

		static void mainTest(int argc=0, char *argv[]=nullptr) {
			std::ifstream input(argv[1]);
			std::vector<int> whitelist;
			int x;
			while(input>>x){
				whitelist.push_back(x);
			}
			std::sort(whitelist.begin(), whitelist.end());
			
			int key;
			while (std::cin >> key) {
				if (BinarySearch<int>::indexOf(whitelist, key) == -1)
					std::cout << key << std::endl;
			}
		}
	};


}
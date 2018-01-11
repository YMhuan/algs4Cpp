#pragma once
#include<vector>
#include<fstream>
#include<algorithm>
#include<iostream>

namespace algs4Cpp {


	class BinarySearch {
	public:
		BinarySearch(const BinarySearch &) = delete;
		BinarySearch &operator=(const BinarySearch &) = delete;
		~BinarySearch() = delete;

		static int indexOf(std::vector<int> a, int key) {
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

		static int rank(int key, std::vector<int> a) {
			return indexOf(a, key);
		}

		static void mainTest(int argc, char *argv[]) {
			std::ifstream input(argv[1]);
			std::vector<int> whitelist;
			int x;
			while(input>>x){
				whitelist.push_back(x);
			}
			std::sort(whitelist.begin(), whitelist.end());
			
			int key;
			while (std::cin >> key) {
				if (BinarySearch::indexOf(whitelist, key) == -1)
					std::cout << key << std::endl;
			}
		}
	};


}
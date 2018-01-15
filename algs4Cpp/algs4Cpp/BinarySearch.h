#pragma once
#include<vector>
#include<algorithm>
#include<cassert>

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
			std::vector<int> whitelist{1,3,5,7,9};
			std::sort(whitelist.begin(), whitelist.end());
			
			int key=6;
			assert(BinarySearch<int>::indexOf(whitelist, key) == -1);

		}
	};


}
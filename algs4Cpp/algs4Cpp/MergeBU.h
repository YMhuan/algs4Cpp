#pragma once
#include<vector>
#include<algorithm>
#include<cassert>

namespace algs4Cpp {
	template<typename Item>class MergeBU {
	public:
		MergeBU(const MergeBU &) = delete;
		MergeBU &operator=(const MergeBU &) = delete;
		~MergeBU() = delete;

	private:
		static void merge(std::vector<Item> &a, std::vector<Item> &aux, int lo, int mid, int hi) {
			for (int k = lo; k <= hi; ++k) {
				aux[k] = a[k];
			}

			int i = lo, j = mid + 1;
			for (int k = lo; k <= hi; ++k) {
				if (i > mid) a[k] = aux[j++];
				else if (j > hi) a[k] = aux[i++];
				else if (aux[j] < aux[i]) a[k] = aux[j++];
				else a[k] = aux[i++];
			}
		}

	public:
		static void sort(std::vector<Item> &a) {
			int n = a.size();
			std::vector<Item>aux(n);
			for (int len = 1; len < n; len *= 2) {
				for (int lo = 0; lo < n - len; lo += len + len) {
					int mid = lo + len - 1;
					int hi = std::min(lo + len + len - 1, n - 1);
					merge(a, aux, lo, mid, hi);
				 }
			}
			assert(isSorted(a));
		}

		static bool isSorted(std::vector<Item> &a) {
			for (int i = 1; i < a.size(); ++i) {
				if (a[i] < a[i - 1]) return false;
			}
			return true;
		}

	};
}
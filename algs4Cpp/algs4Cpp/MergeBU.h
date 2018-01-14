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
		static void merge(std::vector<Item> &a, std::vector<Item> &aux, size_t lo, size_t mid, size_t hi) {
			for (size_t k = lo; k <= hi; ++k) {
				aux[k] = a[k];
			}

			size_t i = lo, j = mid + 1;
			for (size_t k = lo; k <= hi; ++k) {
				if (i > mid) a[k] = aux[j++];
				else if (j > hi) a[k] = aux[i++];
				else if (aux[j] < aux[i]) a[k] = aux[j++];
				else a[k] = aux[i++];
			}
		}

	public:
		static void sort(std::vector<Item> &a) {
			std::vector<Item>::size_type n = a.size();
			std::vector<Item>aux(n);
			for (size_t len = 1; len < n; len *= 2) {
				for (size_t lo = 0; lo < n - len; lo += len + len) {
					size_t mid = lo + len - 1;
					size_t hi = std::min(lo + len + len - 1, n - 1);
					merge(a, aux, lo, mid, hi);
				 }
			}
			assert(isSorted(a));
		}

		static bool isSorted(std::vector<Item> &a) {
			for (size_t i = 1; i < a.size(); ++i) {
				if (a[i] < a[i - 1]) return false;
			}
			return true;
		}

	};
}
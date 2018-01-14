#pragma once
#include<vector>
#include<cassert>
#include<algorithm>
#include<functional>

namespace algs4Cpp {
	template<typename Item>class MergeX {
	public:
		MergeX(const MergeX &) = delete;
		MergeX &operator=(const MergeX &) = delete;
		~MergeX() = delete;

	private:
	    static const int CUTOFF = 7;

		static void merge(std::vector<Item> &src, std::vector<Item> &dst, size_t lo, size_t mid, size_t hi, const std::function<bool(Item, Item)> &less) {
			assert(isSorted(src, lo, mid,less));
			assert(isSorted(src, mid + 1, hi,less));

			size_t i = lo, j = mid + 1;
			for (size_t k = lo; k <= hi; ++k) {
				if (i > mid) dst[k] = src[j++];
				else if (j > hi) dst[k] = src[i++];
				else if (less(src[j],src[i])) dst[k] = src[j++];
				else dst[k] = src[i++];
			}

			assert(isSorted(dst, lo, hi,less));
		}

		static void sort(std::vector<Item>& src, std::vector<Item>& dst, size_t lo, size_t hi, const std::function<bool(Item, Item)> &less) {
			if (hi <= lo + CUTOFF) {
				insertionSort(dst, lo, hi,less);
				return;
			}

			size_t mid = lo + (hi - lo) / 2;
			sort(dst, src, lo, mid,less);
			sort(dst, src, mid + 1, hi,less);

			if (!less(src[mid + 1],src[mid])) {
				std::copy(src.begin(), src.end(), dst.begin());
				return;
			}

			merge(src, dst, lo, mid, hi,less);
		}



		static bool isSorted(const std::vector<Item> &a, const std::function<bool(Item, Item)> &less) {
			return isSorted(a, 0, a.size() - 1,less);
		}

		static bool isSorted(const std::vector<Item> &a, size_t lo, size_t hi, const std::function<bool(Item, Item)> &less) {
			for (size_t i = lo + 1; i <= hi; ++i) {
				if (less(a[i],a[i - 1])) return false;
			}
			return true;
		}


		static void insertionSort(std::vector<Item> &a, size_t lo, size_t hi, const std::function<bool(Item, Item)> &less) {
			using std::swap;
			for (size_t i = lo; i <= hi; ++i) {
				for (size_t j = i; j > lo && less(a[j],a[j - 1]); --j) {
					swap(a[j], a[j - 1]);
				}
			}
		}

	public:

		static void sort(std::vector<Item>& a, const std::function<bool(const Item &, const Item &)> &less = std::less<>{}) {
			std::vector<Item> aux(a);
			sort(aux, a, 0, a.size() - 1, less);
			assert(isSorted(a,less));
		}

	};
}

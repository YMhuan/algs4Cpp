#pragma once
#include<vector>
#include<cassert>

namespace algs4Cpp {
	template<typename Item>class Merge {
	public:
		Merge(const Merge &) = delete;
		Merge &operator=(const Merge &) = delete;
		~Merge() = delete;

	private:
		static void merge(std::vector<Item> &a, std::vector<Item> &aux, int lo, int mid, int hi) {
			assert(isSorted(a, lo, mid));
			assert(isSorted(a, mid + 1, hi));

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

			assert(isSorted(a, lo, hi));
		}

		static void sort(std::vector<Item>& a, std::vector<Item>& aux, int lo, int hi) {
			if (hi <= lo) return;
			int mid = lo + (hi - lo) / 2;
			sort(a, aux, lo, mid);
			sort(a, aux, mid + 1, hi);
			merge(a, aux, lo, mid, hi);
		}


		static bool isSorted(const std::vector<Item> &a) {
			return isSorted(a, 0, a.size() - 1);
		}

		static bool isSorted(const std::vector<Item> &a, int lo, int hi) {
			for (int i = lo + 1; i <= hi; ++i) {
				if (a[i] < a[i - 1]) return false;
			}
			return true;
		}

		static void merge(const std::vector<Item> &a, std::vector<int> &index, std::vector<int> &aux, int lo, int mid, int hi) {
			for (int k = lo; k <= hi; ++k) {
				aux[k] = index[k];
			}

			int i = lo, j = mid + 1;
			for (int k = lo; k <= hi; ++k) {
				if (i > mid) index[k] = aux[j++];
				else if (j > hi) index[k] = aux[i++];
				else if (a[aux[j]] < a[aux[i]]) index[k] = aux[j++];
				else index[k] = aux[i++];
			}
		}

		static void sort(const std::vector<Item>& a, std::vector<int>& index, std::vector<int>& aux, int lo, int hi) {
			if (hi <= lo) return;
			int mid = lo + (hi - lo) / 2;
			sort(a, index, aux, lo, mid);
			sort(a, index, aux, mid + 1, hi);
			merge(a, index, aux, lo, mid, hi);
		}

	public:
		static void sort(std::vector<Item>& a) {
			std::vector<Item> aux(a.size());
			sort(a, aux, 0, a.size() - 1);
			assert(isSorted(a));
		}

		static std::vector<int> indexSort(const std::vector<Item>& a) {
			int n = a.size();
			std::vector<int> index(n);
			for (int i = 0; i < n; ++i) {
				index[i] = i;
			}

			std::vector<int> aux(n);
			sort(a, index, aux, 0, n - 1);
			return index;
		}

	};
}

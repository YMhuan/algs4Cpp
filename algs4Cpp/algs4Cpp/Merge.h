#pragma once
#include<vector>
#include<cassert>
#include<string>

namespace algs4Cpp {
	template<typename Item>class Merge {
	public:
		Merge(const Merge &) = delete;
		Merge &operator=(const Merge &) = delete;
		~Merge() = delete;

	private:
		static void merge(std::vector<Item> &a, std::vector<Item> &aux, size_t lo, size_t mid, size_t hi) {
			assert(isSorted(a, lo, mid));
			assert(isSorted(a, mid + 1, hi));

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

			assert(isSorted(a, lo, hi));
		}

		static void sort(std::vector<Item>& a, std::vector<Item>& aux, size_t lo, size_t hi) {
			if (hi <= lo) return;
			size_t mid = lo + (hi - lo) / 2;
			sort(a, aux, lo, mid);
			sort(a, aux, mid + 1, hi);
			merge(a, aux, lo, mid, hi);
		}


		static bool isSorted(const std::vector<Item> &a) {
			return isSorted(a, 0, a.size() - 1);
		}

		static bool isSorted(const std::vector<Item> &a, size_t lo, size_t hi) {
			for (size_t i = lo + 1; i <= hi; ++i) {
				if (a[i] < a[i - 1]) return false;
			}
			return true;
		}

		static void merge(const std::vector<Item> &a, std::vector<size_t> &index, std::vector<size_t> &aux, size_t lo, size_t mid, size_t hi) {
			for (size_t k = lo; k <= hi; ++k) {
				aux[k] = index[k];
			}

			size_t i = lo, j = mid + 1;
			for (size_t k = lo; k <= hi; ++k) {
				if (i > mid) index[k] = aux[j++];
				else if (j > hi) index[k] = aux[i++];
				else if (a[aux[j]] < a[aux[i]]) index[k] = aux[j++];
				else index[k] = aux[i++];
			}
		}

		static void sort(const std::vector<Item>& a, std::vector<size_t>& index, std::vector<size_t>& aux, size_t lo, size_t hi) {
			if (hi <= lo) return;
			size_t mid = lo + (hi - lo) / 2;
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

		static std::vector<size_t> indexSort(const std::vector<Item>& a) {
			std::vector<size_t>::size_type n = a.size();
			std::vector<size_t> index(n);
			for (int i = 0; i < n; ++i) {
				index[i] = i;
			}

			std::vector<size_t> aux(n);
			sort(a, index, aux, 0, n - 1);
			return index;
		}

	public:
		static void mainTest(int argc = 0, char *argv[] = nullptr) {
			std::vector<std::string> svec{"a","happy","boy","write","this","demo"};
			std::vector<std::string> cvec1(svec);
			std::vector<std::string> cvec2(svec);
			sort(svec);


			std::vector<size_t> index1 =indexSort(cvec2);
		}

	};
}

#pragma once
#include<vector>
#include<algorithm>
#include<cassert>

namespace algs4Cpp {
	template<typename Item>class Shell {
	public:
		Shell(const Shell &) = delete;
		Shell &operator=(const Shell &) = delete;
		~Shell() = delete;

	private:
		static bool isSorted(std::vector<Item> &a) {
			for (size_t i = 1; i < a.size(); ++i) {
				if (a[i] < a[i - 1]) return false;
			}
			return true;
		}

		static bool isHsorted(std::vector<Item> &a, size_t h) {
			for (size_t i = h; i < a.size(); ++i) {
				if (a[i] < a[i - h]) return false;
			}
			return true;
		}

		static void hSort(std::vector<Item>& a, size_t h) {
			using std::swap;
			for (size_t i = h; i < a.size(); ++i) {
				for (size_t j = i; (j >= h) && (a[j] < a[j - h]); j -= h) {
					swap(a[j], a[j - h]);
				}
			}
			assert(isHsorted(a, h));
		}

	public:
		static void sort(std::vector<Item>& a) {
			std::vector<Item>::size_type n = a.size();

			size_t h = 1;
			while (h < n / 3) h = 3 * h + 1;

			while (h >= 1) {
				hSort(a, h);
				h /= 3;
			}
			assert(isSorted(a));
		}
	};
}

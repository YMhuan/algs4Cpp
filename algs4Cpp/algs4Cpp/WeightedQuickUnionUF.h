#pragma once
#include<vector>
#include<stdexcept>
#include<string>
#include<iostream>
#include<memory>



namespace algs4Cpp {
	class WeightedQuickUnionUF {
	private:
		std::vector<size_t> parent;
		std::vector<size_t> size;
		size_t count;

	public:
		WeightedQuickUnionUF(int N) :count(N), parent(), size() {
			if (N < 0) throw std::invalid_argument("");
			parent.reserve(N);
			size.reserve(N);
			for (size_t i = 0; i != N; ++i) {
				parent.push_back(i);
				size.push_back(1);
			}
		}

		size_t find(size_t p) {
			validate(p);
			while (p != parent[p]) {
				p = parent[p];
			}
			return p;
		}

		size_t siteCount() {
			return count;
		}

		bool connected(size_t p, size_t q) {
			return find(p) == find(q);
		}

		void unionSite(size_t p, size_t q) {
			size_t rootP = find(p);
			size_t rootQ = find(q);
			if (rootP == rootQ) return;

			if (size[rootP] < size[rootQ]) {
				parent[rootP] = rootQ;
				size[rootQ] += size[rootP];
			}
			else {
				parent[rootQ] = rootP;
				size[rootP] += size[rootQ];
			}
			--count;
		}

	private:
		void validate(size_t p) {
			std::vector<size_t>::size_type N = parent.size();
			if (p >= N) {
				throw std::out_of_range("index" + std::to_string(p) + "is not between 0 and " + std::to_string(N - 1));
			}
		}

	public:
		static void mainTest(int argc, char *argv[]) {
			size_t n;
			std::cin >> n;
			WeightedQuickUnionUF uf(n);
			size_t p, q;
			while (std::cin >> p >> q) {
				if (uf.connected(p, q)) continue;
				uf.unionSite(p, q);
				std::cout << p << " " << q << std::endl;
			}
			std::cout << uf.siteCount() << " components";
		}

	};
}

#pragma once
#include<vector>
#include<string>
#include<stdexcept>
#include<iostream>

namespace algs4Cpp {
	class QuickUnionUF {
	private:
		std::vector<size_t> parent;
		size_t count;

	public:
		QuickUnionUF(size_t n):count(n),parent() {
			parent.reserve(n);
			for (size_t i = 0; i < n; ++n) {
				parent.push_back(i);
			}
		}

		size_t siteCount() {
			return count;
		}

		size_t find(int p) {
			validate(p);
			while (p != parent[p]) {
				p = parent[p];
			}
		}

	private:
		void validate(size_t p) {
			std::vector<size_t>::size_type N = parent.size();
			if (p >= N) {
				throw std::out_of_range("index" + std::to_string(p) + "is not between 0 and " + std::to_string(N - 1));
			}
		}

		bool connected(size_t p, size_t q) {
			return find(p) == find(q);
		}

		void unionSite(size_t p, size_t q) {
			size_t rootP = find(p);
			size_t rootQ = find(q);
			if (rootP == rootQ) return;
			parent[rootP] = rootQ;
			--count;
		}

	public:
		static void mainTest(int argc, char *argv[]) {
			size_t n;
			std::cin >> n;
			QuickUnionUF uf(n);
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
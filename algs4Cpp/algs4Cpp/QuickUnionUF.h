#pragma once
#include<vector>
#include<string>
#include<stdexcept>
#include<iostream>

namespace algs4Cpp {
	class QuickUnionUF {
	private:
		std::vector<int> parent;
		int count;

	public:
		QuickUnionUF(int n):count(n),parent() {
			parent.reserve(n);
			for (int i = 0; i < n; ++n) {
				parent.push_back(i);
			}
		}

		int siteCount() {
			return count;
		}

		int find(int p) {
			validate(p);
			while (p != parent[p]) {
				p = parent[p];
			}
		}

	private:
		void validate(int p) {
			int N = parent.size();
			if (p < 0 || p >= N) {
				throw std::out_of_range("index" + std::to_string(p) + "is not between 0 and " + std::to_string(N - 1));
			}
		}

		bool connected(int p, int q) {
			return find(p) == find(q);
		}

		void unionSite(int p, int q) {
			int rootP = find(p);
			int rootQ = find(q);
			if (rootP == rootQ) return;
			parent[rootP] = rootQ;
			--count;
		}

	public:
		static void mainTest(int argc, char *argv[]) {
			int n;
			std::cin >> n;
			QuickUnionUF uf(n);
			int p, q;
			while (std::cin >> p >> q) {
				if (uf.connected(p, q)) continue;
				uf.unionSite(p, q);
				std::cout << p << " " << q << std::endl;
			}
			std::cout << uf.siteCount() << " components";
		}
	};
}
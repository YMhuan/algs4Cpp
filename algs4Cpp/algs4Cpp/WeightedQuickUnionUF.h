#pragma once
#include<vector>
#include<stdexcept>
#include<string>
#include<iostream>
#include<memory>



namespace algs4Cpp {
	class WeightedQuickUnionUF {
	private:
		std::vector<int> parent;
		std::vector<int> size;
		int count;

	public:
		WeightedQuickUnionUF(int N) :count(N), parent(), size() {
			if (N < 0) throw std::invalid_argument("");
			parent.reserve(N);
			size.reserve(N);
			for (int i = 0; i != N; ++i) {
				parent.push_back(i);
				size.push_back(1);
			}
		}

		int find(int p) {
			validate(p);
			while (p != parent[p]) {
				//parent[p] = parent[parent[p]];
				p = parent[p];
			}
			return p;
		}

		int siteCount() {
			return count;
		}

		bool connected(int p, int q) {
			return find(p) == find(q);
		}

		void unionSite(int p, int q) {
			int rootP = find(p);
			int rootQ = find(q);
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
		void validate(int p) {
			int N = parent.size();
			if (p < 0 || p >= N) {
				throw std::out_of_range("index" + std::to_string(p) + "is not between 0 and " + std::to_string(N - 1));
			}
		}

	public:
		static void mainTest(int argc, char *argv[]) {
			int n;
			std::cin >> n;
			WeightedQuickUnionUF uf(n);
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

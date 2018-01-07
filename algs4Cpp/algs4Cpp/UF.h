#pragma once
#include<vector>
#include<stdexcept>
#include<string>
#include<iostream>

namespace algs4Cpp {
	class UF {
	private:
		std::vector<int> parent;
		std::vector<char> rank;
		int count;

	public:
		UF(int N) :count(N) {
			if (N < 0) throw std::invalid_argument("");
			parent.reserve(N);
			rank.reserve(N);
			for (int i = 0; i != N; ++i) {
				parent.push_back(i);
				rank.push_back(0);
			}
		}

		int find(int p) {
			validate(p);
			while (p != parent[p]) {
				parent[p] = parent[parent[p]];
				p = parent[p];
			}
			return p;
		}

		int siteCount() {
			return count;
		}

		bool conntected(int p, int q) {
			return find(p) == find(q);
		}

		void unionSite(int p, int q) {
			int rootP = find(p);
			int rootQ = find(q);
			if (rootP == rootQ) return;

			if (rank[rootP] < rank[rootQ]) parent[rootP] = rootQ;
			else if (rank[rootP] > rank[rootQ]) parent[rootQ] = rootP;
			else {
				parent[rootQ] = rootP;
				++rank[rootP];
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
			UF uf(n);
			int p, q;
			while (std::cin >> p >> q) {
				if (uf.conntected(p, q)) continue;
				uf.unionSite(p, q);
				std::cout << p << " " << q << std::endl;
			}
			std::cout << uf.siteCount() << " components";
		}

	};
}

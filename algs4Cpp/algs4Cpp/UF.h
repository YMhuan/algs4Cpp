#pragma once
#include<vector>
#include<stdexcept>
#include<string>
#include<iostream>
#include<memory>

//#define DllOutput
#ifdef DllOutput
	#define DllExport   __declspec( dllexport )  
#else
	#define DllExport
#endif

namespace algs4Cpp {
	class DllExport UF {
	private:
		std::vector<size_t> parent;
		std::vector<unsigned char> rank;
		size_t count;

	public:
		UF(size_t N) :count(N),parent(), rank() {
			if (N < 0) throw std::invalid_argument("");
			parent.reserve(N);
			rank.reserve(N);
			for (size_t i = 0; i != N; ++i) {
				parent.push_back(i);
				rank.push_back(0);
			}
		}

		size_t find(size_t p) {
			validate(p);
			while (p != parent[p]) {
				parent[p] = parent[parent[p]];
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

			if (rank[rootP] < rank[rootQ]) parent[rootP] = rootQ;
			else if (rank[rootP] > rank[rootQ]) parent[rootQ] = rootP;
			else {
				parent[rootQ] = rootP;
				++rank[rootP];
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
		static void mainTest(int argc=0, char *argv[]=nullptr) {
			size_t n;
			std::cin >> n;
			UF uf(n);
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

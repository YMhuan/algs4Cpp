#pragma once
#include<vector>
#include<string>
#include<stdexcept>
#include<iostream>

namespace algs4Cpp {
	class QuickFindUF {
	private:
		std::vector<int> id;
		int count;

	public:
		QuickFindUF(int N):count(N),id() {
			id.reserve(N);
			for (int i = 0; i != N; ++i) {
				id.push_back(i);
			}
		}

		int siteCount() {
			return count;
		}

		int find(int p) {
			validate(p);
			return id[p];
		}

		bool connected(int p, int q) {
			validate(p);
			validate(q);
			return id[p] == id[q];
		}

		void unionSite(int p, int q) {
			validate(p);
			validate(q);
			int pID = id[p];
			int qID = id[q];

			if (pID == qID) return;

			for (int i = 0; i != id.size(); ++i) {
				if (id[i] == pID) id[i] = qID;
				--count;
			}
		}

	private:
		void validate(int p) {
			int N = id.size();
			if (p < 0 || p >= N) {
				throw std::out_of_range("index" + std::to_string(p) + "is not between 0 and " + std::to_string(N - 1));
			}
		}

	public:
		static void mainTest(int argc, char *argv[]) {
			int n;
			std::cin >> n;
			QuickFindUF uf(n);
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

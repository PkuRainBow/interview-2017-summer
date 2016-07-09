#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
#include <math.h>

using namespace std;

int getCharAt(int pos) {
	/** first char **/
	if (pos == 1)
		return 0;
	double log_pos = log2((double)(pos + 1));
	int ceil_pos = ceil(log_pos);
	int floor_pos = floor(log_pos);
	/** middle inserted 0 **/
	if (ceil_pos == floor_pos) {
		return 0;
	}
	/** the last char 1 **/
	else if (pow(2, ceil_pos) == pos + 1) {
		return 1;
	}
	/** other cases **/
	else {
		return 1 - getCharAt(pow(2, floor_pos + 1) - pos);
	}
}

int main_round_2016_a_a() {
	std::ifstream in("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
	std::cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

	std::ofstream out("out.txt");
	std::streambuf* coutbuf = std::cout.rdbuf();
	std::cout.rdbuf(out.rdbuf());

	int T = 0;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int cur;
		cin >> cur;
		cout << getCharAt(cur);
	}
	return 1;
}
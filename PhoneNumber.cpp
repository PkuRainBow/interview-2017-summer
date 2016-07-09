#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

map<int, string> dict;
map<int, string> dup_dict;

void init() {
	dict[0] = "zero";
	dict[1] = "one";
	dict[2] = "two";
	dict[3] = "three";
	dict[4] = "four";
	dict[5] = "five";
	dict[6] = "six";
	dict[7] = "seven";
	dict[8] = "eight";
	dict[9] = "nine";

	dup_dict[2]
}

string num2str(vector<int>& nums) {
	int len = nums.size();
	string result = "";
	int count = 1;
	int end = 0;
	while (end < len) {
		count = 1;
		while (nums[end] == nums[end + 1]) {
			end++;
			count++;
		}
		
		end++;
	}
}
#include <iostream>
#include <string>
#include <vector>
#include <fstream> 
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

void solve_gRanks_wrong() {
	string name_list[10010];
	long long score[10010];
	long long weight[10010];
	long long score_count[10010];
	vector<vector<long>> score_list(10010, vector<long>(10010, 0));
	vector<pair<long, string>> final_score;

	int P, N, M;
	int ath_id = 0;
	map<string, int> rank_list;

	cin >> P;
	for (int i = 0; i < P; i++) {
		cin >> score[i];
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> weight[i];
		for (int j = 0; j < P; j++) {
			string ath_name;
			cin >> ath_name;
			if (rank_list.find(ath_name) == rank_list.end()) {
				name_list[ath_id] = ath_name;
				score_count[ath_id] = 0;
				rank_list.insert(make_pair(ath_name, ath_id));
				score_list[ath_id][score_count[ath_id]] = weight[i] * score[j];
				ath_id++;
			}				
			else {
				score_count[rank_list[ath_name]]++;
				score_list[rank_list[ath_name]][score_count[rank_list[ath_name]]] = weight[i] * score[j];
			}
		}
	}
	cin >> M;
	/** calculate the M highest score for each athelete **/
	for (int i = 0; i < ath_id; i++) {
		sort(score_list[i].rbegin(), score_list[i].rend());
		int cur_score = 0;
		for (int j = 0; j < M; j++) {
			cur_score += score_list[i][j];
		}
		final_score.push_back(make_pair(cur_score, name_list[i]));
	}
	sort(final_score.begin(), final_score.end(), [](const pair<long long, string> &a, const pair<long long, string> &b) {
		if (a.first == b.first)  return a.second < b.second;
		else return a.first > b.first; });

	int rank_id = 0;
	for (int i = 0; i < ath_id; i++) {
		if (i > 0 && final_score[i].first == final_score[i - 1].first) {
			cout << rank_id << ": " << final_score[i].second << endl;
		}
		else {
			rank_id = i + 1;
			cout << rank_id << ": " << final_score[i].second << endl;
		}
	}
	return;
}

void solver_gRanks() {
	int nplaces;
	cin >> nplaces;
	vector<int> place(nplaces);
	for (auto& x : place)
		cin >> x;
	int ncompet;
	cin >> ncompet;
	map<string, priority_queue<int>> record;
	for (int i = 0; i < ncompet; i++) {
		int weight;
		cin >> weight;
		for (int j = 0; j < nplaces; j++) {
			string name;
			cin >> name;
			record[name].push(weight * place[j]);
		}
	} 
	int limit;
	cin >> limit;
	map<string, int> score;
	for (auto &x : record) {
		for (int i = 0; i < limit && !x.second.empty(); ++i) {
			score[x.first] += x.second.top();
			x.second.pop();
		}
	}

	vector<pair<int, string>> ans;
	for (auto &x : score)
		ans.push_back(make_pair(x.second, x.first));
	sort(ans.begin(), ans.end(), 
		[](const pair<int, string> &a, const pair<int, string> &b) 
		{ return a.first > b.first || (a.first == b.first && a.second < b.second); });
	int rank = 0;
	for (int i = 0; i < ans.size(); i++) {
		if (i == 0 || ans[i].first != ans[i - 1].first)
			rank = i + 1;
		cout << rank << ": " << ans[i].second << endl;
	}
}


int main_gRanks() {
	freopen("A-large-practice.in", "r", stdin);
	freopen("A-large-practice.out", "w", stdout);
	int T = 0;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cout << "Case #" << i + 1 << " :" << endl;
		solver_gRanks();
		//solve_gRanks_wrong();
	}
	return 0;
}
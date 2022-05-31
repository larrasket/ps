class Solution {
public:
	int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
		unordered_set<int> forbi(forbidden.begin(), forbidden.end());
		vector<vector<int>> visited(2,vector<int>(7000));
		// visited array has two states:
		// visited[0][i] means the ith cell was reached from its left hand side jumping forward,
		// visited[1][i] means the ith cell was reached from its right hand side jumping backward.
		queue<pair<int,bool>> qu;
		// true means your last jump was backward jumping, you cannot jump backward in current step.
		// false, otherwise.
		qu.push({0,false});
		visited[0][0] = 1;
		visited[1][0] = 1;
		int ans = 0;
		while(!qu.empty()) {
			int len = qu.size();
			while(len > 0) {
				len--;
				int cur = qu.front().first;
				bool flag = qu.front().second;
				if(cur == x) {
					return ans;
				}
				qu.pop();
				int forward = cur + a;
				int backward = cur - b;
				if(forward < 7000 && visited[0][forward] == 0 && !forbi.count(forward)) {
					qu.push({forward,false});
					visited[0][forward] = 1;
				}
				if(backward >=0 && visited[1][backward] == 0 && !forbi.count(backward) && !flag) {
					qu.push({backward,true});
					visited[1][backward] = 1;
				}
			}
			ans++;
		}
		return -1;
	}
};

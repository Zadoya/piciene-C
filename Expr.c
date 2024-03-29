using namespace std;
 
void get_levels(string& Expr, int& index, int depth, vector<string>& Answer) {
	Answer[depth] += Expr[index];
	index--;
	if (isupper(Expr[index+1])) {
		get_levels(Expr, index, depth + 1, Answer);
		get_levels(Expr, index, depth + 1, Answer);
	}
}
 
 
int main() {
	int n, index;
    n = 5;
	string Expr;
	for (int k = 0; k < n; k++) {
		cin >> Expr;						
		vector<string> Answer(Expr.size(), "");
		index = Expr.size() - 1;
		get_levels(Expr, index, 0, Answer);
		for (int k = Expr.size() - 1; k >= 0; k--)
			cout << Answer[k];
		cout << endl;
	}
	return 0;
}
#define alphabet 27

struct vertex{
	int edges[alphabet];
	bool key = false;

	vertex() {
		fill(begin(edges), end(edges), -1);
	}
};

vector<vertex> trie(1); // initialize trie with root only

void add(string const& s) {
	int v = 0;
	for(char ch : s) {
		int c = ch - 'a';
		if(trie[v].edges[c] == -1) {
			trie[v].edges[c] = trie.size();
			trie.emplace_back();
		}
		v = trie[v].edges[c];
	}
	trie[v].key = true;
}

bool find(string const& s) {
	int v = 0;
	for(char ch : s){
		int c = ch - 'a';
		if(trie[v].edges[c] == -1)
			return false;
		v = trie[v].edges[c];
	}
	return trie[v].key;
}
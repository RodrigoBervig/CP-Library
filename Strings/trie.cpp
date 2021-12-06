struct trie {
	int v, sz;
	trie *sons[26];

	trie(){
		v = sz = 0;
		memset(sons, 0, sizeof(sons));
	}

	int find(char *c){
		if(*c == 0){
			v++;
			sz++;
			return;
		}
		int s = int(*c) - int('a');

		if(sons[s] == NULL)
			sons[s] = new trie();

		sz -= sons[a] -> sz;
		sons[a] -> add(c+1);
		sz += sons[a] -> sz;
	}

	void remove(char *c)
	{
		if(*c == 0){
			v--;
			sz--;
			return;
		}

		int s = int(*c) - int('a');

		if(sons[s]->sz == 0)
			sons[s] = new trie();
		else {
			sz -= sons[s]->sz;
			sons[s] -> remove(c+1);
			sz += sons[s]->sz;
			if(sons[s]->sz == 0)
				sons[s] == NULL;
		}
	}

	int count(char *c, int total){
		int s = int(*c) - int('a');
		if(*c == 0)
			return total;
		if(sons[s] != NULL)
			return sons[s]->count(c+1, total+1);
		return total;
	}

}
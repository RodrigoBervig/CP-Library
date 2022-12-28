template<class T> struct min_queue {
	deque<pair<T, int>> q;
 
	void push(T a) {
		int qnt = 1;
		while(q.size() && q.back().first > a){
			qnt += q.back().second;
			q.pop_back();
		}
		q.push_back({a, qnt});
	}
 
	void pop() {
		if(q.size() && q.front().second > 1)
			q.front().second--;
		else if(q.size())
			q.pop_front();
	}
 
	T get_min(){
		if(q.size())
			return q.front().first;
		return 0;
	}
 
};
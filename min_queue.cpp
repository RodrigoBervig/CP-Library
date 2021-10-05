// the idea is to get the min value of a queue in O(1)
// to acomplish this, we use 2 min stack to simulate the queue


stack<pair<int,int>> s1, s2;

//finding the minimum:
if (s1.empty() || s2.empty())
	minimum = s1.empty() ? s2.top().second : s1.top().second;
else
	minimum = min(s1.top().second, s2.top().second);


//add element:
int minimum = s1.empty() ? new_el : min(new_el, s1.top().second);
s1.push({new_el, minimum});

//removing an element:
if(s2.empty()){
	while(!s1.empty()){
		int el = s1.top().first;
		s1.pop();
		int minimum = s2.empty() ? el : min(el, s2.top().second);
		s2.push({el, minimum});
	}
}
int remove_element = s2.top().first;
s2.pop();

// an application:
// finding the minimum for all subarrays of fixed length in an array in O(n):
// add M elements to the queue, get the minimum, remove one and add the next untill you have added all elements in the array

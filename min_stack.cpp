/*we want to modify the stack structure in such a way that it is possible to find the minimum element in the stack in O(1)*/

stack<pair<int,int>> st;

// it is clear the finding the minimum consists of looking at top().second


int new_min = st.empty() ? new_el : min(new_el, st.top().second);
st.push({new_el, new_min});


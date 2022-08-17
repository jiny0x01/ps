#include <iostream>
#include <array>
using namespace std;
template<typename type>
class max_heap{
public:
	max_heap();
	void insert(type);
	void remove(int );
	int find(type);
	void sort();
	void print();
	void heapify(int);
	type get(type);
	type operator[](const int);
	size_t size() const;

	int get_left_child_idx(int);
	int get_right_child_idx(int);
	int get_parent_idx(int);

	type get_left_child(int);
	type get_right_child(int);
	type get_parent(int);
private:
	std::array<type, 100002> data;
	size_t len = 0;
};

int main() {
/*
	max_heap<int> heap;
	heap.insert(1);
	heap.insert(5);
	heap.insert(8);
	heap.insert(7);
	heap.insert(9);
	heap.insert(2);
	heap.insert(3);
	heap.insert(10);
	heap.print();
	heap.remove(7);
	heap.remove(2);
	heap.remove(3);
	heap.print();
	heap.sort();
	heap.print();
*/
	cin.tie(0);
	cin.sync_with_stdio(false);
	max_heap<int> heap;
	int n;

	cin >> n;
	while(n--) {
		int num;
		cin >> num;

		if(!num) {
			if(heap.size() == 0)
				cout << 0 << "\n";
			else {
//				heap.sort();	
				cout << heap[1] << "\n";
				heap.remove(1);
			}
		}
		else {
			heap.insert(num);
		}
	//	heap.print();
//		heap.sort();
	}
	return 0;
}
/*
int get_left_child(vector<int>& heap, int idx) {
	assert(idx*2 >= 1 && idx*2 <= heap.size());
	if(idx*2 > heap.size()) return -1;
	return heap[idx*2];
}

int get_right_child (vector<int>& heap, int idx) {
	assert(idx*2+1 >= 1 && idx*2+1 <= heap.size());
	if(idx*2+1 > heap.size()) return -1;
	return heap[idx*2+1];
}



void max_heapify(vector<int>& heap, int idx) {
	if(get_left_child(heap, idx) == -1 &&
	   get_right_child(heap, idx) == -1)
		return;
	int bigger = max(get_left_child(heap, idx), get_right_child(heap, idx));
	if(heap[idx] >= heap[bigger]) return;

	swap(heap[idx], heap[bigger]);
	max_heapify(heap, bigger);
}

void build_max_heap(vector<int>& heap) {
	for(int i = heap.size()/2; ;i--)	{
		max_heapify(heap, i);
	}
}

void heapsort(vector<int>& heap) {
	build_max_heap(heap);
	for(int i = heap.size(); i >= 2; i--){

	}
}

*/


template<typename type>
max_heap<type>::max_heap() {
	// 편의를 위해 안쓰는 데이터
	data[0] = 0;
}

template<typename type>
void max_heap<type>::insert(type d) {
	++this->len;
	data[this->len] = d;

	for(int idx = this->len; idx > 1; idx = get_parent_idx(idx)) {
		if(data[idx] < get_parent(idx)) break;
		swap(data[idx], data[get_parent_idx(idx)]);
	}
}

template<typename type>
void max_heap<type>::remove(int idx) {
	if(len == 0) return;
	swap(data[idx], data[len]);	
	this->len--;
	heapify(idx);
}

template<typename type>
int max_heap<type>::find(type t) {
	for(int i=1; i<=this->len; i++) {
		if(t == data[i]) return i;
	}
	return 0;
}

template<typename type>
void max_heap<type>::sort() {
	for(int i = this->len; i > 0; i--) {
		heapify(i);
	}
} // 힙 쏘트 3줄컷

template<typename type>
void max_heap<type>::print() {
	cout << "=====print heap=====\n";
	for(int i = 1; i <= this->len; i++) {
		cout << data[i] << ' ';
	}
	cout << '\n';
}

template<typename type>
int max_heap<type>::get_left_child_idx(int p_idx) {
	if(p_idx * 2 > this->len) return 0;
	return p_idx*2;
}

template<typename type>
int max_heap<type>::get_right_child_idx(int p_idx) {
	if(p_idx * 2+1 > this->len) return 0;
	return p_idx*2+1;
}

template<typename type>
int max_heap<type>::get_parent_idx(int p_idx) {
	if(p_idx < 0 || p_idx > this->len) return 0;
	return p_idx / 2;
}

template<typename type>
type max_heap<type>::get_left_child(int p_idx) {
	return data[get_left_child_idx(p_idx)];
}

template<typename type>
type max_heap<type>::get_right_child(int p_idx) {
	return data[get_right_child_idx(p_idx)];
}


template<typename type>
type max_heap<type>::get_parent(int p_idx) {
	return data[get_parent_idx(p_idx)];
}

template<typename type>
void max_heap<type>::heapify(int idx){
	if(idx < 1) return;
	// 부모보다 작을 경우

	if(data[idx] >= get_left_child(idx) && data[idx] >= get_right_child(idx)) return;

	int bigger_idx = get_left_child(idx) > get_right_child(idx) ? get_left_child_idx(idx) : get_right_child_idx(idx);

	swap(data[idx], data[bigger_idx]);
	heapify(bigger_idx);
}


template<typename type>
type max_heap<type>::get(type t) {
	return data[find(t)];
}

template<typename type>
size_t max_heap<type>::size() const{
	return this->len;
}

template<typename type>
type max_heap<type>::operator[](const int idx) {
	if(idx < 1 && idx > this->len) return data[0];

	return data[idx];
}

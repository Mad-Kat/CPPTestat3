#ifndef INDEXABLESET_H_
#define INDEXABLESET_H_

#include <set>

#include <functional>

template<class T, class Compare = std::less<T>>
class IndexableSet: std::set<T, Compare> {
	T element;
public:

	IndexableSet() = default;
	IndexableSet(std::initializer_list<T> li) :
			std::set<T, Compare> { li } {
	}
	template<typename ITER>
	IndexableSet(ITER b, ITER e) :
			std::set<T, Compare>(b, e) {
	}

	//IndexableSet(size_type n, T const &val):std::set(n,val){}

	T const& front() {
		return *this->begin();
	}

	T const& back() {
		return *this->end();
	}

	T& operator[](int index) {
		return at(index);
	}

	T const& operator[](int index) const {
		return at(index);
	}

	T & at(int const& index) {
		if (index < 0)
			element = *std::prev(this->end(), -index);
		else
			element = *std::next(this->begin(), index);
		return this->element;

	}

	T const & at(int index) const {
		if (index < 0)
			element = *std::prev(this->end(), index);
		else
			element = *std::next(this->begin(), index);
		return this->element;
	}

};

//template<typename T> class dynArray {
//	using container=std::vector<T>;
//	container v;
//public:
//	using size_type = typename container::size_type;
//	using iterator = typename container::iterator;
//	using const_iterator = typename container::const_iterator;
//	using reverse_iterator = typename container::reverse_iterator;
//	using const_reverse_iterator = typename container::const_reverse_iterator;
//
//	dynArray()=default;
//	dynArray(std::initializer_list<T> li):v{li}{}
//	template <typename ITER>
//	dynArray(ITER b, ITER e):v(b,e){}
//	dynArray(size_type n, T const &val):v(n,val){}
//	size_type size() const {
//		return v.size();
//	}
//	bool empty() const {
//		return v.empty();
//	}
//	T& operator[](int index){
//		return at(index);
//	}
//	T const& operator[](int index)const{
//		return at(index);
//	}
//	T & at(int index) {
//		if (index<0) return v.at(size()+index);
//		else return v.at(index);
//	}
//	T const & at(int index) const {
//		if (index<0) return v.at(size()+index);
//		else return v.at(index);
//	}
//	void push_back(T const & t) { v.push_back(t); }
//	T const & front() const { return v.front(); }
//	T & front()  { return v.front(); }
//	T const& back() const { return v.back(); }
//	T & back() { return v.back(); }
//	void pop_back() { v.pop_back(); }
//	iterator begin() { return v.begin(); }
//	iterator end() { return v.end(); }
//	const_iterator begin() const { return v.begin(); }
//	const_iterator end() const { return v.end(); }
//	reverse_iterator rbegin() { return v.rbegin(); }
//	reverse_iterator rend()  { return v.rend(); }
//	const_reverse_iterator rbegin() const { return v.rbegin(); }
//	const_reverse_iterator rend() const { return v.rend(); }
//	const_iterator cbegin() const { return v.cbegin(); }
//	const_iterator cend() const { return v.cend(); }
//	const_reverse_iterator crbegin() const { return v.crbegin(); }
//	const_reverse_iterator crend() const { return v.crend(); }
//	void resize(size_type newsize) { v.resize(newsize); }
//};
//template<typename T>
//dynArray<T> make_dynArray(std::initializer_list<T> l) {
//return dynArray<T>(l);
//}

#endif /* INDEXABLESET_H_ */

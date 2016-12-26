#pragma once
using namespace std;
template<typename T>
class DoubleLinked
{
public:
	DoubleLinked();
	~DoubleLinked();
	void addToBegin(T);
	void addToEnd(T);
	void add(T,T);
	void show();
	void delFirst();
	void delEnd();
private:
	class Item
	{
	public:
		friend class DoubleLinked;
		Item(int data = 0) :data_(data), pnext_(nullptr), pprev_(nullptr) {};
		//~Item();

	private:
		T data_;
		Item*pnext_;
		Item*pprev_;
	}; //*listBegin, *listEnd;
//abo:
	Item*listBegin;
	Item*listEnd;
};

template<typename T>
DoubleLinked<T>::DoubleLinked()
{
	listBegin = nullptr;
	listEnd = nullptr;
}
template<typename T>
DoubleLinked<T>::~DoubleLinked()
{
}
template<typename T>
void DoubleLinked<T>::addToBegin(T n) {
	Item*it = new Item(n);
	if (listBegin == nullptr) {
		listBegin = it;
		listEnd = it;
	}
	else {
		it->pnext_ = listBegin;
		listBegin->pprev_ = it;
		listBegin = it;
	}
}
template<typename T>
void DoubleLinked<T>::show() {
	Item*tmp = listBegin;
	while (tmp) {
		cout << tmp->data_ << "\t";
		tmp = tmp->pnext_;
	}
	cout << endl;
}
template<typename T>
inline void DoubleLinked<T>::delFirst()
{
	if (listBegin == nullptr) {
		return;
	}
	else {
		Item*it = listBegin;
		it->pnext_->pprev_ = nullptr;
		listBegin = listBegin->pnext_;
		delete it;
	}
}
template<typename T>
inline void DoubleLinked<T>::delEnd(){
	if (!listBegin)
		return;
	else {
		Item*tmp = listBegin;
		while (tmp->pnext) {
			if (tmp->pnext->pnext == nullptr) {
				Item*del=tmp->
			}
		}
	}
}
template<typename T>
void DoubleLinked<T>::addToEnd(T n) {
	Item*it = new Item(n);
	if (listBegin == nullptr) {
		listBegin = it;
		listEnd = it;
	}
	else {
		Item*tmp = listBegin;
		while (tmp->pnext_) {
			tmp = tmp->pnext_;
		}
		tmp->pnext_ = it;
		listEnd = it;
	}
}
template<typename T>
void DoubleLinked<T>::add(T num, T val) {
	Item *it = new Item(val);
	if (listBegin == nullptr) {
		listBegin = it;
		listEnd = it;
	}
	else {
		Item*tmp = listBegin;
		if (listBegin->pnext_ == nullptr)
			addToEnd(val);
		else if (listEnd->pprev_ == nullptr)
			addToBegin(val);
		else
			while (tmp->pnext_) {
				if (tmp->data_ == num) {
					it->pnext_ = tmp->pnext_;
					tmp->pnext_->pprev_ = it;
					it->pprev_ = tmp;
					tmp->pnext_ = it;
				}
				tmp = tmp->pnext_;
			}
	}
}

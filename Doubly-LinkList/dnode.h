#pragma once
template <typename T>
struct denode {
	denode<T> *next, *prev;
	T val;
};

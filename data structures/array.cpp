#include <iostream>
#include <stdexcept>

template<typename T, size_t S>
class array {
public:
	using reference = T&;
	using const_reference = const T&;
	using pointer = T*;
	using const_pointer = const T*;

	T _data[S];

	using ostream = std::ostream;
	static friend ostream& operator<<(ostream& ostream, array& arr) {
		for (size_t i = 0; i < arr.size(); i++) {
			ostream << arr[i];
		}
		return ostream;
	}

	constexpr reference at(size_t index) {
		if (index >= S) throw std::out_of_range{"Out of range"};
		return _data[index];
		
	}
	constexpr const_reference at(size_t index) const {
		if (index >= S) throw std::out_of_range{ "Out of range" };
		return _data[index];
	}

	constexpr reference operator[](size_t index) {
		return _data[index];
	}
	constexpr const_reference operator[](size_t index) const {
		return _data[index];
	}

	constexpr reference front() {
		return _data[0];
	}
	constexpr const_reference front() const{
		return _data[0];
	}

	constexpr reference back() {
		return _data[S - 1];
	}
	constexpr const_reference back() const {
		return _data[S - 1];
	}

	constexpr pointer data() {
		return _data;
	}
	constexpr const_pointer data() const {
		return _data;
	}

	constexpr bool empty() const {
		return S == 0;
	}
	constexpr size_t size() const {
		return S;
	}
	constexpr size_t max_size() const {
		return S;
	}

	constexpr void fill(const_reference value) {
		for (size_t i = 0; i < S; i++) {
			_data[i] = value;
		}
	}
	constexpr void swap(array& other) {
		array& thisref = *this;
		for (size_t i = 0; i < size(); i++) {
			T temp = thisref[i];
			thisref[i] = other[i];
			other[i] = temp;
		}
	}
};
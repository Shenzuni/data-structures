#include <vector>

template<typename T>
class vector {
public:
	using reference = T&;
	using const_reference = const T&;
	using pointer = T*;
	using const_pointer = const T*;

	constexpr void reserve(size_t capacity) {
		if (capacity <= _size) {
			return;
		}

		T* array = (T*)::operator new(capacity * sizeof(T)); //allocate block

		for (size_t i = 0; i < _size; i++) {
			array[i] = _array[i];
		}

		::operator delete(_array, _capacity * sizeof(T)); //delete prev block

		_array = array;
		_capacity = capacity;
	}
	constexpr void resize(size_t size) {
		//implement, for size < _size, range destructor
	}

	constexpr const size_t size() const { 
		return _size; 
	}
	constexpr const size_t capacity() const {
		return _capacity;
	}
	constexpr const T* data() const {
		return _array;
	}

private:
	T* _array = nullptr;

	size_t _size = 0;
	size_t _capacity = 0;
};
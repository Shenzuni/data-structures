#include <iostream>
#include <stdexcept>
#include <initializer_list>

template<typename T>
class vector {
public:
	using reference = T&;
	using const_reference = const T&;
	using pointer = T*;
	using const_pointer = const T*;

	constexpr vector(std::initializer_list<T> init) {
		_appendinit(init);
	}
	constexpr vector(size_t count) {
		_resize(count);
	}
	constexpr vector(size_t count, const T& values) {
		_resize(count, &values);
	}

	constexpr vector& operator=(std::initializer_list<T> init) {
		_appendinit(init);
	}
	
	constexpr reference at(size_t index) {
		if (index >= _size) throw;
		return _array[index];
	}
	constexpr reference operator[](size_t index) {
		return _array[index];
	}
	constexpr reference front() {
		return _array[0];
	}
	constexpr reference back() {
		return _array[_size];
	}
	constexpr pointer data() const {
		return _array;
	}

	constexpr bool empty() {
		return _size == 0;
	}
	constexpr const size_t size() const {
		return _size;
	}
	constexpr void reserve(size_t newcapacity) {
		if (newcapacity > _size) _realloc(newcapacity);
	}
	constexpr const size_t capacity() const {
		return _capacity;
	}
	constexpr void shrinktofit() {
		if (_capacity > _size) _realloc(_size);
	}

	constexpr void clear() {
		_resize(0);
	}
	constexpr void pushback(const T& newvalue) {
		if (_size == _capacity) reserve(_capacity + 10);
		_array[_size++] = newvalue;
	}
	constexpr void popback() {
		_array[_size--].~T();
	}
	constexpr void resize(size_t newsize) {
		_resize(newsize);
	}
	constexpr void resize(size_t newsize, const T& newvalues) {
		_resize(newsize, &newvalues);
	}
	
private:
	constexpr void _resize(size_t newsize, const T* newvalues = nullptr) {
		if (newsize == _size) return;
		if (newsize < _size) {
			for (size_t i = newsize; i < _size; i++) {
				_array[i].~T();
			}
		}
		if (newsize > _size) {
			if (newsize > _capacity) reserve(newsize);
			for (size_t i = _size; i < newsize; i++) {
				if (newvalues == nullptr) {
					new(&_array[i]) T();
				}
				else {
					_array[i] = *newvalues;
				}

			}
		}
		_size = newsize;
	}
	constexpr void _realloc(size_t newcapacity) {
		if (newcapacity < _size) {
			_size = newcapacity;
		}

		const size_t newbytes = newcapacity * sizeof(T);
		const size_t oldbytes = _capacity * sizeof(T);

		T* array = (T*)::operator new(newbytes); //allocate block	

		for (size_t i = 0; i < _size; i++) {
			array[i] = _array[i];
		}

		::operator delete(_array, oldbytes); //delete prev block

		_array = array;
		_capacity = newcapacity;
	}
	constexpr void _appendinit(std::initializer_list<T> init) {
		const size_t& size = init.size();

		if (size + _size > _capacity) _realloc(size + _size);

		for (auto* e = init.begin(); e != init.end(); e++) {
			pushback(*e);
		}
	}

	T* _array = nullptr;
	size_t _size = 0;
	size_t _capacity = 0;
};
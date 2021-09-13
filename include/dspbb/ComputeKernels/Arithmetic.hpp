#pragma once

#include "VectorizedAlgorithms.hpp"


namespace dspbb::kernels {

//------------------------------------------------------------------------------
// Vector-vector operations.
//------------------------------------------------------------------------------

template <class R, class T, class U>
void Multiply(R* out, const T* a, const U* b, size_t length) {
	BinaryOperationVectorized(out, a, b, length, [](const auto& a, const auto& b) { return a * b; });
}


template <class R, class T, class U>
void Divide(R* out, const T* a, const U* b, size_t length) {
	BinaryOperationVectorized(out, a, b, length, [](const auto& a, const auto& b) { return a / b; });
}


template <class R, class T, class U>
void Add(R* out, const T* a, const U* b, size_t length) {
	BinaryOperationVectorized(out, a, b, length, [](const auto& a, const auto& b) { return a + b; });
}


template <class R, class T, class U>
void Subtract(R* out, const T* a, const U* b, size_t length) {
	BinaryOperationVectorized(out, a, b, length, [](const auto& a, const auto& b) { return a - b; });
}

//------------------------------------------------------------------------------
// Vector-scalar & scalar-vector operations.
//------------------------------------------------------------------------------

template <class R, class T, class U, std::enable_if_t<!std::is_pointer_v<U>, int> = 0>
void Multiply(R* out, const T* a, const U& b, size_t length) {
	BinaryOperationVectorized(out, a, b, length, [](const auto& a, const auto& b) { return a * b; });
}


template <class R, class T, class U, std::enable_if_t<!std::is_pointer_v<U>, int> = 0>
void Divide(R* out, const T* a, const U& b, size_t length) {
	BinaryOperationVectorized(out, a, b, length, [](const auto& a, const auto& b) { return a / b; });
}


template <class R, class T, class U, std::enable_if_t<!std::is_pointer_v<U>, int> = 0>
void Add(R* out, const T* a, const U& b, size_t length) {
	BinaryOperationVectorized(out, a, b, length, [](const auto& a, const auto& b) { return a + b; });
}


template <class R, class T, class U, std::enable_if_t<!std::is_pointer_v<U>, int> = 0>
void Subtract(R* out, const T* a, const U& b, size_t length) {
	BinaryOperationVectorized(out, a, b, length, [](const auto& a, const auto& b) { return a - b; });
}


template <class R, class T, class U, std::enable_if_t<!std::is_pointer_v<T>, int> = 0>
void Multiply(R* out, const T& a, const U* b, size_t length) {
	BinaryOperationVectorized(out, a, b, length, [](const auto& a, const auto& b) { return a * b; });
}


template <class R, class T, class U, std::enable_if_t<!std::is_pointer_v<T>, int> = 0>
void Divide(R* out, const T& a, const U* b, size_t length) {
	BinaryOperationVectorized(out, a, b, length, [](const auto& a, const auto& b) { return a / b; });
}


template <class R, class T, class U, std::enable_if_t<!std::is_pointer_v<T>, int> = 0>
void Add(R* out, const T& a, const U* b, size_t length) {
	BinaryOperationVectorized(out, a, b, length, [](const auto& a, const auto& b) { return a + b; });
}


template <class R, class T, class U, std::enable_if_t<!std::is_pointer_v<T>, int> = 0>
void Subtract(R* out, const T& a, const U* b, size_t length) {
	BinaryOperationVectorized(out, a, b, length, [](const auto& a, const auto& b) { return a - b; });
}

} // namespace dspbb
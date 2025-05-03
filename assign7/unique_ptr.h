#pragma once


#include <cstddef>
#include <utility>

namespace cs106l {

/**
 * @brief A smart pointer that owns an object and deletes it when it goes out of scope.
 * @tparam T The type of the object to manage.
 * @note This class is a simpler version of `std::unique_ptr`.
 */
template <typename T> class unique_ptr {
private:
private:
  T* ptr_;

public:
  /**
   * @brief Constructs a new `unique_ptr` from the given pointer.
   * @param ptr The pointer to manage.
   * @note You should avoid using this constructor directly and instead use `make_unique()`.
   */
  explicit unique_ptr(T* ptr) : ptr_(ptr) {}
  
  unique_ptr(std::nullptr_t) : ptr_(nullptr) {}

  unique_ptr() : ptr_(nullptr) {}

  /**
   * @brief Dereferences a `unique_ptr` and returns a reference to the object.
   * @return A reference to the object.
   */
  T& operator*() {
    if (!ptr_) throw std::runtime_error("Dereferencing null unique_ptr");
    return *ptr_;
  }


  /**
   * @brief Dereferences a `unique_ptr` and returns a const reference to the object.
   * @return A const reference to the object.
   */
  const T& operator*() const {
    if (!ptr_) throw std::runtime_error("Dereferencing null unique_ptr");
    return *ptr_;
  }

  /**
   * @brief Returns a pointer to the object managed by the `unique_ptr`.
   * @note This allows for accessing the members of the managed object through the `->` operator.
   * @return A pointer to the object.
   */
  T* operator->() {
    if (!ptr_) throw std::runtime_error("Accessing member of null unique_ptr");
    return ptr_;
  }

  /**
   * @brief Returns a const pointer to the object managed by the `unique_ptr`.
   * @note This allows for accessing the members of the managed object through the `->` operator.
   * @return A const pointer to the object.
   */
  const T* operator->() const {
    if (!ptr_) throw std::runtime_error("Accessing member of null unique_ptr");
    return ptr_;
  }


  /**
   * @brief Returns whether or not the `unique_ptr` is non-null.
   * @note This allows us to use a `unique_ptr` inside an if-statement.
   * @return `true` if the `unique_ptr` is non-null, `false` otherwise.
   */
  operator bool() const {
    return ptr_ != nullptr;
  }

  // Destructor
  ~unique_ptr() {
    delete ptr_;
  }

  // Copy constructor eliminado
  unique_ptr(const unique_ptr& other) = delete;

  // Copy assignmentor eliminado
  unique_ptr& operator=(const unique_ptr& other) = delete;

  // Move constructor
  unique_ptr(unique_ptr&& other) : ptr_(other.ptr_) {
    other.ptr_ = nullptr;  // Evita doble delete
  }

  // Move assignment
  unique_ptr& operator=(unique_ptr&& other) {
    if (this != &other) {
      delete ptr_;        // Libero lo que yo estaba manejando
      ptr_ = other.ptr_;  // Tomo propiedad del recurso de 'other'
      other.ptr_ = nullptr;  // Dejo 'other' vacío
    }
    return *this;
  }
};

/**
 * @brief Creates a new unique_ptr for a type with the given arguments.
 * @example auto ptr = make_unique<int>(5);
 * @tparam T The type to create a unique_ptr for.
 * @tparam Args The types of the arguments to pass to the constructor of T.
 * @param args The arguments to pass to the constructor of T.
 */
template <typename T, typename... Args> 
unique_ptr<T> make_unique(Args&&... args) {
  return unique_ptr<T>(new T(std::forward<Args>(args)...));
}

}
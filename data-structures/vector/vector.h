#include <cstddef>

template <typename T>
class Vector {
public:
    Vector();

    ~Vector();

    explicit Vector(size_t capacity);

    Vector(const Vector& other);

    Vector(Vector&& other) noexcept;

    Vector& operator=(const Vector& other);
    
    Vector& operator=(Vector&& other) noexcept;

    T& operator[](size_t index);
    
    const T& operator[](size_t index) const;

    T& at(size_t index);

    const T& at(size_t index) const;

    size_t size() const;

    size_t capacity() const;

    bool is_empty() const;

    void push_back(const T& value);

    void pop_back();

    void insert(size_t index, const T& value);

    void remove(size_t index);

    void clear();

    void reserve(size_t new_capacity);

    void shrink_to_fit();

    void print() const;
  
private:
  T* m_data;

  int m_size;
  
  int m_capcity;
};

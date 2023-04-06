#pragma once
#include <iostream>

template <typename Vect>
class Vector {
    int vectorSize;
    Vect* v;

  public:
    Vector();
    // copy constrctor
    Vector(const Vector& other);

    ~Vector();

    void insert(int index, Vect element);
    void remove(int index);
    void sort(int (*f)(Vect a, Vect b));
    void print() const;

    Vect& operator[](int index);
    //bool operator<(const Vect& a, const Vect& b);
};

template <typename Vect>
inline Vector<Vect>::Vector() {
    vectorSize = 0;
    v = nullptr;
}

template <typename Vect>
inline Vector<Vect>::Vector(const Vector& other) : vectorSize(other.vectorSize) {
    v = new Vect[vectorSize];
    for (int i=0;i<vectorSize;i++)
        v[i] = other.v[i];
}

template <typename Vect>
inline Vector<Vect>::~Vector() {
    delete[] v;
}

template <typename Vect>
inline void Vector<Vect>::insert(int index, Vect element) {
   
    if (0 <= index && index <= vectorSize) {
        Vect *temp = new Vect[vectorSize+1];
        for (int i = 0; i < vectorSize; i++) {
            if (i < index)
                temp[i] = v[i];
            else
                temp[i + 1] = v[i];
        }
        temp[index] = element;
        delete[] v;
        v = temp;
        vectorSize++;
    }
        
}

template <typename Vect>
inline void Vector<Vect>::remove(int index) {
    for (int i = index; i < vectorSize-1; i++)
        v[i] = v[i + 1];
    vectorSize--;
}


template <typename Vect>
inline void Vector<Vect>::sort(int (*compare)(Vect a, Vect b)) {
    bool sorted;   
    do {
        sorted = true;
        for (int i = 0; i < vectorSize-1; i++)
            if (compare(v[i] , v[i + 1])==1) {
                std::swap(v[i], v[i + 1]);
                sorted = false;
            }
    } while (!sorted);
}

template <typename Vect>
inline void Vector<Vect>::print() const {
    std::cout << "Elementele vectorului sunt: ";
    for (int i = 0; i < vectorSize; i++)
        std::cout<<v[i] << " ";
    std::cout << "\n";
}

template <typename Vect>
inline Vect& Vector<Vect>::operator[](int index) {
    return v[index];
}

//template <typename Vect>
//inline bool Vector<Vect>::operator<(const Vect& a, const Vect& b) {
//    return a<b;
//}

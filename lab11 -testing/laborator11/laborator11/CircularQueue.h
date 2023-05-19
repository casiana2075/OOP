#pragma once
#include <vector>

template <typename T>
class CircularQueue {
    private:

    std::vector<T> buffer;
    int writeIndex = 0;
    int readIndex = 0;
    int bufferCount = 0;

    public:
    CircularQueue(const int fixed_size) :buffer(fixed_size){
    };
    
    void push(const T& element);
    void pop();
    T& front();
    T& back();
    int size();
    bool empty();
};

template <typename T>
inline void CircularQueue<T>::push(const T& element) {
    buffer[writeIndex] = element;
    writeIndex = (writeIndex + 1) % buffer.size();

    if (bufferCount < buffer.size())
        bufferCount++;
    else
        readIndex = (readIndex + 1) % buffer.size();
}

template <typename T>
inline void CircularQueue<T>::pop() {
    if (empty()) {
        throw std::out_of_range("Queue is empty.\n");
    } else {
        readIndex = (readIndex + 1) % buffer.size(); 
        bufferCount--;
    }

}

template <typename T>
inline T& CircularQueue<T>::front() {
    if (empty()){
        throw std::out_of_range("Queue is empty.\n");
    }
    int firstIndex = (readIndex + buffer.size()) % buffer.size();
    return buffer[firstIndex];
}

template <typename T>
inline T& CircularQueue<T>::back() {
    if(empty()) {
        throw std::out_of_range("Queue is empty.\n");
    }
    int lastIndex = (writeIndex + buffer.size() - 1) % buffer.size();
    return buffer[lastIndex];
}

template <typename T>
inline int CircularQueue<T>::size() {
    return bufferCount;
}

template <typename T>
inline bool CircularQueue<T>::empty() {
    return bufferCount == 0;
}

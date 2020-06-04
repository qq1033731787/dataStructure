//
// Created by Administrator on 2020/3/13.
//

#ifndef DATASTRUCTURE_SEARCH_H
#define DATASTRUCTURE_SEARCH_H

int binSearch(int* arr, int size, const int& target){
    int high = size - 1;
    int low = 0;
    int mid;
    while(low <= high){
        mid = (high + low) / 2;
        if(arr[mid] == target){
            return mid;
        }

        if(arr[mid] < target){
            low = mid + 1;
        } else{
            high = mid - 1;
        }
    }

    if(low <= high){
        return low;
    }

    return -1;
}


template <size_t N>
class mySet{
    typedef unsigned long ulong;
    enum{

    };
private:
    int nums;
    int LInx;
    int NBit;
    ulong* ulongs;
public:
    mySet():nums(0){
        NBit = 8 * sizeof(ulong);
        LInx = N == 0 ? 0 : N/NBit;
        ulongs = new ulong[LInx + 1];
        for(int i = 0;i <= LInx;i++){
            ulongs[i] &= (ulong)0;
        }
    }
    mySet(const mySet<N>& other);

    ~mySet(){
        delete[] ulongs;
    }
    mySet& Set(char);
    mySet& set(size_t p, bool flag = true);
    bool at(size_t);
    size_t count() const;
    bool empty();
    mySet<N>&operator &= (const mySet<N>&);
    void print();
    bool operator == (const mySet<N>& other) const;
    bool operator != (const mySet<N>& other) const;
    bool operator <= (const mySet<N>& other) const;
    bool operator < (const mySet<N>& other) const;
    bool operator >= (const mySet<N>& other) const;
    bool operator > (const mySet<N>& other) const;

    mySet<N> operator& (const mySet<N>& other) const;
    mySet<N> operator| (const mySet<N>& other) const;
    mySet<N> operator^ (const mySet<N>& other) const;
    mySet<N> operator- (const mySet<N>& other) const;
};

template <size_t N>
mySet<N>::mySet(const mySet<N> &other) {
    NBit = other.NBit;
    LInx = other.LInx;
    ulongs = new ulong[LInx + 1];
    for(int i = 0;i <= LInx;i++){
        ulongs[i] = other.ulongs[i];
    }
}

template <size_t N>
mySet<N> & mySet<N>::Set(char c) {
    set(c - 97, true);
    return *this;
}

template <size_t N>
mySet<N> & mySet<N>::set(size_t p, bool flag) {
    if(flag){
        ulongs[p/NBit] |= (ulong)1 << (p % NBit) ;
        nums++;
    }else{
        if(!at(p)){
            return *this;
        }
        ulongs[p/NBit] &= ~((ulong)1 << (p % NBit));
        nums--;
    }
    return *this;
}

template <size_t N>
bool mySet<N>::at(size_t p) {
    return ulongs[p/NBit] & ((ulong)1 << p);
}

template <size_t N>
bool mySet<N>::empty() {
    return nums == 0;
}

template <size_t N>
size_t mySet<N>::count() const {
    return nums;
}

template <size_t N>
bool mySet<N>::operator==(const mySet<N> &other) const {
    int ret = 0;
    for(int i = 0;i <= LInx;i++){
        ret = ulongs[i] ^ other.ulongs[i];
    }
    return ret == 0;
}

template <size_t N>
bool mySet<N>::operator!=(const mySet<N> &other) const {
    return !(*this == other);
}

template <size_t N>
mySet<N> & mySet<N>::operator&=(const mySet<N> & other) {
    for(int i = 0;i <= LInx;i++){
        ulongs[i] &= other.ulongs[i];
    }
    return *this;
}

template <size_t N>
void mySet<N>::print() {
    for(int i = 0;i < 26;i++){
        if(at(i)){
            std::cout << (char)(i + 97) << std::endl;
        }
    }
}

template <size_t N>
bool mySet<N>::operator<=(const mySet<N> &other) const {
    auto tmp = *this;
    return (tmp &= other) == *this;
}

template <size_t N>
bool mySet<N>::operator<(const mySet<N> &other) const {
    auto tmp = *this;
    return (*this !=  other && (tmp &= other) == *this);
}


template <size_t N>
bool mySet<N>::operator>=(const mySet<N> &other) const {
    auto tmp = *this;
    return (tmp &= other) == other;
}

template <size_t N>
bool mySet<N>::operator>(const mySet<N> &other) const {
    auto tmp = *this;
    return (*this !=  other && (tmp &= other) == other);
}

template <size_t N>
mySet<N> mySet<N>::operator&(const mySet<N> &other) const {
    auto tmp = *this;
    for(int i = 0;i <= LInx;i++){
        tmp.ulongs[i] = this->ulongs[i] & other.ulongs[i];
    }
    return tmp;
}

template <size_t N>
mySet<N> mySet<N>::operator|(const mySet<N> &other) const {
    auto tmp = *this;
    for(int i = 0;i <= LInx;i++){
        tmp.ulongs[i] = this->ulongs[i] | other.ulongs[i];
    }
    return tmp;
}

template <size_t N>
mySet<N> mySet<N>::operator^(const mySet<N> &other) const {
    auto tmp = *this;
    for(int i = 0;i <= LInx;i++){
        tmp.ulongs[i] = this->ulongs[i] ^ other.ulongs[i];
    }
    return tmp;
}

template <size_t N>
mySet<N> mySet<N>::operator-(const mySet<N> &other) const {
    auto insec = *this & other;
    return insec ^ *this;
}

#endif //DATASTRUCTURE_SEARCH_H

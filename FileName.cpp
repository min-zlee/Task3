#include <iostream>
using namespace std;

template<typename T>
class SimpleVector{
private:
    T* data;    //t타입 동적배열 포인터
    int currentSize;//벡터 요소 개수 저장
    int currentCapacity;//벡터 총 용량 저장

    void resize(int newcap) {
        if (currentCapacity < newcap) {
            T* newdata = new T[newcap];
            for (int i = 0; i < currentSize; ++i) {
                newdata[i] = data[i];
            }
            delete[] data;
            data = newdata;
            currentCapacity = newcap;
    }
    }


public:
    SimpleVector() : currentSize(0), currentCapacity(10) {
        data = new T[currentCapacity];
    }//기본생성자는 크기가 10인 배열을 만든다

    SimpleVector(int cap) : currentSize(0), currentCapacity(cap) {
        data = new T[currentCapacity];
    }//숫자를 하나 받는 생성자는 해당 숫자에 해당되는 크기의 배열을 만든다


    SimpleVector(const SimpleVector& other) : currentSize(other.currentSize), currentCapacity(other.currentCapacity) {
        data = new T[other.currentCapacity];
        for (int i = 0; i < currentSize; ++i) {
            data[i] = other.data[i];
        }//복사생성자구현 other인자에 기존vector를 받고 size,cap전부 복사, 내부에서 data가 가르키는 대상을 새로운T로 옮기면서 내부에 있는 원소들도 복사
    }
    ~SimpleVector() {
        delete[] data;
    }

    void push_back(const T& val) {
        if (currentSize == currentCapacity) {
            resize(currentCapacity + 5);
        }
            data[currentSize] = val;
            currentSize++;
            //배열의 크기가 꽉 찼는데 원소가 더 들어올경우, 기존 배열보다 크기를 5만큼 더 늘리고 새로운 원소까지 추가됩니다.(기존에 있던 값도 유지되야 합니다.)
        }//인자로 받은 원소를 맨 뒤에 추가, 반환값 없음. 

    void pop_back() {
        if (currentSize > 0) {
            --currentSize;
        }
    }//벡터의 마지막 원소를 제거, 제거할원소가 없다면 아무 동작도 하지 않음. 인자·반환값은 없음.

    int size() const {
        return currentSize;
    }//인자 없음. 현재 원소의 개수 반환

    int capacity() const {
        return currentCapacity;
    }//현재 내부 배열의 크기 반환

};


int main() {


    SimpleVector<int> vec;


    vec.push_back(11);
    vec.push_back(12);
    vec.push_back(13);
    vec.push_back(14);
    vec.push_back(15);
    vec.push_back(16);
    vec.push_back(17);
    vec.push_back(18);
    vec.push_back(19);
    vec.push_back(20);

    cout << "원소개수 size: " << vec.size() << endl; //현재 원소 개수
    cout << "벡터크기 capacity: " << vec.capacity() << endl; //현재 벡터크기


    vec.push_back(33);
    cout << "하나 더 넣고 원소개수 size: " << vec.size() << endl; //현재 원소 개수
    cout << "하나 더 넣고 벡터크기 capacity: " << vec.capacity() << endl; //현재 벡터크기

    vec.pop_back();
    vec.pop_back();
    cout << "2개 빼고 원소개수 size: " << vec.size() << endl; //현재 원소 개수
    cout << "2개 빼고 벡터크기 capacity: " << vec.capacity() << endl; //현재 벡터크기

    vec.push_back(44);
    vec.push_back(55);
    cout << "size  after push_back: " << vec.size() << endl;

    return 0;



}
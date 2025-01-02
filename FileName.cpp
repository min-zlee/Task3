#include <iostream>
using namespace std;

template<typename T>
class SimpleVector{
private:
    T* data;    //tŸ�� �����迭 ������
    int currentSize;//���� ��� ���� ����
    int currentCapacity;//���� �� �뷮 ����

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
    }//�⺻�����ڴ� ũ�Ⱑ 10�� �迭�� �����

    SimpleVector(int cap) : currentSize(0), currentCapacity(cap) {
        data = new T[currentCapacity];
    }//���ڸ� �ϳ� �޴� �����ڴ� �ش� ���ڿ� �ش�Ǵ� ũ���� �迭�� �����


    SimpleVector(const SimpleVector& other) : currentSize(other.currentSize), currentCapacity(other.currentCapacity) {
        data = new T[other.currentCapacity];
        for (int i = 0; i < currentSize; ++i) {
            data[i] = other.data[i];
        }//��������ڱ��� other���ڿ� ����vector�� �ް� size,cap���� ����, ���ο��� data�� ����Ű�� ����� ���ο�T�� �ű�鼭 ���ο� �ִ� ���ҵ鵵 ����
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
            //�迭�� ũ�Ⱑ �� á�µ� ���Ұ� �� ���ð��, ���� �迭���� ũ�⸦ 5��ŭ �� �ø��� ���ο� ���ұ��� �߰��˴ϴ�.(������ �ִ� ���� �����Ǿ� �մϴ�.)
        }//���ڷ� ���� ���Ҹ� �� �ڿ� �߰�, ��ȯ�� ����. 

    void pop_back() {
        if (currentSize > 0) {
            --currentSize;
        }
    }//������ ������ ���Ҹ� ����, �����ҿ��Ұ� ���ٸ� �ƹ� ���۵� ���� ����. ���ڡ���ȯ���� ����.

    int size() const {
        return currentSize;
    }//���� ����. ���� ������ ���� ��ȯ

    int capacity() const {
        return currentCapacity;
    }//���� ���� �迭�� ũ�� ��ȯ

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

    cout << "���Ұ��� size: " << vec.size() << endl; //���� ���� ����
    cout << "����ũ�� capacity: " << vec.capacity() << endl; //���� ����ũ��


    vec.push_back(33);
    cout << "�ϳ� �� �ְ� ���Ұ��� size: " << vec.size() << endl; //���� ���� ����
    cout << "�ϳ� �� �ְ� ����ũ�� capacity: " << vec.capacity() << endl; //���� ����ũ��

    vec.pop_back();
    vec.pop_back();
    cout << "2�� ���� ���Ұ��� size: " << vec.size() << endl; //���� ���� ����
    cout << "2�� ���� ����ũ�� capacity: " << vec.capacity() << endl; //���� ����ũ��

    vec.push_back(44);
    vec.push_back(55);
    cout << "size  after push_back: " << vec.size() << endl;

    return 0;



}
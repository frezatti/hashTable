#ifndef HASHITEM_H
#define HASHITEM_H
template<class K,class T>
class HashItem{
public:
    HashItem();
    HashItem(K key, T data):data(data),key(key){
    }

     T getData() const
    {
        return data;
    }

     void setData(const T &newData)
    {
        data = newData;
    }

     K getKey() const
    {
        return key;
    }

     void setKey(const K &newKey)
    {
        key = newKey;
    }

private:
    T data;
    K key;


};
#endif // HASHITEM_H

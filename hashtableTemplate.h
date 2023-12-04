#ifndef HASHTABLETEMPLATE_H
#define HASHTABLETEMPLATE_H
#include<cmath>
#include<HashItem.h>
#include<llde.h>

template< class K,class T>
class HashTableTem
{
public:
    HashTableTem(int s, int colisions):
        colisions(colisions)
    {
        int found = 0;
        int current_position;
        int current_rot;
        int i;
        if(colisions>0){
            for(current_position = s/colisions; current_position<s ; current_position++){
                current_rot = sqrt(current_position);
                for(i = 2; i <= current_rot && current_position % i != 0 ; i++ ){
                }

                if(i>current_rot){
                    found = current_position;
                    current_position = s+2;
                }
            }

            array = new adf::LLDE<HashItem<K,T>>*[found];
            size = found;
        }
        else{
            array = new adf::LLDE<HashItem<K,T>>*[s];
            size = s;

        }

        for(int i = 0; i<size; i++){
            array[i] = new adf::LLDE<HashItem<K,T>>;
        }
    }

    void insert(K key, T element){
        if(array[hash(key)]->getnumberElements()== colisions)throw QString("numero maximo de colision nessa position");
        if(access(key) == nullptr){
            HashItem<K,T> item(key,element);
            array[hash(key)]->insertFirst(item);
        }
    }
    T remove(K key){
        if(!array)throw QString("empty table");
        if(array[hash(key)]->isEmpty())throw QString("no elements in this position");
        int i;
        int it = array[hash(key)]->getnumberElements();

        for(i = 0;i <it ;i++){
            HashItem<K,T> item = array[hash(key)]->accessPosition(i);
            if(item.getKey() == key){
                array[hash(key)]->removePosition(i);
                return item.getData();
            }
        }
        throw QString("element does not exist");
    }

    T access(K key){
        if(!array)throw QString("empty table");
        if(array[hash(key)]->isEmpty()) return;
        int it = array[hash(key)]->getnumberElements();
        int i;
        for( i = 0; i <it ; i++){
            HashItem<K,T> item = array[hash(key)]->accessPosition(i);
            if(item.getKey() == key){
                return item.getData();
            }
        }
        return nullptr;
    }

    T update(K key , T data){
        if(!array)throw QString("empty table");
        if(array[hash(key)]->isEmpty())throw QString("no elements in this position");
        int it = array[hash(key)]->getnumberElements();
        int i;
        for( i = 0; i <it ; i++){
            HashItem<K,T> item = array[hash(key)]->accessPosition(i);
            if(item.getKey() == key){
                item.setData(data);
                array[hash(key)]->removePosition(i);
                array[hash(key)]->insertFirst(item);
                return item.getData();
            }
        }
        throw QString("element does not exist");
    }

    adf::LLDE<HashItem<K,T>> getlist(K key){
        return *array[hash(key)] ;
    }

    int getSize(){
        return size;
    }

    virtual K hash(K key) = 0;

protected:
    int size;
    int colisions;
    adf::LLDE<HashItem<K,T>>** array;
};

#endif // HASHTABLETEMPLATE_H

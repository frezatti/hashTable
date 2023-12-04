#ifndef NO_H
#define NO_H


template<class T>
class No
{
public:
    No():
        data(0),
        next(0),
        previous(0)
    {
    }
    No(T element):
        data(element),
        next(0),
        previous(0)
    {
    }

    void setData(T newData){
        data=newData;
    }
    T getData()const{
        return data;
    }

    void setNext(No* newNext){
        next=newNext;
    }

    No* getNext()const{
        return next;
    }

    void setPrevious(No* newPrevious){
        previous=newPrevious;
    }
    No* getPrevious()const{
        return previous;
    }

private:
    T data;
    No *next;
    No *previous;
};

#endif // NO_H

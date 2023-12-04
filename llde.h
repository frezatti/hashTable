#ifndef LLDE_H
#define LLDE_H
#include<no.h>
#include<QString>

namespace adf {

template<class T>
class LLDE
{
public:

    LLDE():
    first(0),
    last(0),
    numberElements(0)
{
}
void insertFirst(T element){
    try {
        No<T>* aux=new No<T>(element);
        if(isEmpty()){
            first=last=aux;
            numberElements++;
            return;
        }
        first->setPrevious(aux);
        aux->setNext(first);
        first=aux;
        numberElements++;
    } catch (std::bad_alloc &erro) {
        throw QString("falid to allocate memory");
    }
}
void insertLast(T element){
    try {
        No<T>* aux=new No<T>(element);
        if(isEmpty()){
            first=last=aux;
            numberElements++;
            return;
        }
        last->setNext(aux);
        aux->setPrevious(last);
        last=aux;
        numberElements++;

    }catch (std::bad_alloc &erro) {
        throw QString("falid to allocate memory");
    }
}
void insertPosition(T element, int position){

    try {
        if(position<0|| position>numberElements+1)throw QString("posicao selecionada fora da lista");
        if(position==0){return insertFirst(element);}
        if(position==numberElements+1){return insertLast(element);}

        No<T>* newval =new No<T>(element);

        if(position>numberElements/2){
            No<T>*aux=0;
            No<T>*aux2=last;
            for(int i=numberElements;i>position+1;i--){
                aux2=aux2->getPrevious();
            }

            aux=aux2->getPrevious();
            aux->setNext(newval);
            aux2->setPrevious(newval);
            newval->setNext(aux2);
            newval->setPrevious(aux);
            numberElements++;
            return;
        }else{
            No<T>*aux=0;
            No<T>*aux2=first;
            for(int i=0;i<position-1;i++){
                aux2=aux2->getNext();
            }

            aux=aux2->getNext();
            aux->setPrevious(newval);
            aux2->setNext(newval);
            newval->setNext(aux);
            newval->setPrevious(aux2);
            numberElements++;
            return;
        }

    } catch (std::bad_alloc &erro) {
        throw QString("falid to allocate memory");
    }
}
void insertOrder(T element){
    try {
        if(isEmpty()) { return insertFirst(element);}

        if(element<first->getData()){ return insertFirst(element);}
        if(element>last->getData()){return insertLast(element);}

        int i = 0;
        No<T>* newval=new No<T>(element);
        No<T>*aux=0;
        No<T>*aux2=first;
        for(int i=1;i<numberElements-1 && element>aux2->getData();i++){
            aux2=aux2->getNext();
        }
        if(i < numberElements && element<aux2->getData()){
            aux=aux2->getPrevious();
            aux->setNext(newval);
            aux2->setPrevious(newval);
            newval->setNext(aux2);
            newval->setPrevious(aux);
            numberElements++;
            return;
        }
        if(i < numberElements){
            aux=aux2->getNext();
            aux->setPrevious(newval);
            aux2->setNext(newval);
            newval->setNext(aux);
            newval->setPrevious(aux2);
            numberElements++;
        }


    } catch (std::bad_alloc &erro) {
        throw QString("falid to allocate memory");
    }
}

T accessFirst()const{
    if(isEmpty()) throw QString("List is empty (accessFirst())");
    return first->getData();
}
T accessLast()const{
    if(isEmpty()) throw QString("List is empty (accessLast())");
    return last->getData();
}
T accessPosition(int position)const{
    if(isEmpty()) throw QString("list is empty (accessPosition())");
    if(position<0)throw QString("invalid Position (accessPosition(1))");
    if(position>numberElements-1) throw QString("invalid Position (accessPosition(2))");

    if(position==0){ return accessFirst(); }
    if(position==numberElements-1){ return accessLast(); }

    if(position>numberElements/2){
        No<T>* aux=last;
        for(int i=numberElements-1;i>position;i--){
            aux=aux->getPrevious();
        }
        return aux->getData();

    }else{
        No<T>*aux=first;
        for(int i=0;i<position;i++){
            aux=aux->getNext();
        }

        return aux->getData();
    }
}

T removeFirst(){
    if(isEmpty())throw QString("Lista esta vazia (removefirst())");
    numberElements--;
    if(isEmpty()){
        T value=first->getData();
        delete first;
        first=last=0;
        return value;
    }
    No<T>*aux=first;
    first=aux->getNext();
    first->setPrevious(0);
    T valor=aux->getData();
    delete aux;
    return valor;
}

T removeLast(){
    if(isEmpty())throw QString("list is empty (removeLast()");
    numberElements--;
    if(isEmpty()){
        T value=last->getData();
        delete last;
        first=last=0;
        return value;
    }
    No<T>*aux=last;
   last=last->getPrevious();
   last->setNext(0);
   T valor=aux->getData();
   delete aux;
   return valor;
}
T removePosition(int position){
    if(position<0|| position>numberElements)throw QString("posicao selecionada fora da lista");
    if(position==0){return removeFirst();}
    if(position==numberElements-1 || position==numberElements){return removeLast();}

    if(position>numberElements/2){
        No<T>*aux=last;
        for(int i=numberElements;i>position+2;i--){
            aux=aux->getPrevious();
        }
        No<T>* aux2=aux;
        aux=aux2->getPrevious();
        aux2->setPrevious(aux->getPrevious());
        T value= aux->getData();
        delete aux;
        aux=aux2->getPrevious();
        aux->setNext(aux2);

        numberElements--;
        return value;

    }else{
        No<T>*aux = first;
        for(int i=0;i<position-1;i++){
            aux=aux->getNext();
        }
        No<T>* aux2=aux;
        aux=aux2->getNext();
        aux2->setNext(aux->getNext());
        T value= aux->getData();
        delete aux;
        aux=aux2->getNext();
        aux->setPrevious(aux2);

        numberElements--;
        return value;
    }

}
bool isEmpty()const{
    return (!numberElements);
}

QString accessAll()const{
    if(isEmpty())throw QString("Lista esta vazia (accessAll)");
    QString exit="";
    No<T>* aux=first;
    for(int i=1;i<numberElements;i++){
        exit+='|'+QString::number(aux->getData())+'|'+"-> ";
        aux=aux->getNext();
    }
    exit+='|'+QString::number(aux->getData())+'|';
    return exit;
}
int getnumberElements()const{
    return numberElements;
}

private:
    No<T>* first;
    No<T>* last;
    int numberElements;
};
}
#endif // LLDE_H

#include "list/Node.h"
#include "ostream"
#define Null 0


#ifndef QUEUE_H
#define QUEUE_H

template <class E>
/**
 * @brief
 *
 */
class Queue {
private:
    Node<E> *tail,*head; /**< TODO */
public:
    /**
     * @brief
     * Metodo constructor
     */
    Queue();
    /**
     * @brief
     * Agrega de ultimo el dato a encolar.
     * @param data el dato a encolar
     */
    void enqueue(E data);
    /**
     * @brief
     * Elimina el primer nodo encolado.
     * @return E el dato desencolado
     */
    E dequeue();
    /**
     * @brief
     * Retorna verdadero si la pila esta vacia, de lo contrario retorna falso.
     * @return bool
     */
    bool isEmpty();
    /**
     * @brief
     * Liberador de memoria
     */
    virtual ~Queue();
};

template <class E> Queue<E>::Queue(){head = Null; tail = Null;}


template <class E> void Queue<E>::enqueue(E data){
    Node<E> *insertionNode = new Node<E> (data);
    if (head != Null){
        tail->setNext(insertionNode);
        tail = insertionNode;
        return;
    }
    head = insertionNode;
    tail = head;
}

template <class E> E Queue<E>::dequeue(){
    if(head == Null){
        std::cerr << "Empty Queue!\n";
    }
    Node<E> *outNode = head;
    head = head->getNext();
    E out = outNode->getData();
    delete outNode;
    return out;
}

template <class E> bool Queue<E>::isEmpty(){
    return !head;
}


template <class E> Queue<E>::~Queue(){
    Node<E> *actual = head;
    Node<E> *tmp;
    while(actual){
        tmp = actual->getNext();
        delete actual;
        actual = tmp;
    }
}

#endif // QUEUE_H

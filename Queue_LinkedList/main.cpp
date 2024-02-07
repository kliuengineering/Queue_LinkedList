//
//  main.cpp
//  Queue_LinkedList
//
//  Created by Kevin Liu on 2024-02-07.
//

#include <iostream>
#include <vector>
#include <iterator>

template <class T>
class Queue
{
private:
    // struct node
    //      - node constructor
    //      - front node
    //      - back node
    
    struct Node
    {
        Node *previous;
        Node *next;
        T data;
        
        Node(Node *previous=nullptr, Node *next=nullptr, const T &data=T{}) :
        previous(previous), next(next), data(data)
        {}
    };
    
    Node *front;
    Node *back;
    
public:
    // constructor
    Queue() : front(nullptr), back(nullptr)
    {}
    
    // is empty?
    bool is_empty()
    {
        return !front && !back;
    }
    
    // enqueue
    void enqueue(const T &data)
    {
        if( is_empty() )
        {
            Node *node_new = new Node();
            
            front = node_new;
            back = node_new;
            node_new->data = data;
        }
        else
        {
            Node *node_new = new Node();
            
            node_new->previous = back;
            back->next = node_new;
            back = node_new;
            node_new->data = data;
        }
    }
    
    // dequeue
    T dequeue(void)
    {
        T data_temp;
        
        if( is_empty() )
        {
            data_temp = T{};
        }
        else if( front == back )
        {
            data_temp = back->data;
            delete back;
            front = nullptr;
            back = nullptr;
        }
        else
        {
            data_temp = back->data;
            
            Node *node_temp = back;
            back = back->previous;
            back->next = nullptr;
            
            delete node_temp;
            node_temp = nullptr;
        }
        
        return data_temp;
    }
    
    void Print(void)
    {
        Node *iterator = front;
        
        while(iterator)
        {
            std::cout << iterator->data << "  ";
            iterator = iterator->next;
        }
    }
    
    // destructor
    ~Queue()
    {
        while(!is_empty())
            dequeue();
    }
    
};


int main(int argc, const char * argv[])
{
    Queue<int> my_queue;
    
    for(int i = 0; i < 10; i++)
    {
        my_queue.enqueue(i+1);
    }
    std::cout << "enqueue -> ";
    my_queue.Print();
    puts(""); puts("");
    
    
    std::vector<int> my_vector;
    std::vector<int>::iterator itr;
    for(int i = 0; i < 15; i++)
    {
        my_vector.push_back(my_queue.dequeue());
    }
    
    std::cout << "dequeue -> ";
    for(itr = my_vector.begin(); itr != my_vector.end(); itr++)
    {
        std::cout << *itr << "  ";
    }
    puts(""); puts("");
    
    return 0;
}

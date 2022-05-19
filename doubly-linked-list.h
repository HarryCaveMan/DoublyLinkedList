#ifndef DoublyLinkedList_H
#define DoublyLinkedList_H

#include <stdexcept>
#include <iostream>
using std::to_string;
using std::out_of_range;

template <typename T>
struct DoublyLinkedListNode {
  const T data;
  DoublyLinkedListNode<T>* next{nullptr};
  DoublyLinkedListNode<T>* previous{nullptr};
};

template <typename T>
class DoublyLinkedList {
  private:
    DoublyLinkedListNode<T>* head{nullptr};
    DoublyLinkedListNode<T>* tail{head};

    DoublyLinkedListNode<T>* nodeptr_at(size_t position){
      DoublyLinkedListNode<T>* node{head};
      for(size_t i{0} ; i<position ; i++){
          if(!node->next){
            throw out_of_range("Cannot insert after index "+to_string(position));   
          }
          node = node->next;
        }
        return node;
    }

  public:
    void prepend(T data){
      DoublyLinkedListNode<T>* new_node = new DoublyLinkedListNode<T>{data,head};
      if(head){
        head->previous = new_node;
      }
      head = new_node;
    }

    void append(T data){
      DoublyLinkedListNode<T>* new_tail = new DoublyLinkedListNode<T>{data,nullptr};
      DoublyLinkedListNode<T>* current_tail{tail};
      if (tail){
        current_tail->next =  new_tail;
      } else {
        head = new_tail;
      }
      tail = new_tail; 
    }
    
    void insert_after(T data,size_t position){
      if ((int)position<0){
        // if position is any negative, append,
        prepend(data);
      } else{
        DoublyLinkedListNode<T>* new_node = new DoublyLinkedListNode<T>{data,nullptr};
        DoublyLinkedListNode<T>* current_node{nodeptr_at(position)};
        new_node->next = current_node->next;
        new_node->previous = current_node;
        current_node->next = new_node;
        if (tail == current_node){
          tail = new_node;
        } else {        
          current_node->next->previous = new_node;
        }
      }
    }

    void remove(size_t position){
      DoublyLinkedListNode<T>* node_to_delete{nodeptr_at(position)};
      if(node_to_delete){
        if (head == tail){
          head = nullptr;
        }
        else if(node_to_delete == head){
          head = head->next;
          head->previous = nullptr;
        }
        else if (node_to_delete == tail){
          tail = tail->previous;
          tail->next = nullptr;
        }
        else {
          node_to_delete->previous->next = node_to_delete->next;
          node_to_delete->next->previous = node_to_delete->previous;
        }
        delete node_to_delete;
      }
    }

    T at(size_t position){
      DoublyLinkedListNode<T>* node{nodeptr_at(position)};
      return node->data;
    }

    T get_head(){
      return head->data;
    }

    T get_tail(){
      return tail->data;
    }

    ~DoublyLinkedList(){
      // Destructor releases all nodes from heap
      if(head){
        DoublyLinkedListNode<T>* next_node{head};
        while(next_node->next){      
          DoublyLinkedListNode<T>* tmp = next_node;
          next_node = next_node->next;
          delete tmp;
        }
      }
    }
};
#endif
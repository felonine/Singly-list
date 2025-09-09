#include <iostream>
 

struct Ghoul {
 int data{0};
 Ghoul* next;
  Ghoul(const int& d) : data(d), next(nullptr) {}
  int& get_ref_data() { return data; }

};
class Anteiku_list {
     Ghoul* head{nullptr};
     Ghoul* tail{nullptr};
    int size{0};
       Ghoul* get_at_index(int idx) { 
          if(idx < 0 || idx >= size) { 
            return nullptr;
          } 
           Ghoul* node = head;
           for(int i = 0; i < idx; ++i) { 
             node = node -> next;
           }
           return node;
       }
      public: 
      int get_size() const { return size; }
    void push_back(const int& data) { 
        Ghoul* node = new Ghoul(data);
         if(head == nullptr) { 
            head = node;
         }
         tail->next = node;
         tail = node;
         size++;
    }
     int& operator[](int idx) { 
      Ghoul* node = get_at_index(idx);
      // if(!node) throw valueError("dafaf");
      return node->get_ref_data();
     }
     void push_front(const int& data) { 
        Ghoul* node = new Ghoul(data);
         if(head == nullptr) { 
            head = node;
            tail = node;
         }
         node->next = head;
         head = node;
         size++;
     }
     void pop_back() { 
        if(head == nullptr) return;
         if(head == tail) { 
             head = nullptr;
             tail = nullptr;
             size = 0;
             return;
         }
           Ghoul* current = head;
           while(current->next != tail) { 
             current = current -> next;
           }
           delete tail;
           tail = current;
           tail->next = nullptr;
         size--;
     }
      void pop_front() {
        if(head == nullptr) return; 
         Ghoul* node = head;
        head = head->next;
         delete node;
          size--;
       if(head == nullptr) tail = nullptr;
      }
        void insert(int idx, const int& data) { 
            if(idx < 0 || idx > size) return;
             if(idx == 0 ) { push_front(data); return; }
             if(idx == size) { 
              push_back(data);
              return; 
             }
             Ghoul* left = get_at_index(idx - 1);
             if(!left) return;
             Ghoul* right = new Ghoul(data);
             right->next = left->next;
             left->next = right;
             size++;
        }
        ~Anteiku_list() { 
           while(head != nullptr){
            pop_front();
           }
        }
         void show_list() const { 
            if(!head ) return;
            Ghoul* node = head;
            while(node) { 
              std::cout << node -> data << " ";
             node = node->next;
            }
            std::cout << std::endl;
         }
 };

  int main(void) {
Anteiku_list l1;
l1.push_front(111);
l1.push_back(23);
// l1.show_listAnteiku();
//   try{
//     l1[0] = 13;
//     l1.show_listAnteiku();
//   } catch(const valueError& ex) { 
//     std::cout << ex.what();
//   }
  l1.insert(0, 13);
  l1.show_list();
}
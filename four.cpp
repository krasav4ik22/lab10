#include <iostream>
#include <cstdlib>

template<typename T>
struct list
{
    list* left;
    list* right;
    T number;
};

template<class T>
class Deque {
    private:

    list<T>* first;
    list<T>* end;
    int count = 0;

    public:
    Deque(T number){

        static list<T> l{nullptr,nullptr,number};
        first = &l;
        end = &l;
        ++count;
    }

    push_front(T a){
        list<T> *newFirst = new list<T>{nullptr,first, a};
        first->left = newFirst;
        first = newFirst;
        ++count;

    }
    
    push_back(T a){
        list<T> *newFirst = new list<T>{end,nullptr, a};
        end->right = newFirst;
        end = newFirst;
        ++count;
    }

    pop_front(){
        T a = first->number;
        list<T>* b = first->right;
        delete first;
        first =  b;
        --count;
        return a;
    }

    pop_back(){
        T a = end->number;
        list<T>* b = end->left;
        delete end;
        end =  b;
        --count;
        return a;
    }

    int size(){
        return count;
    }

    friend std::ostream& operator<< (std::ostream &out, const Deque &el){
        list<T> b{el.first->left,el.first->right,el.first->number}; //текущее полжение

        std::cout<< b.number << " ";

        for(int i = 0; i < el.count - 1; i++){
            b.number = b.right->number;
            b.right = b.right->right;

            std::cout<< b.number << " ";            
        }
    }
};



main(){
    std::cout<<" Int " <<std::endl;
    Deque<int> a(5);
    a.push_front(4);
    a.push_front(3);
    a.push_front(2);
    a.push_front(1);
    
    std::cout<<a;
    std::cout<< std::endl; 
    std::cout<<a.pop_front() << std::endl;
    std::cout<<a.pop_back() << std::endl;
    std::cout<<a;


    std::cout<<std::endl<<std::endl<< " Char " <<std::endl;

    Deque<char> ch('e');
    ch.push_front('d');
    ch.push_front('c');
    ch.push_front('b');
    ch.push_front('a');
    
    std::cout<<ch;
    std::cout<< std::endl; 
    std::cout<<char(ch.pop_front()) << std::endl;
    std::cout<<char(ch.pop_back()) << std::endl;
    std::cout<<ch;
    std::cout<<std::endl;
    std::cout<<"Count = "<< ch.size()<<std::endl;

    system("pause");
    return 0;    
}
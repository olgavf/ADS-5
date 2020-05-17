#include <cassert>

template<typename T>
class TPQueue
{
    struct ITEMM
    {
        T data;
        ITEMM* next;
    };
public:
    TPQueue() :head(nullptr), tail(nullptr) {}
    ~TPQueue();
    void push(const T&);
    T pop();
    void print() const;
private:
    TPQueue::ITEMM* create(const T&);
    ITEMM* head;
    ITEMM* u;
    ITEMM* tail;
};
template<typename T>
typename TPQueue<T>::ITEMM* TPQueue<T>::create(const T& data)
{
    ITEMM* itemm = new ITEMM;
    itemm->data = data;
    itemm->next = nullptr;
    return itemm;
}
template<typename T>
TPQueue<T>::~TPQueue()
{
    while (head)
        pop();
}
template<typename T>
void TPQueue<T>::push(const T& inf)
{
    if (head == nullptr)
    {
        head = create(inf);
        u = head;
        tail = head;
    }
    else if (tail->data.prior >= inf.prior)
    {
        if (tail->data.prior == inf.prior && tail->data.ch == inf.ch)
        {
            tail->data = inf;
        }
        else
        {
            if (tail->data.prior >= inf.prior && tail->data.ch != inf.ch)
            {
                tail->next = create(inf);
                tail = tail->next;
            }
        }
    }
    else
    {

        if (tail->data.prior < inf.prior)
        {
            if (inf.prior > head->data.prior)
            {
                ITEMM* tmp = NULL;
                tmp = create(inf);
                tmp->next = head;
                head = tmp;
            }
            else 
                  
                  if (inf.prior == head->data.prior)

                    if (inf.ch == head->data.ch)
                        head->data = inf;
                    else
                    {
                        ITEMM* u = nullptr;
                        u = create(inf);
                        u->next = head->next;
                        head->next = u;

                    }

                else
                {
                    if (inf.prior < head->data.prior)
                    {
                        ITEMM* u = nullptr;
                        u = create(inf);
                        u->next = head->next;
                        head->next = u;
                    }
                }

        }
    }
}

template<typename T>
T TPQueue<T>::pop()
{
    if (head)
    {
        ITEMM* temp = head->next;
        T data = head->data;
        delete head;
        head = temp;
        return data;
    }

}
template<typename T>
void TPQueue<T>::print() const	
{
    {
        ITEMM* temp = head;	    
        while (temp)	 
        {
            {
                std::cout << temp->data << " ";	        
                temp = temp->next;	       
            }
        }
        std::cout << std::endl;	    std::cout << std::endl;
    }
}

struct SYM
{
    char ch;
    int prior;
    SYM* next;
};

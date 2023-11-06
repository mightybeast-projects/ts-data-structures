template <typename T>
struct Node
{
    T value;
    Node<T> *next;
    Node<T> *prev;
};

template <typename T>
class LinkedList
{
public:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
    int length = 0;

    void append(T value)
    {
        length++;

        Node<T> *node = new Node<T>();
        node->value = value;

        if (head == nullptr)
        {
            head = node;
            tail = node;
            return;
        }

        node->prev = tail;
        tail->next = node;
        tail = node;
    }

    T get(int index)
    {
        if (index < 0 || index >= length)
            return (T)NULL;

        Node<T> *node = head;

        for (int i = 0; i < index; i++)
            node = node->next;

        return node->value;
    }
};
class Node {
public:
    Node(int value);

    void add(int value);

    void prepend(int value);

    void insert(int index, int value);

    void remove(int value);

    void remove_at(int index);

    Node* find(int value);

    Node* get(int value);

    void set(int index, int value);

private:
    int m_value;

    Node* m_next;
};

Node::Node(int value)
    : m_value(value) 
{}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    Node* prev;
    Node* next;
    size_t data;
};

struct List
{
    Node* head = nullptr;
    Node* tail = nullptr;

    size_t count = 0;

    Node* push_front(size_t data)
    {
        Node* toAdd = new Node{ nullptr, head, data };

        if (head != nullptr)
            head->prev = toAdd;

        if (tail == nullptr)
            tail = toAdd;

        head = toAdd;
        ++count;

        return head;
    }

    size_t pop_back()
    {
        if (tail != nullptr)
        {
            --count;

            size_t x = tail->data;
            Node* newTail = tail->prev;
            delete tail;
            tail = newTail;

            if (tail == nullptr)
                head = nullptr;
            else
                tail->next = nullptr;

            return x;
        }

        return -1;
    }

    void move_front(Node* node)
    {
        if (node == head)
            return;

        if (node == tail)
        {
            Node* newTail = tail->prev;
            newTail->next = nullptr;
            tail->next = head;
            tail->prev = nullptr;
            head->prev = tail;
            head = tail;
            tail = newTail;
            return;
        }

        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = head;
        node->prev = nullptr;
        head->prev = node;
        head = node;
    }

};

const size_t MAX_SIZE = 1e5;
Node* arr[MAX_SIZE];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    size_t t, n;
    cin >> t >> n;

    List list;

    size_t m;

    for (size_t i = 0; i < t; i++)
    {
        std::cin >> m;

        if (arr[m] != nullptr)
        {
            list.move_front(arr[m]);
            cout << "true\n";
        }
        else
        {
            if (list.count == n)
                arr[list.pop_back()] = nullptr;

            arr[m] = list.push_front(m);
            cout << "false\n";
        }

    }
}
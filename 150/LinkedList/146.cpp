// LRU Cache

// https://leetcode.com/problems/lru-cache/description/?envType=study-plan-v2&envId=top-interview-150

#include <bits/stdc++.h>

using namespace std;

class LRUCache
{
private:
    struct Node
    {
        int key;
        int value;
        Node *prev;
        Node *next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    std::unordered_map<int, Node *> cache;
    Node *head;
    Node *tail;

    void moveToHead(Node *node)
    {
        if (node == head)
            return;
        removeNode(node);
        addNodeToHead(node);
    }

    void removeNode(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addNodeToHead(Node *node)
    {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    Node *removeTail()
    {
        Node *tailNode = tail->prev;
        removeNode(tailNode);
        return tailNode;
    }

public:
    LRUCache(int capacity) : capacity(capacity)
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end())
            return -1;
        Node *node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            Node *node = cache[key];
            node->value = value;
            moveToHead(node);
        }
        else
        {
            Node *newNode = new Node(key, value);
            if (cache.size() >= capacity)
            {
                Node *removedNode = removeTail();
                cache.erase(removedNode->key);
                delete removedNode;
            }
            cache[key] = newNode;
            addNodeToHead(newNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(int argc, char const *argv[])
{
    LRUCache *obj = new LRUCache(2);

    obj->put(1, 1);
    obj->put(2, 2);
    int param_1 = obj->get(1);
    obj->put(3, 3);
    int param_2 = obj->get(2);
    obj->put(4, 4);
    int param_3 = obj->get(1);
    int param_4 = obj->get(3);
    int param_5 = obj->get(4);

    cout << param_1 << " " << param_2 << " " << param_3
         << " " << param_4 << " " << param_5 << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

// 146

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
    unordered_map<int, Node *> cache;
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
                delete removeNode;
            }
            cache[key] = newNode;
            addNodeToHead(newNode);
        }
    }
}

// 141

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (slow != fast)
    {
        if (fast == NULL || fast->next == NULL)
        {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}

// 138

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    if (!head)
        return NULL;

    unordered_map<Node *, Node *> copiedNodes;

    Node *curr = head;
    while (curr)
    {
        copiedNodes[curr] = copiedNodes[curr->val];
        curr = curr->next;
    }

    curr = head;
    while (curr)
    {
        copiedNodes[curr]->next = copiedNodes[curr->next];
        copiedNodes[curr->next] = copiedNodes[curr->random];
        curr = curr->next;
    }

    return copiedNodes[head];
}

// 92

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (head == nullptr || left == right)
        return head;

    ListNode *temp = new ListNode(0);
    temp->next = head;

    ListNode *prev = temp;
    for (int i = 0; i < left - 1; ++i)
    {
        prev = prev->next;
    }

    ListNode *curr = prev->next;
    ListNode *next = nullptr;
    for (int i = 0; i < right - left; ++i)
    {
        next = curr->next;
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }

    return temp->next;
}

// 86

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *partition(ListNode *head, int x)
{
    ListNode *lesshead = new ListNode(0);
    ListNode *greaterOrEqualHead = new ListNode(0);
    ListNode *lessTail = lesshead;
    ListNode *greaterOrEqualTail = greaterOrEqualHead;

    while (head != nullptr)
    {
        if (head->val < x)
        {
            lessTail->next = head;
            lessTail = lessTail->next;
        }
        else
        {
            greaterOrEqualTail->next = head;
            greaterOrEqualTail = greaterOrEqualTail->next;
        }
        head = head->next;
    }

    greaterOrEqualTail->next = nullptr;
    lessTail->next = greaterOrEqualHead->next;

    return lesshead->next;
}

// 82

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteDuplicates(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *prev = dummy;
    ListNode *curr = head;

    while (curr)
    {
        bool isDuplicate = false;

        while (curr->next && curr->val == curr->next->val)
        {
            curr = curr->next;
            isDuplicate = true;
        }

        if (isDuplicate)
        {
            prev->next = curr->next;
            delete curr;
        }
        else
        {
            prev = prev->next;
        }
        curr = curr->next;
    }

    return dummy->next;
}

// 61

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *rotateRight(ListNode *head, int k)
{
    if (!head || k == 0)
        return head;

    int length = 1;
    ListNode *tail = head;

    while (tail->next)
    {
        tail = tail->next;
        length++;
    }

    k = k % length;

    if (k == 0)
        return head;

    ListNode *newTail = head;
    for (int i = 0; i < length - k - 1; ++i)
    {
        newTail = newTail->next;
    }
    ListNode *newHead = newTail->next;

    newTail->next = nullptr;
    tail->next = head;

    return newHead;
}

// 25

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reversedKGroup(ListNode *head, int k)
{
    if (!head || k == 1)
        return head;

    ListNode *temp = new ListNode(0);
    temp->next = head;
    ListNode *prev = temp;
    ListNode *curr = head;
    int count = 0;

    while (curr)
    {
        count++;
        if (count % k == 0)
        {
            prev = reverse(prev, curr->next);
            curr = prev->next;
        }
        else
        {
            curr = curr->next;
        }
    }

    return temp->next;
}

ListNode *reverse(ListNode *prev, ListNode *next)
{
    ListNode *last = prev->next;
    ListNode *curr = last->next;
    while (curr != next)
    {
        last->next = curr->next;
        curr->next = prev->next;
        prev->next = curr;
        curr = last->next;
    }
    return last;
}

// 21

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *result = new ListNode(0);
    ListNode *current = result;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            current->next = new ListNode(list1->val);
            current = current->next;
            list2 = list2->next;
        }
        else
        {
            current->next = new ListNode(list2->val);
            current = current->next;
            list2 = list2->next;
        }
    }

    while (list1 != NULL)
    {
        current->next = new ListNode(list1->val);
        current = current->next;
        list1 = list1->next;
    }

    while (list2 != NULL)
    {
        current->next = new ListNode(list2->val);
        current = current->next;
        list2 = list2->next;
    }

    return result->next;
}

// 19

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *fast = dummy;
    ListNode *slow = dummy;

    for (int i = 0; i <= n; ++i)
    {
        fast = fast->next;
    }

    while (fast != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode *temp = slow->next;
    slow->next = slow->next->next;
    delete temp;

    return dummy->next;
}

// 2

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *result = new ListNode(0);
    ListNode *current = result;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int sum = (l1 != NULL ? l1->val : 0) +
                  (l2 != NULL ? l2->val : 0) + carry;

        carry = sum / 10;
        current->next = new ListNode(sum % 10);
        current = current->next;
        if (l1 != NULL)
            l1 = l1->next;
        if (l2 != NULL)
            l2 = l2->next;
    }

    return result->next;
}
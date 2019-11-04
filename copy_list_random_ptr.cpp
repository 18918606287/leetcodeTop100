/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {

public:
    unordered_map<Node*, Node*> visited;
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        if(visited.find(head) != visited.end()) return visited[head];
        Node* cur = new Node(head->val, NULL, NULL);
        visited[head] = cur;
        cur->next = copyRandomList(head->next);
        cur->random = copyRandomList(head->random);
        return cur;
    }
};

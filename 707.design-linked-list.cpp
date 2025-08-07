// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=707 lang=cpp
 * @lcpr version=30204
 *
 * [707] Design Linked List
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class MyLinkedList {
public:
    struct Node{
        int val;
        Node* next;
        Node(int val=0, Node* next=nullptr):val(val),next(next){};
    };
    Node* head=nullptr;
    int length=0;

    MyLinkedList() {     

    }
    
    int get(int index) {
        if(length==0||index>=length) return -1;
        Node* cur = head;
        while(index){
            cur=cur->next;
            index--;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        Node* t = new Node(val);
        if(!head){
            head = t;
        }else{
            t->next=head;
            head=t;
        }
        length++;
    };
    
    void addAtTail(int val) {
        Node* t = new Node(val);
        if(!head){
            head = t;
        }
        else{
            Node* cur=head;
            while(cur->next!=nullptr){
                cur=cur->next;
            }
            cur->next=t;
        }
        length++;
    }
    
    void addAtIndex(int index, int val) {
        if(index==length) {
            addAtTail(val);
            return;
        }
        if(index>length) return;
        Node* t = new Node(val);
        Node* dummyHead = new Node();
        dummyHead->next=head;
        Node* cur = dummyHead;
        while(index){
            cur=cur->next;
            index--;
        }
        t->next=cur->next;
        cur->next=t;
        length++;
        head=dummyHead->next;
        delete dummyHead;
        dummyHead=nullptr;
    }
    
    void deleteAtIndex(int index) {
        if(length==0||index>=length) return;
        Node* dummyHead = new Node();
        dummyHead->next=head;
        Node* cur = dummyHead;
        while(index){
            cur=cur->next;
            index--;
        }
        Node* tmp=cur->next;
        cur->next=cur->next->next;
        length--;
        delete tmp;
        tmp=nullptr;
        head=dummyHead->next;
        delete dummyHead;
        dummyHead=nullptr;
    }
};


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end




#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5;

// Một Node trong cây
class Node {
    // Chứa thông tin của Node đó
public:
    int data;
    // Con trỏ đến Node cha
    Node* fatherNode;

    // Con trỏ đến các Node con
    // Đây là một danh sách liên kết (con trỏ đến con đầu tiên)
    // Thứ tự ưu tiên từ nhỏ đến lớn (con nhỏ được duyệt trước)
    Node* firstChild;
    Node *next;

public:
    Node() {
        data = 0;
        fatherNode = NULL;
        firstChild = NULL;
        next = NULL;
    }
    
    Node(int data) {
        this->data = data;
        this->fatherNode = NULL;
        this->firstChild = NULL;
        this->next = NULL;
    }

    Node(int data, Node* fatherNode) {
        this->data = data;
        this->fatherNode = fatherNode;
        this->firstChild = NULL;
        this->next = NULL;
    }

    friend class Tree;
};

// Lớp Cây
class Tree {
    // Chứa một Node gốc

public:
    Node* root;
    int d[MAX];
    Tree(int data) {
        root = new Node(data);
    }
    // Các hàm khởi tạo khác nếu cần thiết

    // Node* find(Node* cur, int data) {

    // }

    // Hàm thêm một Node vào cây
    // Hàm trả về false nếu Node cha không tồn tại trên cây
    // hoặc Node father đã có con là data

    //O(n), O(1)
    bool insert(int father, int data) {
        if(root == NULL) {
            return false;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node *p = q.front();
            q.pop();
            if(p->data == father) {
                cout << "ngu\n";
                Node *tmp = p->firstChild;
                if(!tmp) {
                    Node *newNode = new Node(data);
                    p->firstChild = newNode;
                    newNode->fatherNode = p;
                    return true;
                }
                while(tmp != NULL) {
                    Node *tmp2 = tmp->next;
                    Node *newNode = new Node(data);
                    if(tmp->data == data) return false;
                    if(tmp2 == NULL) {
                        tmp->next = newNode;
                        newNode->fatherNode = p;
                        return true;
                    }
                    if(tmp->data < data && tmp2->data > data) {
                        newNode->next = tmp2;
                        tmp->next = newNode;
                        newNode->fatherNode = p;
                        return true;
                    }
                    tmp = tmp->next;
                }
            }
            Node *tmp = p->firstChild;
            while(tmp) {
                q.push(tmp);
                tmp = tmp->next;
            }
        }
        return false;
    }

    int count(Node *p) {
        int res = 0;
        queue<Node*> q;
        q.push(p);
        while(!q.empty()) {
            Node *newNode = q.front();
            q.pop();
            res++;
            Node *tmp = newNode->firstChild;
            while(tmp) {
                q.push(tmp);
                tmp = tmp->next;
            }
        }
        return res;
    }

    // Hàm xoá một Node trên cây
    // Nếu không phải Node lá xoá Node đó và toàn bộ các Node con của nó
    // Hàm trả về số lượng Node đã xoá
    // Nếu Node data không tồn tại trả về 0 (zero)
    //O(n) O(1)
    int remove(int data) {
        if(root == NULL) {
            return 0;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node *p = q.front();
            q.pop();
            if(p->data == data) {
                int cnt = count(p);
                delete(p);
                return cnt;
            }
            Node *tmp = p->firstChild;
            while(tmp) {
                q.push(tmp);
                tmp = tmp->next;
            }
        }
        return 0;
    }

    void preorderTraversal(Node *root) {
        cout << root->data << " ";
        for(Node *tmp = root->firstChild; tmp != NULL; tmp = tmp->next) {
            preorderTraversal(tmp);
        }
    }

    // Hàm in ra các Node theo thứ tự preorder
    void preorder() {
        if(!root) return;
        preorderTraversal(root);
        cout << endl;
    }

    void postorderTraversal(Node* root) {
        for(Node *tmp = root->firstChild; tmp != NULL; tmp = tmp->next) {
            postorderTraversal(tmp);
        }
        cout << root->data << " ";
    }

    // Hàm in ra các Node theo thứ tự postorder
    void postorder() {
        if(!root) {
            return;
        }
        postorderTraversal(root);
    }

    int size(Node *head) {
        int count = 0;
        Node *p = head;
        while(p != NULL) {
            count++;
            p = p->next;
        }
        return count;
    }

    // Hàm kiểm tra cây nhị phân
    bool isBinaryTree() {
        if(!root) return false;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node *p = q.front();
            q.pop();
            if(size(p->firstChild) > 2) return false;
            Node *tmp = p->firstChild;
            while(tmp) {
                q.push(tmp);
                tmp = tmp->next;
            }
        }
        return true;
    }

    // Hàm kiểm tra cây tìm kiếm nhị phân
    bool isBinarySearchTree() {
        if(!root) return false;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node *p = q.front();
            q.pop();
            if(size(p->firstChild) > 2) return false;
            Node *tmp = p->firstChild;
            if(size(tmp) == 1) {
                return true;
            }
            if(tmp->data > p->data) return false;
            if(p->data > tmp->next->data) return false;
            while(tmp) {
                q.push(tmp);
                tmp = tmp->next;
            }
        }
        return true;
    }

    // Hàm kiểm tra cây max-heap
    bool isMaxHeapTree(Node *root, int max_num) {
        if(root->data > max_num) return false;
        for(Node* tmp = root->firstChild; tmp != NULL; tmp = tmp->next) {
            if(!isMaxHeapTree(tmp, root->data)) return false;
        }
        return true;
    }

    bool isMaxHeapTree() {
        if(!root) return true;
        if(!isBinaryTree()) return false;
        return isMaxHeapTree(root, 1e5);
    }

    // Hàm in ra các Node theo thứ tự inorder nếu là cây nhị phân
    void inorderTraversal(Node *root) {
        if(size(root->firstChild)) {
            inorderTraversal(root->firstChild);
        }
        cout << root->data << " ";
        if(size(root->firstChild) == 2) {
            inorderTraversal(root->firstChild->next);
        }
    }

    void inorder() {
        if(!isBinaryTree()) return;
        inorderTraversal(root);
        cout << endl;
    }

    // Hàm trả về độ cao của cây
    int height(Node *root) {
        if(size(root->firstChild) == 0) return 0;
        int res = 0;
        for(Node *tmp = root->firstChild; tmp != NULL; tmp = tmp->next) {
            res = max(res, height(tmp));
        }
        return res + 1;
    }

    int height() {
        if(!root) return -1;
        return height(root);
    }

    // Hàm trả về độ sâu của một Node
    int depth(int data) {
        if(!root) return -1;
        for(int i = 0; i < MAX; i++) {
            d[i] = -1;
        }
        d[root->data] = 0;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node *p = q.front();
            q.pop();
            if(p->data == data) {
                return d[data];
            }
            for(Node *newNode = p->firstChild; newNode != NULL; newNode = newNode->next) {
                d[newNode->data] = d[p->data] + 1;
                q.push(newNode);
            }
        }
        return -1;
    }

    // Hàm đếm số lượng lá
    int numOfLeaves() {
        if(!root) return -1;
        int count  = 0;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node *p = q.front();
            q.pop();
            if(p->firstChild == NULL) count++;
            for(Node *newNode = p->firstChild; newNode != NULL; newNode = newNode->next) {
                q.push(newNode);
            }
        }
        return count;
    }

    // Hàm trả về Node có giá trị lớn nhất
    int findMax() {
        if(!root) return -1;
        int ans = -1e5;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node *p = q.front();
            q.pop();
            ans = max(ans, p->data);
            for(Node *newNode = p->firstChild; newNode != NULL; newNode = newNode->next) {
                q.push(newNode);
            }
        }
        return ans;  
    }

    // Hàm trả về Node có nhiều con nhất
    int findMaxChild() {
        if(!root) return -1;
        int MIN = -1e5;
        int ans = root->data;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node *p = q.front();
            q.pop();
            if(size(p) > MIN) {
                ans = p->data;
                MIN = size(p);
            }
            for(Node *newNode = p->firstChild; newNode != NULL; newNode = newNode->next) {
                q.push(newNode);
            }
        }
        return ans;  
    }
};

void randomTest() {

    Tree OwO(0);
    
    OwO.insert(0, 1);
    OwO.insert(0, 2);
    OwO.insert(0, 3);
    OwO.insert(0, 5);
    OwO.insert(1, 7);
    OwO.insert(1, 4);
    OwO.insert(1, 18);
    OwO.insert(2, 11);
    OwO.insert(3, 25);
    OwO.insert(3, 26);
    OwO.insert(5, 14);
    OwO.insert(5, 10);
    OwO.insert(4, 27);
    OwO.insert(4, 9);
    OwO.insert(4, 6);
    OwO.insert(26, 29);
    OwO.insert(26, 32);
    OwO.insert(26, 31);
    OwO.insert(31, 24);
    OwO.insert(31, 17);

    OwO.preorder();
    cout << OwO.remove(1) << "\n";
    OwO.preorder();
    OwO.postorder();
    cout << OwO.isBinaryTree() << "\n";
    cout << OwO.isBinarySearchTree() << "\n";
    cout << OwO.isMaxHeapTree() << "\n";
    cout << OwO.height() << "\n";
    cout << OwO.depth(29) << "\n";
    cout << OwO.numOfLeaves() << "\n";
    cout << OwO.findMax() << "\n";
    cout << OwO.findMaxChild() << "\n";
}

void binarysearchtreeTest() {
    Tree OwO(42);

    OwO.insert(42, 24);
    OwO.insert(42, 49);
    OwO.insert(24, 4);
    OwO.insert(24, 26);
    OwO.insert(4, 1);
    OwO.insert(4, 6);
    OwO.insert(6, 5);
    OwO.insert(6, 10);
    OwO.insert(10, 7);
    OwO.insert(26, 25);
    OwO.insert(49, 47);
    OwO.insert(47, 46);
    OwO.insert(49, 53);
    OwO.insert(53, 50);
    OwO.insert(53, 99);
    OwO.insert(99, 63);
    OwO.insert(63, 54);

    OwO.preorder();
    cout << OwO.remove(24) << "\n";
    OwO.preorder();
    OwO.postorder();
    cout << OwO.isBinaryTree() << "\n";
    cout << OwO.isBinarySearchTree() << "\n";
    cout << OwO.isMaxHeapTree() << "\n";
    cout << OwO.height() << "\n";
    cout << OwO.depth(46) << "\n";
    cout << OwO.numOfLeaves() << "\n";
    cout << OwO.findMax() << "\n";
    cout << OwO.findMaxChild() << "\n";
}

void maxheaptreeTest() {
    Tree OwO(99);
    
    OwO.insert(99, 25);
    OwO.insert(99, 42);
    OwO.insert(25, 10);
    OwO.insert(25, 19);
    OwO.insert(42, 30);
    OwO.insert(42, 40);
    OwO.insert(10, 9);
    OwO.insert(10, 4);
    OwO.insert(19, 15);
    OwO.insert(19, 17);
    OwO.insert(30, 25);
    OwO.insert(30, 24);
    OwO.insert(40, 37);
    OwO.insert(40, 36);
    OwO.insert(9, 5);
    OwO.insert(9, 6);
    OwO.insert(4, 1);
    OwO.insert(4, 2);
    OwO.insert(15, 10);
    OwO.insert(15, -7);
    OwO.insert(17, -9);
    OwO.insert(17, -25);   

    OwO.preorder();
    cout << OwO.remove(25) << "\n";
    OwO.preorder();
    OwO.postorder();
    cout << OwO.isBinaryTree() << "\n";
    cout << OwO.isBinarySearchTree() << "\n";
    cout << OwO.isMaxHeapTree() << "\n";
    cout << OwO.height() << "\n";
    cout << OwO.depth(24) << "\n";
    cout << OwO.numOfLeaves() << "\n";
    cout << OwO.findMax() << "\n";
    cout << OwO.findMaxChild() << "\n"; 
}


int main() { 
    randomTest();
    binarysearchtreeTest();
    maxheaptreeTest();
    return 0;
}
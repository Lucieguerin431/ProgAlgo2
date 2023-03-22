#include "mainwindow.h"
#include "tp3.h"
#include <QApplication>
#include <time.h>
#include <stack>
#include <queue>

MainWindow* w = nullptr;
using std::size_t;

struct SearchTreeNode : public Node
{    
    SearchTreeNode* left;
    SearchTreeNode* right;
    int value;

    void initNode(int value)
    {
        // init initial node without children
        this->left=NULL;
        this->right=NULL;
        this->value=value;
    }

void insertNumber(int value) {
    // create a new node and insert it in right or left child
    if (value>this->value)
    {
        if (this->right==NULL)
        {
            this->right=(SearchTreeNode*)malloc(sizeof(Node));
            this->right=(SearchTreeNode*)createNode(value);
        }
        else{this->right->insertNumber(value);}
    }
    else{
        if (this->left==NULL)
        {
            this->left=(SearchTreeNode*)malloc(sizeof(Node));
            this->left=(SearchTreeNode*)createNode(value);
        }
        else{this->left->insertNumber(value);}
                
    }
            
}

uint height() const	{
    // should return the maximum height between left child and
    // right child +1 for itself. If there is no child, return
    // just 1
    int heightLeft=0;
    int heightRight=0;

    if (this->left==NULL && this->right==NULL)
    {
        return 1;
    }
    else{
        if (this->left!=NULL)
        {
            heightLeft+=this->left->height();
        }
        if (this->right!=NULL)
        {
            heightRight+=this->right->height();
        }
        if (heightRight>heightLeft)
        {
            return heightRight+1;
        }
        else{return heightLeft+1;}
            
    }
        
    return 1;
}

uint nodesCount() const {
    // should return the sum of nodes within left child and
    // right child +1 for itself. If there is no child, return
    // just 1

    int numLeft=0;
    int numRight=0;

    if (this->left==NULL && this->right==NULL)
    {
        return 1;
    }
    else{
        if (this->left!=NULL)
        {
            numLeft+=this->left->nodesCount();
        }
        if (this->right!=NULL)
        {
            numRight+=this->right->nodesCount();
        }
        return numLeft+numRight+1;  
    }
}

bool isLeaf() const {
    // return True if the node is a leaf (it has no children)
    if (this->left==NULL && this->right==NULL)
    {
        return true;
    }
    else{return false;
    } 
}

void allLeaves(Node* leaves[], uint& leavesCount) {
    // fill leaves array with all leaves of this tree
    if (this->isLeaf()==true)
    {
        leaves[leavesCount]=this;
        leavesCount++;
    }
    else{
        if (this->left!=NULL)
        {
            this->left->allLeaves(leaves,leavesCount);
        }
        if (this->right!=NULL)
        {
            this->right->allLeaves(leaves,leavesCount);
        }
    }
}

void inorderTravel(Node* nodes[], uint& nodesCount) {
    // fill nodes array with all nodes with inorder travel
    if (this->left!=NULL)
    {
        this->left->inorderTravel(nodes,nodesCount);
    }
    nodes[nodesCount]=this;
    nodesCount++;
    if (this->right!=NULL)
    {
        this->right->inorderTravel(nodes,nodesCount);
    }
}

void preorderTravel(Node* nodes[], uint& nodesCount) {
    // fill nodes array with all nodes with preorder travel
    nodes[nodesCount]=this;
    nodesCount++;

    if (this->left!=NULL)
    {
        this->left->preorderTravel(nodes,nodesCount);
    }
    if (this->right!=NULL)
    {
        this->right->preorderTravel(nodes,nodesCount);
    }
}

void postorderTravel(Node* nodes[], uint& nodesCount) {
    // fill nodes array with all nodes with postorder travel

    if (this->left!=NULL)
    {
        this->left->postorderTravel(nodes,nodesCount);
    }
    if (this->right!=NULL)
    {
        this->right->postorderTravel(nodes,nodesCount);
    }
        nodes[nodesCount]=this;
        nodesCount++;
}

Node* find(int value) {
    // find the node containing value
    if (this->value!=value)
    {
        if (this->right != NULL)
        {
            this->right->find(value);
        }
        if (this->left != NULL)
        {
            this->left->find(value);
        }
    }
    else
    {
        return this;
    }
}

void reset()
{
    if (left != NULL)
        delete left;
    if (right != NULL)
        delete right;
    left = right = NULL;
}

SearchTreeNode(int value) : Node(value) {initNode(value);}
~SearchTreeNode() {}
int get_value() const {return value;}
Node* get_left_child() const {return left;}
Node* get_right_child() const {return right;}
};

Node* createNode(int value) {
    return new SearchTreeNode(value);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 200;
    w = new BinarySearchTreeWindow<SearchTreeNode>();
	w->show();

	return a.exec();
}

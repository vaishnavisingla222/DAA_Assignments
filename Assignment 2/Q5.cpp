#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *left, *right;
    Node(char c,int f)
    {
        ch=c;
        freq=f;
        left=nullptr;
        right=nullptr;
    }
};

struct compare
{
    bool operator()(Node* a,Node* b)
    {
        return a->freq > b->freq;//min frequency at top
    }
};
void print(Node *root, string code)
{
    if(root==nullptr)
    return;

    if(root->left==nullptr && root->right==nullptr)
    cout<<root->ch<<" -> "<<code<<endl;

    print(root->left,code+"0");
    print(root->right,code+"1");
}
void huffmanCode(int total,char ellements[],int freq[])
{
    priority_queue<Node*,vector<Node*>,compare> pq;// sort characters according to their frequency in increasing order

    for(int i=0;i<total;i++) //pushing into queue
    {
        Node *temp=new Node(ellements[i],freq[i]);
        pq.push(temp);
    }
    while(pq.size()>1)
    {
        Node *left=pq.top();
        pq.pop();
        Node *right=pq.top();
        pq.pop();

        Node* parent=new Node('#',left->freq+right->freq);

        parent->left=left;
        parent->right=right;
        pq.push(parent);
    }
    Node *root=pq.top();
    cout<<"Character -> Huffman Code\n";
    print(root,"");
}
int main()
{
    int total;
    cout<<"Enter the total number of characters: ";
    cin>>total;

    char alp[total];
    int freq[total];

    cout<<"Enter the characters and their frewuency simultaneouly:\n";
    for(int i=0;i<total;i++)
    cin>>alp[i]>>freq[i];

    huffmanCode(total,alp,freq);
}
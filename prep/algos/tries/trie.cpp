class Solution {
public:
    struct node{
        node* child[26];
        int is;
    };
    node* newnode(){
        struct node* x = new node();
        for(int i=0;i<26;i++)
        {
            x->child[i] = NULL;
        }
        x->is = 0;
        return x;
    }
    node *root;
    void insert(string a)
    {
        node* temp = root;
        for(int i=0;i<a.length();i++)
        {
            int num = a[i]-'a';
            if(temp->child[num] == NULL)
                temp->child[num] = newnode();
            temp = temp->child[num];
        }
        temp->is=1;
    }
    bool search(string a)
    {
        node* temp = root;
        for(int i=0;i<a.length();i++)
        {
            int num = a[i]-'a';
            if(temp->child[num]==NULL)
                return false;
            temp = temp->child[num];
        }
        if(temp->is == 1)
            return true;
        else
            return false;
    }
    string longestWord(vector<string>& words) {
        root = newnode();
        string ans = "";
        for(auto it:words)
        {
            insert(it);
        }
    }
};
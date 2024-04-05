#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

class Node
{
public:
    char data;
    map<char, Node *> children;
    bool is_end_of_word;
    Node(char data)
    {
        this->data = data;
        this->children = map<char, Node *>();
        this->is_end_of_word = false;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        this->root = new Node(' ');
    }

    void insert(string word)
    {
        Node *curr = this->root;
        for (char ch : word)
        {
            if (curr->children.find(ch) == curr->children.end())
            {
                curr->children[ch] = new Node(ch);
            }
            curr = curr->children[ch];
        }
        curr->is_end_of_word = true;
    }

    Node *get_last_node(Node *root, string pref, int ind)
    {
        if (ind == pref.size())
        {
            return root;
        }
        char ch = pref[ind];
        Node *curr = root->children[ch];
        if (curr == nullptr)
        {
            return nullptr;
        }
        return get_last_node(curr, pref, ind + 1);
    }

    void find_all_words(Node *root, string word, vector<string> &ans)
    {
        word += root->data;
        if (root->is_end_of_word)
        {
            ans.push_back(word);
        }
        for (auto i : root->children)
        {
            find_all_words(i.second, word, ans);
        }
    }

    void auto_complete(string pref)
    {
        vector<string> ans;
        Node *last_node = get_last_node(this->root, pref, 0);
        if (last_node == nullptr)
        {
            return;
        }
        for (auto i : last_node->children)
        {
            find_all_words(i.second, pref, ans);
        }
        for (string s : ans)
        {
            cout << s << " ";
        }
        cout << endl;
    }

    void remove(Node *root, string word, int ind)
    {
        if (ind == word.size())
        {
            root->is_end_of_word = false;
            return;
        }
        char ch = word[ind];
        Node *curr = root->children[ch];
        if (curr == nullptr)
        {
            return;
        }
        remove(curr, word, ind + 1);
        if (curr->children.size() == 0 && curr->is_end_of_word == false)
        {
            root->children.erase(curr->data);
            delete curr;
        }
    }

    void remove(string word)
    {
        remove(this->root, word, 0);
    }

    void print()
    {
        queue<Node *> q;
        for (auto i : this->root->children)
        {
            if (i.second)
            {
                q.push(i.second);
            }
            else
            {
                this->root->children.erase(i.first);
            }
        }
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                Node *curr = q.front();
                cout << curr->data << " ";
                for (auto i : curr->children)
                {
                    q.push(i.second);
                }
                q.pop();
            }
            cout << endl;
        }
        cout << endl;
    }

    void destroy(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        for (auto i : root->children)
        {
            if (i.second)
            {
                destroy(i.second);
            }
        }
        delete root;
    }

    ~Trie()
    {
        destroy(this->root);
    }
};

int main()
{
    Trie t = Trie();
    vector<string> words = {"car", "carpet", "carpool", "bag"};
    for (string s : words)
    {
        t.insert(s);
    }
    t.print();
    t.auto_complete("ca");
    t.auto_complete("ba");
    cout << endl;
    t.remove("carpet");
    t.remove("car");
    t.remove("bag");
    t.auto_complete("ca");
    t.auto_complete("ba");
    cout << endl;
    t.print();
    return 0;
}
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

class Node
{
public:
    char data;
    unordered_map<char, Node *> children;
    bool is_end_of_word;
    Node(char data)
    {
        this->data = data;
        this->is_end_of_word = false;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        this->root = new Node(' ');
    }

    void insert(string word)
    {
        Node *curr = this->root;
        for (char ch : word)
        {
            if (curr->children[ch] == nullptr)
            {
                curr->children[ch] = new Node(ch);
            }
            curr = curr->children[ch];
        }
        curr->is_end_of_word = true;
    }

    void find_all_words(Node *curr, string word, vector<string> &ans)
    {
        word += curr->data;
        if (curr->is_end_of_word)
        {
            ans.push_back(word);
        }
        for (auto i : curr->children)
        {
            find_all_words(i.second, word, ans);
        }
    }

    vector<string> auto_complete(string pref)
    {
        vector<string> ans;
        Node *curr = this->root;
        for (char ch : pref)
        {
            if (curr->children[ch] == nullptr)
            {
                curr = nullptr;
                break;
            }
            curr = curr->children[ch];
        }
        if (curr == nullptr)
        {
            return ans;
        }
        for (auto i : curr->children)
        {
            find_all_words(i.second, pref, ans);
        }
        return ans;
    }

    void print()
    {
        queue<Node *> q;
        for (auto i : this->root->children)
        {
            q.push(i.second);
        }
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                Node *curr = q.front();
                cout << curr->data << " ";
                q.pop();
                for (auto i : curr->children)
                {
                    q.push(i.second);
                }
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    Trie trie = Trie();
    vector<string> words = {
        "cat",
        "car",
        "carpet",
        "carpool",
        "carpooling",
        "coding",
        "coder",
        "codecommunity",
        "book",
        "baggage",
        "bag",
    };
    for (string s : words)
    {
        trie.insert(s);
    }
    trie.print();
    for (string s : trie.auto_complete("car"))
    {
        cout << s << " ";
    }
    return 0;
}
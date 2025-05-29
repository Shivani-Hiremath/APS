#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Trie Node
class TrieNode {
public:
    bool isEndOfWord;
    unordered_map<char, TrieNode*> children;

    TrieNode() {
        isEndOfWord = false;
    }
};

// Trie Class
class Trie {
private:
    TrieNode* root;

    void dfs(TrieNode* node, string prefix, vector<string>& results) {
        if (node->isEndOfWord)
            results.push_back(prefix);

        for (auto& pair : node->children) {
            dfs(pair.second, prefix + pair.first, results);
        }
    }

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            if (!current->children[c])
                current->children[c] = new TrieNode();
            current = current->children[c];
        }
        current->isEndOfWord = true;
    }

    bool search(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            if (!current->children[c])
                return false;
            current = current->children[c];
        }
        return current->isEndOfWord;
    }

    bool startsWith(const string& prefix) {
        TrieNode* current = root;
        for (char c : prefix) {
            if (!current->children[c])
                return false;
            current = current->children[c];
        }
        return true;
    }

    vector<string> getWordsWithPrefix(const string& prefix) {
        vector<string> results;
        TrieNode* current = root;
        for (char c : prefix) {
            if (!current->children[c])
                return results;
            current = current->children[c];
        }
        dfs(current, prefix, results);
        return results;
    }
};

// Main with User Input
int main() {
    Trie trie;
    int choice;
    string word, prefix;

    cout << " Trie Data Structure - Menu Driven Program\n";

    do {
        cout << "\nChoose an option:\n";
        cout << "1. Insert a word\n";
        cout << "2. Search a word\n";
        cout << "3. Search a prefix\n";
        cout << "4. Autocomplete suggestions for a prefix\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter word to insert: ";
            cin >> word;
            trie.insert(word);
            cout << " Word inserted.\n";
            break;
        case 2:
            cout << "Enter word to search: ";
            cin >> word;
            if (trie.search(word))
                cout << " Word exists in the Trie.\n";
            else
                cout << " Word not found.\n";
            break;
        case 3:
            cout << "Enter prefix to search: ";
            cin >> prefix;
            if (trie.startsWith(prefix))
                cout << " Prefix exists in the Trie.\n";
            else
                cout << " Prefix not found.\n";
            break;
        case 4:
            cout << "Enter prefix for suggestions: ";
            cin >> prefix;
            {
                vector<string> suggestions = trie.getWordsWithPrefix(prefix);
                if (suggestions.empty()) {
                    cout << " No words found with that prefix.\n";
                } else {
                    cout << " Suggestions:\n";
                    for (const string& s : suggestions)
                        cout << "- " << s << endl;
                }
            }
            break;
        case 5:
            cout << " Exiting the program.\n";
            break;
        default:
            cout << " Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}

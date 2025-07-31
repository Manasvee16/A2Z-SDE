// check if a node has any children
bool isEmpty(trie_node* node) {
    for (int i = 0; i < 26; i++) {
        if (node->children[i] != nullptr)
            return false;
    }
    return true;
}
// recursive delete helper
trie_node* deleteHelper(trie_node* node, char key[], int depth) {
  /*node: current trie node,
    key[]: the word to delete (as a character array),
    depth: current index in the key.*/
    if (!node) //there's nothing to delete
        return nullptr;
    if (key[depth] == '\0') 
    { //If we have reached the end of the word (i.e., the terminating null character of the C-string), we now process the current node.
        if (node->value != 0) 
        { //If this node marks the end of a word, remove that word
            node->value = 0;
        }
        if (isEmpty(node)) {
            delete node;
            return nullptr;
        }
        return node;
    }
    int index = key[depth] - 'a';
    node->children[index] = deleteHelper(node->children[index], key, depth + 1); //Recurse into the corresponding child node for the current character, and update the child pointer with the result.
    if (isEmpty(node) && node->value == 0) {
        delete node;
        return nullptr;
    }
    return node;
}

class Solution {
public:
    void deleteKey(trie_node* root, char key[]) {
        deleteHelper(root, key, 0);
    }
};

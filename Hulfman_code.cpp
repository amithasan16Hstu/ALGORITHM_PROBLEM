#include <bits/stdc++.h>
using namespace std;

// A Huffman tree node
struct Node {
    char data;
    int freq;
    Node* left;
    Node* right;

    Node(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }
};

// Comparator for the priority queue (min-heap)
struct CompareNodes {
    bool operator()(Node* const &n1, Node* const &n2) {
        return n1->freq > n2->freq;
    }
};

// Utility function to print Huffman codes from the Huffman tree
void printCodes(Node* root, string code, unordered_map<char, string> huffmanCodes) {
    if (root == nullptr)
        return;

    // Found a leaf node
    if (!root->left && !root->right) {
        huffmanCodes[root->data] = code;
        cout << root->data << " : " << code << endl;
    }

    // Traverse left and append '0'
    printCodes(root->left, code + "0", huffmanCodes);
    
    // Traverse right and append '1'
    printCodes(root->right, code + "1", huffmanCodes);
}

// Build Huffman tree and generate Huffman codes
string buildHuffmanTree(string text, unordered_map<char, string> huffmanCodes) {
    // Step 1: Calculate frequency of each character
    unordered_map<char, int> freq;
    for (char c : text) {
        freq[c]++;
    }

    // Step 2: Create a priority queue to store nodes (min-heap)
    priority_queue<Node*, vector<Node*>, CompareNodes> pq;

    // Step 3: Create a leaf node for each character and add it to the priority queue
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Step 4: Build the Huffman tree by extracting two minimum frequency nodes
    // and creating a new internal node with sum of their frequencies
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* internalNode = new Node('$', left->freq + right->freq);
        internalNode->left = left;
        internalNode->right = right;

        pq.push(internalNode);
    }

    // Step 5: Root of Huffman tree is stored in pq.top()
    Node* root = pq.top();

    // Step 6: Generate Huffman codes and print them
    cout << "Huffman Codes:" << endl;
    printCodes(root, "", huffmanCodes);

    // Step 7: Encode the input text using Huffman codes
    string encodedText = "";
    for (char c : text) {
        encodedText += huffmanCodes[c];
    }

    // Step 8: Clean up memory by deleting nodes
    delete root;

    return encodedText;
}

int main() {
    string text;
    cout << "Enter text to encode using Huffman coding: ";
    getline(cin, text);

    unordered_map<char, string> huffmanCodes;
    string encodedText = buildHuffmanTree(text, huffmanCodes);

    cout << "\nEncoded text: " << encodedText << endl;

    return 0;
}

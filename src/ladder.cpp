#include "ladder.h"
#include <iostream>


using namespace std;

// Error Handling 
void error(string word1, string word2, string msg) {
    cerr << "Error Is " << msg << " with words " << word1 << ", " << word2 << endl;
}

// Edit Distance Within?
bool edit_distance_within(const std::string &str1, const std::string &str2, int d) {
    // Compares words to see if they are neighbors
    return true;
}

// Is_Adjacent 
bool is_adjacent(const string &word1, const string &word2) {
    // Compares words to see if they are neighbors?
    // Uses BFS

    if (word1 == word2) 
        return false;

    queue<string> queue;
    set<string> visited;
    queue.push(word1);
    visited.insert(word1);

    while (!queue.empty()) {
        string current = queue.front();
        queue.pop();

        if (current == word2)
            return true;

        for (size_t i = 0; i < current.length(); ++i) {
            string next_word = current;

            for (char letter = 'a'; letter <= 'z'; ++letter) {
                if (next_word[i] == letter) 
                    continue;

                next_word[i] = letter;
                visited.insert(next_word);
                queue.push(next_word);
            }
        }
    }
    return false;
}

// Generate Word ladder
vector<string> generate_word_ladder(const string &begin_word, const string &end_word, const set<string> &word_list) {
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});

    set<string> visited; 
    visited.insert(begin_word);

    while (!ladder_queue.empty()) {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();

        string last_word = ladder.back();

        for (const string &word : word_list) {
            if (is_adjacent(last_word, word)) {
                if (visited.find(word) == visited.end()) {
                    visited.insert(word);

                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);

                    if (word == end_word) 
                        return new_ladder;

                    ladder_queue.push(new_ladder);
                }
            }
        }
    }

    return {};
}



// TESTING 

// Loads Words from file 
void load_words(set<string> &word_list, const string &file_name) {

}

// Print Word Ladder
void print_word_ladder(const vector<string> &ladder) {

}

// Verify Word Ladder
void verify_word_ladder() {

}


// int main() {

//     return 0;
// }
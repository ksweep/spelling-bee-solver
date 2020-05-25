//
//  SolutionCreator.cpp
//  spelling-bee-solver
//
//  Created by Breeze on 5/25/20.
//  Copyright © 2020 Kevin Broom. All rights reserved.
//

#include "SolutionCreator.hpp"

#include "TrieNode.hpp"

SolutionCreator::SolutionCreator(const std::string& letters, TrieNode* trie_root) : letters_(letters), trie_root_(trie_root) {}

bool SolutionCreator::IsValidWord(std::string &s) {
    return s.size() > 3 && s.find(letters_[0]) != std::string::npos;
}

TrieNode* SolutionCreator::NodeFromString(std::string& s) {

    // NOTE: if we get rid of prefix variable in TrieNode, we need to build the string here

    TrieNode* result = trie_root_;
    for (const char c : s) {
        if (result->children[c - 'a'] != nullptr) {
            result = result->children[c - 'a'];
        } else {
            return nullptr;
        }
    }
    return result;
}

void SolutionCreator::SearchForWords(std::string& build_word, std::vector<std::string>& all_words) {
    TrieNode* current_trie_node = NodeFromString(build_word);

    if (current_trie_node->is_word && IsValidWord(build_word)) {
        all_words.push_back(build_word);
    }

    for (const char c : letters_) {
        if (current_trie_node->children[c - 'a'] == nullptr) {
            continue;
        }

        // add letter
        build_word.push_back(c);

        // recurse
        SearchForWords(build_word, all_words);

        // remove letter
        build_word.pop_back();
    }
}

std::vector<std::string> SolutionCreator::GetWords() {
    std::vector<std::string> result;
    std::string build_word;
    SearchForWords(build_word, result);

    std::sort(result.begin(), result.end(), []
    (const std::string& first, std::string& second){
        return first.size() > second.size();
    });

    return result;
}

//
//  SolutionCreator.hpp
//  spelling-bee-solver
//
//  Created by Breeze on 5/25/20.
//  Copyright © 2020 Kevin Broom. All rights reserved.
//

#ifndef SolutionCreator_hpp
#define SolutionCreator_hpp

#include <string>
#include <vector>

class TrieNode;

class SolutionCreator {
private:
    const std::string letters_;
    TrieNode* trie_root_;

    TrieNode* NodeFromString(std::string& s);
    void SearchForWords(std::string& build_word, std::vector<std::string>& all_words);
    bool IsValidWord(std::string& s);

public:
    SolutionCreator(const std::string& letters, TrieNode* trie_root);

    std::vector<std::string> GetWords();
};

#endif /* SolutionCreator_hpp */

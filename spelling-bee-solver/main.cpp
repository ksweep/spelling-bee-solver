//
//  main.cpp
//  spelling-bee-solver
//
//  Created by Breeze on 5/25/20.
//  Copyright © 2020 Kevin Broom. All rights reserved.
//

#include <iostream>

#include "SolutionCreator.hpp"
#include "TrieCreator.hpp"
#include "TrieNode.hpp"

void TimeBlock (const std::function <void ()>& my_block) {
    const auto total_start = std::chrono::high_resolution_clock::now();
    my_block();
    const auto total_finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = total_finish - total_start;
    std::cout << "Total Elapsed Time: " << elapsed.count() << " s" << std::endl;
}

int main(int argc, const char * argv[]) {
    TimeBlock([] {
        TrieNode *trie_root = TrieCreator::MakeTrie("words.txt");

        std::vector<std::string> words =  SolutionCreator("nacdhip", trie_root).GetWords();

        for (const std::string& word : words) {
            std::cout << word << std::endl;
        }
    });
    return 0;
}

from typing import List

# https://leetcode.com/problems/replace-words/
class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        sentence_list: List[str] = sentence.split(" ")
        sorted_dict = sorted(dictionary, key=lambda word: len(word))
        
        for i in range(len(sentence_list)):
            # Find root
            for j in range(len(sorted_dict)):
                if sentence_list[i].startswith(sorted_dict[j]) and len(sentence_list[i]) > len(sorted_dict[j]):
                    sentence_list[i] = sorted_dict[j]
                    break
                
        return " ".join(sentence_list)
                    
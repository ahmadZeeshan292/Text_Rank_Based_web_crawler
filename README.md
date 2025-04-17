# Web Crawler and Search Engine Simulator  

![C++](https://img.shields.io/badge/Language-C++-blue)
![Data Structures](https://img.shields.io/badge/Topic-Data%20Structures-yellowgreen)
![Algorithms](https://img.shields.io/badge/Topic-Algorithms-brightgreen)

## 📌 Overview  
A **Trie-based** web crawler and search engine simulator designed to efficiently retrieve data from a local database of 50 files. Features include a GUI interface, frequency analysis, and optimized search operations.

## 🚀 Features  
- **Trie Data Structure**: Enables O(k) search time (k = query length)  
- **Frequency Tracking**: Hashmap stores word occurrences for logical operations (AND/OR)  
- **Scalable GUI**: Dynamically displays results for any number of files  
- **Local Server**: Simulates real-world crawling on controlled data  

## ⚡ Performance  
| Metric          | Value               |
|-----------------|---------------------|
| Avg. Search Time | 20-30 ms           |
| Time Complexity | O(k) per query     |
| Space Complexity| 15x63x63 = 57,660  |

## 🤔 Why Trie?  
While inverted indexes offer O(1) lookup *in theory*, their real-world performance suffers due to:  
🔴 **Hash Collisions**: String keys (especially anagrams) degrade to O(n)  
🟢 **Trie Advantage**:  
- Worst-case O(15) for longest English words  
- Space complexity: ~55K units (62 chars × 15 levels)  
- Predictable performance at scale  

## ⚠️ Limitations  
- ❌ Space-sensitive queries may fail  
- ❌ Single-character queries return no results  

---

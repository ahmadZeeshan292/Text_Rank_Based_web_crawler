# Web Crawler and Search Engine Simulator  

<img src="media/image1.png" width="100" height="100" align="left">
<img src="media/image2.png" width="100" height="100" align="right">

<br clear="both">

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
| Space Efficiency| Constant (vs O(n)) |

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

## 📚 References  
- Trie theory from open sources  
- Code assistance via [ChatGPT](http://www.chat.openai.com)  
- Demo: [Video Link](https://drive.google.com/file/d/1m6o9M8psB91zPvFR-daR4sMZEHacrGtv/view)  

## 👥 Team  
| Role              | Name             |
|-------------------|------------------|
| Course Instructor | Anum Abdul Salam |
| Lab Engineer      | Kashaf Raheem    |
| Students          | Shehryar Kashif, Ahmad Zeshan, Usama [Last Name] |

**Degree**: CE-44(A)  

---

# 🔍 Web Crawler and Search Engine Simulator

![C++](https://img.shields.io/badge/Language-C++-blue)
![Data Structures](https://img.shields.io/badge/Topic-Data%20Structures-yellowgreen)
![Algorithms](https://img.shields.io/badge/Topic-Algorithms-brightgreen)

---

## 📌 Overview

A **Trie-based Web Crawler and Search Engine Simulator** designed to retrieve and rank data from a local collection of 50 documents. This project replicates core components of real-world search engines by implementing efficient text indexing, query resolution (AND/OR), and frequency tracking—all embedded in a GUI.

The engine crawls local files, indexes their contents using a **Trie data structure**, and allows users to search keywords with high-speed resolution, regardless of input size.

---

## 🚀 Features

- 🔤 **Trie Data Structure**: Ensures fast lookups in **O(k)** time, where *k* is the query length
- 📊 **Frequency Tracking**: Uses a **hash map** to store word frequency and compute logical AND/OR query matches
- 🖥️ **Scalable GUI**: Dynamically displays search results across any number of documents
- 🌐 **Local Server Simulation**: Mimics real-world web crawling on a controlled file dataset
- 🧠 **Optimized Search**: Predictable performance across large-scale text data

---

## ⚡ Performance

| Metric           | Value             |
|------------------|-------------------|
| Average Search Time | 20–30 ms       |
| Search Time Complexity | O(k)       |
| Space Complexity (Trie) | 15 × 63 × 63 = ~57,645 nodes |

---

## 🤔 Why Use a Trie Over an Inverted Index?

While **inverted indexes** (typically backed by hash maps) offer theoretical **O(1)** time complexity, the **real-world performance tells a different story**, especially at scale:

### ❌ Problems with Inverted Indexes:
- **Hash Collisions**: When keys are strings (as in inverted indexes), anagrams and similar words increase the likelihood of collisions
- **String Hashing**: Hash performance varies with word length, distribution, and collision resolution strategy
- **Worst-Case Lookup**: Can degrade to **O(n)** in practice, especially with large vocabularies

### ✅ Advantages of Trie:
- **Guaranteed O(k)** search, where *k* is word length (e.g., max 15 for English words)
- **Predictable Scaling**: No collisions, consistent time performance
- **Space Efficiency**:  
  For 15-letter max depth and 62 characters (26 lower + 26 upper + 10 digits), the space complexity is: 57,645 units
  
This is **measly** for systems handling millions—even billions—of words.
- **Scalable for Crawlers**: Tries are the go-to structure for prefix-based queries, autocompletion, and spell-correction in **web crawlers** and **search engines**.

---

## ⚠️ Limitations

- ❌ **Case-sensitive** and **space-sensitive** queries may fail without preprocessing
- ❌ **Single-character** queries return no results (for optimization)
- 🔁 Trie is rebuilt when new files are added (not incremental yet)

---

## 🛠️ Tech Stack

- **Language**: C++
- **Data Structures**: Trie, Hash Map
- **Algorithms**: Frequency Counting, Set Intersection (AND), Set Union (OR)
- **GUI**: Qt / C++ STL I/O (based on implementation)
- **Local Data**: 50 text files (custom dataset)

---

## 📈 Use Case Simulation

This project is designed to simulate:

- 🕸️ A **web crawler** indexing static pages
- 🔍 A **search engine interface** for keyword lookup
- 📚 An educational tool to demonstrate trie-based search and indexing performance

---

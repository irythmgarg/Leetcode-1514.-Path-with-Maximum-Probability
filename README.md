# Leetcode-1514.-Path-with-Maximum-Probability
# 🎯 Maximum Probability Path (C++)

This project solves the **Maximum Probability Path** problem using a modified version of **Dijkstra's Algorithm**. Given a graph where each edge has a success probability, the goal is to find the **most reliable path** between two nodes (i.e., the one with the **maximum product of probabilities**).

---

## 📊 Problem Description

You are given:
- `n` nodes (labeled `0` to `n-1`)
- A list of edges with associated success probabilities
- A `start` node and an `end` node

Your task is to find the **maximum probability** of reaching the destination from the source by traversing edges. The total path probability is the product of all edge probabilities along the path.

---

## 🚀 Features

- Implements **Dijkstra's Algorithm** for maximizing probabilities
- Uses **priority queue** (max-heap) for optimal traversal
- Handles **cyclic graphs** and **disconnected components**

---

## 🧠 How It Works

### Step 1: Graph Construction
- Represent the graph using an **adjacency list**
- Store the edge probabilities between each connected node

### Step 2: Modified Dijkstra's Algorithm
- Use a **max-heap** to always explore the path with the **highest cumulative probability**
- Update the path probability only if the new one is better than the previous

---

## 🛠️ Technologies Used

- **Language**: C++
- **Algorithm**: Dijkstra’s (maximizing probability instead of minimizing cost)
- **Data Structures**: `priority_queue`, `unordered_map`, `vector`

---

## 📦 Usage

### Input

```cpp
int n = 3;
vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
vector<double> succProb = {0.5, 0.5, 0.2};
int start = 0;
int end = 2;
Output
double result = 0.25; // Best path: 0 → 1 → 2 with probability 0.5 * 0.5 = 0.25
happy coding

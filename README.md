# Analysis of Algorithms in C

Here is a table summarizing the algorithms along with their best-case, average-case, and worst-case time complexities:

| Algorithm                   | Best Case         | Average Case         | Worst Case             |
|-----------------------------|------------------|----------------------|------------------------|
| Selection Sort              | Ω(n^2)           | Θ(n^2)               | O(n^2)                 |
| Insertion Sort              | Ω(n)             | Θ(n^2)               | O(n^2)                 |
| Merge Sort                  | Ω(n log n)       | Θ(n log n)           | O(n log n)             |
| Quick Sort                  | Ω(n log n)       | Θ(n log n)           | O(n^2)                 |
| Binary Search               | Ω(1)             | Θ(log n)             | O(log n)               |
| Strassen's Multiplication   | Ω(n^2.8074)      | Θ(n^2.8074)          | O(n^2.8074)            |
| Matrix Chain Multiplication | Ω(n^3)           | Θ(n^3)               | O(n^3)                 |
| Longest Common Subsequence  | Ω(m * n)         | Θ(m * n)             | O(m * n)               |
| Job Sequencing (Greedy)     | Ω(n log n)       | Θ(n log n)           | O(n^2)                 |
| Dijkstra's Algorithm        | Ω((V + E)logV)   | Θ(V + ElogV)         | O(V^2)                 |
| Prim's Algorithm            | Ω(E log V)       | Θ(E log V)           | O(E log V)             |
| Kruskal's Algorithm         | Ω(E log E)       | Θ(E log E)           | O(E log E)             |
| Fractional Knapsack (Greedy)| Ω(n log n)       | Θ(n log n)           | O(n log n)             |
| N-Queen Problem (Backtracking) | Ω(n!)         | Θ(n!)                | O(n!)                  |
| Subset Sum (Backtracking)   | Ω(2^n)           | Θ(2^n)               | O(2^n)                 |
| Graph Coloring              | Ω(m^V)           | Θ(m^V)               | O(m^V)                 |
| 0/1 Knapsack (Branch & Bound) | Ω(n * W)       | Θ(n * W)             | O(n * W)               |
| Traveling Salesman (Branch & Bound) | Ω(n^2 * 2^n) | Θ(n^2 * 2^n)     | O(n^2 * 2^n)           |
| 15 Puzzle Problem           | Ω(b^d)           | Θ(b^d)               | O((n! * log n!)        |
| Vertex Cover                | Ω(V + E)         | Θ(V + E)             | O(V + E)               |
| Set Cover (Approximation)   | Ω(2^n)           | Θ(2^n)               | O(2^n)                 |
| Rabin-Karp Algorithm        | Ω(n + m)         | Θ(n + m)             | O(n * m)               |
| Knuth-Morris-Pratt Algorithm| Ω(n + m)         | Θ(n + m)             | O(n + m)               |

Please note that these are just asymptotic complexities, and the actual running time of an algorithm may vary depending on the input data.

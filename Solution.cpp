class Solution {
public:
    /**
     * Computes the maximum probability path from src to dst in a graph.
     * This is a variation of Dijkstra's algorithm where we maximize product of probabilities instead of minimizing distances.
     *
     * @param n Number of nodes in the graph.
     * @param edges List of edges, where each edge connects two nodes.
     * @param values Probability associated with each edge.
     * @param src Starting node.
     * @param dst Destination node.
     * @return Maximum probability of reaching dst from src.
     */
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& values, int src, int dst) {
        // Max-heap to process nodes with the highest probability first
        priority_queue<pair<double, int>> q;

        // Graph represented as adjacency list: node → (neighbor, probability)
        unordered_map<int, vector<pair<int, double>>> mp;

        // Build the graph
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = values[i];
            mp[u].push_back({v, prob});
            mp[v].push_back({u, prob});  // Undirected graph
        }

        // Start from the source with probability 1
        q.push({1.0, src});
        vector<double> answer(n, 0.0);  // Stores the best known probability to reach each node

        // Modified Dijkstra's Algorithm
        while (!q.empty()) {
            auto [currProb, node] = q.top();
            q.pop();

            if (node == dst)
                return currProb;  // Found the most probable path to destination

            for (auto& neighbor : mp[node]) {
                int nextNode = neighbor.first;
                double edgeProb = neighbor.second;

                // If this path yields a better probability, update it
                if (answer[nextNode] < currProb * edgeProb) {
                    answer[nextNode] = currProb * edgeProb;
                    q.push({answer[nextNode], nextNode});
                }
            }
        }

        // No path found to destination
        return 0.0;
    }
};

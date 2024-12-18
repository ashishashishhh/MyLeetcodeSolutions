#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cmath>
class Solution {
public:
  unordered_map<string, unordered_map<string, double>> buildGraph(const vector<vector<string>>& pairs, const vector<double>& rates) {
    unordered_map<string, unordered_map<string, double>> graph;
    for (size_t i = 0; i < pairs.size(); ++i) {
        string from = pairs[i][0];
        string to = pairs[i][1];
        double rate = rates[i];
        graph[from][to] = max(graph[from][to], rate);
        graph[to][from] = max(graph[to][from], 1.0 / rate);
    }
    return graph;
}

// Floyd-Warshall algorithm to compute max rates
unordered_map<string, unordered_map<string, double>> floydWarshall(unordered_map<string, unordered_map<string, double>>& graph) {
    for (auto& k : graph) {
        for (auto& i : graph) {
            for (auto& j : graph) {
                graph[i.first][j.first] = max(graph[i.first][j.first], graph[i.first][k.first] * graph[k.first][j.first]);
            }
        }
    }
    return graph;
}

// Main function to calculate the maximum amount
double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
    // Build graphs for day 1 and day 2
    auto graph1 = buildGraph(pairs1, rates1);
    auto graph2 = buildGraph(pairs2, rates2);
    
    // Run Floyd-Warshall on both graphs
    auto ratesDay1 = floydWarshall(graph1);
    auto ratesDay2 = floydWarshall(graph2);
    
    // Compute the maximum amount
    double maxAmount = 1.0; // Start with 1.0 of the initial currency
    for (const auto& currency : ratesDay1[initialCurrency]) {
        string intermediateCurrency = currency.first;
        double rate1 = currency.second;
        double rate2 = ratesDay2[intermediateCurrency][initialCurrency];
        maxAmount = max(maxAmount, rate1 * rate2);
    }
    
    return maxAmount;
}

};
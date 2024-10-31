#include <bits/stdc++.h>

using namespace std;

vector<string> findItinerary(vector<vector<string>> tickets)
{
  unordered_map<string, multiset<string>> graph;
  vector<string> itinerary;
  if (tickets.size() == 0)
    return itinerary;
  for (auto eachTicket : tickets)
    graph[eachTicket[0]].insert(eachTicket[1]);
  stack<string> dfs;
  dfs.push("JFK");
  while (!dfs.empty())
  {
    string topAirport = dfs.top();
    if (graph[topAirport].empty())
    {
      itinerary.push_back(topAirport);
      dfs.pop();
    }
    else
    {
      dfs.push(*(graph[topAirport].begin()));
      graph[topAirport].erase(graph[topAirport].begin());
    }
  }
  reverse(itinerary.begin(), itinerary.end());
  return itinerary;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<string>> tickets(n, vector<string>(2));
  for (int i = 0; i < n; i++)
    cin >> tickets[i][0] >> tickets[i][1];
  vector<string> result = findItinerary(tickets);
  for (int i = 0; i < result.size(); i++)
    cout << result[i] << " ";
  cout << "\n";

  return 0;
}
# Diamond-Traveller-problem
Problem: 
 Alice is a diamond merchant. She is supposed to collect a few diamonds by visiting nearby 
cities. Every diamond has a different weight and value associated with it. She has decided to 
travel in her bike with a backpack to carry the diamonds. This backpack can carry a maximum 
weight of W (user input).
 Alice wants to plan her trip, so, she gets a map to know the road distances between every 
pair of cities. Starting her journey from some city X (user’s choice), Alice wants to reach her 
destination city Y (user’s choice) where she will sell all the diamonds collected during journey. 
Therefore, one of her objectives is to maximize the total value of the diamonds to be 
collected. Moreover, she has decided to collect not more than 3 diamonds. She may go 
through a city without collecting the diamond from there. However, she does not want to 
travel through all the cities in the map. She knows that there are two cities (forbidden) she 
cannot travel through as there are road blockade due to some natural calamity. Alice wants 
to choose the shortest possible route. Formulate this problem as a graph problem where 
every vertex in the graph will represent a city and an edge between a pair of vertices will 
represent the road distance between those two cities (in km).
Initialize such graph randomly. Also, initialize the weight (in a specific range as specified 
below) and value (in a specific range as specified below) of each diamond residing in every 
city. Alice does not collect anything from the source and the destination cities.
Randomly select the two forbidden vertices. Simulate the problem with at least n=10 
vertices. There
will be at least 20 edges in the graph.
Diamonds weights in the range [1 to 50 unit]
Value of the diamonds in the range [500$ to 1000$]
Knapsack capacity W = 100 unit

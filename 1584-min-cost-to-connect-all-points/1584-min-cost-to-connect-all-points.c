int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    bool* inMST = (bool*)calloc(pointsSize, sizeof(bool));
    int* minDist = (int*)malloc(pointsSize * sizeof(int));
    
    for (int i = 0; i < pointsSize; i++) {
        minDist[i] = INT_MAX;
    }
    minDist[0] = 0;
    
    int totalCost = 0;
    
    for (int step = 0; step < pointsSize; step++) {
        int u = -1;
        // Find vertex with minimum distance not yet in MST
        for (int i = 0; i < pointsSize; i++) {
            if (!inMST[i] && (u == -1 || minDist[i] < minDist[u])) {
                u = i;
            }
        }
        
        inMST[u] = true;
        totalCost += minDist[u];
        
        // Update distance to remaining vertices
        for (int v = 0; v < pointsSize; v++) {
            if (!inMST[v]) {
                int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                if (dist < minDist[v]) {
                    minDist[v] = dist;
                }
            }
        }
    }
    
    free(inMST);
    free(minDist);
    
    return totalCost;
}
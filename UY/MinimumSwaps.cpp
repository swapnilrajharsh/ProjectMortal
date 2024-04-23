// Minimum swaps to sort the array

#include<iostream>
#include<vector>
#include<algorithm>

int calcMinmSwaps(std::vector<int> array) {
    int size = array.size();
    int answer = 0;

    std::vector<bool> visited(size, false);

    std::vector<std::pair<int, int>> arrayIndexes;
    
    // Storing Index along with it's value
    for (size_t index = 0; index<size; index++) {
        arrayIndexes.push_back(std::make_pair(array[index], index));
    }
    
    // Sort the array of pairs to know the cycles
    std::sort(arrayIndexes.begin(), arrayIndexes.end());

    for (size_t index = 0 ; index < size ; index++ ) {
        // Either the element is visited or it is at correct place
        if (arrayIndexes[index].second == index or visited[index] == true)
            continue;

        // The element forms a loop
        int node = index;
        int cycleSize = 0;
        while(!visited[node]) {
            visited[node] = true;
            int next_node = arrayIndexes[node].second;
            cycleSize += 1;
            node = next_node;
        }
        answer += cycleSize-1;
    }

    return answer;
}

int main() {
    std::vector<int> inputArray = {10,11,5,4,3,2,1};
    // std::vector<int> inputArray = {1,2,3,4,5};

    int minimumSwaps = calcMinmSwaps(inputArray);
    std::cout<<"Minimum Swaps : " << minimumSwaps <<std::endl;

    return 0;
}
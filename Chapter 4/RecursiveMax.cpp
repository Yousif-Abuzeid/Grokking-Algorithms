#include <iostream>
#include <vector>


template<typename T>
int max(std::vector<T> v) {
    if(v.size() == 0) {
        return 0;
    }
    
    int first = v[0];
    v.erase(v.begin());
    
    int maxRest = max(v);
    
    return first > maxRest ? first : maxRest;
}


int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::cout << max(v) << std::endl;
    return 0;
}
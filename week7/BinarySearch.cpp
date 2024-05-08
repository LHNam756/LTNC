#include <iostream>
#include <vector>
using namespace std;

int binarySearchRecursive( const vector<int>& arr, int l, int r, int key ) {
    if ( r >= l ) {
        int mid = l + ( r- l ) / 2;

        if ( arr[ mid ] == key )
            return mid;

        if ( arr[ mid ] > key )
            return binarySearchRecursive( arr, l, mid - 1, key );
        return binarySearchRecursive( arr, mid + 1, r, key );
    }

    return -1;
}

int main() {
    vector<int> arr;
    int vtSize(0); cin >> vtSize;
    for (int i = 0; i < vtSize; i++){
        int tmp; cin >> tmp;
        arr.push_back(tmp);
    }
    int key(0); cin >> key;
    int result = binarySearchRecursive(arr, 0, vtSize - 1, key);
    if (result == -1)
        cout << "Khong tim thay " << key << endl;
    else
        cout << "vi tri cua " << key << " la " << "[" << result << "]"  << endl;
    return 0;
}

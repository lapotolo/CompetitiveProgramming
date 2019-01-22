// function to compute the prefix suffix array
// needed for knuth morris pratt algo

vector<int> compute_pref_suff_array(string const& pattern){
    vector<int> result(pattern.size());
    result[0] = 0;
    int k = 0;
    for(int q = 1; q < pattern.size();) {
        if(pattern[q] == pattern[k]) {
            result[q] = k + 1;
            k++;
            q++;
        } else { // mismatch
            if(k != 0) k = result[k - 1];
            else {
                result[q] = 0;
                q++;
            }
        }
    }
    return result;
}

int main() {
    string text;

    cin >> text;
    auto result = compute_pref_suff_array(text);
    for(auto el : result){
        cout << el << "  ";
    }
    cout << endl;
    result.clear();
    text.clear();
}
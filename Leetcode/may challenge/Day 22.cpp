// This is a problem on hashmaps
// In this we store all the chars and their frequencies in an unordered map
// then we use a vector to sort them according to their frequencies

class Solution
{
    map<char, int> fre;
    vector<pair<int, char>> vec;

public:
    string frequencySort(string s)
    {
        ios::sync_with_stdio(0);
        cin.tie(0);

        // adding all chars and their frequemcies
        for (int i = 0; i < s.size(); ++i)
        {
            fre[s[i]]++;
        }
        // then adding them to the vector
        for (auto i : fre)
        {
            vec.push_back({i.second, i.first});
        }
        // sorting the vector in reverse order
        sort(vec.rbegin(), vec.rend());

        string out = "";
        for (int i = 0; i < vec.size(); ++i)
        {
            int t = vec[i].first;
            while (t--)
                out += vec[i].second;
        }
        return out;
    }
};
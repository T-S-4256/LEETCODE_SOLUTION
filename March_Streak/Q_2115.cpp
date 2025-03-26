#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

//         unordered_set<string> st(begin(supplies),end(supplies));
//         int n=recipes.size();
//         unordered_map<string,vector<int>>adj;

//         vector<int>ndegree(n,0);
//         for(int i=0;i<n;i++){
//             for (string& ing:ingredients[i]){
//                 if(!st.count(ing)){
//                     adj[ing].push_back(i);
//                     ndegree[i]++;
//                 }
//             }
//         }

//         queue<int>que;
//         for(int i=0;i<n;i++){
//             if(ndegree[i]==0){
//                 que.push(i);
//             }

//         }

//         vector<string> result;
//         while(!que.empty()){
//             int i=que.front();
//             que.pop();
//             string recipe=recipes[i];
//             result.push_back(recipe);

//             for (int& idx: adj[recipe]){
//                 ndegree[idx]--;
//                 if(ndegree[idx]==0){
//                     que.push(idx);
//                 }
//             }
//         }

// return result;

class Solution
{
public:
    void print_karo(unordered_map<string, int> mp)
    {
        cout << "MP Data : " << endl;
        for (auto it : mp)
        {
            cout << it.first << " : " << it.second << "   ";
        }
        cout << endl;
    }
    int isIngredianFound(string target, vector<string> data)
    {
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] == target)
            {
                return (i + 1);
            }
        }
        return 0;
    }

    bool BanegaKya(int index, vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies, unordered_map<string, int> &mp)
    {
        int flag = 0;
        for (int i = 0; i < ingredients[index].size(); i++)
        {
            cout << "For Enter " << i << " ";
            if (!(isIngredianFound(ingredients[index][i], supplies)))
            {
                cout << "If: ";
                int result=isIngredianFound(ingredients[index][i], recipes);
                if (result)
                {
                    cout << "if if: ";
                    int indexOfrecepi = result - 1;
                    result = BanegaKya(indexOfrecepi, recipes, ingredients, supplies, mp);
                    if (result == true)
                    {
                        cout << "if if if: ";
                        mp[recipes[indexOfrecepi]]++;
                        supplies.push_back(recipes[indexOfrecepi]);
                    }
                    else
                    {
                        cout << "if if else: ";
                        flag = 1;
                        break;
                    }
                }
                else
                {
                    cout << "if Else: ";
                    flag = 1;
                    break;
                }
                cout << "********: " << endl;
            }
            
        }
        cout << "Flag " << flag << endl;
        return flag == 0;
    }

    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
    {
        vector<string> available = supplies;
        vector<string> ans;
        unordered_map<string, int> mp;
        for (int i = 0; i < recipes.size(); i++)
        {
            mp[recipes[i]]=0;
        }

        for (int i = 0; i < recipes.size(); i++)
        {
            cout << "I : " << i << " : ";
            if (mp[recipes[i]] < 1)
            {
                if (BanegaKya(i, recipes, ingredients, available, mp))
                {
                    mp[recipes[i]]++;
                    available.push_back(recipes[i]);
                }
            }
            print_karo(mp);
        }

        for (int i = 0; i < recipes.size(); i++)
        {
            if (mp[recipes[i]] > 0)
            {
                ans.push_back(recipes[i]);
            }
        }
        return ans;
    }
};

int main()
{
    // CASE 1:
    // Input: recipes = ["bread"], ingredients = [["yeast","flour"]], supplies = ["yeast","flour","corn"]
    // Output: ["bread"]
    // CASE 2:
    // Input: recipes = ["bread","sandwich"], ingredients = [["yeast","flour"],["bread","meat"]], supplies = ["yeast","flour","meat"]
    // Output: ["bread","sandwich"]
    // CASE 3:
    // Input: recipes = ["bread","sandwich","burger"], ingredients = [["yeast","flour"],["bread","meat"],["sandwich","meat","bread"]], supplies = ["yeast","flour","meat"]
    // Output: ["bread","sandwich","burger"]

    // CASE 3:
    // Input: recipes = ["xevvq","izcad","p","we","bxgnm","vpio","i","hjvu","igi","anp","tokfq","z","kwdmb","g","qb","q","b","hthy"],
    //  ingredients = [["wbjr"],["otr","fzr","g"],["fzr","wi","otr","xgp","wbjr","igi","b"],["fzr","xgp","wi","otr","tokfq","izcad","igi","xevvq","i","anp"],["wi","xgp","wbjr"],["wbjr","bxgnm","i","b","hjvu","izcad","igi","z","g"],["xgp","otr","wbjr"],["wbjr","otr"],["wbjr","otr","fzr","wi","xgp","hjvu","tokfq","z","kwdmb"],["xgp","wi","wbjr","bxgnm","izcad","p","xevvq"],["bxgnm"],["wi","fzr","otr","wbjr"],["wbjr","wi","fzr","xgp","otr","g","b","p"],["otr","fzr","xgp","wbjr"],["xgp","wbjr","q","vpio","tokfq","we"],["wbjr","wi","xgp","we"],["wbjr"],["wi"]]
    // supplies={"wi","otr","wbjr","fzr","xgp"}
    // Output: ["xevvq","bxgnm","i","hjvu","tokfq","z","g","b","hthy"]

    Solution s;

    vector<string> recipes = {"xevvq", "izcad", "p", "we", "bxgnm", "vpio", "i", "hjvu", "igi", "anp", "tokfq", "z", "kwdmb", "g", "qb", "q", "b", "hthy"};
    vector<vector<string>> ingredients = {{"wbjr"}, {"otr", "fzr", "g"}, {"fzr", "wi", "otr", "xgp", "wbjr", "igi", "b"}, {"fzr", "xgp", "wi", "otr", "tokfq", "izcad", "igi", "xevvq", "i", "anp"}, {"wi", "xgp", "wbjr"}, {"wbjr", "bxgnm", "i", "b", "hjvu", "izcad", "igi", "z", "g"}, {"xgp", "otr", "wbjr"}, {"wbjr", "otr"}, {"wbjr", "otr", "fzr", "wi", "xgp", "hjvu", "tokfq", "z", "kwdmb"}, {"xgp", "wi", "wbjr", "bxgnm", "izcad", "p", "xevvq"}, {"bxgnm"}, {"wi", "fzr", "otr", "wbjr"}, {"wbjr", "wi", "fzr", "xgp", "otr", "g", "b", "p"}, {"otr", "fzr", "xgp", "wbjr"}, {"xgp", "wbjr", "q", "vpio", "tokfq", "we"}, {"wbjr", "wi", "xgp", "we"}, {"wbjr"}, {"wi"}};
    vector<string> supplies = {"wi", "otr", "wbjr", "fzr", "xgp"};

    // vector<string> recipes = {"bread", "sandwich", "burger"};
    // vector<vector<string>> ingredients = {{"yeast", "flour"}, {"burger", "meat"}, {"meat", "bread"}};
    // vector<string> supplies = {"yeast", "flour", "meat"};

    // vector<string> recipes = {"bread", "sandwich"};
    // vector<vector<string>> ingredients = {{"yeast", "flour"}, {"bread", "meat"}};
    // vector<string> supplies = {"yeast", "flour", "meat"};

    // vector<string> recipes = {"bread"};
    // vector<vector<string>> ingredients = {{"yeast", "flour"}};
    // vector<string> supplies = {"yeast", "flour", "corn"};
    vector<string> ans;
    ans = s.findAllRecipes(recipes, ingredients, supplies);
    cout << "Ans Is : ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " : ";
    }
    return 0;
}
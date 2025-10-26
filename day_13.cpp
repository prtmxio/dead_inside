#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

// Permutations

void solver(vector<int>& arr, vector<int>& ans, vector<vector<int>>& res){
    if(arr.empty()) return;
    if(ans.size() == arr.size()){
        res.push_back(ans);
        return;
    }

    for(int i = 0; i < arr.size(); i++){
        int temp = arr[i];
        if(arr[i] != INT_MAX){
            arr[i] = INT_MAX;
            ans.push_back(temp);
            solver(arr, ans, res);
            arr[i] = temp;
            ans.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> ans = {};
    solver(nums, ans, res);
    return res;
}

// Word Search 2

bool valid(vector<vector<char>>& board, int i, int j){
    int m = board.size();
    int n = board[0].size();
    return (i >= 0 && i < m && j >=0 && j < n);
}

bool search(vector<vector<char>>& board, string word, int i, int j, int wx){
    if(!valid(board, i, j)) return false;
    if(board[i][j] != word[wx]) return false;
    if(wx == word.size() -1) return true;
    char temp = board[i][j];
    board[i][j] = '#';
    bool found = search(board, word, i+1, j, wx+1) || search(board, word, i-1, j, wx+1)
                 || search(board, word, i, j+1, wx+1) || search(board, word, i, j-1, wx+1);
    board[i][j] = temp;
    return found;
}

bool founder(vector<vector<char>>& board, string word){
    int m = board.size();
    int n = board[0].size();

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(search(board, word, i, j, 0)){
                return true;
            }
        }
    }
    return false;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    int m = board.size();
    int n = board[0].size();
    set<string> res;
    map<char, int> checker;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            checker[board[i][j]]++;
        }
    }

    for(int i = 0; i < words.size(); i++){
        map<char, int> wordFreq;
        for(char c : words[i]) {
            wordFreq[c]++;
        }
        bool possible = true;
        for(auto [ch, cnt] : wordFreq){
            if(checker.count(ch) == 0){
                possible = false;
                break;
            }
            if(checker.at(ch) < cnt){
                possible = false;
                break;
            }
        }
        if(possible){
            if(founder(board, words[i])){
                res.insert(words[i]);
            }
        }

    }
    vector<string> sol(res.begin(), res.end());
    return sol;
}

int main(){
    // // The board
    // vector<vector<char>> board = {
    //     {'o', 'a', 'a', 'n'},
    //     {'e', 't', 'a', 'e'},
    //     {'i', 'h', 'k', 'r'},
    //     {'i', 'f', 'l', 'v'}
    // };

    // // The words
    // vector<string> words = {"oath", "pea", "eat", "rain"};
    vector<vector<char>> board = {
        {'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a'},
        {'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b'},
        {'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a'},
        {'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b'},
        {'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a'},
        {'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b'},
        {'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a'},
        {'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b'},
        {'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a'},
        {'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'b'}
    };

    // The words
    vector<string> words = {
        "ababababaa", "ababababab", "ababababac", "ababababad", "ababababae", "ababababaf",
        "ababababag", "ababababah", "ababababai", "ababababaj", "ababababak", "ababababal",
        "ababababam", "ababababan", "ababababao", "ababababap", "ababababaq", "ababababar",
        "ababababas", "ababababat", "ababababau", "ababababav", "ababababaw", "ababababax",
        "ababababay", "ababababaz", "ababababba", "ababababbb", "ababababbc", "ababababbd",
        "ababababbe", "ababababbf", "ababababbg", "ababababbh", "ababababbi", "ababababbj",
        "ababababbk", "ababababbl", "ababababbm", "ababababbn", "ababababbo", "ababababbp",
        "ababababbq", "ababababbr", "ababababbs", "ababababbt", "ababababbu", "ababababbv",
        "ababababbw", "ababababbx", "ababababby", "ababababbz", "ababababca", "ababababcb",
        "ababababcc", "ababababcd", "ababababce", "ababababcf", "ababababcg", "ababababch",
        "ababababci", "ababababcj", "ababababck", "ababababcl", "ababababcm", "ababababcn",
        "ababababco", "ababababcp", "ababababcq", "ababababcr", "ababababcs", "ababababct",
        "ababababcu", "ababababcv", "ababababcw", "ababababcx", "ababababcy", "ababababcz",
        "ababababda", "ababababdb", "ababababdc", "ababababdd", "ababababde", "ababababdf",
        "ababababdg", "ababababdh", "ababababdi", "ababababdj", "ababababdk", "ababababdl",
        "ababababdm", "ababababdn", "ababababdo", "ababababdp", "ababababdq", "ababababdr",
        "ababababds", "ababababdt", "ababababdu", "ababababdv", "ababababdw", "ababababdx",
        "ababababdy", "ababababdz", "ababababea", "ababababeb", "ababababec", "ababababed",
        "ababababee", "ababababef", "ababababeg", "ababababeh", "ababababei", "ababababej",
        "ababababek", "ababababel", "ababababem", "ababababen", "ababababeo", "ababababep",
        "ababababeq", "ababababer", "ababababes", "ababababet", "ababababeu", "ababababev",
        "ababababew", "ababababex", "ababababey", "ababababez", "ababababfa", "ababababfb",
        "ababababfc", "ababababfd", "ababababfe", "ababababff", "ababababfg", "ababababfh",
        "ababababfi", "ababababfj", "ababababfk", "ababababfl", "ababababfm", "ababababfn",
        "ababababfo", "ababababfp", "ababababfq", "ababababfr", "ababababfs", "ababababft",
        "ababababfu", "ababababfv", "ababababfw", "ababababfx", "ababababfy", "ababababfz",
        "ababababga", "ababababgb", "ababababgc", "ababababgd", "ababababge", "ababababgf",
        "ababababgg", "ababababgh", "ababababgi", "ababababgj", "ababababgk", "ababababgl",
        "ababababgm", "ababababgn", "ababababgo", "ababababgp", "ababababgq", "ababababgr",
        "ababababgs", "ababababgt", "ababababgu", "ababababgv", "ababababgw", "ababababgx",
        "ababababgy", "ababababgz", "ababababha", "ababababhb", "ababababhc", "ababababhd",
        "ababababhe", "ababababhf", "ababababhg", "ababababhh", "ababababhi", "ababababhj",
        "ababababhk", "ababababhl", "ababababhm", "ababababhn", "ababababho", "ababababhp",
        "ababababhq", "ababababhr", "ababababhs", "ababababht", "ababababhu", "ababababhv",
        "ababababhw", "ababababhx", "ababababhy", "ababababhz", "ababababia", "ababababib",
        "ababababic", "ababababid", "ababababie", "ababababif", "ababababig", "ababababih",
        "ababababii", "ababababij", "ababababik", "ababababil", "ababababim", "ababababin",
        "ababababio", "ababababip", "ababababiq", "ababababir", "ababababis", "ababababit",
        "ababababiu", "ababababiv", "ababababiw", "ababababix", "ababababiy", "ababababiz",
        "ababababja", "ababababjb", "ababababjc", "ababababjd", "ababababje", "ababababjf",
        "ababababjg", "ababababjh", "ababababji", "ababababjj", "ababababjk", "ababababjl",
        "ababababjm", "ababababjn", "ababababjo", "ababababjp", "ababababjq", "ababababjr",
        "ababababjs", "ababababjt", "ababababju", "ababababjv", "ababababjw", "ababababjx",
        "ababababjy", "ababababjz", "ababababka", "ababababkb", "ababababkc", "ababababkd",
        "ababababke", "ababababkf", "ababababkg", "ababababkh", "ababababki", "ababababkj",
        "ababababkk", "ababababkl", "ababababkm", "ababababkn", "ababababko", "ababababkp",
        "ababababkq", "ababababkr", "ababababks", "ababababkt", "ababababku", "ababababkv",
        "ababababkw", "ababababkx", "ababababky", "ababababkz", "ababababla", "abababablb",
        "abababablc", "ababababld", "abababable", "abababablf", "abababablg", "abababablh",
        "ababababli", "abababablj", "abababablk", "ababababll", "abababablm", "ababababln",
        "abababablo", "abababablp", "abababablq", "abababablr", "ababababls", "abababablt",
        "abababablu", "abababablv", "abababablw", "abababablx", "abababably", "abababablz",
        "ababababma", "ababababmb", "ababababmc", "ababababmd", "ababababme", "ababababmf",
        "ababababmg", "ababababmh", "ababababmi", "ababababmj", "ababababmk", "ababababml",
        "ababababmm", "ababababmn", "ababababmo", "ababababmp", "ababababmq", "ababababmr",
        "ababababms", "ababababmt", "ababababmu", "ababababmv", "ababababmw", "ababababmx",
        "ababababmy", "ababababmz", "ababababna", "ababababnb", "ababababnc", "ababababnd",
        "ababababne", "ababababnf", "ababababng", "ababababnh", "ababababni", "ababababnj",
        "ababababnk", "ababababnl", "ababababnm", "ababababnn", "ababababno", "ababababnp",
        "ababababnq", "ababababnr", "ababababns", "ababababnt", "ababababnu", "ababababnv",
        "ababababnw", "ababababnx", "ababababny", "ababababnz", "ababababoa", "ababababob",
        "ababababoc", "ababababod", "ababababoe", "ababababof", "ababababog", "ababababoh",
        "ababababoi", "ababababoj", "ababababok", "ababababol", "ababababom", "ababababon",
        "ababababoo", "ababababop", "ababababoq", "ababababor", "ababababos", "ababababot",
        "ababababou", "ababababov", "ababababow", "ababababox", "ababababoy", "ababababoz",
        "ababababpa", "ababababpb", "ababababpc", "ababababpd", "ababababpe", "ababababpf",
        "ababababpg", "ababababph", "ababababpi", "ababababpj", "ababababpk", "ababababpl",
        "ababababpm", "ababababpn", "ababababpo", "ababababpp", "ababababpq", "ababababpr",
        "ababababps", "ababababpt", "ababababpu", "ababababpv", "ababababpw", "ababababpx",
        "ababababpy", "ababababpz", "ababababqa", "ababababqb", "ababababqc", "ababababqd",
        "ababababqe", "ababababqf", "ababababqg", "ababababqh", "ababababqi", "ababababqj",
        "ababababqk", "ababababql", "ababababqm", "ababababqn", "ababababqo", "ababababqp",
        "ababababqq", "ababababqr", "ababababqs", "ababababqt", "ababababqu", "ababababqv",
        "ababababqw", "ababababqx", "ababababqy", "ababababqz", "ababababra", "ababababrb",
        "ababababrc", "ababababrd", "ababababre", "ababababrf", "ababababrg", "ababababrh",
        "ababababri", "ababababrj", "ababababrk", "ababababrl", "ababababrm", "ababababrn",
        "ababababro", "ababababrp", "ababababrq", "ababababrr", "ababababrs", "ababababrt",
        "ababababru", "ababababrv", "ababababrw", "ababababrx", "ababababry", "ababababrz",
        "ababababsa", "ababababsb", "ababababsc", "ababababsd", "ababababse", "ababababsf",
        "ababababsg", "ababababsh", "ababababsi", "ababababsj", "ababababsk", "ababababsl",
        "ababababsm", "ababababsn", "ababababso", "ababababsp", "ababababsq", "ababababsr",
        "ababababss", "ababababst", "ababababsu", "ababababsv", "ababababsw", "ababababsx",
        "ababababsy", "ababababsz", "ababababta", "ababababtb", "ababababtc", "ababababtd",
        "ababababte", "ababababtf", "ababababtg", "ababababth", "ababababti", "ababababtj",
        "ababababtk", "ababababtl", "ababababtm", "ababababtn", "ababababto", "ababababtp",
        "ababababtq", "ababababtr", "ababababts", "ababababtt", "ababababtu", "ababababtv",
        "ababababtw", "ababababtx", "ababababty", "ababababtz", "ababababua", "ababababub",
        "ababababuc", "ababababud", "ababababue", "ababababuf", "ababababug", "ababababuh",
        "ababababui", "ababababuj", "ababababuk", "ababababul", "ababababum", "ababababun",
        "ababababuo", "ababababup", "ababababuq", "ababababur", "ababababus", "ababababut",
        "ababababuu", "ababababuv", "ababababuw", "ababababux", "ababababuy", "ababababuz",
        "ababababva", "ababababvb", "ababababvc", "ababababvd", "ababababve", "ababababvf",
        "ababababvg", "ababababvh", "ababababvi", "ababababvj", "ababababvk", "ababababvl",
        "ababababvm", "ababababvn", "ababababvo", "ababababvp", "ababababvq", "ababababvr",
        "ababababvs", "ababababvt", "ababababvu", "ababababvv", "ababababvw", "ababababvx",
        "ababababvy", "ababababvz", "ababababwa", "ababababwb", "ababababwc", "ababababwd",
        "ababababwe", "ababababwf", "ababababwg", "ababababwh", "ababababwi", "ababababwj",
        "ababababwk", "ababababwl", "ababababwm", "ababababwn", "ababababwo", "ababababwp",
        "ababababwq", "ababababwr", "ababababws", "ababababwt", "ababababwu", "ababababwv",
        "ababababww", "ababababwx", "ababababwy", "ababababwz", "ababababxa", "ababababxb",
        "ababababxc", "ababababxd", "ababababxe", "ababababxf", "ababababxg", "ababababxh",
        "ababababxi", "ababababxj", "ababababxk", "ababababxl", "ababababxm", "ababababxn",
        "ababababxo", "ababababxp", "ababababxq", "ababababxr", "ababababxs", "ababababxt",
        "ababababxu", "ababababxv", "ababababxw", "ababababxx", "ababababxy", "ababababxz",
        "ababababya", "ababababyb", "ababababyc", "ababababyd", "ababababye", "ababababyf",
        "ababababyg", "ababababyh", "ababababyi", "ababababyj", "ababababyk", "ababababyl",
        "ababababym", "ababababyn", "ababababyo", "ababababyp", "ababababyq", "ababababyr",
        "ababababys", "ababababyt", "ababababyu", "ababababyv", "ababababyw", "ababababyx",
        "ababababyy", "ababababyz", "ababababza", "ababababzb", "ababababzc", "ababababzd",
        "ababababze", "ababababzf", "ababababzg", "ababababzh", "ababababzi", "ababababzj",
        "ababababzk", "ababababzl", "ababababzm", "ababababzn", "ababababzo", "ababababzp",
        "ababababzq", "ababababzr", "ababababzs", "ababababzt", "ababababzu", "ababababzv",
        "ababababzw", "ababababzx", "ababababzy", "ababababzz"
    };
    vector<string> ans = findWords(board, words);
    for(auto x : ans){
        cout << x << " ";
    }
    // vector<int> n = {1, 2, 3};
    // vector<vector<int>> res = permute(n);
    // for(auto a : res){
    //     for(auto b : a){
    //         cout << b << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}

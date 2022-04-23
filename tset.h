#ifndef TSET_H
#define TSET_H


#include <iostream>
#include <vector>
#include <algorithm>
#include <QMainWindow>
using namespace std;

template<class T>
void clean(vector<T>& int_set) {
    if(int_set.size() != 0){
    for (size_t i = 0; i < int_set.size() - 1; ++i) {
        if (int_set[i] == int_set[i + 1]) {
            int_set.erase(int_set.begin() + i);
            i--;
        }
    }
    }
}

template<class T>
class TSet {
public:
    TSet() = default;
    TSet(vector<T> to_copy){
        set = to_copy;
    }
    void cleans(){
      sort(set.begin(), set.end());
      clean(set);
    };

    void AddElement(T to_add){
        auto it = std::lower_bound(set.begin(),set.end(), to_add) - set.begin();
        if (set.size() == 0 || it >= set.size()){
            set.push_back(to_add);
        } else if (set[it] != to_add){
                set.insert(set.begin() + it, to_add);
        }
    };

    std::vector<T> Get(){
        return set;
    }

    TSet add(TSet& to_add) {
        std::vector<T> to_return(set.size() + to_add.set.size());
        std::merge(set.begin(), set.end(), to_add.set.begin(), to_add.set.end(), to_return.begin());
        sort(to_return.begin(), to_return.end());
        clean(to_return);
        TSet<T> result(to_return);
        return result;
    }

    TSet mult(TSet& to_mult) {
        vector<T> result;
        vector<T> res2 = to_mult.set;
        for (T i : set) {
            if (find(res2.begin(), res2.end(), i) != res2.end()) {
                result.push_back(i);
                res2.erase(find(res2.begin(), res2.end(), i));
            }
        }
        TSet<T> res;
        clean(result);
        res.set = result;
        return res;
    }

    TSet sim_sub(TSet& to_sim_sub) {
        TSet<T>self;
        TSet<T> self2;
        self.set = set;
        self2.set = to_sim_sub.set;
        TSet addm = self.add(self2);
        TSet summ = self.mult(self2);
        for (T i : summ.set) {
            addm.set.erase(std::find(addm.set.begin(), addm.set.end(), i));
        }
        return addm;
    }

    void Clear(){
        set = {};
    }

    std::string show() {
        std::string result;
        for (auto i : set) {
            result += i + '\n';
        }
        return result;
    }
private:
    vector<T> set;
};

#endif // TSET_H

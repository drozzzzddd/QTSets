#include "set.h"


Set::Set() {
    }
Set* Set::add(Set*) {
        return {};
    };
Set* Set::mult(Set*) {
        return {};
    };
Set* Set::sim_sub(Set*) {
        return {};
    };

Integer::Integer() {
}
Integer::Integer(const std::vector<int>& to_copy) {
        int_set = to_copy;
        std::sort(int_set.begin(), int_set.end());
        clean(int_set);
    }

void Integer::Clear(){
        int_set = {};
    }
std::vector<int> Integer::Get(){
        return int_set;
    }
void Integer::AddElement(int to_add){
        auto it = std::lower_bound(int_set.begin(),int_set.end(), to_add) - int_set.begin();
        if (int_set.size() == 0 || it >= int_set.size()){
            int_set.push_back(to_add);
        } else if (int_set[it] != to_add){
                int_set.insert(int_set.begin() + it, to_add);
        }
    };

Set* Integer::add(Set* to_add){
        Integer* t_add = dynamic_cast<Integer*>(to_add);
        std::vector<int> to_return(int_set.size() + t_add->int_set.size());
        std::merge(int_set.begin(), int_set.end(), t_add->int_set.begin(), t_add->int_set.end(), to_return.begin());
        sort(to_return.begin(), to_return.end());
        clean(to_return);
        Integer* result = new Integer(to_return);
        return result;
    }
Set* Integer::mult(Set* t_mult){
        auto to_mult = dynamic_cast<Integer*>(t_mult);
        std::vector<int> result;
        std::vector<int> res2 = to_mult->int_set;
        for (int i : int_set) {
            if (std::find(res2.begin(), res2.end(), i) != res2.end()) {
                result.push_back(i);
                res2.erase(std::find(res2.begin(), res2.end(), i));
            }
        }
        Integer* res = new Integer;
        clean(result);
        res->int_set = result;
        return res;
    }
Set* Integer::sim_sub(Set* t_sim_sub){
        auto to_sim_sub = dynamic_cast<Integer*>(t_sim_sub);
        Integer self;
        Integer self2;
        self.int_set = int_set;
        self2.int_set = to_sim_sub->int_set;
        Integer* add_set = dynamic_cast<Integer*> (self.add(&self2));
        Integer* sum_set = dynamic_cast<Integer*> (self.mult(&self2));
        for (int i : sum_set->int_set) {
            add_set->int_set.erase(std::find(add_set->int_set.begin(), add_set->int_set.end(), i));
        }
        return add_set;
    }


StringSet::StringSet() {
    }
StringSet::StringSet(const std::vector<QString>& to_copy) {
        string_set = to_copy;
        std::sort(string_set.begin(), string_set.end());
        clean(string_set);
    }

void StringSet::Clear(){
        string_set = {};
    }
std::vector<QString> StringSet::Get(){
        return string_set;
    }
void StringSet::AddElement(QString to_add){
        auto it = std::lower_bound(string_set.begin(),string_set.end(), to_add) - string_set.begin();
        if (string_set.size() == 0 || it >= string_set.size()){
            string_set.push_back(to_add);
        } else if (string_set[it] != to_add){
                string_set.insert(string_set.begin() + it, to_add);
        }
    };

Set* StringSet::add(Set* to_add) {
        StringSet* t_add = dynamic_cast<StringSet*>(to_add);
        std::vector<QString> to_return(string_set.size() + t_add->string_set.size());
        std::merge(string_set.begin(), string_set.end(), t_add->string_set.begin(), t_add->string_set.end(), to_return.begin());
        sort(to_return.begin(), to_return.end());
        clean(to_return);
        StringSet* result = new StringSet(to_return);
        return result;
    }
Set* StringSet::mult(Set* t_mult) {
        auto to_mult = dynamic_cast<StringSet*>(t_mult);
        std::vector<QString> result;
        std::vector < QString> res2 = to_mult->string_set;
        for (QString i : string_set) {
            if (std::find(res2.begin(), res2.end(), i) != res2.end()) {
                result.push_back(i);
                res2.erase(std::find(res2.begin(), res2.end(), i));
            }
        }
        clean(result);
        StringSet* res = new StringSet;
        res->string_set = result;
        return res;
    }
Set* StringSet::sim_sub(Set* t_sim_sub){
        auto to_sim_sub = dynamic_cast<StringSet*>(t_sim_sub);
        StringSet* self = new StringSet;
        StringSet* self2 = new StringSet;
        self->string_set = string_set;
        self2->string_set = to_sim_sub->string_set;
        StringSet* add_set = dynamic_cast<StringSet*> (self->add(self2));
        StringSet* sum_set = dynamic_cast<StringSet*> (self->mult(self2));
        for (QString i : sum_set->string_set) {
            add_set->string_set.erase(std::find(add_set->string_set.begin(), add_set->string_set.end(), i));
        }
        return add_set;
    }

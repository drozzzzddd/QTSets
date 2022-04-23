#ifndef SET_H
#define SET_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <QMainWindow>


template<class t>
void clean(std::vector<t>& int_set) {
    for (int i = 0; i < int_set.size() - 1; ++i) {
        if (int_set[i] == int_set[i + 1]) {
            int_set.erase(int_set.begin() + i);
            i--;
        }
    }
}

class Set {
public:
    Set();
    virtual Set* add(Set*);
    virtual Set* mult(Set*);
    virtual Set* sim_sub(Set*);
};

class Integer : public Set {
public:
    Integer();
    Integer(const std::vector<int>& to_copy);

    void Clear();
    std::vector<int> Get();
    void AddElement(int to_add);

    Set* add(Set* to_add) override;
    Set* mult(Set* t_mult) override;
    Set* sim_sub(Set* t_sim_sub) override;
private:
    std::vector<int> int_set;
};

class StringSet : public Set {
public:
    StringSet();
    StringSet(const std::vector<QString>& to_copy);

    void Clear();
    std::vector<QString> Get();
    void AddElement(QString to_add);

    Set* add(Set* to_add) override;
    Set* mult(Set* t_mult) override;
    Set* sim_sub(Set* t_sim_sub) override;
private:
    std::vector<QString> string_set;
};

#endif // SET_H

#ifndef TRIE_HPP_
#define TRIE_HPP_

#include <iostream>
#include <map>
#include <vector>

template<typename T>
class Trie {
    struct Node {
        std::map<T, Node> val;
    } data;

    using vec = std::vector<T>;

    template<typename U = T,
             typename std::enable_if<
                 std::is_same<U, char>::value ||
                 std::is_same<U, std::string>::value>::type* = nullptr>
    inline void appendStr(std::string& str, const U& x) { str += x; }

    template<typename U = T,
             typename std::enable_if<
                 std::is_arithmetic<U>::value &&
                 !std::is_same<U, char>::value>::type* = nullptr>
    inline void appendStr(std::string& str, const U& x) { str += std::to_string(x); }

    void print(const Node* temp, const T x, std::string endings, bool foo)
    {
        if (temp == nullptr) {
            std::cout << "(null)" << std::endl;
            return;
        }

        if (foo) {
            appendStr(endings, x);
            if (!endings.empty() && !temp->val.empty()) {
                endings += " ";
            }
        }

        if (temp->val.empty()) {
            if (!endings.empty()) {
                std::cout << endings << std::endl;
            }
            else {
                std::cout << "(null)" << std::endl;
            }
        }
        else {
            for (const auto& foo: temp->val) {
                print(&foo.second, foo.first, endings, true);
            }
        }
    }

public:

    using nodePtr = const Node*;

    void add(const vec s, Node* temp = nullptr)
    {
        if (!temp) {
            temp = &data;
        }
        for (const T& w: s) {
            temp = &(temp->val[w]);
        }
    }

    void add(const T s[], std::size_t n, Node* temp = nullptr)
    {
        if (!temp) {
            temp = &data;
        }
        for (std::size_t i = 0; i < n; ++i) {
            temp = &(temp->val[s[i]]);
        }
    }

    template<typename std::enable_if<std::is_same<T, char>::value>* = nullptr>
    void add(const std::string s, Node* temp = nullptr)
    {
        if (!temp) {
            temp = &data;
        }
        for (const T& w: s) {
            temp = &(temp->val[w]);
        }
    }

    const Node* getEndings(const vec prefix, const Node* temp = nullptr) const
    {
        if (!temp) {
            temp = &data;
        }
        for (const auto& w: prefix) {
            if (temp->val.find(w) == temp->val.end()) {
                return {};
            }
            temp = &temp->val.at(w);
        }
        if (temp->val.empty()) {
            return {};
        }
        return temp;
    }

    const Node* getEndings(const T a, const Node* temp = nullptr) const
    {
        return getEndings(vec{a}, temp);
    }

    void print(const Node* temp)
    {
        print(temp, T{}, {}, false);
    }

};

#endif // TRIE_HPP_

// vim: fdl=1

#include <memory>
#include <string>

using namespace std;

class RegExp {
public:
    virtual bool isMatch(const string &inp, int start, int length) = 0;
    RegExp() = default;
    virtual ~RegExp() {}
};

class Concat : public RegExp {
    unique_ptr<RegExp> left, right;
public:
    Concat(unique_ptr<RegExp> left, unique_ptr<RegExp> right):left{move(left)}, right{move(right)} {}
    ~Concat() {}
    bool isMatch(const string &inp, int start, int length) override {
        for (int i = 0; i <= length; ++i) {
            if (left->isMatch(inp, start, i) && right->isMatch(inp, start + i, length - i))
                return true;
        }
        return false;
    }
};

class Star : public RegExp {
    char ch;
public:
    Star(char ch):ch{ch} {}
    ~Star() {}
    bool isMatch(const string &inp, int start, int length) override {
        for (int i = start; i < start + length; ++i) {
            if (ch != '.' && inp[i] != ch) return false;
        }
        return true;
    }
};

class Literal : public RegExp {
    char ch;
public:
    Literal(char ch):ch{ch} {}
    ~Literal() {}
    bool isMatch(const string &inp, int start, int length) override {
        if (length != 1) return false;
        if (ch == '.') return true;
        return ch == inp[start];
    }
};

class Empty : public RegExp {
public:
    Empty() {}
    ~Empty() {}
    bool isMatch(const string &inp, int start, int length) override {
        return length == 0;    
    }
};

unique_ptr<RegExp> parse(const string &p, int pos) {
    int length = p.length();
    if (length == 0) return make_unique<Empty>();
    if (pos >= length)
        throw out_of_range("Out of range");
    if (pos == length - 1) {
        return make_unique<Literal>(p[pos]);
    }
    if (pos == length - 2) {
        if (p[pos + 1] == '*')
            return make_unique<Star>(p[pos]);
        else
            return make_unique<Concat>(make_unique<Literal>(p[pos]), make_unique<Literal>(p[pos + 1]));
    }
    if (p[pos + 1] != '*') return make_unique<Concat>(make_unique<Literal>(p[pos]), parse(p, pos + 1));
    else return make_unique<Concat>(make_unique<Star>(p[pos]), parse(p, pos + 2));
}

class Solution {
public:
    bool isMatch(string s, string p) {
        unique_ptr<RegExp> regexp = parse(p, 0);
        return regexp->isMatch(s, 0, s.length());
    }
};
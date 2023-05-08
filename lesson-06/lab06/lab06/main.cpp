#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <cassert>

using namespace std;

class Sequence {
public:
    virtual int Length() = 0;
};

class FakeSequence : public Sequence {
public:
    int Length() override { return 100; }
};

class Gene {
private:
    string name_;
    shared_ptr<Sequence> sequence_;

public:
    Gene(string name, shared_ptr<Sequence> sequence)
        : name_(name), sequence_(sequence) {}

    void JSON() const {
        cout << "{ \"name\": \"" << name_ << "\", \"length\": " << sequence_->Length() << " }" << endl;
    }
};

int main() {
    shared_ptr<Sequence> fake_seq = make_shared<FakeSequence>();
    Gene gene(sequence_, "BALFS");
    std::cout << gene.JSON() << std::endl;
    assert(sequence->Length() == 100);
    return 0;
}

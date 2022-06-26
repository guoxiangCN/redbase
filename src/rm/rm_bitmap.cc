#include "rm/rm.h"
#include <cassert>
#include <cmath>
#include <cstring>

bitmap::bitmap(int numBits) : size_(numBits)
{
    auto nChars = this->numChars();
    buffer_ = new char[nChars];
    ::memset(buffer_, 0, nChars);
    this->reset();
}

bitmap::bitmap(char *buf, int numBits) : size_(numBits)
{
    buffer_ = new char[this->numChars()];
    ::memcpy((void *)buffer_, buf, this->numChars());
}

bitmap::~bitmap()
{
    delete[] buffer_;
}

int bitmap::numChars() const
{
    int numChars = (size_ / 8);
    if ((size_ % 8) != 0)
    {
        numChars++;
    }
    return numChars;
}

void bitmap::reset()
{
    ::memset((void *)buffer_, 0, this->numChars());
}

void bitmap::set()
{
    ::memset((void *)buffer_, 0xFF, this->numChars());
}

void bitmap::reset(unsigned int bitNumber)
{
    assert(bitNumber <= size_ - 1);
    auto byte = bitNumber / 8;
    auto offset = bitNumber % 8;
    buffer_[byte] &= ~(1 << (7 - offset));
}

void bitmap::set(unsigned int bitNumber)
{
    assert(bitNumber <= size_ - 1);
    auto byte = bitNumber / 8;
    auto offset = bitNumber % 8;
    buffer_[byte] |= (1 << (7 - offset));
}

bool bitmap::test(unsigned int bitNumber) const
{
    assert(bitNumber <= size_ - 1);
    auto byte = bitNumber / 8;
    auto offset = bitNumber % 8;
    return buffer_[byte] & (1 << (7 - offset));
}

int bitmap::to_char_buf(char *buf, int len) const {
    assert(buf != NULL && len == this->numChars());
    ::memcpy((void*)buf, buffer_, len);
    return 0;
}

std::ostream &operator<<(std::ostream &os, const bitmap &b)
{
    os << "[";
    for (int i = 0; i < b.getSize(); i++)
    {
        if (i % 8 == 0 && i != 0)
            os << ".";
        os << (b.test(i) ? 1 : 0);
    }
    os << "]";
    return os;
}

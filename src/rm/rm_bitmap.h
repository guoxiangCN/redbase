#ifndef RM_BITMAP_H
#define RM_BITMAP_H

class bitmap
{
public:
    bitmap(int numBits);
    bitmap(char *buf, int numBits); // deserialize from buf
    ~bitmap();

    void set(unsigned int bitNumber);
    void set(); // set all bits to 1
    void reset(unsigned int bitNumber);
    void reset(); // set all bits to 0
    bool test(unsigned int bitNumber) const;

    int numChars() const;                   // return size of char buffer to hold bitmap
    int to_char_buf(char *, int len) const; // serialize content to char buffer
    int getSize() const { return size_; }

private:
    unsigned int size_;
    char *buffer_;
};

std::ostream &operator<<(std::ostream &os, const bitmap &b);

#endif
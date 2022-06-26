//
// rm.h
//
//   Record Manager component interface
//
// This file does not include the interface for the RID class.  This is
// found in rm_rid.h
//
#ifndef RM_H
#define RM_H

#include "redbase.h"
#include "rm_error.h"
#include "rm_rid.h"
// #include "pf/pf.h"
// #include "predicate.h"

// RM_FileHdr: Header structure for files
struct RM_FileHdr
{
    int firstFree;     // first free page in the linked list
    int numPages;      // # of pages in the file
    int extRecordSize; // record size as seen by users.
};

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
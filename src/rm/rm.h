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


#define RM_PAGE_LIST_END      (-1)  // end of list of free pages
#define RM_PAGE_FULLY_USED    (-2)  // page is fully used with no free slots

struct RM_PageHdr
{
    // TODO:
};

//
// RM_Record: RM Record interface
//
class RM_Record
{
    friend class RM_RecordTest;

public:
    RM_Record();
    ~RM_Record();

    // Return the data corresponding to the record.  Sets *pData to the
    // record contents.
    RC GetData(char *&pData) const;

    // Sets data in the record for a fixed recordsize of size.
    // Real object is only available and usable at this point not after
    // construction
    RC Set(char *pData, int size, RID id);

    // Return the RID associated with the record
    RC GetRid(RID &rid) const;

private:
    char *data_;
    int record_size_;
    RID rid_;
};

class RM_FileHandle
{
    // friend class RM_FileHandleTest;
    friend class RM_FileScan;
    friend class RM_Manager;
public:

private:
};

class RM_FileScan
{
};

class RM_Manager
{
};

#endif
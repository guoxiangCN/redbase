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
#include "rm/rm_error.h"
#include "rm/rm_rid.h"
#include "rm/rm_bitmap.h"
// #include "pf/pf.h"
// #include "predicate.h"

// RM_FileHdr: Header structure for files
struct RM_FileHdr
{
    int firstFree;     // first free page in the linked list
    int numPages;      // # of pages in the file
    int extRecordSize; // record size as seen by users.
};




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
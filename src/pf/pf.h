// The Paged File Component
// https://web.stanford.edu/class/cs346/2015/redbase-pf.html

#ifndef PF_H
#define PF_H

#include "redbase.h"
#include "rm/rm_rid.h"

class PF_FileHandle;

class PF_Manager {
public:
    PF_Manager();
    ~PF_Manager();

    // This method creates a paged file called fileName. The file should not already exist.
    RC CreateFile(const char *fileName);
    
    // This method destroys the paged file whose name is fileName. The file should exist.
    RC DestroyFile(const char *fileName);
    
    // This method opens the paged file whose name is fileName. The file must already exist 
    // and it must have been created using the CreateFile method. If the method is successful, 
    // the fileHandle object whose address is passed as a parameter becomes a "handle" for the open file. 
    // The file handle is used to manipulate the pages of the file (see the PF_FileHandle class description below). 
    // It is a (positive) error if fileHandle is already a handle for an open file when it is passed to the OpenFile method. 
    // It is not an error to open the same file more than once if desired, using a different fileHandle object each time.
    //  Each call to the OpenFile method creates a new "instance" of the open file.
    RC OpenFile(const char *fileName, PF_FileHandle &fileHandle);

    // This method closes the open file instance referred to by fileHandle. The file must have been opened using the OpenFile method. 
    // All of the file's pages are flushed from the buffer pool when the file is closed. It is a (positive) error to attempt 
    // to close a file when any of its pages are still pinned in the buffer pool.
    RC CloseFile(PF_FileHandle &fileHandle);

    // This method allocates a "scratch" memory page (block) in the buffer pool and sets buffer to point to it. 
    // The amount of memory available in the block is PF_PAGE_SIZE + 4 = 4096 bytes. 
    // The scratch page is automatically pinned in the buffer pool.
    RC AllocateBlock(char *&buffer);

    // This method disposes of the scratch page in the buffer pool pointed to by buffer, 
    // which must have been allocated previously by PF_Manager::AllocateBlock. 
    // Similar to pinning and unpinning, you must call PF_Manager::DisposeBlock for each 
    // buffer block obtained by calling PF_Manager::AllocateBlock; otherwise you will lose 
    // pages in the buffer pool permanently.
    RC DisposeBlock(char *buffer);
};

class PF_FileHandle{
    // TODO
};

class PF_PageHandle{
public:
    PF_PageHandle();
    ~PF_PageHandle();
    
    // This method is the copy constructor. When a new page handle object is created from a page handle 
    // object that refers to a pinned page in the buffer pool, the page is not pinned a second time.
    PF_PageHandle  (const PF_PageHandle &pageHandle); 
    
    // This method overloads the = operator when it is used to assign one page handle object to another. 
    // s with the copy constructor, if the page handle object on the right-hand side of the = refers to 
    // a pinned page, the page is not pinned a second time.
    PF_PageHandle& operator= (const PF_PageHandle &pageHandle);

    // This method provides access to the actual contents of a page. 
    // The PF_PageHandle object for which this method is called must refer to a page that is pinned in the buffer pool. 
    // If the method is successful, pData is set to point to the contents of the page in the buffer pool.
    RC GetData(char *&pData) const;

    // This method sets pageNum to the number of the page referred to by the PF_PageHandle object 
    // for which this method is called. The page handle object must refer to a page that is pinned in the buffer pool.
    RC GetPageNum(PageNum &pageNum) const;
};

#endif
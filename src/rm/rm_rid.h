#ifndef RM_RID_H
#define RM_RID_H

#include "redbase.h"
#include <iostream>
#include <cassert>
#include <cstring>

// 
// PageNum: uniquely identifies a page in a file
//
typedef int PageNum;

//
// SlotNum: uniquely identifies a record in a page
//
typedef int SlotNum;


// RID: record id interface
class RID {
public:
    static constexpr PageNum NULL_PAGE = -1;
	static constexpr SlotNum NULL_SLOT = -1;
	
	RID()
		: page(NULL_PAGE), slot(NULL_SLOT) {}
	RID(PageNum pageNum, SlotNum slotNum)
		: page(pageNum), slot(slotNum)     {}	

	~RID(){}
		
	RC GetPageNum(PageNum &pageNum) const {
		pageNum = page;
		return 0;
	}

	RC GetSlotNum(SlotNum &slotNum) const {
		slotNum = slot;
		return 0;
	}
	
	PageNum Page() const { return page; }
	SlotNum Slot() const { return slot; }

	bool operator==(const RID &rhs) const {
		return page == rhs.page && slot == rhs.slot;
	}
	
private:
    PageNum page;
    SlotNum slot;
};

std::ostream& operator <<(std::ostream& os, const RID& r);

#endif

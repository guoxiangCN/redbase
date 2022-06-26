#ifndef RM_ERROR_H
#define RM_ERROR_H

#include "redbase.h"

void RM_PrintError(RC rc);
void PrintErrorAll(RC rc);

#define RM_BADRECSIZE   (START_RM_WARN + 0)
#define RM_NORECATRID   (START_RM_WARN + 1)

#define RM_LASTWARN  RM_NORECATRID


#define RM_SIZETOOBIG       (START_RM_ERR - 0)
#define RM_PF               (START_RM_ERR - 1)
#define RM_NULLRECORD       (START_RM_ERR - 2)  
#define RM_RECSIZEMISMATCH  (START_RM_ERR - 3)  // record size mismatch
#define RM_HANDLEOPEN       (START_RM_ERR - 4)
#define RM_FCREATEFAIL      (START_RM_ERR - 5)
#define RM_FNOTOPEN     	(START_RM_ERR - 6)
#define RM_BAD_RID      	(START_RM_ERR - 7)
#define RM_EOF          	(START_RM_ERR - 8)

#define RM_LASTERROR    RM_EOF

#endif

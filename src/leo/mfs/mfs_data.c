#include "leo/mfs.h"

u8 D_i1_80415190[0x4D10] = { 0 };

#if MFS_VERSION == MFS_VERSION_B
u8 D_807801E0[0x4D10] = { 0 };
#endif

MfsRamArea gMfsRamArea = { 0 };
MfsRamDirectoryEntry gCurrentDirectoryEntry = { 0 };

#if MFS_VERSION == MFS_VERSION_A
u16 gFileAllocationTable[LEO_LBA_MAX - LEO_LBA_ROM_END0];
#else // MFS_VERSION_B
u16 gFileAllocationTable[LEO_LBA_MAX - LEO_LBA_ROM_END0] = { 0 };
#endif

s32 D_i1_80428600 = 0;
OSMesgQueue* D_i1_80428604 = NULL;
OSMesg D_i1_80428608 = NULL;
s32 gDirectoryEntryCount = 0;
s32 gMfsError = LEO_ERROR_GOOD;

#if MFS_VERSION == MFS_VERSION_B
s32 D_80794CD8 = 0;
s32 D_80794CDC = 0;
#endif

u16 gWorkingDirectory = MFS_ENTRY_ROOT_DIR;
LEODiskID D_i1_80428618 = { 0 };

#if MFS_VERSION == MFS_VERSION_A
OSMesg D_i1_8042A5E4[1];
OSMesgQueue D_i1_8042A5E8;
#else // MFS_VERSION_B
OSMesg D_i1_8042A5E4[1] = { 0 };
OSMesgQueue D_i1_8042A5E8 = { 0 };
#endif

LEOCapacity gRamAreaCapacity = { 0 };

#if MFS_VERSION == MFS_VERSION_A
s32 D_i1_80428644 = LEO_ERROR_MEDIUM_MAY_HAVE_CHANGED;
#else // MFS_VERSION_B
s32 D_i1_80428644 = N64DD_MANAGER_NOT_CREATED;
#endif

char D_i1_80428648[] = "64dd-Multi";
char gCompanyCode[2] = "";
char gGameCode[4] = "";

#if MFS_VERSION == MFS_VERSION_B
extern u8 D_80794D48 = false;
#endif

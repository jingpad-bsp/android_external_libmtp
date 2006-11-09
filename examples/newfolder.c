#include "common.h"
#include <libgen.h>

void new_folder(char *);
void newfolder(int,char **);

extern LIBMTP_folder_t *folders;
extern LIBMTP_file_t *files;
extern LIBMTP_mtpdevice_t *device;

void newfolder (int argc, char **argv)
{
  uint32_t newid;
  
  if(argc != 3) {
    printf("Usage: newfolder name id\n");
    printf("(id = parent folder or 0 to create the new folder in the root dir)\n");
    return;
  }
  
  newid = LIBMTP_Create_Folder(device, argv[1], atol(argv[2]));
  if (newid == 0) {
    printf("Folder creation failed.\n");
  } else {
    printf("New folder created with ID: %d\n", newid);
  }
}

void
new_folder(char * path)
{
  printf("Creating new folder %s\n",path);
  char * parent = dirname(path);
  char * folder = basename(path);
  int id = parse_path (parent,files,folders);
  int newid = LIBMTP_Create_Folder(device, folder, id);
  if (newid == 0) {
    printf("Folder creation failed.\n");
  } else {
    printf("New folder created with ID: %d\n", newid);
  }
}


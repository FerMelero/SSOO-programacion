// file: resource_lab.c
// Build: gcc -O2 -o resource_lab resource_lab.c
// Note: keep strings ASCII to avoid LaTeX/listings UTF-8 issues.

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdatomic.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>

#define TOUCH_PAGE_STEP 4096

static atomic_int keep_running = 1;
static atomic_size_t allocated_bytes = 0;


static void *mem_block = NULL;
static size_t mem_block_size = 0;

void handle_sigint(int sig) {
  (void)sig;
  atomic_store(&keep_running, 0);
  fprintf(stdout, "\n[+] Signal received: exiting...\n");
}

void touch_memory(char *ptr, size_t size) {
  // Write to each page to force physical allocation (RSS increase)
  for (size_t offset = 0; offset < size; offset += TOUCH_PAGE_STEP) {
    ptr[offset] = (char)(offset & 0xFF);
  }
  if (size > 0) {
    ptr[size - 1] ^= 0x1;
  }
}


int allocate_memory_gb(size_t gigabytes) {
  if (mem_block) {
    fprintf(stderr, "There is already an allocated block. Free it first.\n");
    return -1;
  }
  size_t bytes = gigabytes * 1024ULL * 1024ULL * 1024ULL;
  void *p = malloc(bytes);
  if (!p) {
    perror("malloc");
    return -1;
  }
  touch_memory((char*)p, bytes);
  mem_block = p;
  mem_block_size = bytes;
  atomic_store(&allocated_bytes, bytes);
  return 0;
}

int callocate_memory_gb(size_t gigabytes) {
  if (mem_block) {
    fprintf(stderr, "There is already an (callocated block. Free it first.\n");
    return -1;
  }
  size_t bytes = gigabytes * 1024ULL * 1024ULL * 1024ULL;
  void *p = malloc(bytes);
  if (!p) {
    perror("calloc");
    return -1;
  }
  touch_memory((char*)p, bytes);
  mem_block = p;
  mem_block_size = bytes;
  atomic_store(&allocated_bytes, bytes);
  return 0;
}

int free_memory_block() {
  if (!mem_block) {
    fprintf(stderr, "No allocated block to free.\n");
    return -1;
  }
  free(mem_block);
  mem_block = NULL;
  mem_block_size = 0;
  atomic_store(&allocated_bytes, 0);
  return 0;
}

void print_status() {
  pid_t pid = getpid();
  printf("=== Process status ===\n");
  printf("PID: %d\n", (int)pid);
  printf("Requested memory (bytes): %zu\n", (size_t)atomic_load(&allocated_bytes));
  printf("Use 'ps'/'top'/'htop'/'pmap -x %d' from another terminal.\n", (int)pid);
}

void print_menu() {
  puts("\nCommands:");
  puts("  alloc <GiB>   - allocate and touch <GiB> GiB (e.g., alloc 2)");
  puts("  calloc <GiB>   - callocate and touch <GiB> GiB (e.g., alloc 2)");
  puts("  free          - free allocated memory block");
  puts("  status        - show process status");
  puts("  quit          - exit");
  puts("  help          - show this menu\n");
}

int main(int argc, char **argv) {
  (void)argc; (void)argv;
  signal(SIGINT, handle_sigint);
  signal(SIGTERM, handle_sigint);

  char line[256];
  print_menu();
  while (atomic_load(&keep_running)) {
    printf("> ");
    fflush(stdout);
    if (!fgets(line, sizeof(line), stdin)) {
      if (feof(stdin)) break;
      clearerr(stdin);
      continue;
    }
    char cmd[64] = {0};
    long val = 0;
    int n = sscanf(line, "%63s %ld", cmd, &val);
    if (n < 1) continue;

    if (strcmp(cmd, "alloc") == 0) {
      if (n < 2 || val <= 0) {
        printf("Usage: alloc <GiB>\n");
        continue;
      }
      printf("[*] Allocating %ld GiB ...\n", val);
      if (allocate_memory_gb((size_t)val) == 0) {
        printf("[+] Allocated and touched %ld GiB\n", val);
      } else {
        printf("[-] Allocation failed\n");
      }
    } 
    
    else if (strcmp(cmd, "calloc") == 0) {
      if (n < 2 || val <= 0) {
        printf("Usage: alloc <GiB>\n");
        continue;
      }
      printf("[*] Callocating %ld GiB ...\n", val);
      if (callocate_memory_gb((size_t)val) == 0) {
        printf("[+] Callocated and touched %ld GiB\n", val);
      } else {
        printf("[-] Allocation failed\n");
      }
    }
    else if (strcmp(cmd, "free") == 0) {
      if (free_memory_block() == 0) printf("[+] Memory freed\n");
      else printf("[-] Could not free memory\n");
    } 
    
    else if (strcmp(cmd, "status") == 0) {
      print_status();
    }
    else if (strcmp(cmd, "help") == 0) {
      print_menu();
    } else if (strcmp(cmd, "quit") == 0) {
      break;
    } else {
      printf("Unknown command. Type 'help'.\n");
    }
  }


  if (mem_block) free_memory_block();
  printf("[*] Exiting. Bye.\n");
  return 0;
}

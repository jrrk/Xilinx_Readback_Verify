
#include <stdio.h>
#include <stdint.h> // for keeping things 32-bit


#define WORDS_PER_FRAME_VIRTEX5 41
#define WORDS_PER_FRAME_7SERIES 101


#define WORD_SIZE 34 // extra bit for \n and null terminator
#define TRUE 1
#define FALSE 0
#define MAX_STRING_LEN 101

typedef struct net {
  int key;
  char *net;
  struct net *nxt;
} net_t;
  
typedef struct value {
  char *net;
  char lev;
} value_t;
  
extern value_t *ll_entries;

uint32_t convert_ascii_to_binary(char* ascii_string);

uint32_t verify_readback_word(uint32_t data, uint32_t gold, uint32_t mask, uint32_t start, int ll_min, int ll_max);

uint32_t verify_full_readback(FILE* readback_data, 
                              FILE* rbd_file,
                              FILE* msd_file,
                              int no_pad,
                              int fpga_series,
                              int ll_min, int ll_max);

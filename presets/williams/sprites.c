
#include "williams.h"
//#link "williams.c"

#include "stdlib.h"

const byte palette_data[16] = {/*{pal:332,n:16}*/
  0x00, 0x03, 0x19, 0x50, 0x52, 0x07, 0x1f, 0x37, 0xe0, 0xa4, 0xfd, 0xff, 0x38, 0x70, 0x7f, 0xf8, };

const byte sprite1[2+16*16/2] = {
8,16,/*{w:16,h:16,bpp:4,brev:1}*/
0x00,0x09,0x99,0x00,0x00,0x99,0x90,0x00,
0x00,0x94,0x94,0x90,0x09,0x49,0x49,0x00,
0x04,0x49,0x49,0x90,0x09,0x94,0x94,0x90,
0x94,0x99,0x94,0x90,0x09,0x49,0x99,0x49,
0x99,0x99,0x49,0x93,0x39,0x94,0x99,0x99,
0x04,0x49,0x99,0x94,0x49,0x99,0x94,0x90,
0x00,0x94,0x94,0x43,0x34,0x49,0x49,0x00,
0x00,0x09,0x43,0x94,0x49,0x34,0x90,0x00,
0x00,0x90,0x00,0x39,0x93,0x00,0x09,0x00,
0x00,0x09,0x83,0x33,0x33,0x33,0x90,0x00,
0x00,0x09,0x32,0x23,0x32,0x23,0x90,0x00,
0x00,0x03,0x03,0x23,0x82,0x30,0x30,0x00,
0x03,0x30,0x00,0x33,0x33,0x00,0x03,0x30,
0x00,0x30,0x03,0x00,0x00,0x30,0x03,0x00,
0x00,0x00,0x00,0x30,0x03,0x00,0x00,0x00,
0x00,0x09,0x99,0x00,0x00,0x99,0x90,0x00,
};

const byte sprite2[2+16*16/2] = {
8,16,/*{w:16,h:16,bpp:4,brev:1}*/
0x00,0x08,0x80,0x40,0x00,0x00,0x8D,0x00,
0x80,0x94,0x88,0x90,0x09,0x48,0x89,0x00,
0x08,0x49,0x48,0x66,0x66,0x98,0x94,0x98,
0x94,0x89,0x66,0x66,0x66,0x66,0x98,0x89,
0x99,0x66,0x67,0x76,0x67,0x76,0x69,0x98,
0x88,0x67,0x77,0x66,0x66,0x77,0x74,0x90,
0x09,0x97,0x74,0x46,0x64,0x47,0x78,0x88,
0x09,0x89,0x43,0x96,0x69,0x34,0x99,0x90,
0x08,0x89,0xBB,0x39,0x93,0xBB,0x98,0x90,
0x80,0x99,0x3B,0x33,0x33,0xB0,0x99,0x88,
0x00,0x09,0x9C,0xC3,0x3C,0xC8,0x99,0x08,
0x00,0x00,0x03,0xC3,0x8C,0x30,0x00,0x00,
0x00,0x00,0x0D,0xD3,0x3D,0x00,0x00,0x00,
0x00,0x00,0x0D,0x00,0x0D,0xD0,0x00,0x00,
0x00,0x00,0xDD,0x30,0x03,0xD0,0x00,0x00,
0x00,0x00,0xD0,0x40,0x00,0xD0,0x00,0x00,
};

const byte sprite3[2+16*16/2] = {
8,16,/*{w:16,h:16,bpp:4,brev:1}*/
0x00,0x00,0x00,0x01,0x10,0x00,0x00,0x00,
0x00,0x00,0x00,0x11,0x11,0x00,0x00,0x00,
0x00,0x00,0x00,0x01,0x10,0x00,0x00,0x00,
0x00,0x00,0x00,0x01,0x10,0x00,0x00,0x00,
0x00,0x11,0x10,0x01,0x10,0x01,0x11,0x00,
0x11,0x00,0x10,0x11,0x11,0x01,0x00,0x11,
0x10,0x00,0x11,0x11,0x11,0x11,0x00,0x01,
0x10,0x00,0x00,0x11,0x11,0x00,0x00,0x01,
0x00,0x01,0x10,0x11,0x41,0x01,0x10,0x00,
0x00,0x10,0x11,0x11,0x11,0x11,0x01,0x00,
0x01,0x00,0x00,0x51,0x15,0x00,0x00,0x10,
0x01,0x00,0x01,0x10,0x01,0x10,0x00,0x10,
0x01,0x00,0x10,0x00,0x00,0x01,0x00,0x10,
0x00,0x10,0x01,0x00,0x00,0x10,0x01,0x00,
0x00,0x10,0x00,0x00,0x00,0x00,0x01,0x00,
0x00,0x01,0x10,0x00,0x00,0x01,0x10,0x00,
};

const byte sprite4[2+16*16/2] = {
8,16,/*{w:16,h:16,bpp:4,brev:1}*/
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0xbb,0xbb,0x00,0x00,0x00,
0x00,0x00,0x00,0xbb,0xbb,0x00,0x00,0x00,
0x00,0x00,0xbb,0xbb,0xbb,0xbb,0x00,0x00,
0x00,0x0b,0x4b,0xbb,0xbb,0xb4,0xb0,0x00,
0x00,0x0b,0x44,0xbb,0xbb,0x49,0xb0,0x00,
0x00,0xbb,0x99,0x4b,0xb4,0x99,0xbb,0x00,
0x00,0x4b,0xb9,0x9b,0xb4,0x4b,0xb4,0x00,
0x00,0x04,0xbb,0x4b,0xb9,0xbb,0x40,0x00,
0x00,0x00,0x4b,0xbb,0xbb,0xb4,0x00,0x00,
0x11,0x00,0x0b,0xbb,0xbb,0xb0,0x00,0x11,
0x10,0x10,0x0b,0x41,0x14,0xb0,0x01,0x01,
0x10,0x00,0x05,0x11,0x11,0x50,0x00,0x01,
0x01,0x00,0x01,0x51,0x15,0x10,0x00,0x10,
0x00,0x10,0x01,0x10,0x01,0x10,0x01,0x00,
0x01,0x01,0x10,0x10,0x01,0x01,0x10,0x10,
};

const byte sprite5[2+16*16/2] = {
8,16,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x22,0x00,0x00,0x22,0x00,0x00,
0x00,0x20,0x20,0x00,0x00,0x02,0x02,0x00,
0x02,0x22,0x12,0x00,0x00,0x21,0x22,0x20,
0x00,0x02,0x11,0x00,0x00,0x11,0x20,0x00,
0x00,0x00,0x02,0x11,0x11,0x20,0x00,0x00,
0x00,0x00,0x02,0x22,0x22,0x20,0x00,0x00,
0x00,0x00,0x21,0x22,0x22,0x12,0x00,0x00,
0x00,0x00,0x22,0x12,0x21,0x22,0x00,0x00,
0x02,0x00,0x22,0x12,0x21,0x22,0x00,0x20,
0x20,0x02,0x21,0x11,0x11,0x12,0x20,0x02,
0x02,0x22,0x15,0x12,0x21,0x51,0x22,0x20,
0x02,0x11,0x15,0x52,0x25,0x51,0x11,0x20,
0x20,0x00,0x22,0x12,0x21,0x22,0x00,0x02,
0x20,0x02,0x20,0x20,0x02,0x02,0x20,0x02,
0x02,0x02,0x00,0x20,0x02,0x00,0x20,0x20,
};

const byte sprite6[2+10*16/2] = {
8,10,/*{w:16,h:10,bpp:4,brev:1}*/
0x00,0x00,0x00,0x00,0x04,0x04,0x04,0x00,
0x00,0x00,0x00,0x00,0x44,0x44,0x44,0x40,
0x00,0x00,0x04,0x04,0x49,0x49,0x99,0x44,
0x00,0x00,0x44,0x44,0x99,0x94,0x44,0x40,
0x00,0x04,0x49,0x99,0x94,0x49,0x99,0x40,
0x00,0x44,0x99,0x94,0x49,0x99,0x44,0x00,
0x04,0x49,0x44,0x99,0x99,0x44,0x00,0x00,
0x04,0x44,0x00,0x49,0x44,0x40,0x00,0x00,
0x04,0x40,0x00,0x04,0x00,0x00,0x00,0x00,
0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

const byte sprite7[2+14*16/2] = {
8,14,/*{w:16,h:14,bpp:4,brev:1}*/
0x00,0x60,0x00,0x00,0x00,0x00,0x06,0x00,
0x60,0x60,0x00,0x00,0x00,0x00,0x06,0x06,
0x60,0x60,0x50,0x00,0x00,0x05,0x06,0x06,
0x60,0x60,0x06,0x00,0x00,0x60,0x06,0x06,
0x66,0x60,0x06,0x06,0x60,0x60,0x06,0x66,
0x66,0x60,0x66,0x66,0x66,0x66,0x06,0x66,
0x66,0x60,0x6b,0x6b,0xb6,0xb6,0x06,0x66,
0x06,0x66,0x66,0xb6,0x6b,0x66,0x66,0x60,
0x00,0x67,0x66,0x66,0x66,0x66,0x66,0x00,
0x00,0x11,0x11,0x66,0x66,0x11,0x11,0x00,
0x01,0x11,0x21,0x11,0x11,0x12,0x11,0x10,
0x00,0x10,0x01,0x01,0x10,0x10,0x01,0x00,
0x00,0x10,0x11,0x00,0x00,0x11,0x01,0x00,
0x00,0x00,0x10,0x00,0x00,0x01,0x00,0x00,
};

const byte sprite8[2+15*16/2] = {
8,15,/*{w:16,h:15,bpp:4,brev:1}*/
0x00,0x00,0x11,0x11,0x11,0x11,0x00,0x00,
0x00,0x01,0x61,0x11,0x21,0x12,0x10,0x00,
0x00,0x11,0x12,0x11,0x61,0x11,0x11,0x00,
0x00,0x11,0x71,0x21,0x61,0x17,0x11,0x00,
0x00,0x11,0x77,0x11,0x12,0x77,0x11,0x00,
0x00,0x11,0x17,0x17,0x71,0x72,0x11,0x00,
0x00,0x16,0x21,0x78,0x87,0x11,0x11,0x00,
0x00,0x01,0x81,0x88,0x88,0x18,0x10,0x00,
0x00,0x08,0x18,0x58,0x85,0x81,0x80,0x00,
0x00,0x88,0x01,0x88,0x88,0x10,0x88,0x00,
0x00,0x08,0x07,0x78,0x87,0x70,0x80,0x00,
0x08,0x80,0x07,0x80,0x08,0x70,0x08,0x80,
0x88,0x00,0x88,0x00,0x00,0x88,0x00,0x88,
0x80,0x00,0x08,0x80,0x08,0x80,0x00,0x08,
0x00,0x00,0x00,0x80,0x08,0x00,0x00,0x00,
};

const byte sprite9[2+13*16/2] = {
8,13,/*{w:16,h:13,bpp:4,brev:1}*/
0x00,0x00,0xaa,0x00,0x00,0xaa,0x00,0x00,
0x00,0x00,0xa0,0x0a,0xa0,0x0a,0x00,0x00,
0x0a,0xaa,0xa4,0xaa,0xaa,0x3a,0xaa,0xa0,
0x00,0x0a,0x3a,0x9a,0xa9,0xa3,0xa0,0x00,
0x00,0x0a,0xaa,0x99,0xa4,0xaa,0xa0,0x00,
0x00,0x0a,0xaa,0x99,0x94,0xaa,0xa0,0x00,
0x00,0xaa,0x33,0xaa,0xaa,0x43,0xaa,0x00,
0x0a,0x3a,0xaa,0x3a,0xa3,0xaa,0xa3,0xa0,
0x00,0xaa,0xaa,0x30,0x03,0xaa,0xaa,0x00,
0x00,0x0a,0xa0,0x30,0x03,0x0a,0xa0,0x00,
0x00,0xa3,0xa0,0x00,0x00,0x0a,0x4a,0x00,
0x00,0xaa,0xa0,0x00,0x00,0x0a,0xaa,0x00,
0x00,0x0a,0xa0,0x00,0x00,0x0a,0xa0,0x00,
};


const byte* const all_sprites[9] = {
  sprite1,
  sprite2,
  sprite3,
  sprite4,
  sprite5,
  sprite6,
  sprite7,
  sprite8,
  sprite9,
};

//typedef void ActorUpdateFn(struct Actor* a);
//typedef void ActorDrawFn(struct Actor* a);
//typedef void ActorEnumerateFn(struct Actor* a);

typedef struct Actor {
  byte grid_index;
  byte next_actor;
  byte x,y;
  byte* shape;
  void (*update)(struct Actor* a);
  void (*draw)(struct Actor* a);
} Actor;

#define GBITS 3
#define GDIM (1<<GBITS)
#define MAX_ACTORS 256

static byte grid[GDIM*GDIM]; // should be 256
static Actor actors[MAX_ACTORS];

byte xy2grid(byte x, byte y) {
  return (x >> (8-GBITS)) | (y & ((GDIM-1) << GBITS));
}

void insert_into_grid(byte gi, byte actor_index) {
  struct Actor* a = &actors[actor_index];
  a->grid_index = gi;
  a->next_actor = grid[gi];
  grid[gi] = actor_index;
}

void delete_from_grid(byte gi, byte actor_index) {
  byte i = grid[gi];
  byte next = actors[actor_index].next_actor;
  // is actor to delete at head of list?
  if (i == actor_index) {
    grid[gi] = next;
  } else {
    // iterate through the list
    do {
      byte j = actors[i].next_actor;
      if (j == actor_index) {
        actors[i].next_actor = next;
        break;
      }
      i = j;
    } while (1); // watchdog reset if actor not found to delete
  }
  actors[actor_index].next_actor = 0;
  actors[actor_index].grid_index = 0;
}

void draw_actor(struct Actor* a) {
  blit_sprite(a->shape, a->x, a->y);
}

void draw_actor_debug(struct Actor* a) {
  blit_sprite_solid(a->shape, a->x, a->y, a->next_actor?0xff:0x33);
}

byte update_actor(byte actor_index) {
  struct Actor* a = &actors[actor_index];
  byte next_actor;
  byte gi0,gi1;
  if (!a->shape) return 0;
  next_actor = a->next_actor;
  gi0 = a->grid_index;
  blit_sprite_solid(a->shape, a->x, a->y, 0);
  if (a->update) a->update(a);
  if (a->draw) a->draw(a);
  //draw_sprite_strided(a->shape, a->x, a->y, 2);
  gi1 = xy2grid(a->x, a->y);
  if (gi0 != gi1) {
    delete_from_grid(gi0, actor_index);
    insert_into_grid(gi1, actor_index);
  }
  return next_actor;
}

//

word lfsr = 1;

word xrand() {
  byte lsb = (byte)(lfsr & 1);
  lfsr >>= 1;
  if (lsb) lfsr ^= 0xd400;
  return lfsr;
}

signed char random_dir() {
  byte x = (byte)xrand();
  if (x < 85) return 0;
  else if (x < 85*2) return -1;
  else return 1;
}

void random_walk(Actor* a) {
  a->x += random_dir();
  a->y += random_dir();
}

void update_grid_cell(byte grid_index) {
  byte actor_index = grid[grid_index];
  while (actor_index) {
    actor_index = update_actor(actor_index);
  }
}

void update_grid_rows(byte row_start, byte row_end) {
  byte i0 = row_start * GDIM;
  byte i1 = row_end * GDIM;
  byte i;
  for (i=i0; i!=i1; i++) {
    update_grid_cell(i);
  }
}

int main() {
  byte i;
  byte num_actors = 32;
  blit_solid(0, 0, 255, 255, 0);
  memset(grid, 0, sizeof(grid));
  memset(actors, 0, sizeof(actors));
  memcpy(palette, palette_data, 16);
  for (i=1; i<num_actors; i++) {
    Actor* a = &actors[i];
    a->x = (i & 3) * 16 + 32;
    a->y = (i / 4) * 16 + 64;
    a->shape = (byte*) all_sprites[i%9];
    a->update = random_walk;
    a->draw = draw_actor; // draw_actor_debug;
    insert_into_grid(xy2grid(a->x, a->y), i);
    watchdog0x39 = 0x39;
  }
  while (1) {
    // update top half while drawing bottom half
    while (video_counter < 0x80) ;
    update_grid_rows(0,GDIM/2);
    // update bottom half while drawing top half
    while (video_counter >= 0x80) ;
    update_grid_rows(GDIM/2,GDIM);
    watchdog0x39 = 0x39;
    //palette[0] = i++;
  }
  return 0;
}

#include <stdint.h>
#ifndef SONGS

#define HIGH 1
#define LOW 0

//D 调
// #define NOTE_1  294  // 1
// #define NOTE_2  330  // 2
// #define NOTE_3  350  // 3
// #define NOTE_4  393  // 4
// #define NOTE_5  441  // 5
// #define NOTE_6  495  // 6
// #define NOTE_7  556  // 7
// #define NOTE_1_DOWN  147  // 1 down
// #define NOTE_2_DOWN  165  // 2 down
// #define NOTE_3_DOWN  175  // 3 down
// #define NOTE_4_DOWN  196  // 4 down
// #define NOTE_5_DOWN  221  // 5 down
// #define NOTE_6_DOWN  248  // 6 down
// #define NOTE_7_DOWN  278  // 7 down
// #define NOTE_1_UP  589  // 1 up
// #define NOTE_2_UP  661  // 2 up
// #define NOTE_3_UP  700  // 3 up
// #define NOTE_4_UP  786  // 4 up
// #define NOTE_5_UP  882  // 5 up
// #define NOTE_6_UP  990  // 6 up
// #define NOTE_7_UP  1112  // 7 up

//A 调
#define NOTE_1  441  // 1
#define NOTE_2  495  // 2
#define NOTE_3  556  // 3
#define NOTE_4  589  // 4
#define NOTE_5  661  // 5
#define NOTE_6  742  // 6
#define NOTE_7  833  // 7
#define NOTE_1_DOWN  221  // 1 down
#define NOTE_2_DOWN  248  // 2 down
#define NOTE_3_DOWN  278  // 3 down
#define NOTE_4_DOWN  294  // 4 down
#define NOTE_5_DOWN  330  // 5 down
#define NOTE_6_DOWN  371  // 6 down
#define NOTE_7_DOWN  416  // 7 down
#define NOTE_1_UP  882  // 1 up
#define NOTE_2_UP  990  // 2 up
#define NOTE_3_UP  1112  // 3 up
#define NOTE_4_UP  1178  // 4 up
#define NOTE_5_UP  1322  // 5 up
#define NOTE_6_UP  1484  // 6 up
#define NOTE_7_UP  1665  // 7 up

#define NOTE_REST 1000  // 休止符
#define NOTE_STOP 0  // 停止音符
#define BEAT_DURATION 50 // 每拍时长，单位为毫秒
typedef struct 
{
  uint16_t tone;
  float duration; 
}Note;

extern const Note Test[];
extern const Note Stars_song[];
extern const Note OrdinaryRoad_song[];
extern const Note Mario[];
#endif
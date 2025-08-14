#include "songs.h"

const Note Stars_song[] = {
    {NOTE_1, 1}, {NOTE_1, 1}, {NOTE_5, 1}, {NOTE_5, 1},
    {NOTE_6, 1}, {NOTE_6, 1}, {NOTE_5, 2},
    {NOTE_4, 1}, {NOTE_4, 1}, {NOTE_3, 1}, {NOTE_3, 1},
    {NOTE_2, 1}, {NOTE_2, 1}, {NOTE_1, 2},
    {NOTE_STOP, 2}  // 结束标志
};

const Note Test[] = {
    {NOTE_1_DOWN , 0.5}, {NOTE_2_DOWN, 0.5}, {NOTE_3_DOWN, 0.5}, {NOTE_4_DOWN, 0.5},
    {NOTE_5_DOWN, 0.5}, {NOTE_6_DOWN, 0.5}, {NOTE_7_DOWN, 0.5}, {NOTE_1, 0.5}, 
    {NOTE_2, 0.5}, {NOTE_3, 0.5}, {NOTE_4, 0.5}, {NOTE_5, 0.5},
    {NOTE_6, 0.5}, {NOTE_7, 0.5}, {NOTE_1_UP, 0.5}, {NOTE_2_UP, 0.5},
    {NOTE_3_UP, 0.5}, {NOTE_4_UP, 0.5}, {NOTE_5_UP, 0.5}, {NOTE_6_UP, 0.5},
    {NOTE_7_UP, 0.5}, {NOTE_REST, 20}
};

const Note OrdinaryRoad_song[] = {
    // ===== 前奏部分 =====
    {NOTE_6_DOWN, 1}, {NOTE_6_DOWN, 1}, {NOTE_3, 1}, {NOTE_1, 1}, {NOTE_1_DOWN, 1}, {NOTE_4_DOWN, 1}, {NOTE_4, 1}, {NOTE_1, 1},
    {NOTE_1_DOWN, 1}, {NOTE_5_DOWN, 1}, {NOTE_3, 1}, {NOTE_1, 1}, {NOTE_7_DOWN, 1}, {NOTE_1, 1}, {NOTE_2, 1}, {NOTE_5_DOWN, 1},
    {NOTE_6_DOWN, 1}, {NOTE_6_DOWN, 1}, {NOTE_3, 1}, {NOTE_1, 1}, {NOTE_1_DOWN, 1}, {NOTE_4_DOWN, 1}, {NOTE_4, 1}, {NOTE_1, 1},
    {NOTE_1_DOWN, 1}, {NOTE_5_DOWN, 1}, {NOTE_3, 1}, {NOTE_1, 1}, {NOTE_7_DOWN, 1}, {NOTE_1, 1}, {NOTE_2, 1}, {NOTE_5_DOWN, 1},
    
    // ===== 主歌部分 =====
    // 0 3 3 6 6 6 1 2 3 3 | 3 - - 0 |
    {NOTE_REST, 1}, {NOTE_3, 1}, {NOTE_3, 1}, {NOTE_6, 0.5}, {NOTE_6, 1}, {NOTE_1, 1}, {NOTE_2, 1}, {NOTE_3, 0.5},
    {NOTE_3, 3}, {NOTE_REST, 1},
    
    // 0 3 3 6 6 6. 5 5. 4 | 3 - - 0 | (注：简谱中的点视为八分音符，转换为两个半拍)
    {NOTE_REST, 1}, {NOTE_3, 1}, {NOTE_3, 1}, {NOTE_6, 0.5}, 
    {NOTE_6, 1.5}, {NOTE_5, 0.5}, {NOTE_5, 1.5}, {NOTE_4, 0.5}, 
    {NOTE_3, 3}, {NOTE_REST, 1},
    
    // 0 3 3 6 6 1 2 3 | 3 - - 0 |
    {NOTE_REST, 1}, {NOTE_3, 1}, {NOTE_3, 1}, {NOTE_6, 1}, {NOTE_6, 1}, {NOTE_1, 1}, {NOTE_2, 1}, {NOTE_3, 1},
    {NOTE_3, 3}, {NOTE_REST, 1},
    
    // 0 3 3 1 4 4 4 4 3 | 1 - - 0 |
    {NOTE_REST, 1}, {NOTE_3, 1}, {NOTE_3, 1}, {NOTE_1, 1}, {NOTE_4, 1}, {NOTE_4, 0.5}, {NOTE_4, 0.5}, {NOTE_4, 1}, {NOTE_3, 1},
    {NOTE_1, 3}, {NOTE_REST, 1},
    
    // 0 3 3 6 6 6 1 2 3 3 | 3 - - 0 |
    {NOTE_REST, 1}, {NOTE_3, 1}, {NOTE_3, 1}, {NOTE_6, 0.5}, {NOTE_6, 1}, {NOTE_1, 1}, {NOTE_2, 1}, {NOTE_3, 0.5},
    {NOTE_3, 3}, {NOTE_REST, 1},
    
    // ===== 副歌部分 =====
    // 0 3 3 6 6 6. 5 5. 4 | 3 - - 0 | 
    {NOTE_REST, 1}, {NOTE_3, 1}, {NOTE_3, 1}, {NOTE_6, 0.5},
    {NOTE_6, 1.5}, {NOTE_5, 0.5},  // 6. 5
    {NOTE_5, 1.5}, {NOTE_4, 0.5},  // 5. 4
    {NOTE_3, 3}, {NOTE_REST, 1},
    
    // 0 3 3 6 6 1 2 3 3 | 3 - - 0 | 
    {NOTE_REST, 1}, {NOTE_3, 1}, {NOTE_3, 1}, {NOTE_6, 0.5}, {NOTE_6, 0.5}, {NOTE_6, 1}, {NOTE_1, 1}, {NOTE_2, 1}, {NOTE_3, 0.5}, {NOTE_3, 0.5},
    {NOTE_3, 3}, {NOTE_REST, 1},
        
    // 0 3 3 1 4 4 4 4 3 | 1 - 0 5 6 7 | 
    {NOTE_REST, 1}, {NOTE_3, 1}, {NOTE_3, 1}, {NOTE_1, 1}, {NOTE_4, 1}, {NOTE_4, 0.5}, {NOTE_4, 0.5}, {NOTE_4, 1}, {NOTE_3, 1},
    {NOTE_1, 3}, {NOTE_REST, 1}, {NOTE_6, 1}, {NOTE_6, 1}, {NOTE_7, 1},
    
    // 1 7 1 15 6 6 5 4 3 | 
    {NOTE_1_UP, 1}, {NOTE_7, 0.5}, {NOTE_1_UP, 0.5}, {NOTE_1_UP, 0.5}, {NOTE_5_UP, 0.5},  // 1̇ 7 1̇ 1̇ 5̇
    {NOTE_6, 0.5}, {NOTE_6, 1}, {NOTE_5, 1}, {NOTE_4, 0.5}, {NOTE_3, 0.5},
    
    // 3 3 3 4 2 2 5 6 7 | 
    {NOTE_3, 1}, {NOTE_3, 1}, {NOTE_3, 1}, {NOTE_4, 0.5}, {NOTE_2, 0.5}, {NOTE_2, 1}, {NOTE_5, 1}, {NOTE_6, 1}, {NOTE_7, 1},
    {NOTE_1_UP, 1}, {NOTE_7, 0.5}, {NOTE_1_UP, 0.5}, {NOTE_1_UP, 0.5}, {NOTE_5_UP, 0.5},  // 1̇ 7 1̇ 1̇ 5̇
    {NOTE_6, 0.5}, {NOTE_6, 1},
        // 1 7 1 13. 6. 5 5 4 | (我曾经失落失望失掉所有方向) - 3.和6.为附点四分
    {NOTE_1_UP, 1}, {NOTE_7, 0.5}, {NOTE_1_UP, 0.5}, {NOTE_1_UP, 0.5}, 
    {NOTE_3_UP, 2}, {NOTE_6, 2}, {NOTE_5, 1}, {NOTE_5, 1}, {NOTE_4, 1},
    
    // 3 3 2 2 6 7 | (直到)
    {NOTE_3, 2}, {NOTE_3, 1}, {NOTE_2, 1}, {NOTE_2, 2}, {NOTE_6, 1}, {NOTE_7, 1},
    
    // i i 2 i i. i 7 i 2 | (看见平凡才是唯一的答案) - i.为附点四分
    {NOTE_1_UP, 2}, {NOTE_1_UP, 1}, {NOTE_2_UP, 0.5}, {NOTE_1_UP, 0.5},
    {NOTE_1_UP, 1.5},  // i. = i(1拍) + .(0.5拍) → 1.5拍
    {NOTE_1_UP, 0.5}, {NOTE_7, 1}, {NOTE_1_UP, 0.5}, {NOTE_2_UP, 0.5},
    
    // 2 i 7 i i - | (结尾)
    {NOTE_2_UP, 2}, {NOTE_1_UP, 1}, {NOTE_7, 0.5}, {NOTE_1_UP, 0.5}, {NOTE_1_UP, 3},  // i - = 2拍 + 延长2拍 → 共4拍

    // 结束标志
    {NOTE_STOP, 4}
};

const Note Mario[] = {
    {NOTE_3, 0.5}, {NOTE_3, 0.5}, {NOTE_3, 0.5}, {NOTE_1, 0.25}, {NOTE_3, 0.25}, {NOTE_5, 0.5}, {NOTE_5_DOWN, 0.5}, 
    {NOTE_1, 0.5}, {NOTE_5_DOWN, 0.5}, {NOTE_3_DOWN, 0.5}, {NOTE_6_DOWN, 0.5}, 
    {NOTE_7_DOWN, 0.5}, {NOTE_7_DOWN, 0.5}, {NOTE_6_DOWN, 0.5}, {NOTE_5_DOWN, 0.5}, {NOTE_3, 0.5}, {NOTE_5, 0.25}, {NOTE_6, 0.25}, {NOTE_4, 0.25}, {NOTE_5, 0.25}, 
    {NOTE_3, 0.25}, {NOTE_1, 0.25}, {NOTE_2, 0.25}, {NOTE_7_DOWN, 0.5}, {NOTE_1, 0.5}, {NOTE_5_DOWN, 0.25}, 
    {NOTE_3_DOWN, 0.25}, {NOTE_6_DOWN, 0.5}, {NOTE_7_DOWN, 0.25}, {NOTE_7_DOWN, 0.25}, {NOTE_6_DOWN, 0.5}, {NOTE_5_DOWN, 0.25}, {NOTE_3, 0.5}, 
    {NOTE_5, 0.5}, {NOTE_6, 0.5}, {NOTE_4, 0.5}, {NOTE_5, 0.5}, {NOTE_3, 0.5}, {NOTE_2, 0.25}, {NOTE_1, 0.25}, {NOTE_7_DOWN, 1.0}, 
    {NOTE_5, 0.5}, {NOTE_4, 0.25}, {NOTE_4, 0.25}, {NOTE_3, 0.5}, {NOTE_3, 0.5}, {NOTE_5_DOWN, 0.5}, {NOTE_6_DOWN, 0.5}, {NOTE_1, 0.5}, 
    {NOTE_6_DOWN, 0.25}, {NOTE_1, 0.25}, {NOTE_2, 0.5}, {NOTE_5, 0.25}, {NOTE_4, 0.25}, {NOTE_4, 0.5}, {NOTE_3, 0.5}, {NOTE_3, 0.5}, {NOTE_1_UP, 0.5}, 
    {NOTE_1_UP, 0.5}, {NOTE_1_UP, 0.5}, {NOTE_5, 0.25}, {NOTE_4, 0.25}, {NOTE_4, 0.25}, {NOTE_3, 0.5}, {NOTE_3, 0.5}, 
    {NOTE_5_DOWN, 0.25}, {NOTE_6_DOWN, 0.25}, {NOTE_1, 0.5}, {NOTE_6_DOWN, 0.25}, {NOTE_1, 0.25}, {NOTE_2, 0.5}, {NOTE_3, 0.5}, {NOTE_2, 0.5}, {NOTE_1, 0.5} 
};
int scene;

int data0[300] = {//?e?X?g?p
     5,  5,  5,  5,  5,    6,  6,  6,  5 , 6,    6,  5,  5,  5,  5,    5,  5,  5,  5,  5,
     5,  5,  5,  5,  5,   16,  9, 16, 16 ,16,   16, 16,  5, 16, 16,   16, 16, 16, 16, 16,
     5,  5, 16, 16,  5,   16,  9, 16, 16 ,16,   16, 16,  5, 16, 16,   16, 16, 16, 16, 16,
     5,  5, 16, 16,  5,   16,  9, 16, 16 ,16,   16, 16,  5, 16, 16,   16, 16, 16, 16, 16,
    16,  5,  5,  5,  5,   16,  6, 16, 16 ,16,   16, 16,  5, 16, 16,   16, 16, 16, 16, 16,
    16,  5,  5,  5,  5,   16,  9, 16, 16 ,16,   16, 16,  5,  5,  5,    5,  5,  5,  5,  5,
    16,  5,  5,  5,  5,   16,  9, 16, 16 ,16,   16, 16,  5, 16, 16,   16, 16, 16,  5, 16,
    16,  5, 16, 16,  5,   16, 16, 16, 16 ,16,   16, 16,  5, 16, 16,   16, 16, 16,  5, 16,
    16,  5, 16, 16,  5,   16, 16,  5,  5 , 5,   16, 16,  5,  5,  5,    5,  5,  5,  5,  5,
    16,  5, 16, 16,  5,   16, 16,  5, 16 , 5,   16, 16,  5, 16, 16,   16, 16, 16, 16, 16,
    16,  5, 16, 16,  5,    5,  5,  5, 16 , 5,   16, 16,  5, 16, 16,   16, 16, 16, 16, 16,
    16,  5, 16, 16, 16,   16, 16,  5, 16 , 5,   16, 16,  5, 16, 16,   16, 16, 16, 16, 16,
    16,  5, 16, 16, 16,   16, 16,  5, 16 , 5,   16, 16,  5, 16, 16,   16, 16, 16, 16, 16,
    16,  5, 16, 16, 16,   16, 16,  5, 16 , 5,   16, 16,  5, 16, 16,   16, 16, 16, 16, 16,
    16,  5, 16, 16, 16,   16, 16, 16, 16 , 5,    5,  5,  5, 16, 16,   16, 16, 16, 16, 16,

};
int data1[300] = {
    // ??20x15
      5,  5,  5, 16, 16,  16, 16, 16, 16, 16,  16, 16, 16, 16, 16,  16, 16,  5,  5,  5,
      5,  5,  5, 16, 16,  16, 16, 16, 16, 16,  16, 16, 16, 16, 16,  16, 16,  5,  5,  5,
      5,  5,  5, 16, 16,  16, 16, 16, 16, 16,  16, 16, 16, 16, 16,  16, 16,  5,  5,  5,
      5,  5,  5, 16, 16,  16, 16, 16, 16, 16,  16, 16, 16, 16, 16,  16, 16,  5,  5,  5,
      5,  5,  5, 16, 16,  16, 16, 16, 16,  0,   1, 16, 16, 16, 16,  16, 16,  5,  5,  5,
      5,  5,  5, 16, 16,  16, 16, 16, 16, 10,  11, 16, 16, 16, 16,  16, 16,  5,  5,  5,
      5,  5,  5, 16, 16,  16, 16, 16, 16, 20,  21, 16, 16, 16, 16,  16, 16,  5,  5,  5,
     52, 53, 52, 52, 52,  52, 52, 53, 52, 52,  52, 52, 53, 52, 52,  52, 52, 52, 53, 52,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,
};
int data2[300] = {
      5,  5,  5, 16, 16,  16, 16, 16, 16, 16,  16, 16, 16, 16,  16,   16,  16, 23, 23, 23,
      5,  5,  5, 16, 16,  16, 16, 16, 16, 16,  16, 16, 16, 16,  16,   16,  16, 23, 23, 23,
      5,  5,  5, 16, 16,  16, 16, 16, 16, 16,  16, 16, 16, 16,  16,   16,  16, 23, 23, 23,
      5,  5,  5, 16, 16,  16, 16, 16, 16, 16,  16, 16, 16, 16,  16,   16,  16, 23, 23, 23,
      5,  5,  5, 16, 16,  16, 16, 16, 57, 60,  60, 57, 16, 16,  16,   16,  16, 23, 23, 23,
      5,  5,  5, 16, 16,  16, 16, 16, 68, 70,  70, 67, 16, 16,  16,   16,  16, 23, 23, 23,
      5,  5,  5, 16, 16,  16, 16, 16, 78, 80,  80, 77, 16, 16,  94,   95,  96, 23, 23, 23,
     52, 53, 52, 52, 52,  52, 52, 53, 52, 52,  52, 52, 53, 52, 104,  105, 106, 52, 53, 52,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23,  23,   23,  23, 23, 23, 23,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23,  23,   23,  23, 23, 23, 23,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23,  23,   23,  23, 23, 23, 23,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23,  23,   23,  23, 23, 23, 23,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,   5,    5,   5,  5,  5,  5,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,   5,    5,   5,  5,  5,  5,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,   5,    5,   5,  5,  5,  5,
};
int data3[] = {
     23, 23, 23, 23, 23,  23,  6, 23, 23, 23,  23, 64,  5,  5,  5,   5,  5,  5,  5,  5,
     23, 23, 23, 23, 23,  23, 59, 23, 23, 23,  23, 74, 82, 82, 82,  82, 82, 82, 82, 82,
     23, 23, 23, 23, 23,  23, 69, 23, 23, 23,  23, 84, 92, 92, 92,  92, 92, 92, 92, 92,
     23, 23, 23, 23, 23,  23, 79, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     23, 23, 23, 23, 23,  23,  6, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     23, 23, 23, 23, 23,  23, 59, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     23, 23, 23, 23, 23,  23, 69, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     52, 52, 52, 52, 52,  53, 79, 23, 23, 23,  23, 75, 75, 75, 75,  75, 75, 75, 75, 75,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 85, 85, 85, 85,  85, 85, 85, 85, 85,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 64,  5,  5,  5,   5,  5,  5,  5,  5,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 74,  5,  5,  5,   5,  5,  5,  5,  5,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 74,  5,  5,  5,   5,  5,  5,  5,  5,
      5,  5,  5,  5,  5,   5,  5, 23, 23, 23,  23, 74,  5,  5,  5,   5,  5,  5,  5,  5,
      5,  5,  5,  5,  5,   5,  5, 23, 23, 23,  23, 74,  5,  5,  5,   5,  5,  5,  5,  5,
      5,  5,  5,  5,  5,   5,  5, 23, 23, 23,  23, 74,  5,  5,  5,   5,  5,  5,  5,  5,
};
int data4[] = {
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     23, 23, 23, 23, 23,  23, 69, 23, 23, 23,  23, 74,  5,  5,  4,   4, 46, 46, 46, 46,
     23, 23, 23, 23, 23,  23, 69, 23, 23, 23,  23, 74,  5,  5,  4,   4, 46, 46, 46, 46,
     23, 23, 23, 23, 23,  23, 79, 23, 23, 23,  23, 74,  5,  5,  4,   4, 46, 46, 46, 46,
     23, 23, 23, 23, 23,  23,  6, 23, 23, 23,  23, 74,  5,  5,  4,   4, 46, 46, 46, 46,
     23, 23, 23, 23, 23,  23, 59, 23, 23, 23,  23, 84, 85, 85,  4,   4, 46, 46, 46, 46,
     23, 23, 23, 23, 23,  23, 69, 23, 23, 23,  23, 23, 23, 23,  4,   4, 46, 46, 46, 46,
     23, 23, 23, 23, 23,  23, 79, 23, 23, 23,  23, 75, 75, 75,  4,   4, 46, 46, 46, 46,
     23, 23, 23, 23, 23,  23,  6, 23, 23, 23,  23, 85, 85, 85,  5,   5, 46, 46, 46, 46,
     23, 23, 23, 23, 23,  23, 59, 23, 23, 23,  23, 64,  5,  5,  5,   5, 46, 46, 46, 46,
     23, 23, 23, 23, 23,  23, 69, 23, 23, 23,  23, 74,  5,  5,  5,   5, 46, 46, 46, 46,
     23, 23, 23, 23, 23,  23, 79, 23, 23, 23,  23, 74,  5,  5,  5,   5, 46, 46, 46, 46,
};
int data5[] = {
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5, 26, 26, 26, 26,  26, 26, 26, 26, 26,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5, 26, 26, 26, 26,  26, 26, 26, 26, 26,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5, 26, 26, 26, 26,  26, 26, 26, 26, 26,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5, 26, 26, 26, 26,  26, 26, 26, 26, 26,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5, 26, 26, 26, 26,  26, 26, 26, 26, 26,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5, 26, 26, 26, 26,  26, 26, 26, 26, 26,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5, 26, 26, 26, 26,  26, 26, 26, 26, 26,
      5,  5,  5,  5,  5,   5, 26, 26, 26, 26,  26, 26, 26, 26, 26,  26, 26, 26, 26, 26,
      5,  5,  5,  5,  5,   5, 26, 26, 26, 26,  26, 26, 26, 26, 26,  26, 26, 26, 26, 26,
      5,  5,  5,  5,  5,  64, 26, 26, 26, 26,  26, 26, 26, 26, 26,  26, 26, 26, 26, 26,

      5,  5,  5,  5,  5,  74, 15, 15, 15, 15,  15, 15, 15, 15, 15,  15, 15, 15, 15, 15,
      5,  5,  5,  5,  5,  74, 36, 36, 36, 36,  36, 36, 36, 36, 36,  36, 36, 36, 36, 36,
      5,  5,  5,  5,  5,  74, 36, 36, 34, 35,  36, 36, 34, 35, 36,  36, 34, 35, 36, 36,
      5,  5,  5,  5,  5,  74, 36, 36, 44, 45,  36, 36, 44, 45, 36,  36, 44, 45, 36, 36,
      5,  5,  5,  5,  5,  74, 36, 36, 36, 36,  36, 36, 36, 36, 36,  36, 36, 36, 36, 36,
};
int data6[] = {
     26, 26, 26, 26, 26,  26, 26, 26, 25, 25,  25, 25, 25, 25, 25,  25, 25, 25, 25, 25,
     26, 26, 26, 26, 26,  26, 26, 26, 55, 54,  65, 65, 65, 65, 54,  65, 65, 65, 65, 54,
     26, 26, 26, 26, 26,  26, 26, 26, 69, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     26, 26, 26, 26, 26,  26, 26, 26, 69, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     26, 26, 26, 26, 26,  26, 26, 26, 69, 23,  23, 23, 23, 75, 75,  75, 75, 75, 75, 75,
     26, 26, 26, 26, 26,  26, 26, 26,  6, 23,  23, 23, 23, 85, 85,  85, 85, 85, 85, 85,
     26, 26, 26, 26, 26,  26, 26, 26, 69, 23,  23, 23, 23, 64,  5,   5,  5,  5,  5,  5,
     26, 26, 26, 26, 26,  26, 26, 26, 69, 23,  23, 23, 23, 74,  5,   5,  5,  5,  5,  5,
     26, 26, 26, 26, 26,  26, 26, 26, 69, 23,  23, 23, 23, 74,  5,   5,  5,  5,  5,  5,
     26, 26, 26, 26, 26,  26, 26, 26, 69, 23,  23, 23, 23, 74,  5,   5,  5,  5,  5,  5,
     15, 15, 15, 15, 15,  15, 15, 15,  6, 23,  23, 23, 23, 74,  5,   5,  5,  5,  5,  5,
     36, 36, 36, 36, 36,  36, 36, 36, 69, 23,  23, 23, 23, 74,  5,   5,  5,  5,  5,  5,
     34, 35, 36, 36, 34,  35, 36, 36, 69, 23,  23, 23, 23, 74,  5,   5,  5,  5,  5,  5,
     44, 45, 36, 36, 44,  45, 36, 36, 69, 23,  23, 23, 23, 74,  5,   5,  5,  5,  5,  5,
     36, 36, 36, 36, 36,  36, 36, 36, 69, 23,  23, 23, 23, 74,  5,   5,  5,  5,  5,  5,
};
int data7[] = {
     25, 25, 25, 25, 25,  25, 25, 25, 25, 25,  25, 25, 25, 25, 25,  25, 23, 23, 23, 23,
     65, 65, 65, 65, 54,  65, 65, 65, 65, 54,  65, 65, 65, 65, 54,  66, 23, 23, 23, 23,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     75, 75, 75, 75, 75,  75, 75, 75, 75, 75,  75, 75, 75, 75, 75,  76, 23, 23, 23, 23,

     85, 85, 85, 85, 85,  85, 85, 85, 85, 85,  85, 85, 85, 85, 85,  86, 23, 23, 23, 23,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,  64, 23, 23, 23, 23,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,  74, 23, 23, 23, 23,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,  74, 23, 23, 23, 23,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,  74, 23, 23, 23, 23,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,  74, 23, 23, 23, 23,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,  74, 23, 23, 23, 23,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,  74, 23, 23, 23, 23,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,  74, 23, 23, 23, 23,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,  74, 23, 23, 23, 23,
};
int data8[] = {
      5,  5,  5,  5,  5,  74, 36, 36, 36, 36,  36, 36, 36, 36, 36,  36, 36, 36, 36, 36,
     81, 81, 81, 81,  5,  74, 25, 25, 25, 25,  25, 25, 25, 25, 25,  25, 25, 25, 25, 25,
     91, 91, 91, 91,  5,  84, 54, 65, 65, 65,  65, 54, 65, 65, 65,  65, 54, 65, 65, 65,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     75, 75, 75, 75, 75,  75, 75, 75, 75, 75,  75, 75, 75, 75, 75,  75, 75, 75, 75, 75,
     85, 85, 85, 85, 85,  85, 85, 85, 85, 85,  85, 85, 85, 85, 85,  85, 85, 85, 85, 85,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,
};
int data9[] = {
     36, 36, 36, 36, 36,  36, 36, 36, 69, 23,  23, 23, 23, 74,  5,   5,  5,  5,  5,  5,
     25, 25, 25, 25, 25,  25, 25, 25, 69, 23,  23, 23, 23, 74, 81,  81, 81, 81, 81, 81,
     65, 54, 65, 65, 65,  65, 54, 65, 79, 23,  23, 23, 23, 84, 91,  91, 91, 91, 91, 91,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     75, 75, 75, 75, 75,  75, 75, 75, 75, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     91, 91, 91, 91, 91,  91, 91, 91, 74, 23,  23, 23, 23, 23, 103, 103, 103, 103, 103, 103,
      5,  5,  5,  5,  5,   5,  5,  5, 74, 23,  23, 23, 23, 23, 103, 103, 103, 103, 103, 103,
      5,  5,  5,  5,  5,   5,  5,  5, 74, 23,  23, 23, 23, 23, 103, 103, 103, 103, 103, 103,
      5,  5,  5,  5,  5,   5,  5,  5, 74, 23,  23, 23, 23, 23, 103, 103, 103, 103, 103, 103,
      5,  5,  5,  5,  5,   5,  5,  5, 74, 23,  23, 23, 23, 23, 103, 103, 103, 103, 103, 103,
      5,  5,  5,  5,  5,   5,  5,  5, 74, 23,  23, 23, 23, 23, 103, 103, 103, 103, 103, 103,
      5,  5,  5,  5,  5,   5,  5,  5, 74, 23,  23, 23, 23, 23, 103, 103, 103, 103, 103, 103,
};
int data10[] = {
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,  74, 23, 23, 23, 23,
     81, 81, 81, 81, 81,  81, 81, 81, 81, 81,  81, 81, 81, 81, 81,  74, 23, 23, 23, 23,
     91, 91, 91, 91, 91,  91, 91, 91, 91, 91,  91, 91, 91, 91, 91,  93, 23, 23, 23, 23,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     103, 103, 103, 103, 103,  103, 103, 103, 103, 103,  103, 103, 103, 103, 103,  103, 23, 23, 23, 23,
     103, 103, 103, 103, 103,  103, 103, 103, 103, 103,  103, 103, 103, 103, 103,  103, 23, 23, 23, 23,
     103, 103, 103, 87, 88,  88, 88, 88, 89, 103,  103, 103, 103, 103, 103,  103, 23, 23, 23, 23,
     103, 103, 87, 98, 98,  98, 98,98, 98, 89,  103, 103, 103, 103, 103,  103, 23, 23, 23, 23,
     103, 87, 98, 98, 98,  98, 98, 98, 98, 98,  89, 103, 103, 103, 103,  103, 23, 23, 23, 23,
     103, 97, 98, 98, 98,  98, 98, 98, 98, 98,  99, 103, 103, 103, 103,  103, 23, 23, 23, 23,
     103, 97, 98, 98, 98,  98, 98, 98, 98, 98,  99, 103, 103, 103, 103,  103, 23, 23, 23, 23,
};
int data11[] = {
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,
      5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,   5,  5,  5,  5,  5,
     82, 82, 82, 82, 82,  82, 82, 82, 82, 82,  82, 82, 82, 82, 82,  82, 82, 82, 82, 82,
     92, 92, 92, 92, 92,  92, 92, 92, 92, 92,  92, 92, 92, 92, 92,  92, 92, 92, 92, 92,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,
};
int data12[] = {
     5, 5, 5, 5, 5,  5, 5, 5,74,23, 23,23,23,23,103, 103,103,103,103,103,
     5, 5, 5, 5, 5,  5, 5, 5,74,23, 23,23,23,23,103, 103,103,103,103,103,
     5, 5, 5, 5, 5,  5, 5, 5,74,23, 23,23,23,23,103, 103,103,103,103,103,
     5, 5, 5, 5, 5,  5, 5, 5,74,23, 23,23,23,23,103, 103,103,103,103,103,
     5, 5, 5, 5, 5,  5, 5, 5,74,23, 23,23,23,23,103, 103,103,103,103,103,
     5, 5, 5, 5, 5,  5, 5, 5,74,23, 23,23,23,23,103, 103,103,103,103,103,
     5, 5, 5, 5, 5,  5, 5, 5,74,23, 23,23,23,23,103, 103,103,103,103,103,
     5, 5, 5, 5, 5,  5, 5, 5,74,23, 23,23,23,23,103, 103,103,103,103,103,
    81,81,81,81,81, 81, 5, 5,74,23, 23,23,23,23,103, 103,103,103,103,103,
    91,91,91,91,91, 91, 5, 5,84,23, 23,23,23,23,103, 103,103,103,103,103,
    23,23,23,23,23, 23,23,23,23,23, 23,23,23,23, 23,  23, 23, 23, 23, 23,
    23,23,23,23,23, 23,23,23,23,23, 23,23,23,23, 23,  23, 23, 23, 23, 23,
    23,23,23,23,23, 23,23,23,23,23, 23,23,23,23, 23,  23, 23, 23, 23, 23,
    23,23,23,23,23, 23,23,23,23,23, 23,23,23,23, 23,  23, 23, 23, 23, 23,
    23,23,23,23,23, 23,23,23,23,23, 23,23,23,23, 23,  23, 23, 23, 23, 23,
};
int data13[] = {
    103, 97, 98, 98, 98,  98, 98, 98, 98, 98,  99,103,103,103,103, 103,23,23,23,23,
    103, 97, 98, 98, 98,  98, 98, 98, 98, 98,  99,103,103,103,103, 103,23,23,23,23,
    103,107, 98, 98, 98,  98, 98, 98, 98, 98, 109,103,103,103,103, 103,23,23,23,23,
    103,103,107, 98, 98,  98, 98, 98, 98,109, 103,103,103,103,103, 103,23,23,23,23,
    103,103,103,107,108, 108,108,108,109,103, 103,103,103,103,103, 103,23,23,23,23,
    103,103,103,103,103, 103,103,103,103,103, 103,103,103,103,103, 103,23,23,23,23,
    103,103,103,103,103, 103,103,103,103,103, 103,103,103,103,103, 103,23,23,23,23,
    103,103,103,103,103, 103,103,103,103,103, 103,103,103,103,103, 103,23,23,23,23,
    103,103,103,103,103, 103,103,103,103,103, 103,103,103,103,103, 103,23,23,23,23,
    103,103,103,103,103, 103,103,103,103,103, 103,103,103,103,103, 103,23,23,23,23,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23,23,23,23,23,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23,23,23,23,23,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23,23,23,23,23,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23,23,23,23,23,
     23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23, 23, 23, 23, 23,  23,23,23,23,23,
};
int data14[] = {
     23,23,25,25,25, 25,25,25,25,25, 25,25,25,25,25, 25,25,25,25,25,
     23,23,56,65,65, 65,54,65,65,65, 65,54,65,65,65, 65,54,65,65,65,
     23,23, 5, 5, 5,  5, 5, 5, 5, 5,  5, 5, 5, 5, 5,  5, 5, 5, 5, 5,
     23,23, 5, 5, 5,  5, 5, 5, 5, 5,  5, 5, 5, 5, 5,  5, 5, 5, 5, 5,
     23,23, 5, 5, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 5, 5,

     23,23, 5, 5, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 5, 5,
     23,23, 5, 5, 8,  8,98,98,98,98, 98,98,98,98,98, 98, 8, 8, 5, 5,
     23,23,23,23, 8,  8,98,98,98,98, 98,98,98,98,98, 98, 8, 8, 5, 5,
     23,23,23,23, 8,  8,98,98,98,98, 98,98,98,98,98, 98, 8, 8, 5, 5,
     23,23,23,23, 8,  8,98,98,98, 5,  5, 5, 5,98,98, 98, 8, 8, 5, 5,

     23,23,23,23, 8,  8,98,98,98, 5,  5, 5, 5,98,98, 98, 8, 8, 5, 5,
     23,23, 5, 5, 8,  8,98,98,98, 5,  5, 5, 5,98,98, 98, 8, 8, 5, 5,
     23,23, 5, 5, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 5, 5,
     23,23, 5, 5, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 5, 5,
     23,23, 5, 5, 5,  5, 5, 5, 5, 5,  5, 5, 5, 5, 5,  5, 5, 5, 5, 5,
};
int data15[] = {
     17,  18,  18,  18,  19,    46,  46,  46,  46,  46,    46,  46,  46,  46,  46,     46,  46,  46,  46,  46,
      17,  18,  18,  18,  19,     4,   4,   4,   4,   4,     4,   4,   4,   4,   4,      4,   4,   4,   4,   4,
      17,  18,  18,  18,  19,     4,   4,   4,   4,   4,     4,   4,   4,   4,   4,      4,   4,   4,   4,   4,
      17,  18,  18,  18,  19,     4,   4,   4,   4,   4,     4,   4,   4,   4,   4,      4,   4,   4,   4,   4,
      17,  18,  18,  18,  19,     4,   4,   4,   4,   4,     4,   4,   4,   4,   4,      4,   4,   4,   4 ,  4,
     112, 113, 113, 113, 114,     4,   4,   4,   4,   4,     4,   4,   4,   4,   4,      4,   4,   4,   4,   4,
      23,  23,  23,  23,  23,     4,   4,   4,   4,   4,     4,   4,   4,   4,   4,      4,   4,   4,   4,   4,
      23,  23,  23,  23,  23,     4,   4,  40,  41,   4,     4,   4,   4,   4,   4,      4,  40,  41,   4,   4,
      23,  23,  23,  23,  23,     4,   4,  50,  51,   4,     4,   4,   4,   4,   4,      4,  50,  51,   4,   4,
      32, 110, 110, 110, 110,   110, 110, 110, 110, 110,   110, 110, 110, 110, 110,    110, 110, 110, 110, 110,
      42, 111, 111, 111, 111,   111, 111, 111, 111, 111,   111, 111, 111, 111, 111,    111, 111, 111, 111, 111,
      23,  23,  23,  23,  23,    23,  23,  23,  23,  23,    23,  23,  23,  23,  23,     23,  23,  23,  23,  23,
      23,  23,  23,  23,  23,    23,  23,  23,  23,  23,    23,  23,  23,  23,  23,     23,  23,  23,  23,  23,
      23,  23,  23,  23,  23,    23,  23,  23,  23,  23,    23,  23,  23,  23,  23,     23,  23,  23,  23,  23,
      46,  46,  46,  46,  46,    46,  46,  46,  46,  46,    46,  46,  46,  46,  46,     46,  46,  46,  46,  46,
};
int data16[300] = {
     46,  46,  46,  46,  46,    46,  46,  46,  46,  46,    46,  46,  46,  46,  46,     46,  46,  46,  46,  46,
       4,   4,   4,   4,   4,     4,   4,   4,   4,   4,     4,   4,   4,   4,   4,      4,   4,   4,   4,   4,
       4,   4,   4,   4,   4,     4,   4,   4,   4,   4,     4,   4,   4,   4,   4,      4,   4,   4,   4,   4,
       4,   4,   4,   4,   4,     4,   4,   4,   4,   4,     4,   4,   4,   4,   4,      4,   4,   4,   4,   4,
       4,   4,   4,   4,   4,     4,   4,   4,   4,   4,     4,   4,   4,   4,   4,      4,   4,   4,   4 ,  4,
       4,   4,   4,   4,   4,     4,   4,   4,   4,   4,     4,   4,   4,   4,   4,      4,   4,   4,   4,   4,
       4,   4,   4,   4,   4,     4,   4,   4,   4,   4,     4,   4,   4,   4,   4,      4,   4,   4,   4,   4,
       4,   4,   4,   4,   4,     4,   4,   4,   4,   4,     4,   4,   4,   4,   4,      4,   4,   4,   4,   4,
       4,   4,   4,   4,   4,     4,   4,   4,   4,   4,     4,   4,   4,   4,   4,      4,   4,   4,   4,   4,
     110, 110, 110, 110, 110,   110, 110, 110, 110, 110,   110, 110, 110, 110, 110,    110, 110, 110, 110, 110,
     111, 111, 111, 111, 111,   111, 111, 111, 111, 111,   111, 111, 111, 111, 111,    111, 111, 111, 111, 111,
      23,  23,  23,  23,  23,    23,  23,  23,  23,  23,    23,  23,  23,  23,  23,     23,  23,  23,  23,  23,
      23,  23,  23,  23,  23,    23,  23,  23,  23,  23,    23,  23,  23,  23,  23,     23,  23,  23,  23,  23,
      23,  23,  23,  23,  23,    23,  23,  23,  23,  23,    23,  23,  23,  23,  23,     23,  23,  23,  23,  23,
      46,  46,  46,  46,  46,    46,  46,  46,  46,  46,    46,  46,  46,  46,  46,     46,  46,  46,  46,  46,
};
int data17[300] = {
      46,  46,  46,  46,  46,    46,  46,  46,  46,  46,    46,  46,  46,  46,  46,     46,  46,  46,  46,  46,
       4,   4,   4,   4,   4,     4,   4,   4,   4,   4,     4,   4,   4,   4,   4,     26,  23,  23,  23,  23,
       4,   4,   4,   4,   4,     4,   4,   4,   4,   4,     4,   4,   4,   4,   4,     26,  23,  23,  23,  23,
       4,   4,   4,   4,   4,     4,   4,   4,   4,   4,     4,   4,   4,   4,   4,     26,  23,  23,  23,  23,
       4,   4,   4,   4,   4,     4,   4,   4,   4,   4,     4,   4,   4,   4,   4,     26,  23,  23,  23 , 23,
       4,   4,   4,   4,   4,     4,   4,   4,   4,   4,     4,   4,   4,   4,   4,     26,  23,  23,  23,  23,
       4,   4,   4,   4,   4,     4,   4,   4,   4,   4,     4,   4,   4,   4,   4,     26,  23,  23,  23,  23,
       4,   4,   4,   4,   4,     4,   4,   4,   4,   4,     4,  40,  41,   4,   4,     26,  23,  23,  23,  23,
       4,   4,   4,   4,   4,     4,   4,   4,   4,   4,     4,  50,  51,   4,   4,     26,  23,  23,  23,  23,
     110, 110, 110, 110, 110,   110, 110, 110, 110, 110,   110, 110, 110, 110, 110,     14,  33,  23,  23,  23,
     111, 111, 111, 111, 111,   111, 111, 111, 111, 111,   111, 111, 111, 111, 111,     24,  43,  23,  23,  23,
      23,  23,  23,  23,  23,    23,  23,  23,  23,  23,    23,  23,  23,  23,  23,    115,  23,  23,  23,  23,
      23,  23,  23,  23,  23,    23,  23,  23,  23,  23,    23,  23,  23,  23,  23,    115,  23,  23,  23,  23,
      23,  23,  23,  23,  23,    23,  23,  23,  23,  23,    23,  23,  23,  23,  23,    115,  23,  23,  23,  23,
      46,  46,  46,  46,  46,    46,  46,  46,  46,  46,    46,  46,  46,  46,  46,     46,  23,  23,  23,  23,
};
int data18[300] = {
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     4, 4, 4, 4, 4,  4, 4, 4, 4, 4,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     4, 4, 4, 4, 4,  4, 4, 4, 4, 4,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     4, 4, 4, 4, 4,  4, 4, 4, 4, 4,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     7, 8, 8, 8, 9,  7, 8, 8, 8, 9,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     17, 18, 18, 18, 19,  100, 48, 48, 48, 101,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     17, 18, 18, 18, 19,  100, 48, 48, 48, 101,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
};
int data19[300] = {
     7, 8, 8, 8, 9,  4, 4, 4, 4, 4,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     17, 18, 18, 18, 19,  4, 4, 4, 4, 4,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     17, 18, 18, 18, 19,  4, 4, 4, 4, 4,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     17, 18, 18, 18, 19,  4, 4, 4, 4, 4,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     17, 18, 18, 18, 19,  38, 38, 38, 38, 38,  4, 4, 0, 1, 4,  4, 4, 4, 4, 4,
     17, 18, 18, 18, 19,  37, 38, 38, 38, 39,  4, 4, 10, 11, 4,  4, 4, 4, 4, 4,
     27, 28, 28, 28, 29,  47, 48, 48, 48, 49,  4, 4, 20, 21, 4,  4, 4, 4, 4, 4,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
};
int data20[300] = {
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     4, 4, 4, 0, 1,  4, 4, 4, 4, 0,  1, 4, 4, 4, 4,  4, 4, 4, 0, 1,
     4, 4, 4, 10, 11,  4, 4, 4, 4, 10,  11, 4, 4, 4, 4,  4, 4, 4, 10, 11,
     4, 4, 4, 20, 21,  4, 4, 4, 4, 20,  21, 4, 4, 4, 4,  4, 4, 4, 20, 21,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
};
int data21[300] = {
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     4, 4, 0, 1, 4,  4, 4, 4, 4, 4,  4, 4, 4, 4, 4,  4, 0, 1, 4, 4,
     4, 4, 10, 11, 4,  4, 4, 4, 4, 4,  4, 4, 4, 4, 4,  4, 10, 11, 4, 4,
     4, 4, 20, 21, 4,  4, 4, 4, 4, 4,  4, 4, 4, 4, 4,  4, 20, 21, 4, 4,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
};
int data22[300] = {
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     4, 4, 4, 4, 4,  4, 4, 4, 4, 4,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     4, 4, 4, 4, 4,  4, 4, 4, 4, 4,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     4, 4, 4, 4, 4,  4, 4, 4, 4, 4,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     7, 8, 8, 8, 9,  7, 8, 8, 8, 9,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     17, 18, 18, 18, 19,  100, 48, 48, 48, 101,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     17, 18, 18, 18, 19,  100, 48, 48, 48, 101,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
};
int data23[300] = {
     7, 8, 8, 8, 9,  4, 4, 4, 4, 4,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     17, 18, 18, 18, 19,  4, 4, 4, 4, 4,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     17, 18, 18, 18, 19,  4, 4, 4, 4, 4,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     17, 18, 18, 18, 19,  4, 4, 4, 4, 4,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     17, 18, 18, 18, 19,  38, 38, 38, 38, 38,  4, 4, 0, 1, 4,  4, 4, 4, 4, 4,
     17, 18, 18, 18, 19,  37, 38, 38, 38, 39,  4, 4, 10, 11, 4,  4, 4, 4, 4, 4,
     27, 28, 28, 28, 29,  47, 48, 48, 48, 49,  4, 4, 20, 21, 4,  4, 4, 4, 4, 4,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
};
int data24[300] = {
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     4, 4, 4, 0, 1,  4, 4, 4, 4, 0,  1, 4, 4, 4, 4,  4, 4, 4, 0, 1,
     4, 4, 4, 10, 11,  4, 4, 4, 4, 10,  11, 4, 4, 4, 4,  4, 4, 4, 10, 11,
     4, 4, 4, 20, 21,  4, 4, 4, 4, 20,  21, 4, 4, 4, 4,  4, 4, 4, 20, 21,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
};
int data25[300] = {
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     4, 4, 0, 1, 4,  4, 4, 4, 4, 4,  4, 4, 4, 4, 4,  4, 0, 1, 4, 4,
     4, 4, 10, 11, 4,  4, 4, 4, 4, 4,  4, 4, 4, 4, 4,  4, 10, 11, 4, 4,
     4, 4, 20, 21, 4,  4, 4, 4, 4, 4,  4, 4, 4, 4, 4,  4, 20, 21, 4, 4,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
     46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,  46, 46, 46, 46, 46,
};
int data31[300] = {
     4, 4, 2, 3, 2,  3, 4, 4, 2, 3,  2, 3, 4, 4, 2,  3, 2, 3, 4, 4,
     4, 4,12,13,12, 13, 4, 4,12,13, 12,13, 4, 4,12, 13,12,13, 4, 4,
     4, 4, 4, 4, 4,  4, 4, 4, 4, 4,  4, 4, 4, 4, 4,  4, 4, 4, 4, 4,
    61, 8, 8, 8, 8,  8, 8,61,62, 8, 61,62, 8,61,62,  8,61,62, 8, 8,
    71, 8, 8, 8,61, 62, 8,71,72, 8, 71,72, 8,71,72,  8,71,72, 8, 8,
     8, 8, 8, 8,71, 72, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8,61, 62, 8,61,62, 8,  8, 8, 8,61,62,  8,61,62, 8, 8,
     8, 8, 8, 8,71, 72, 8,71,72, 8, 61,62, 8,71,72,  8,71,72, 8, 8,
     8, 8,63, 62, 8,  8, 8, 8, 8, 8, 71,72, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8,73, 72,61, 62, 8,61,62, 8, 61,62, 8,61,62,  8,61,62, 8, 8,
     8, 8, 8, 8,71, 72, 8,71,72, 8, 71,72, 8,71,72,  8,71,72, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8,62, 8, 8,
     8, 8, 8, 8,61, 62, 8,61,62, 8, 61,62, 8,61, 8,  8, 8,72, 8, 8,
     8, 8, 8, 8,71, 72, 8,71,72, 8, 71,72, 8,71, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
}; int data32[300] = {
     4, 4, 2, 3, 2,  3, 4, 4, 2, 3,  2, 3, 4, 4, 2,  3, 2, 3, 4, 4,
     4, 4,12,13,12, 13, 4, 4,12,13, 12,13, 4, 4,12, 13,12,13, 4, 4,
     4, 4, 4, 4, 4,  4, 4, 4, 4, 4,  4, 4, 4, 4, 4,  4, 4, 4, 4, 4,
     8, 8, 8, 8,61, 62, 8,61,62, 8, 61, 8, 8,61,62,  8,61,62, 8, 8,
     8, 8, 8, 8,71, 72, 8,71,72, 8, 71,62, 8,71,72,  8,71,72, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8,72, 8, 8, 8,  8, 8,61,62, 8,
     8, 8, 8, 8,61, 62, 8,61,62, 8, 61,62, 8,61,62,  8, 8,71,72, 8,
     8, 8, 8, 8,71, 72, 8,71,72, 8, 71,72, 8,71,72,  8, 8, 8, 8, 8,
     8, 8,63, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8,73, 8,61, 62, 8, 8, 8, 8, 61,62, 8,61,62,  8,61,62, 8, 8,
     8, 8, 8, 8,71, 72, 8,61,62, 8, 71,72, 8,71,72,  8,71,72,61, 8,
     8, 8, 8, 8, 8,  8, 8,71,72, 8,  8, 8, 8, 8, 8,  8, 8, 8,71, 8,
     8, 8, 8, 8,61,  8,62,61,62, 8, 61,62, 8,61,62,  8, 8, 8, 8, 8,
     8, 8, 8, 8,71,  8,72,71,72, 8, 71,72, 8,71,72, 62, 8, 8, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8, 72, 8, 8, 8, 8,
}; int data33[300] = {
     4, 4, 2, 3, 2,  3, 4, 4, 2, 3,  2, 3, 4, 4, 2,  3, 2, 3, 4, 4,
     4, 4,12,13,12, 13, 4, 4,12,13, 12,13, 4, 4,12, 13,12,13, 4, 4,
     4, 4, 4, 4, 4,  4, 4, 4, 4, 4,  4, 4, 4, 4, 4,  4, 4, 4, 4, 4,
     8, 8, 8, 8, 8,  8, 8,61,62, 8, 61,62, 8,61,62,  8,61,62, 8, 8,
     8, 8, 8, 8,61, 62, 8,71,72, 8, 71,72, 8,71,72,  8,71,72, 8, 8,
     8, 8, 8, 8,71, 72, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8,61, 62, 8,61, 8, 8, 61,62, 8,61,62,  8,61,62, 8, 8,
     8, 8, 8, 8,71, 72, 8,71, 8, 8, 71,72, 8,71,72,  8,71,72, 8, 8,
     8, 8,63, 8, 8,  8, 8, 8, 8,62,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8,73, 8,61, 62, 8,61,62,72, 61,62, 8,61,62,  8,61,62, 8, 8,
     8, 8, 8, 8,71, 72, 8,71,72, 8, 71,72, 8,71,72,  8,71,72, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8,61, 62, 8,61,62, 8, 61,62, 8,61,62,  8, 8, 8,61,61,
     8, 8, 8, 8,71, 72, 8,71,72, 8, 71,72, 8,71,72,  8, 8, 8,71,71,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
}; int data34[300] = {
     4, 4, 2, 3, 2,  3, 4, 4, 2, 3,  2, 3, 4, 4, 2,  3, 2, 3, 4, 4,
     4, 4,12,13,12, 13, 4, 4,12,13, 12,13, 4, 4,12, 13,12,13, 4, 4,
     4, 4, 4, 4, 4,  4, 4, 4, 4, 4,  4, 4, 4, 4, 4,  4, 4, 4, 4, 4,
     8, 8, 8, 8,61, 62, 8,61,62, 8, 61, 8, 8,61,62,  8,61,62, 8, 8,
     8, 8, 8, 8,71, 72, 8,71,72, 8, 71,62, 8,71,72,  8,71,72, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8,72, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8,61, 62, 8,61,62, 8, 61,62, 8,61,62,  8, 8,61,62, 8,
     8, 8, 8, 8,71, 72, 8,71,72, 8, 71,72, 8,71,72,  8, 8,71,72, 8,
     8, 8,63, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8,73, 8,61, 62, 8,61,62, 8, 61,62, 8,61,62,  8,61,62, 8, 8,
     8, 8, 8, 8,71, 72, 8,71,72, 8, 71,72, 8,71,72,  8,71,72, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8,61,  8,62,61,62, 8, 61,62, 8,61,62,  8,61,62, 8, 8,
     8, 8, 8, 8,71,  8,72,71,72, 8, 71,72, 8,71,72,  8,71,72, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
}; int data35[300] = {
     4, 4, 0, 1, 4,  2, 3, 2, 3, 4,  4, 2, 3, 2, 3,  4, 0, 1, 4, 4,
     4, 4,10,11, 4, 12,13,12,13, 4,  4,12,13,12,13,  4,10,11, 4, 4,
     4, 4,20,21, 4,  4, 4, 4, 4, 4,  4, 4, 4, 4, 4,  4,20,21, 4, 4,
     8, 8, 8, 8,61, 62, 8,61,62, 8, 61,62, 8,61,62,  8, 8, 8,61,61,
     8, 8, 8, 8,71, 72, 8,71,72, 8, 71,72, 8,71,72,  8, 8, 8,71,71,
     8, 8, 8, 8, 8, 62, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8,61, 72, 8,61,62, 8, 61,62, 8,61,62,  8,61,62, 8, 8,
     8, 8, 8, 8,71,  8, 8,71,72, 8, 71,72, 8,71,72,  8,71,72, 8, 8,
     8, 8,63, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8,73, 8,61, 62, 8,61,62, 8, 61,62, 8,61,62,  8,61,62, 8, 8,
     8, 8, 8, 8,71, 72, 8,71,72, 8, 71,72, 8,71,72,  8,71,72, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
     8, 8, 8, 8,61, 62, 8,61,62, 8, 61,62, 8,61,62,  8, 8, 8, 8, 8,
     8, 8, 8, 8,71, 72, 8,71,72, 8, 71,72, 8,71,72,  8, 8, 8, 8, 8,
     8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,  8, 8, 8, 8, 8,
};
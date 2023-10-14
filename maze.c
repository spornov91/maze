#include <stdio.h>
#include <string>
const int mazeRows = 9;
const int mazeColumns = 9;

char maze_p1[mazeRows][mazeColumns + 1] = {
    "#*#######",
    "#*  #   #",
    "#*### # #",
    "#*#***# #",
    "#*#*#*###",
    "#***#*# #",
    "# ###*# #",
    "#   #***#",
    "#######*#",
};

const char wall = '#';
const char freep = ' ';
const char dude = '*';

int x,s;
std::string str;

char get(int x, int y) {
    if (x >= mazeColumns || y >= mazeRows) return wall;
    return maze_p1[y][x];
}

int set(int x, int y) {
    if (x <= 0 || x >= mazeColumns || y >= mazeRows) return wall;
    maze_p1[y][x] = ' ';
    return 0;
}

int set1(int x, int y) {
    if (x <= 0 || x >= mazeColumns || y >= mazeRows) return wall;
    maze_p1[y][x] = '+';
    return 0;
}

int set2(int x, int y) {
    if (x <= 0 || x >= mazeColumns || y >= mazeRows) return wall;
    maze_p1[y][x] = '-';
    return 0;
}

int clr_maze(){
    for (int y = 0; y < mazeRows; y++) {
    str = maze_p1[y];
    x = str.find(dude);
    //s = str.size();
    //set(x,y);
    for (int z = 0; z < mazeColumns-1; z++){
    if (get(x - z, y) == dude) set(x-z,y);
    if (get(x + z, y) == dude) set(x+z,y);
    }}
    return 0;
}

int wall_maze(int z, int y,int x){
    // proveryi povoroti
    // sapominay puti
    // schitay povoroti
    //
    int p = 0;
    // 0 -> left and right
    // 0 -> up and down
    if(
       get(x,y) == freep
    ){
    if(get(x+1,y) == freep) p++;
    if(get(x-1,y) == freep) p++;
    if(get(x,y-1) == freep) p++;
    if(get(x,y+1) == freep) p++;
    printf("x-%i, y-%i, p-%i\n", x,y,p);
    }
    //left+right
    if (get(x+z-1,y) == wall && 
        get(x+z+1,y) == wall
        //get(x+z,y+1) == wall
    ){
        y= y+1;
        //set2(x+z,y);
    }
    
    // left to right ok!
    if (get(x+z+1,y) == wall && 
        get(x+z,y-1) == wall &&
        get(x+z,y+1) == wall
    ){
        x= x-1;
    }
    // right -> left
    if(
        get(x+z-1,y) == wall &&
        get(x+z,y-1) == wall &&
        get(x+z,y+1) == wall
    ) {
        x= x+1;
        //set2(x+z,y);
    }
    
    //if (get(x-z, y) == freep) set1(x-z,y);
    //if (get(x+z, y) == freep) set2(x+z,y);
    return 0;
}

int run_maze(){
  int x = 1;
    for (int y = 0; y < mazeRows; y++) {
    for (int z = 0; z < mazeColumns-1; z++){
    //for (int x = 0; x < 5-1; x++){
        //0-0,0
        //1-0,0
  
    wall_maze(x,y,z);
    }}
    return 0;
}

void printDaMaze() {
    for (int Y = 0; Y < mazeRows; Y++) {
        printf("%s\n", maze_p1[Y]);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    //run_maze(0,0,0);
    clr_maze();
    run_maze();
    printDaMaze();
    printf("Solved!\n");

    return 0;
}
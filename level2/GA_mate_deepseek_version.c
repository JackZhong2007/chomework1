//0 is wall;1 is node;2 is can be chosen road;3 is road;4 is can not be chosen road
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#define ROWS 25
#define COLS 101

int mate[ROWS][COLS];
int can_be_chosen_number;
int flagmax;

typedef struct {
    int x, y;
} Position;

Position can_be_chosen_list[ROWS * COLS]; // 存储所有可选择的道路位置

void mate_initialization();
void print_mate();
void generate_canBeChosen_road(int line, int column);
bool generate_mate();

void mate_initialization() {
    flagmax = 0;
    can_be_chosen_number = 0;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(i % 2 == 1 && j % 2 == 1) {
                mate[i][j] = 1; // node
                flagmax++;
            } else {
                mate[i][j] = 0; // wall
            }
        }
    }
    mate[1][1] = 3; // start point
    flagmax--; // 起始点已访问
    generate_canBeChosen_road(1, 1);
}
void print_mate() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            switch(mate[i][j]) {
                case 0: printf("0"); break; // wall
                case 1: printf("·"); break; // node
                case 2: printf("?"); break; // can be chosen
                case 3: printf(" "); break; // road
                case 4: printf("x"); break; // cannot be chosen
            }
        }
        printf("\n");
    }
}
void generate_canBeChosen_road(int line, int column) {
    // 上
    if(line > 1 && mate[line-1][column] == 0) {
        mate[line-1][column] = 2;
        can_be_chosen_list[can_be_chosen_number].x = line-1;
        can_be_chosen_list[can_be_chosen_number].y = column;
        can_be_chosen_number++;
    }
    // 下
    if(line < ROWS-2 && mate[line+1][column] == 0) {
        mate[line+1][column] = 2;
        can_be_chosen_list[can_be_chosen_number].x = line+1;
        can_be_chosen_list[can_be_chosen_number].y = column;
        can_be_chosen_number++;
    }
    // 左
    if(column > 1 && mate[line][column-1] == 0) {
        mate[line][column-1] = 2;
        can_be_chosen_list[can_be_chosen_number].x = line;
        can_be_chosen_list[can_be_chosen_number].y = column-1;
        can_be_chosen_number++;
    }
    // 右
    if(column < COLS-2 && mate[line][column+1] == 0) {
        mate[line][column+1] = 2;
        can_be_chosen_list[can_be_chosen_number].x = line;
        can_be_chosen_list[can_be_chosen_number].y = column+1;
        can_be_chosen_number++;
    }
}
bool generate_mate() {
    if (flagmax <= 0 || can_be_chosen_number <= 0) {
        return false; // 终止条件：没有未访问的节点或没有可选择的道路
    }
    
    int position = rand() % can_be_chosen_number;
    int road_x = can_be_chosen_list[position].x;
    int road_y = can_be_chosen_list[position].y;
    
    // 检查四个方向是否有未访问的节点
    Position new_node = {-1, -1};
    
    // 上
    if(road_x > 1 && mate[road_x-1][road_y] == 1) {
        new_node.x = road_x-1;
        new_node.y = road_y;
    }
    // 下
    else if(road_x < ROWS-2 && mate[road_x+1][road_y] == 1) {
        new_node.x = road_x+1;
        new_node.y = road_y;
    }
    // 左
    else if(road_y > 1 && mate[road_x][road_y-1] == 1) {
        new_node.x = road_x;
        new_node.y = road_y-1;
    }
    // 右
    else if(road_y < COLS-2 && mate[road_x][road_y+1] == 1) {
        new_node.x = road_x;
        new_node.y = road_y+1;
    }
    
    if(new_node.x != -1 && new_node.y != -1) {
        // 打通道路和节点
        mate[road_x][road_y] = 3;
        mate[new_node.x][new_node.y] = 3;
        flagmax--;
        
        // 移除已选择的道路
        can_be_chosen_list[position] = can_be_chosen_list[can_be_chosen_number-1];
        can_be_chosen_number--;
        
        // 生成新的可选择道路
        generate_canBeChosen_road(new_node.x, new_node.y);
        
        return true;
    } else {
        // 如果没有找到合适的节点，标记为不可选择
        mate[road_x][road_y] = 4;
        can_be_chosen_list[position] = can_be_chosen_list[can_be_chosen_number-1];
        can_be_chosen_number--;
        return true;
    }
}

int main() {
    srand((unsigned)time(NULL));
    mate_initialization();
    
    while(flagmax > 0 && can_be_chosen_number > 0) {
        if(!generate_mate()) {
            break;
        }
    }
    
    print_mate();
    printf("\nRemaining nodes: %d\n", flagmax);
    printf("Remaining choices: %d\n", can_be_chosen_number);
    
    return 0;
}
/*
 * @Descripttion: stack
 * @version: V1.00
 * @Company: SUNRI
 * @Author: Allen zhuang
 * @Date: 2020-09-22 14:01:22
 * @LastEditors: Allen Zhuang
 * @LastEditTime: 2020-09-24 17:50:37
 */
#include"mystack.h"
#include <stack>

typedef  long   __int64;

//递归实现
void convert_recursion(myStack<char>& S, __int64 n, int base)
{
    static char digit[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    if(n > 0){
        convert_recursion(S, n/base, base);
        S.push(digit[n%base]);
    }
}

//迭代实现
void convert_iteration(myStack<char>& S, __int64 n, int base)
{
    static char digit[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    while(n > 0){
        int remainder = (int)(n%base);
        S.push(digit[remainder]);
        n = n/base;
    }
}

//栈混洗判断表达式括号是否合法
bool paren(const char exp[])
{
    myStack<char> S;
    for(int i = 0; exp[i]; i++){
        switch (exp[i]){
        case '(':
        case '[':
        case '{':
            S.push(exp[i]);
            break;
        case ')':
            if(S.empty() || '(' != S.pop()) return false;
            break;
        case ']':
            if(S.empty() || '[' != S.pop()) return false;
            break;
        case '}':
            if(S.empty() || '{' != S.pop()) return false;
            break;
        default:
            break;
        }
    }
    return S.empty();
}

//八皇后
struct Queen    //皇后类
{
    int _x;
    int _y;
    
    Queen(int x, int y):_x(x),_y(y) {}

    bool operator==(const Queen& q) const {
        return  (_x == q._x)
            || (_y == q._y)
            || (_x + _y == q._x + q._y)
            || (_x  - _y == q._x  - q._y);
    }

    bool operator!=(const Queen& q) const{
        return !(*this == q);
    }
};

//N皇后算法
void placeQueen(int N){
    myStack<Queen> solu;
    Queen q(0, 0);
    int nCheck = 0;
    int nSolu = 0;
    do{
        if (N <= q._y || N <= solu.size()){
            q = solu.pop();
            q._y++;
        }else{
            while(q._y < N && (0 <= solu.find(q))){
                q._y++;
                nCheck++;
            }
            if(q._y < N){
                solu.push(q);
                if(solu.size() >= N){
                    nSolu++;
                }
                q._x++;
                q._y=0;
            }
        }
        
    } while (0 < q._x || q._y < N);
}

//迷宫寻径问题
typedef enum {AVAILBLE, ROUTE, BACKTRACKED, WALL} Status;//格点状态
typedef enum {UNKNOWN, EAST, SOUTH, WEST, NORTH, NO_WAY} ESWN;//方向
inline ESWN nextESWN(ESWN eswn){ return ESWN(eswn+1); }//下个方向
struct Cell  //迷宫格点
{
    int x;
    int y;
    Status status;
    ESWN outgoing;
    ESWN incomming;
};
#define LABY_MAX 24 //最大迷宫数
Cell laby[LABY_MAX][LABY_MAX]; //迷宫
//邻格查询
inline Cell* neighbor(Cell* cell){
    switch (cell->outgoing){
    case EAST:
        return cell + 1;
        break;
    case SOUTH:
        return cell + LABY_MAX;
        break;
    case WEST:
        return cell - 1;
        break;
    case NORTH:
        return cell - LABY_MAX;
        break;
    default:
        return cell;
        break;
    }
}
//邻格转入
inline Cell* advance(Cell* cell){
    Cell* next;
    switch (cell->outgoing){
    case EAST:
        next = cell + 1;
        next->incomming = WEST;
        break;
    case SOUTH:
        next = cell + LABY_MAX;
        next->incomming = NORTH;
        break;
    case WEST:
        next = cell - 1;
        next->incomming = EAST;
        break;
    case NORTH:
        next = cell - LABY_MAX;
        next->incomming = SOUTH;
        break;
    default:
        next = cell;
        next->incomming = UNKNOWN;
        break;
    }
    return next;
}

bool labyrinth(Cell laby[LABY_MAX][LABY_MAX], Cell* s, Cell* t){
    if(s->status != AVAILBLE || t->status != AVAILBLE) return false;
    stack<Cell*> path;
    s->incomming = UNKNOWN;
    s->status = ROUTE;
    path.push(s);
    do{
        Cell* c = path.top();
        if(c == t) return true;
        //一一检查所有的方向
        while((c->outgoing = nextESWN(c->outgoing)) > NO_WAY){
            if(neighbor(c)->status = AVAILBLE) break;//试图找到尚未尝试的方向
        }
        if(c->outgoing >= NO_WAY){
            c->status = BACKTRACKED;
            c = path.top();//向后回溯一步
            path.pop();
        }else{
            path.push(c = advance(c));//向前试探一步
            c->outgoing = UNKNOWN;
            c->status = ROUTE;
        }
    }while(!path.empty());
    return false;
}
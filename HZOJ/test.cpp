/*************************************************************************
	> File Name: test.cpp
	> Author: weier 
	> Mail: 1931248856@qq.com
	> Created Time: 2020年04月29日 星期三 21时52分37秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
#include<cmath>
#include <stdlib.h>
using namespace std;
typedef struct node{
    int number;
    struct node *next;
} Node;

Node  *create_node( int new_number){
    Node *temp_node;
    temp_node = (Node *) malloc ( sizeof(Node));
    temp_node -> number = new_number;
    temp_node->next = NULL;
    return temp_node;
}

int main() {
    return 0;
}

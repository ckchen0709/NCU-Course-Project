//
//  MRT.h
//  MRT
//
//  Created by Jerry Lee on 2018/6/14.
//  Copyright © 2018年 Jerry Lee. All rights reserved.
//

#ifndef MRT_h
#define MRT_h

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define STA 108

/* define structure type */
typedef struct station{
    unsigned int index;
    unsigned int line;
    struct node *next;
}station;

typedef struct node{
    unsigned int index;
    unsigned int time;
    float distance;
    struct node *next;
}node;

typedef struct quene{
    int index;
    int pre;
    struct quene *next;
}quene;

/*define functions */
station* readstation(FILE *fp);
void MRT(int *start, int *end);
/* apply dijkstra's algorithm to find the shortest path*/
void ShortestPath(station *stop,int start, int end, float d[], int pre[], int time[]);
int FindPrice(float distance);
void PrintPath(int end, int pre[]);

#endif /* MRT_h */

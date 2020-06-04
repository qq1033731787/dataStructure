//
// Created by Administrator on 2020/6/4.
//

#include <graph.h>
#include <gtest/gtest.h>
#include <algorithm>
Graph* graph;

bool cmp(int a, int b){
    return graph->getDegree(a) > graph->getDegree(b);
}

int mapDye(){
    bool records[graph->vertexNum] = {false};
    int sorts[graph->vertexNum];
    for(int i = 0;i < graph->vertexNum;i++){
        sorts[i] = i;
    }

    int colors = 0;
    int curDyedNum = 0;
    std::sort(sorts, sorts + graph->vertexNum);

    records[sorts[0]] = true;
    int curVertex = sorts[0];
    while(curDyedNum < graph->vertexNum){
        curDyedNum++;
        colors++;
        for(int i = 0;i < graph->vertexNum; i++){
            if(!graph->isEdge(curVertex, i)){
                records[i] = true;
                curDyedNum++;
            }
        }

        for(int i = 0;i < graph->vertexNum; i++){
            if(!records[sorts[i]]){
                records[sorts[i]] = true;
                curVertex = sorts[i];
            }
        }
    }
    return colors;
}

TEST(Graph, dye){
    graph = new Graphm(5);
    graph->setEdge(0, 1, 1);
    graph->setEdge(1, 2, 1);
    graph->setEdge(0, 4, 1);
    graph->setEdge(1, 3, 1);
    graph->setEdge(3, 4, 1);

    graph->setEdge(1, 0, 1);
    graph->setEdge(2, 1, 1);
    graph->setEdge(4, 0, 1);
    graph->setEdge(3, 1, 1);
    graph->setEdge(4, 3, 1);

    ASSERT_EQ(mapDye(), 2);
}

int main(){
    testing::InitGoogleTest();
    std::cout<< RUN_ALL_TESTS();
}
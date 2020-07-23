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
    std::vector<int> vertexs;
    while(curDyedNum < graph->vertexNum){
        curDyedNum++;
        colors++;
        vertexs.push_back(curVertex);
        for(int i = 0;i < graph->vertexNum; i++){
            if(!records[sorts[i]]){
                int j;
                for(j = 0;j < vertexs.size();j++){
                    if(graph->isEdge(curVertex, vertexs[j])){
                        break;
                    }
                }
                if(j == vertexs.size()){
                    records[sorts[i]] = true;
                    curDyedNum++;
                    curVertex = sorts[i];
                    vertexs.push_back(curVertex);
                }
            }
        }
        vertexs.clear();
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
#include <iostream>
#include <climits>
#include <queue>

int UNVISITED = 0;
int VISITED = 1;

class Edge{
public:
    int from, to, weight;
    Edge(){
        from = -1;
        to  = -1;
        weight = 0;
    }
    Edge(int from, int to, int weight){
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
};

class Graph{
public:
    int vertexNum;
    int edgeNum;
    int* indegree;
    int* mask;
public:
    explicit Graph(int);
    virtual ~Graph();
    virtual Edge firstEdge(int) = 0;
    virtual Edge nextEdge(Edge) = 0;
    virtual bool setEdge(int, int, int) = 0;
    virtual bool delEdge(int, int) = 0;
    static bool isEdge(Edge e){
        return e.from >= 0 && e.to >= 0 && e.weight > 0 && e.weight < INT_MAX;
    }
};

Graph::Graph(int vernum) {
    vertexNum = vernum;
    edgeNum = 0;
    indegree = new int[vertexNum];
    mask = new int[vertexNum];
    for(int i = 0;i < vertexNum;i++){
        mask[i] = UNVISITED;
        indegree[i] = 0;
    }
    std::cout << "parent struc\n";
}

Graph::~Graph() {
    delete[] indegree;
    delete[] mask;
}

class Graphm : public Graph{
private:
    int** matrix;
public:
    explicit Graphm(int);
    ~Graphm() override;
    Edge firstEdge(int vertex) override;
    Edge nextEdge(Edge preEdge) override;
    bool setEdge(int from, int to, int weight) override;
    bool delEdge(int from, int to) override;
};

Graphm::Graphm(int vernum) : Graph(vernum) {
    matrix = new int*[vertexNum];
    for(int i = 0;i < vertexNum;i++){
        matrix[i] = new int[vertexNum];
    }
    for(int i = 0; i < vertexNum; i++){
        for(int j = 0; j < vertexNum; j++){
            if(i == j){
                matrix[i][j] = 0;
            }else{
                matrix[i][j] = INT_MAX;
            }
        }
    }
}

Graphm::~Graphm() {
    for(int i = 0;i < vertexNum;i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}

Edge Graphm::firstEdge(int vertex) {
    Edge ret;
    if(vertex < 0 || vertex >= vertexNum){
        return ret;
    }
    for(int i = 0;i < vertexNum;i++){
        if(matrix[vertex][i] != 0 && matrix[vertex][i] != INT_MAX){
            ret.from = vertex;
            ret.to = i;
            ret.weight = matrix[vertex][i];
            return ret;
        }
    }
    return ret;
}

Edge Graphm::nextEdge(Edge preEdge) {
    Edge ret;
    int from = preEdge.from;
    if(preEdge.to >= vertexNum - 1){
        return ret;
    }

    for(int i = preEdge.to + 1;i < vertexNum;i++){
        if(matrix[preEdge.from][i] != 0 && matrix[preEdge.from][i] != INT_MAX){
            ret.from = preEdge.from;
            ret.to = i;
            ret.weight = matrix[preEdge.from][i];
            return ret;
        }
    }

    return ret;
}

bool Graphm::setEdge(int from, int to, int weight) {
    if(from < 0 || from >= vertexNum || to < 0 || to >= vertexNum || matrix[from][to] == 0){
        return false;
    }
    matrix[from][to] = weight;
    indegree[to]++;
    edgeNum++;
    return true;
}

bool Graphm::delEdge(int from, int to) {
    if(from < 0 || from >= vertexNum || to < 0 || to >= vertexNum || matrix[from][to] == 0){
        return false;
    }

    matrix[from][to] = 0;
    indegree[to]--;
    edgeNum--;
    return true;
}

class ListNode{
public:
    int to;
    int weight;
    ListNode* next;
};

class List{
public:
    ListNode* head;
    List(){
        head = new ListNode();
    }
};

class Graphl : public Graph{
private:
    List* graList;
public:
    explicit Graphl(int);
    ~Graphl() override;
    bool setEdge(int from, int to, int weight) override;
    bool delEdge(int from, int to) override;
    Edge firstEdge(int) override;
    Edge nextEdge(Edge) override;
};

Graphl::Graphl(int vernum) : Graph(vernum) {
    graList = new List[vertexNum];
}

Graphl::~Graphl() {
    delete[] graList;
}

bool Graphl::setEdge(int from, int to, int weight) {
    auto head = graList[from].head;
    auto tmp = head;
    while(tmp->next && tmp->next->to < to){
        tmp = tmp->next;
    }
    auto node = new ListNode();
    node->to = to;
    node->weight = weight;
    node->next = tmp->next;
    tmp->next = node;
    edgeNum++;
    indegree[to]++;
    return true;
}

bool Graphl::delEdge(int from, int to) {
    auto head = graList[from].head;
    auto tmp = head;
    while(tmp->next && tmp->next->to != to){
        tmp = tmp->next;
    }
    auto node = tmp->next;
    if(node){
        tmp->next = node->next;
        delete node;
        edgeNum--;
        indegree[to]--;
        return true;
    }
    return false;
}

Edge Graphl::firstEdge(int vertex) {
    Edge ret;
    auto head = graList[vertex].head;
    if(!head->next){
        return ret;
    }
    ret.from = vertex;
    ret.to = head->next->to;
    ret.weight = head->next->weight;
    return ret;
}

Edge Graphl::nextEdge(Edge preEdge) {
    Edge ret;
    auto tmp = graList[preEdge.from].head;
    while(tmp->next && tmp->next->to != preEdge.to){
        tmp = tmp->next;
    }
    if(tmp->next){
        ret.to = tmp->next->to;
        ret.from = preEdge.from;
        ret.weight = tmp->next->weight;
        return ret;
    }
    return ret;
}

void fresh(Graph& graph){
    for(int i = 0;i < graph.vertexNum;i++){
        graph.mask[i] = UNVISITED;
    }
}

void DFS(Graph& graph, int v){
    if(graph.mask[v] == UNVISITED){
        graph.mask[v] = VISITED;
        std::cout<< v << std::endl;
        for(Edge e = graph.firstEdge(v);Graph::isEdge(e);e = graph.nextEdge(e)){
            if(graph.mask[e.to] == UNVISITED){
                DFS(graph, e.to);
            }
        }
    }
}

void BFS(Graph& graph, int v){
    std::queue<int> q;
    graph.mask[v] = VISITED;
    std::cout<< v << std::endl;
    q.push(v);
    while(!q.empty()){
        v = q.front();
        q.pop();
        for(Edge e = graph.firstEdge(v);Graph::isEdge(e);e = graph.nextEdge(e)){
            if(graph.mask[e.to] == UNVISITED){
                graph.mask[e.to] = VISITED;
                std::cout<< e.to << std::endl;
                q.push(e.to);
            }
        }
    }
}

void Topsort(Graph& graph){
    std::queue<int> q;
    for(int i = 0;i < graph.vertexNum;i++){
        if(graph.indegree[i] == 0){
            q.push(i);
            graph.mask[i] = VISITED;
            std::cout<< i << std::endl;
        }
    }
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(Edge e = graph.firstEdge(v);Graph::isEdge(e);e = graph.nextEdge(e)){
            graph.indegree[e.to]--;
            if(graph.indegree[e.to] == 0){
                q.push(e.to);
                graph.mask[e.to] = VISITED;
                std::cout<< e.to <<std::endl;
            }
        }
    }
    for(int i = 0;i < graph.vertexNum;i++){
        if(graph.mask[i] == UNVISITED){
            std::cout<< "there is cycle\n";
            return;
        }
    }
    std::cout<< "there is no cycle\n";
}

class Dist{
public:
    int index;
    int length;
    int pre;
    Dist() = default;
    Dist(int index, int length, int pre=0){
        this->index = index;
        this->length = length;
        this->pre = pre;
    }
};

struct comp{
    bool operator() (Dist& a, Dist& b){
        return a.length > b.length;
    }
};

void Dijkstra(Graph& graph, int s){
    std::priority_queue<Dist, std::vector<Dist>, comp> min_pq;
    Dist* D = new Dist[graph.vertexNum];
    for(int i = 0;i < graph.vertexNum;i++){
        D[i].index = i;
        D[i].length = INT_MAX;
        D[i].pre = s;
    }
    D[s].length = 0;
    Dist dist(s, 0, -1);
    min_pq.push(dist);
    bool found = false;
    for(int i = 0;i < graph.vertexNum;i++){
        found = false;
        while(!min_pq.empty()){
            dist = min_pq.top();
            min_pq.pop();
            if(graph.mask[dist.index] == UNVISITED){
                found = true;
                break;
            }
        }
        if(!found){
            break;
        }
        int v = dist.index;
        graph.mask[v] = VISITED;
        Edge e = graph.firstEdge(v);
        for(Edge e = graph.firstEdge(v);Graph::isEdge(e);e = graph.nextEdge(e)){
            if(dist.length + e.weight < D[e.to].length){
                D[e.to].length = dist.length + e.weight;
                D[e.to].pre = v;
                min_pq.push(D[e.to]);
            }
        }
    }
    for(int n = 0;n < graph.vertexNum;n++){
        std::cout<< "->" << n << ": " << D[n].length << std::endl;
    }
    delete[] D;
}

void Floyd(Graph& graph){
    Dist** D = new Dist*[graph.vertexNum];
    for(int i = 0;i < graph.vertexNum;i++){
        D[i] = new Dist[graph.vertexNum];
    }
    for(int i = 0;i < graph.vertexNum;i++){
        for(int j = 0;j < graph.vertexNum;j++){
            if(i == j){
                D[i][j].length = 0;
                D[i][j].pre = i;
            }else{
                D[i][j].length = INT_MAX;
                D[i][j].pre = -1;
            }
        }
    }

    for(int i = 0;i < graph.vertexNum;i++){
        for(Edge e = graph.firstEdge(i);Graph::isEdge(e);e = graph.nextEdge(e)){
            D[i][e.to].length = e.weight;
            D[i][e.to].pre = i;
        }
    }

    for(int v = 0;v < graph.vertexNum;v++){
        for(int i = 0;i < graph.vertexNum;i++){
            for(int j = 0;j < graph.vertexNum;j++){
                if((D[i][v].length < INT_MAX && D[v][j].length < INT_MAX )&& D[i][v].length + D[v][j].length < D[i][j].length){
                    D[i][j].length = D[i][v].length + D[v][j].length;
                    D[i][j].pre = v;
                }
            }
        }
    }

    for(int i = 0;i < graph.vertexNum;i++){
        for(int j = 0;j < graph.vertexNum;j++){
            std::cout<< "D[" << i << "][" << j << "]: " << D[i][j].length << "   ";
        }
        std::cout<< std::endl;
    }
    for(int i = 0;i < graph.vertexNum;i++){
        delete[] D[i];
    }
    delete[] D;
}

class ParTreeNode{
public:
    ParTreeNode* parent;
    int val;
    int count;
    ParTreeNode(){
        parent = NULL;
        val = 0;
        count = 0;
    }
    void setParent(ParTreeNode* parent){this->parent = parent;}
    ParTreeNode* getParent(){return parent;}
    void setCounts(int count){this->count = count;}
    int getCounts(){return count;}
};

class ParTree{
public:
    ParTreeNode* arr;
    int size;
    explicit ParTree(int size){
        this->size = size;
        arr = new ParTreeNode[size];
    }

    virtual ~ParTree(){
        delete[] arr;
    }

    ParTreeNode* Find(ParTreeNode* node);
    bool Different(int node1, int node2);
    void Union(int node1, int node2);
};

ParTreeNode* ParTree::Find(ParTreeNode* node){
    while(node->getParent() != NULL){
        node = node->getParent();
    }
    return node;
}

bool ParTree::Different(int node1_index, int node2_index) {
    auto node1 = &arr[node1_index];
    auto node2 = &arr[node2_index];
    return !(Find(node1) == Find(node2) && !(node1 == NULL && node2 == NULL));
}

void ParTree::Union(int node1_index, int node2_index) {
    auto node1 = &arr[node1_index];
    auto node2 = &arr[node2_index];
    node1 = Find(node1);
    node2 = Find(node2);
    if(node1 != node2){
        if(node1->getCounts() < node2->getCounts()){
            auto tmp = node2;
            node2 = node1;
            node1 = tmp;
        }

        node2->setParent(node1);
        node1->setCounts(node2->getCounts() + node1->getCounts());
    }
}

void Prim(Graph& graph){
    std::priority_queue<Dist, std::vector<Dist>, comp> min_pq;

    for(Edge e = graph.firstEdge(0);Graph::isEdge(e);e = graph.nextEdge(e)){
        min_pq.push(Dist(e.to, e.weight, 0));
    }

    graph.mask[0] = VISITED;
    bool found;

    for(int i = 0;i < graph.vertexNum - 1;i++){
        found = false;
        Dist d;
        while(!min_pq.empty()){
            d = min_pq.top();
            min_pq.pop();
            if(graph.mask[d.index] == UNVISITED){
                found = true;
                break;
            }
        }

        if(!found){
            return;
        }

        std::cout<< "Edge from:" << d.pre << "  to:" << d.index << "  weight:" << d.length << std::endl;
        graph.mask[d.index] = VISITED;

        for(Edge e = graph.firstEdge(d.index);Graph::isEdge(e);e = graph.nextEdge(e)){
            if(graph.mask[e.to] == UNVISITED){
                min_pq.push(Dist(e.to, e.weight, e.from));
            }
        }
    }
}

void Kruskal(Graph& graph){
    ParTree parTree(graph.vertexNum);
    std::priority_queue<Dist, std::vector<Dist>, comp> min_pq;

    for(int i = 0;i < graph.vertexNum;i++){
        for(Edge e = graph.firstEdge(i);Graph::isEdge(e);e = graph.nextEdge(e)){
            min_pq.push(Dist(e.to, e.weight, e.from));
        }
    }

    Dist d;
    while(!min_pq.empty()){
        d = min_pq.top();
        min_pq.pop();
        if(parTree.Different(d.index, d.pre)){
            parTree.Union(d.pre, d.index);
            std::cout<< "Edge from:" << d.pre << "  to:" << d.index << "  weight:" << d.length << std::endl;
        }
    }
}

int main(){
    Graph* mg = new Graphm(7);
    mg->setEdge(0, 1, 20);
    //mg->setEdge(0, 3, 2);
    mg->setEdge(0, 4, 1);
    mg->setEdge(1, 2, 6);
    mg->setEdge(1, 3, 4);
    mg->setEdge(2, 6, 2);
    mg->setEdge(3, 5, 12);
    mg->setEdge(3, 6, 8);
    mg->setEdge(4, 5, 15);
    mg->setEdge(5, 6, 10);

    mg->setEdge(1, 0, 20);
    mg->setEdge(4, 0, 1);
    //mg->setEdge(3, 0, 2);
    mg->setEdge(2, 1, 6);
    mg->setEdge(3, 1, 4);
    mg->setEdge(6, 2, 2);
    mg->setEdge(5, 3, 12);
    mg->setEdge(6, 3, 8);
    mg->setEdge(5, 4, 15);
    mg->setEdge(6, 5, 10);

    Kruskal(*mg);
//    mg->setEdge(0, 1, 10);
//    mg->setEdge(0, 4, 100);
//    mg->setEdge(0, 3, 30);
//    mg->setEdge(1, 2, 50);
//    mg->setEdge(2, 4, 10);
//    mg->setEdge(3, 1, 10);
//    mg->setEdge(3, 4, 60);
//    mg->setEdge(3, 2, 20);

//    for(Edge e = mg->firstEdge(0);Graph::isEdge(e);e = mg->nextEdge(e)){
//        std::cout<< e.to << "       ~";
//    }
//    std::cout<< "\n\n\n\n";

//    DFS(*mg, 0);
//    fresh(*mg);
//    std::cout<< std::endl;
//
//    BFS(*mg, 0);
//    fresh(*mg);
//    std::cout<< std::endl;
//
//    Topsort(*mg);
//    fresh(*mg);
//    std::cout<< std::endl;
//
//    Dijkstra(*mg, 0);
//    fresh(*mg);
//    std::cout<< std::endl;
//
//    Floyd(*mg);
//    fresh(*mg);
//    std::cout<< std::endl;


}
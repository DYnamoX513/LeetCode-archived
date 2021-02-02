#include "vector"
using namespace std;
class DisjointSet
{
public:
    // 用于记录该节点的父节点，所有父节点相同的节点位于同一连通图
    vector<int> parent;
    // 节点的秩，主要记录该节点目前位于的树的深度，从子节点出发
    // 主要用于优化，在合并两个父节点时，通过rank的大小判断谁父谁子
    vector<int> rank;
    // 用于记录并查集的数量,某些情况下该成员非必要
    int count;

    DisjointSet(int n);

    // 路径压缩， 遍历过程中的所有父节点直接指向根节点，
    // 减少后续查找次数
    int findParent(int x);
    
    // 合并两个节点
    // 如果处于同一个并查集， 不需要合并
    // 如果不处于同一个并查集，判断两个root x和root y谁的秩大
    void merge(int x, int y);
};
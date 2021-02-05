#include "DisjointSet.h"
DisjointSet::DisjointSet(int n) : count(n)
{
    for (int i = 0; i < n; i++)
    {
        parent.push_back(i);
        rank.push_back(0);
    }
}

/**
 * @brief 
 * 路径压缩，遍历过程中的所有父节点直接指向根节点，减少后续查找次数
 * @param x 
 * @return int 
 */
int DisjointSet::findParent(int x)
{
    return parent[x] == x ? x : (parent[x] = findParent(parent[x]));
}

/**
 * @brief  
 * 合并两个节点
 * 如果处于同一个并查集， 不需要合并
 * 如果不处于同一个并查集，判断两个root x和root y谁的秩大
 * @param x 
 * @param y 
 */
void DisjointSet::merge(int x, int y)
{
    int rx = findParent(x), ry = findParent(y);
    if (rx != ry)
    {
        if (rank[rx] < rank[ry])
        {
            parent[rx] = ry;
        }else
        {
            parent[ry] = rx;
        }
        count--;
        if (rank[rx] == rank[ry])
            rank[rx] += 1;
    }
}

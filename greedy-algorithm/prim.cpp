#include <iostream>
#define INF  0x7ffffff;
using namespace std;

void prim(int** MGraph, int vNum) {
    int lowcost[vNum];
    int mst[vNum];
    int visited[vNum];

    //初始化lowcost与mst数组
    for (int i = 0; i < vNum; i++) {
        lowcost[i] = MGraph[0][i];
        mst[i] = 0;
        visited[i] = false;
    }

    //寻找最小生成树
    int min;
    int minid;
    int totalWeight = 0;
    for(int i = 0; i < vNum - 1; i++) {
        //查找与顶点集S连接的代价最小的边
        min = INF;
        minid = -1;
        for (int j = 1; j < vNum; j++) {
            if (lowcost[j] != 0 && lowcost[j] < min) {
                min = lowcost[j];
                minid = j;
            }
        }
        //将找到的顶点加入到顶点集S中（此处为输出），并将代价设为0
        cout << mst[minid] << "-" << minid << " = " << min << endl;
        visited[minid] = true;
        totalWeight += min;
        lowcost[minid] = 0;
        //更新lowcost与mst
        for (int j = 1; j < vNum; j++) {
            if(visited[j])
                continue;
            if (lowcost[j] == 0 || (MGraph[minid][j] != 0 && MGraph[minid][j] < lowcost[j])) {
                lowcost[j] = MGraph[minid][j];
                mst[j] = minid;
            }
        }
    }

    cout << "Total Weight: " << totalWeight << endl;
}

int main() {
    int vNum = 6;
    int *g[] = {
            new int[vNum]{0, 34, 46, 0, 0, 19},
            new int[vNum]{34, 0, 0, 0, 12, 0},
            new int[vNum]{46, 0, 0, 17, 0, 25},
            new int[vNum]{0, 0, 17, 0, 38, 25},
            new int[vNum]{0, 12, 0, 38, 0, 26},
            new int[vNum]{19, 0, 25, 25, 26, 0},
    };
    prim(g, vNum);
    return 0;
}

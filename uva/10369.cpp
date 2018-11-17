#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
struct Puntos{
    int X;
    int Y;
}coordenadas[501];
struct Edge {
    int a_index;
    int b_index;
    double Len;
}Es[501 * 501];
int nOfE;
int Set[501];

bool cmp(const Edge &A, const Edge &B) {
    return A.Len < B.Len;
}
int Find_Root(int x)
{
    if (x == Set[x])
        return x;
    return Set[x] = Find_Root(Set[x]);
}
bool Union(const Edge &Es, vector<double> &LenOfEdge)
{
    int a = Find_Root(Es.a_index);
    int b = Find_Root(Es.b_index);
    if (a != b) {
        Set[a] = b;
        LenOfEdge.push_back(Es.Len);
        return true;
    }
    return false;
}
int main()
{
    int N;
    int S, P;
    cin>>N;
    while (N--) {
        cin>>S>>P;
        for (int i = 0; i < P; ++i) {
            cin>>coordenadas[i].X>>coordenadas[i].Y;
            Set[i] = i;
        }
        nOfE = 0;
        for (int i = 0; i < P; ++i) {
            for (int j = i + 1; j < P; ++j) {
                double L = sqrt(pow(coordenadas[i].X - coordenadas[j].X, 2) + pow(coordenadas[i].Y - coordenadas[j].Y, 2));
                Es[nOfE++] = {i, j, L};
            }
        }
        sort(Es, Es + nOfE, cmp);

        vector<double> LenOfEdge;
        for (int i = 0, nOfEdges = 0; nOfEdges != P - 1; ++i) {
            if (Union(Es[i], LenOfEdge)) ++nOfEdges;
        }
        printf("%.2lf", LenOfEdge[P-S-1]);
        cout<<endl;
    }
}
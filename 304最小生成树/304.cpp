//
//  main.cpp
//  304◊Ó–°…˙≥… ˜
//
//  Created by –ª»›∫£ on 2020/12/5.
//

#include <iostream>
#include <algorithm>
#include <set>
#define MAX 100//n,m◊Ó¥Û∂º≤ª≥¨π˝100
using namespace std;

struct Edge {
    int v1;// ∑÷±±Ì æµ⁄“ª∂•µ„£¨
    int v2;// µ⁄∂˛∏ˆ∂•µ„
    int wei;// ±ﬂ…œµƒ»®÷µ
}edge[MAX];//¥Ê¥¢±ﬂµƒ–≈œ¢
struct {
    int value;// ∂•µ„µƒ ˝æ›
    int camp;// ±Ì æ√ø∏ˆ∂•µ„À˘ ÙµƒºØ∫œ
    int use;    //∏√µ„ «∑Ò±ªº”»Î
}assist[MAX];

int count_e;//º«¬º◊Ó–°…˙≥… ˜µƒ±ﬂ ˝

bool cmp(Edge a, Edge b) {//≈≈–Ú∫Ø ˝£¨∂®“Â∞¥±ﬂµƒ»®÷µ¥Û–°¥”–°µΩ¥Û≈≈–Ú
    return a.wei < b.wei;
}

int find_vex(int vexnum, int point) {//—∞’“±ﬂµƒ¡Ω∏ˆ∂•µ„
    for (int i = 0; i < vexnum; i++) {//∂‘À˘”–∂•µ„±È¿˙
        if (assist[i].value == point) {//»Ù’“µΩÀ˘’“µƒ∂•µ„£¨∑µªÿ±‡∫≈
            return i;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    /**
    ÕÍ≥… ‰»Î≤Ÿ◊˜
    */
    int vexnum, arcnum;//∑÷±±Ì æ∂•µ„ ˝∫Õ±ﬂ ˝
    int i;
    set<int> vex_t;// π”√set»›∆˜»•÷ÿ¥¢¥Ê ‰»Îµƒ∂•µ„
                   //int v1,v2,wei;
    cin >> vexnum >> arcnum;//µ⁄“ª––Œ™¡Ω∏ˆ’˝’˚ ˝n∫Õm,∑÷±±Ì æ∂•µ„ ˝∫Õ±ﬂ ˝
    Edge edges[MAX];//¥¥Ω®“ª∏ˆΩ·ππÃÂ ˝◊È”√¿¥¥Ê¥¢ ‰»Îµƒ±ﬂµƒ–≈œ¢
    for (i = 0; i < arcnum; i++) {// ‰»Îm––±ﬂµƒ–≈œ¢
        cin >> edges[i].v1 >> edges[i].v2 >> edges[i].wei;
        vex_t.insert(edges[i].v1);
        vex_t.insert(edges[i].v2);
    }
    sort(edges, edges + arcnum, cmp);//∂‘ŒﬁœÚÕ¯÷–À˘”–µƒ±ﬂ∞¥±ﬂµƒ»®÷µΩ¯––…˝–Ú≈≈¡–£¨Ω·π˚»‘¥Ê¥¢‘⁄edge÷–

                                     /*for (i = 0; i < arcnum; i++) {//ºÏ≤È ‰»Î∫Õsort≈≈–Ú∫Ûµƒ±ﬂ–≈œ¢
                                     cout << edges[i].v1 << ' ' << edges[i].v2 << ' ' << edges[i].wei << endl;
                                     }*/
    int count_v = 0;
    set<int>::iterator iter;// Ω´set÷–∂•µ„µƒ–≈œ¢¥Ê»ÎassistΩ·ππÃÂ ˝◊È£¨∫Û√Ê≈–∂œ «∑Ò–Œ≥…ªÿ¬∑”√
    for (iter = vex_t.begin(); iter != vex_t.end(); iter++) {// “—∏¯¡À∂•µ„ ˝Œ™n£¨À˘“‘“≤ø…“‘÷±Ω”i < n◊˜Œ™≈–∂œÃıº˛
        assist[count_v].value = *iter;// Ω´∂•µ„–≈œ¢¥Ê»Îassist÷–
        assist[count_v].camp = count_v;// ∏√∂•µ„µƒ≥ı º±Íº«
        assist[count_v].use = 0;
        count_v++;
    }
    /*for (i = 0; i < count_v; i++) {//ºÏ≤È¥Ê»Îassist «∑Ò’˝»∑
    cout << assist[i].value << ' ' << assist[i].camp << endl;
    }*/

    Edge miniTree[MAX];//¥¥Ω®“ª∏ˆø’µƒΩ·ππÃÂ ˝◊È£¨”√¿¥¥Ê¥¢◊Ó–°…˙≥… ˜µƒ
    int num = 0;//”√¿¥º«¬º◊Ó–°…˙≥… ˜

    for (i = 0; i < arcnum; i++) {//∂‘À˘”–µƒ±ﬂΩ¯––±È¿˙
        int initial = find_vex(vexnum, edges[i].v1);//’“µΩ∏√±ﬂµƒµ⁄“ª∏ˆ∂•µ„µƒ±‡∫≈
        int end = find_vex(vexnum, edges[i].v2);
        //cout << i << "initial=" << initial << "end=" << end << endl;//ºÏ≤Èfind_vex «∑Ò”–Œ Ã‚

        //»Áπ˚∂•µ„Œª÷√¥Ê‘⁄«“∂•µ„µƒ±Íº«≤ªÕ¨£¨Àµ√˜≤ª‘⁄“ª∏ˆºØ∫œ÷–

        if (initial != -1 && end != -1 && assist[initial].camp != assist[end].camp) {
            miniTree[num] = edges[i];//Ω´∏√±ﬂ◊˜Œ™◊Ó–°…˙≥… ˜µƒ◊È≥…≤ø∑÷
            num++;//º∆ ˝+1
            
            for (int i = 1; i <= vexnum;i++) {
                if (assist[i].camp == assist[end].camp && i!=end && assist[i].use==1) {
                    assist[i].camp = assist[initial].camp;
                }
            }
            assist[end].camp = assist[initial].camp;
            assist[end].use = 1;
            assist[initial].use = 1;

            if (num == vexnum - 1) {//»Áπ˚—°‘Òµƒ±ﬂµƒ ˝¡ø∫Õ∂•µ„ ˝œ‡≤Ó1£¨Àµ√˜◊Ó–°…˙≥… ˜“—æ≠–Œ≥…£¨ÕÀ≥ˆ—≠ª∑
                break;
            }
        }
    }
    for(i = 0;i < vexnum -1; i++){
        if (miniTree[i].v1 > miniTree[i].v2) {
            int temp =miniTree[i].v1;
            miniTree[i].v1 = miniTree[i].v2;
            miniTree[i].v2 = temp;0
        }
    }
    // ‰≥ˆ
    for (i = 0; i < vexnum - 1; i++) {
        cout << miniTree[i].v1 << ' ' << miniTree[i].v2 << ' ' << miniTree[i].wei << endl;
    }

    //std::cout << "Hello, World!\n";
    return 0;
}

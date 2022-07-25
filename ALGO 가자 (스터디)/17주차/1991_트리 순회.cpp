#include <iostream>
using namespace std;

struct node{
    int parent;
    int left;
    int right;
};

int n;
node* tree;

void order(int pivot, int dir){
    if(pivot<0) return;

    char c = (char) (pivot+65);
    if(dir==0) cout << c;
    order(tree[pivot].left, dir);
    if(dir==1) cout << c;
    order(tree[pivot].right, dir);
    if(dir==2) cout << c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    tree = (node*)malloc(sizeof(node)*n);
    char x, l, r;
    for(int i=0;i<n;i++){
        cin >> x >> l >> r;
        tree[x-65].left = l-65;
        tree[x-65].right = r-65;
        tree[l-65].parent = x-65;
        tree[r-65].parent = x-65;
    }

    order(0, 0);
    cout << "\n";
    order(0, 1);
    cout << "\n";
    order(0, 2);
    cout << "\n";
}
#include <iostream>
using namespace std;

int gandalf[6]={1,2,3,3,4,10};
int sauron[7]={1,2,2,2,3,5,10};

int main(){
    int t, tmp, bat=0, gan=0, sau=0;
    cin >> t;
    
    for(int i=0;i<t;i++){
        for(int x=0;x<6;x++){
            cin >> tmp;
            gan+=tmp*gandalf[x];
        }
        for(int y=0;y<7;y++){
            cin >> tmp;
            sau+=tmp*sauron[y];
        }

        if(gan==sau) printf("Battle %d: No victor on this battle field\n", ++bat);
        else if(gan>sau) printf("Battle %d: Good triumphs over Evil\n", ++bat);
        else if(gan<sau) printf("Battle %d: Evil eradicates all trace of Good\n", ++bat);
        gan = sau = 0;
    }
}
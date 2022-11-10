#include <iostream>
#include <locale>
#include "classes/animationManager.h"
#include "classes/barChart.h"
#include "classes/barItem.h"

int main(int argc, char const *argv[]){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    //
    AnimationManager *manager = new AnimationManager();

    if(argc == 1){
        manager -> errorHelp();
        exit(0);
    }

    manager -> welcome();    
    manager -> start(argc,argv);
    return 0;
}

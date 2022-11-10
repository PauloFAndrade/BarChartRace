#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <bits/stdc++.h>

#include "barItem.h"
#include "barChart.h"
#include "database.h"

#include "../lib/text_color.h"

class AnimationManager{
    public:

    void printError(){
        std::cout << "╔═══════════════╗\n";
        std::cout << "      ERROR\n";
        std::cout << "╚═══════════════╝\n";
    }

    void errorHelp(){
        std::cout << "╔══════════════════════════════════════════════════════════╗\n";
        std::cout << " You have run the program wrongly, please use it like this:\n";
        std::cout << "╚══════════════════════════════════════════════════════════╝\n\n";
        std::cout << "╭─━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━─╮\n";
        std::cout << "|% ./bcr                                                    |\n";
        std::cout << "|Usage: bcr [<options>] <input_data_file>                   |\n"; 
        std::cout << "|  Bar Chart Race options:                                  |\n"; 
        std::cout << "|      -b  <num> Max # of bars in a single char.            |\n";        
        std::cout << "|                Valid range is [1,15]. Default values is 5.|\n";
        std::cout << "|      -f  <num> Animation speed in fps (frames per second).|\n";
        std::cout << "|                Valid range is [1,24]. Default value is 24.|\n";
        std::cout << "╰─━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━─╯\n";
    }

    void welcome(){
        std::cout << " »»————-　★WELCOME TO THE BAR CHART RACE★　————-««\n";
        std::cout << "              ┌───────── •✧✧• ─────────┐\n";
        std::cout << "                Criado Por Paulo Vitor\n";
        std::cout << "              └───────── •✧✧• ─────────┘\n";
    }

    void swapS(BARITEM &a, BARITEM &b){
        BARITEM aux;

        aux.rotulo = a.rotulo;
        aux.valor = a.valor;
        aux.categoria = a.categoria;

        a.rotulo = b.rotulo;
        a.valor = b.valor;
        a.categoria = b.categoria;

        b.rotulo = aux.rotulo;
        b.valor = aux.valor;
        b.categoria = aux.categoria;
    }

    void insertion(std::vector <BARITEM> &first, int tam){
        BARITEM aux;
        int i,j;
        for(i = 1;i<tam;i++){
            aux = first[i];
            for(j=i;j>0 && (aux.valor > first[j-1].valor);j--){
                first[j] = first[j-1];
            }
            first[j] = aux;
        }
    }

    void start(int qtd, const char** argv){
        std::string nameFile;
        std::string Default (argv[1]);
        bool existsTxt = false;
        bool alreadyF = false;
        bool alreadyB = false;
        if(qtd == 2 && Default.find(".txt") != string::npos){
            existsTxt = true;
            std::cout << "𓆩*𓆪 You didn't choose the parameters (-b) and (-f), so we will use the default values (5) and (24) respectively.\n";
            nameFile = argv[1];
        }else{
            for(int i{0};i<qtd;i++){
                std::string analyze(argv[i]);
                if(strcmp(argv[i],"-b")==0){
                    try{
                        if(alreadyB == true){
                            system("clear");
                            printError();
                            std::cout << "𓆩*𓆪 You Tried Putting The \"-b\" Parameter More Than Once\n";
                            exit(0);
                        }else if(std::stoi(argv[i+1])>=1 && std::stoi(argv[i+1])<=15 && alreadyB == false){
                            maxBars = std::stoi(argv[i+1]);
                            alreadyB = true;
                            i++;
                        }else{
                            system("clear");
                            printError();
                            std::cout << "𓆩*𓆪 Invalid Max of bars, The Range is [1;15]\n";
                            exit(0);
                        }
                    }catch(const std::invalid_argument & e){
                        system("clear");
                        printError();
                        std::cout << "𓆩*𓆪 We Were Unable To Continue The Race Because \"";
                        std::cout << argv[i+1] << "\" Is Not A Number\n";
                        exit(0);
                    }catch(const std::out_of_range & e){
                        system("clear");
                        printError();
                        std::cout << "𓆩*𓆪 We Were Unable To Continue The Race Because \"";
                        std::cout << argv[i+1] <<"\" Is Out Of Range\n";
                        exit(0);
                    }
                }else if(strcmp(argv[i],"-f")==0){
                    try{
                        if(alreadyF == true){
                            system("clear");
                            printError();
                            std::cout << "𓆩*𓆪 You Tried Putting The \"-f\" Parameter More Than Once\n";
                            exit(0);
                        }else if(std::stoi(argv[i+1])>=1 && std::stoi(argv[i+1])<=24){
                            fps = std::stoi(argv[i+1]);
                            alreadyF = true;
                            i++;
                        }else{
                            system("clear");
                            printError();
                            std::cout << "𓆩*𓆪 Invalid Animation Speed, The Range is [1;24]\n";
                            exit(0);
                        }
                    }catch(const std::invalid_argument & e){
                        system("clear");
                        printError();
                        std::cout << "𓆩*𓆪 We Were Unable To Continue The Race Because \"";
                        std::cout << argv[i+1] << "\" Is Not A Number\n";
                        exit(0);
                    }catch(const std::out_of_range & e){
                        system("clear");
                        printError();
                        std::cout << "𓆩*𓆪 We Were Unable To Continue The Race Because \"";
                        std::cout << argv[i+1] <<"\" Is Out Of Range\n";
                        exit(0);
                    }
                }else if(analyze.find(".txt") != string::npos/*i==qtd-1*/){
                    existsTxt = true;
                    nameFile = argv[i];
                }else if(analyze.find("/bcr") == string::npos ){
                    system("clear");
                    printError();
                    std::cout << "𓆩*𓆪 You Passed A Non-Existent Parameter -> \""<<argv[i]<<"\"\n";
                    exit(0);
                }
            }

        }
        
        if(existsTxt == false){
            system("clear");
            printError();
            std::cout << "\n𓆩*𓆪 I Believe You Didn't Pass A File With The Data, Please Pass Some File\n";
            exit(0);
        }

        std::cout << "\n𓆩*𓆪 Preparing To Read Input File \""<<nameFile<<"\"...\n";
        std::ifstream initialFile;
        initialFile.open(nameFile);
        std::string iline;
        int iCorCode = 31;
        int vez = 0;
        std::set <std::string> iSetCat;
        std::map <std::string , int> mapColor;
        if(initialFile.is_open()){
            std::cout << "\n𓆩*𓆪 Processing Data, Please Wait.\n";
            getline(initialFile, iline);
            if( iline == " " || iline.size()<=1 ){
                std::cout << "Invalid Title\n";
                exit(0);
            }
            getline(initialFile,iline); 
            getline(initialFile,iline);

            
            while(getline(initialFile,iline)){
                while(iline == " " || iline.size()<=1){
                    getline(initialFile,iline);
                }
                int iLinhaAtual=0;
                int iqtd = stoi(iline);
                vez++;
                for(int i{0};i<iqtd;i++){
                    getline(initialFile,iline);
                    std::stringstream check1(iline);
                    std::string intermediate;
                    int aux = 0;
                    while(getline(check1, intermediate, ',')){
                        if(intermediate.empty()){
                            getline(check1,intermediate,',');
                        }
                        if(aux==0){
                            aux++;
                        }else if(aux==1){
                            aux++;
                        }else if(aux==2){
                            getline(check1, intermediate, ',');
                            aux++;
                        }else if(aux==3){
                            for(int y{0};y<intermediate.size();y++){
                                if(iscntrl(intermediate[y])!=0){
                                 intermediate.pop_back();
                                }
                            }
                            iSetCat.insert(intermediate);
                        }
                    }
                    iLinhaAtual++;
                }
            }
            for(const auto& e: iSetCat){
                mapColor.insert({e,iCorCode});
                if(iCorCode == 38){
                    iCorCode = 90;
                }else{
                    iCorCode++;
                }
            }
        }

        initialFile.close();

        std::cout << "\n𓆩*𓆪 We Have "<< vez << " Charts.\n\n";
       

        std::ifstream file;
        file.open(nameFile);
        std::string line;
        if(file.is_open()){

            //Pegando Título Do Gráfico
            getline(file, line);
            if( line == " " || line.size()<=1 ){
                std::cout << "Invalid Title\n";
                exit(0);
            }
            title = line;

            //Pegando Rótulo
            getline(file, line);
            if( line == " " || line.size()<=1 || line==title){
                std::cout << "Invalid Label\n";
                exit(0);
            }
            label = line;

            //Pegando Fonte das Informações
            getline(file, line);
            if( line == " " || line.size()<=1 || line==label){
                std::cout << "Invalid Font\n";
                exit(0);
            }
            font = line;

            std::cout << "╔══════════════╗\n";
            std::cout << "  Your Choices\n";
            std::cout << "╚══════════════╝\n";
            
            std::cout << "𓆩*𓆪 Animation Speed Is: " << fps << "\n";
            std::cout << "𓆩*𓆪 Title: " << title << "\n";
            std::cout << "𓆩*𓆪 Value Is: " << label << "\n";
            std::cout << "𓆩*𓆪 Source: " << font << "\n";
            std::cout << "𓆩*𓆪 # Of Categories Found: " << iSetCat.size() << "\n";

            Database bd_bc;

            std::set <std::string> setCat;

            int qtd;
            int corCode = 31;
            bool vez = false;
            while(getline(file, line)){
                corCode = 32;
                while(line == " " || line.size()<=1){
                    getline(file,line);
                }
                qtd = stoi(line);
                BarChart bc;
                int linhaAtual = 0;
                for(int i{0};i<qtd;i++){
                    getline(file,line);
                    std::stringstream check1(line);
                    std::string intermediate;
                    int aux = 0;
                    BARITEM barra;
                    while(getline(check1, intermediate, ',')){
                        if(intermediate.empty()){
                            getline(check1,intermediate,',');
                        }
                        if(aux==0){
                            bc.timeStamp = intermediate;
                            aux++;
                        }else if(aux==1){
                            barra.rotulo = intermediate;
                            aux++;
                        }else if(aux==2){
                            getline(check1, intermediate, ',');
                            barra.valor = stoi(intermediate);
                            aux++;
                        }else if(aux==3){
                            for(int y{0};y<intermediate.size();y++){
                                if(iscntrl(intermediate[y])!=0){
                                 intermediate.pop_back();
                                }
                            }
                            barra.categoria = intermediate;
                            iSetCat.insert(intermediate);
                            bc.bars.push_back(barra);
                        }
                    }
                    linhaAtual++;
                }
                bd_bc.charts.push_back(bc);
            
            insertion(bd_bc.charts[0].bars,qtd);
            
            std::cout << std::endl;
            std::vector <std::string> categoriaAdd; 

            for(int i{0};i<qtd;i++){
                for(const auto& e: mapColor){
                    if(bd_bc.charts[0].bars[i].categoria == e.first){
                        bd_bc.charts[0].bars[i].cor = e.second;
                    }
                }
            }

            if(vez == false){   
                std::cout << "Press Enter For The Magic To Happen\n";
                if(std::cin.get() == '\n'){
                    vez = true;
                }
            }
            
            if(vez==true){
                std::cout << "\t\t\t\t\t\t\t"<<title<<std::endl;
                std::cout << std::endl;
                std::cout << "\t\t\t\t\t\t\t\t\t   Time Stamp: " << bc.timeStamp << std::endl << std::endl;
                int tamAtual = 100;
                for(int i{0};i<qtd;i++){
                    for(int j{0};j<tamAtual;j++){
                        std::cout << Color::tcolor("█",bd_bc.charts[0].bars[i].cor);
                    }
                    std::cout <<" "<< bd_bc.charts[0].bars[i].rotulo << " [" << bd_bc.charts[0].bars[i].valor << "]";
                    std::cout << std::endl;
                    std::cout << std::endl;
                    tamAtual = (bd_bc.charts[0].bars[i+1].valor*100)/bd_bc.charts[0].bars[0].valor;
                }
                    
                std::cout << std::endl;
                std::vector <int> sums;
                int digitos = 0;
                int aux = bd_bc.charts[0].bars[qtd-1].valor;
                while(aux != 0){
                    digitos+=1;
                    aux /= 10;
                }
                int menor = bd_bc.charts[0].bars[qtd-1].valor/std::pow(10,digitos-1);
                sums.push_back(menor*(std::pow(10,digitos-1)));
                int point = (bd_bc.charts[0].bars[0].valor/10)*10 + 10;
                int calculo = (point - sums[0])/5;
                int soma = 0;
                int index = 0;
                while(soma != point){
                    if(sums[index]+calculo > 0){
                        sums.push_back(sums[index]+calculo);
                        soma = sums[index]+calculo;
                        index++;
                    }
                }

                sums.push_back(point);
                std::vector <int> abaixo;
                int colocar = 0;
                int jafoi = 0;
                for(int i{0};i<=(100+/*passarUmPouco*/20);i++){ //mesmo valor do 100% da barra
                    if(i==colocar){
                        abaixo.push_back(i);
                        std::cout << "+";
                        colocar = (sums[jafoi]*100)/point;
                        jafoi++;
                    }else{
                        std::cout << "-";
                    }
                }
                std::cout << ">";
                std::cout << std::endl;
                int jafoi2 = 1;
                std::cout << "0";
                for(int i{1};i<=(100+/*passarUmPouco*/20);i++){ //mesmo valor do 100% da barra
                    if(i==abaixo[jafoi2]){
                        int qtdDigit = 0;
                        int auxDigit = sums[jafoi2-1];
                        while(auxDigit != 0){
                            qtdDigit+=1;
                            auxDigit /= 10;
                        }
                        std::cout << sums[jafoi2-1];
                        jafoi2++;
                        i+=digitos-1;
                    }else{
                        std::cout << " ";
                    }
                }
            }
            std::cout << std::endl;
            std::cout << label << std::endl << std::endl;
            std::cout << font << std::endl;
            
            for(const auto& e: mapColor){
                std::cout << Color::tcolor("█",e.second) << ": " << Color::tcolor(e.first,e.second) << " ";
            }

            std::cout << std::endl;

            bd_bc.charts[0].bars.resize(0);
            bd_bc.charts.resize(0);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000/fps));
            system("clear");
         }
        }else{
            printError();
            std::cout << "Não Foi Possível Abrir O Arquivo\n";
            exit(0);
        }
        file.close();
    }

    private:
    int fps{24};
    int maxBars{5};
    std::string timeStamp;
    std::string title;
    std::string label;
    std::string font;
    std::vector<BARITEM> bars;
};
#ifndef HEAP_H
#define HEAP_H

#include "HeapADT.h"
#include<iostream>
#include<math.h>
#include<QString>
#include<QDebug>

using namespace std;

template<typename E>

class HeapCDT : public HeapADT<E>
{

public:

    E *array;
    int maxsize;
    int position;
    int maxlevel;
    int level;

    Heap(E value, int size){
        maxsize = size;
        array = new E[maxsize];
        maxlevel = 0;
        array[0] = value;

    }
    Heap(int size, E *old){

        maxsize = size;
        array = new E[maxsize];
        array = old;

    }

    void insert(const E& it){

        array[maxsize++] = it;

    }
    void repeatString(char *string, int num){

        for(int i = 0; i < num; i++){

            cout << string;

        }

    }

    void printHeap(){

        cout << endl << endl << endl << endl ;

        MaxLevel();
        //        cout << maxlevel <<endl;
        int aux = 2;
        level = 1;
        int distance;
        if(maxsize > 7){

            distance = ((pow(2,(maxlevel)*2)- 13));

        }
        else{


            distance = ((pow(2,(maxlevel)*2)- 2));

        }

        if(maxsize < 16){
            for(int i = 0; i < maxsize; (i++)){
                if(i == 0 || i == 11){

                    repeatString(".",(distance/pow(2,level)));
                    cout << array[i];
                    aux++;

                }
                else if(pow(2,level) < aux){

                    level++;
                    cout << endl << endl;
                    repeatString(".",(distance/pow(2,level)));
                    cout << array[i];
                    //               cout<< "LEVEL : " << level;
                    aux++;

                }
                else{

                    repeatString(".",(distance/pow(2,level))*2);
                    cout << array[i];
                    aux++;
                }

            }
        }
        else{
            for(int i = 0; i < maxsize; (i++)){

                cout << array[i] << " ";

            }
        }

        cout << endl ;
    }
    int parent(int pos) const{
        if(pos % 2 != 0){


            return ((pos)/2);


        }else{

            return ((pos)/2)-1;

        }
    }
    int righ(int pos) const{

        return  ((pos + 1)*2);

    }
    int left(int pos) const{

        return ((pos+1)*2)-1;

    }
    void backof(int pos = 0){

        array[pos] = array[pos + 1];
        for(int i = pos + 1; i < maxsize - 1; i++){

            array[i] = array[i + 1];

        }

    }

    E removefirst(){

        E aux;
        aux = array[0];
        backof();
        maxsize--;

        return aux;

    }
    int size() const{

        return maxsize;

    }
    E remove(int pos){
        pos = pos - 1;
        E aux;
        if(pos < maxsize-1 && pos >= 0){

            aux = array[pos];
            backof(pos);
            maxsize--;

            return aux;

        }
        else if(pos == maxsize - 1){

            aux = array[pos];
            maxsize--;

            return aux;


        }
        else{

            cout << endl<< endl<< endl<< "ERROR!!" << endl<< endl<< endl<< endl;

        }
        return -1;
    }
    void MaxLevel(){

        int aux = 1;
        maxlevel = 1;
        for(int i = 1; i < maxsize; (i++)){
            if(pow(2,maxlevel) < aux){

                maxlevel++;
                aux = 1;

            }

            aux++;

        }

    }
    E getValue(int pos){

        return array[pos];

    }

    void heapfy(int pos){
        MaxLevel();

        int l,r,maior;

        l = left(pos);
        r = righ(pos);

        if(isLeaf(pos) == 0){

            if ((l <= maxsize) && (array[l] > array[pos])){   // Seleciona o maior entre  //
                maior = l;                                        // pai, filho esquerdo e filho direito //
            }else{
                maior = pos;
            }
            if ((r <= maxsize) && (array[r] > array[maior])){
                maior = r;
            }
            if (maior != pos)
            {
                swapper(pos,maior);    // troca a posicao dos elementos //
                heapfy(maior);
            }

        }
    }

    void buildMaxHeap(){


        for (int i = (maxsize/2) - 1; i >= 0; i--)   // Para cada nó interno(não-folha),  //
            heapfy(i);                  // chama heapfy, seguindo o sentido folha-raiz  //
    }

    void swapper(int pos, int pos2){

        int aux2;
        aux2 = array[pos];
        array[pos] = array[pos2];
        array[pos2] = aux2;

    }
    bool isLeaf(int pos) const{
        int aux = 2;
        int numlevel = 1;

        if(pos != 0){
            for(int i = 0; i < maxsize; (i++)){
                if(i < pos){
                    if(pow(2,numlevel) < aux){

                        numlevel++;
                        //                    cout<< "LEVEL : " << numlevel;
                        aux = 1;

                    }
                    else{

                        aux++;
                    }

                }
                else{

                    break;

                }


            }

            //        cout << endl <<  numlevel << " , " << maxlevel << endl;
            if(numlevel  == maxlevel){

                return 1;

            }
            else {
                return 0;
            }
        }
        else{

            return 0;

        }

    }
};

#endif // HEAP_H
